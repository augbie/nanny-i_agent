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

// BIniFile.cpp: implementation of the CBIniFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "com_struct.h"
#include "BIniFile.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CBIniFile::CBIniFile()
{
	memset(m_szFileName, 0x00, MAX_PATH);
}

CBIniFile::CBIniFile(LPCTSTR lpFileName)
{
	if(lpFileName)
		strncpy(m_szFileName, lpFileName, MAX_PATH-1);
}

CBIniFile::~CBIniFile()
{

}

void CBIniFile::SetFileName(LPCTSTR lpFileName)
{
	if(lpFileName)
		strncpy(m_szFileName, lpFileName, MAX_PATH-1);
}

BOOL CBIniFile::WriteProfileSection(LPCTSTR lpszSection, LPCTSTR lpString)
{
	return TRUE;
}


BOOL CBIniFile::WriteProfileString(LPCTSTR lpszSection, LPCTSTR lpKeyName, LPCTSTR lpString)
{
	return TRUE;
}

BOOL CBIniFile::WriteProfileInt(LPCTSTR lpszSection, LPCTSTR lpKeyName, int nVal)
{
	return TRUE;
}

BOOL CBIniFile::WriteProfileStruct(LPCTSTR lpszSection, LPCTSTR lpKeyName, LPVOID lpStruct, UINT uSizeStruct)
{
	return TRUE;
}

DWORD CBIniFile::GetProfileSectionNames(LPCSTR lpszReturnBuffer, DWORD nSize)
{
	return TRUE;
}

DWORD CBIniFile::GetProfileSection(LPCTSTR lpszSection, LPCSTR lpReturnedString, DWORD nSize)
{
	return TRUE;
}

DWORD CBIniFile::GetProfileString(LPCTSTR lpszSection, LPCTSTR lpKeyName, LPCTSTR lpDefault, LPCSTR lpReturnedString, DWORD nSize)
{
	return TRUE;
}

UINT CBIniFile::GetProfileInt(LPCTSTR lpszSection, LPCTSTR lpKeyName, INT nDefault)
{
	return TRUE;
}

BOOL CBIniFile::GetProfileStruct(LPCTSTR lpszSection, LPCTSTR lpKeyName, LPVOID lpStruct, UINT uSizeStruct)
{
	return TRUE;
}

DWORD CBIniFile::GetProfileStringW(LPCWSTR lpszSection, LPCWSTR lpKeyName, LPCWSTR lpDefault, LPWSTR lpReturnedString, DWORD nSize, LPWSTR lpFileName)
{
	return TRUE;
}

