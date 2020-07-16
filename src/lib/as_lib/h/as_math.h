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


#ifndef ASI_SDK_LV01_GLB_FN_MATH_H_15BE18C4_D543_413E_96F8_61C24AD45985
#define	ASI_SDK_LV01_GLB_FN_MATH_H_15BE18C4_D543_413E_96F8_61C24AD45985

INT32	StrToIntExt(LPCTSTR lpValue);
INT64	StrToInt64(LPCTSTR lpValue);
UINT64	StrToUInt64(LPCTSTR lpValue);
String UInt64ToStr(UINT64 nValue);
String	BinToHex(BYTE nValue);
String	IntToHex(UINT32 nValue);
String	Int16ToHex(UINT16 nValue);
String	Int64ToHex(UINT64 nValue);

BYTE	HexToBin(LPCTSTR lpHex);
UINT32	HexToInt(LPCTSTR lpHex);
UINT16	HexToInt16(LPCTSTR lpHex);
UINT64	HexToInt64(LPCTSTR lpHex);

String	BinToHexLen(PBYTE lpBin, INT32 nBinLen);
PBYTE	HexToBinLen(LPCTSTR lpHex, PBYTE lpBin, INT32 nBinLen);

INT32	CompareText(LPCTSTR strA, LPCTSTR strB);
INT32	CompareValue(INT32 nA, INT32 nB);
INT32	CompareValue(UINT32 nA, UINT32 nB);
INT32	CompareValue(UINT64 nA, UINT64 nB);
INT32	CompareAddr(UINT32 nA, UINT32 nB);
INT32	CompareVersion(String strVerA, String strVerB);

UINT64	GetSurplusBit64(UINT64 nMax, UINT64 nChk);
UINT32	GetSurplusBit32(UINT32 nMax, UINT32 nChk);
UINT16	GetSurplusBit16(UINT16 nMax, UINT16 nChk);

#endif

