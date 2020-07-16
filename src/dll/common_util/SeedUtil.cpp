/*
 * Copyright (C) 2020-2025 ASHINi corp. 
 * 
 * This library is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU Lesser General Public 
 * License as published by the Free Software Foundation; either 
 * version 2.1 of the License, or (at your option) any later version. 
 * 
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * Lesser General Public License for more details. 
 * 
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this library; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
 * 
 */

// SeedUtil.cpp: implementation of the CSeedUtil class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "com_struct.h"
#include "SeedUtil.h"
#include "Seedx.h"

const GUID GUID_NULL = {0L,0,0,0,0,0,0,0,0,0,0};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSeedUtil::CSeedUtil()
{
	m_nIsInit = 0;
	memset(m_pdwRoundKey, 0, sizeof(DWORD)*32);
}
//--------------------------------------------------------------------

CSeedUtil::~CSeedUtil()
{

}
//--------------------------------------------------------------------

INT32	CSeedUtil::Set_Key(BYTE* lpKey, INT32 nKeyLen)
{
	UINT8 pSeedKey[16] = {0, };
	if(lpKey == NULL || nKeyLen < 1)
		return -1;
	
	memcpy(pSeedKey, lpKey, nKeyLen);

	SeedEncRoundKey(m_pdwRoundKey, pSeedKey);
	m_nIsInit = 1;
	return 0;
}
//--------------------------------------------------------------------

INT32	CSeedUtil::Make_Key(BYTE* lpKey)
{
    GUID m_guid = GUID_NULL;

	if(lpKey == NULL)
		return -1;
	CoCreateGuid(&m_guid);
	if(memcmp(&m_guid,  &GUID_NULL, sizeof(GUID)) != 0)
		return -2;

	memcpy(lpKey, &m_guid, 16);

	return 0;
}
//--------------------------------------------------------------------

INT32	CSeedUtil::Encrypt_Data(BYTE* lpData, INT32 nLen, BYTE** lpOutData, UINT32& nOutLen)
{
	if(!m_nIsInit)	return -1;

	INT32 nLoofNum	= nLen/SeedBlockSize;
	INT32 nRemain	= nLen%SeedBlockSize;

	if(lpData == NULL || nLen < 1 || lpOutData == NULL)
		return -1;
	if(nRemain)
		nOutLen = nLen + (24 - nRemain);
	else
		nOutLen = nLen + 8;

	if(*lpOutData == NULL)	
		*lpOutData	= (BYTE*)malloc(nOutLen + 1);
	if(*lpOutData == NULL)
		return -2;
	
	memset(*lpOutData, 0, nOutLen + 1);

	BYTE* lpOrPoint = *lpOutData;
	
	if(*lpOutData == 0)
		return -3;

	//memset(*lpOutData, 0, nOutLen);
	memcpy(*lpOutData,	&nOutLen,	4);	*lpOutData += 4;
	memcpy(*lpOutData,	&nLen,		4);	*lpOutData += 4;
		
	memcpy(*lpOutData, lpData, nLen);
	
	for(INT32 i = 0 ; i < nLoofNum; i++)
	{			
		SeedEncrypt(*lpOutData, m_pdwRoundKey);		
		*lpOutData += SeedBlockSize;
	}
	if(nRemain)
	{
		SeedEncrypt(*lpOutData, m_pdwRoundKey);		
	}	

	*lpOutData = lpOrPoint;
	return 0;
}
//--------------------------------------------------------------------

INT32	CSeedUtil::Encrypt_Len(INT32 nLen)
{
	INT32 nRemain	= nLen%SeedBlockSize;

	if(nRemain)
		nLen += (24 - nRemain);
	else
		nLen += 8;

	return nLen;
}
//--------------------------------------------------------------------

INT32	CSeedUtil::Decrypt_Data(BYTE* lpData, BYTE** lpOutData, UINT32& nOutLen)
{
	INT32 nLen = 0;

	if(!m_nIsInit)
		return -1;
	if(lpData == NULL || lpOutData == NULL)
		return -2;

	memcpy(&nLen, lpData, 4);		lpData += 4;
	memcpy(&nOutLen, lpData, 4);	lpData += 4;

	if (nLen > 100000000)
		return -3;

	*lpOutData = (BYTE*)malloc(nLen - 7);
	memset(*lpOutData, 0, nLen - 7);
	memcpy(*lpOutData, lpData, nLen - 8);

	BYTE* lpOrPoint = *lpOutData;

	INT32 nLoofNum	= nOutLen/16;
	INT32 nRemain	= nOutLen%16;
	
	for(INT32 i = 0 ; i < nLoofNum; i++)
	{
		SeedDecrypt(*lpOutData, m_pdwRoundKey);		
		*lpOutData += SeedBlockSize;
	}
	if(nRemain)
	{
		SeedDecrypt(*lpOutData, m_pdwRoundKey);
	}

	*lpOutData = lpOrPoint;
	return 0;
}
//--------------------------------------------------------------------

INT32	CSeedUtil::FreeBuffer(BYTE* lpBuffer)
{
	safe_free(lpBuffer);
	return 0;
}
//--------------------------------------------------------------------

