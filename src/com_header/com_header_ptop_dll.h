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


#ifndef COM_HEADER_PTOP_DLL_H_152BCED9_0D66_4F66_8A87_BF47B4A5386C
#define COM_HEADER_PTOP_DLL_H_152BCED9_0D66_4F66_8A87_BF47B4A5386C


//////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------

typedef struct _asi_ptp_init
{
	_asi_ptp_init()
	{
		ZeroMemory(szHomePath, MAX_PATH);
		ZeroMemory(szTempPath, MAX_PATH);
		ZeroMemory(szOpenAddr, MAX_PATH);

		ZeroMemory(szLogPath, MAX_PATH);
		ZeroMemory(szLogFile, MAX_PATH);

		nOpenPort	= 0;
		hOwner		= 0;
	}

	CHAR		szHomePath[MAX_PATH];
	CHAR		szTempPath[MAX_PATH];
	CHAR		szLogPath[MAX_PATH];
	CHAR		szLogFile[MAX_PATH];
	CHAR		szOpenAddr[MAX_PATH];
	UINT32		nOpenPort;
	HANDLE		hOwner;
}ASI_PTP_INIT, *PASI_PTP_INIT;


//---------------------------------------------------------------------------

typedef INT32 (*ASIPTP_InitPtoPType)(PASI_PTP_INIT papi, INT32 nSize);
typedef INT32 (*ASIPTP_GetFileRequestType)(UINT32 nRequestID, LPTSTR strFileName);
typedef INT32 (*ASIPTP_SetCheckResultToFileHashType)(UINT32 nRequestID, UINT32 nRtn);
typedef INT32 (*ASIPTP_AddFileInfoFromHttpSvrType)(LPTSTR strFileName, INT32 nResult);
typedef INT32 (*ASIPTP_AddFileInfoFromExistsType)(LPTSTR strFileName);
typedef INT32 (*ASIPTP_SetRemainLogFlagType)(UINT32 nFlag);

//---------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////

#endif //COM_HEADER_PTOP_DLL_H_152BCED9_0D66_4F66_8A87_BF47B4A5386C
