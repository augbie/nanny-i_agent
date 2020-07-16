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

#ifndef _AS_REGISTRY_H_
#define _AS_REGISTRY_H_

#define ERROR_NO_MORE_ITEMS      259
#define ERROR_MORE_DATA			 234


#define KEY_READ	1
#define	KEY_WRITE	2
#define	KEY_ALL_ACCESS	3

#define REG_NONE                    ( 0 )   // No value type
#define REG_SZ                      ( 1 )   // Unicode nul terminated string
#define REG_EXPAND_SZ               ( 2 )   // Unicode nul terminated string with environment variable references
#define REG_BINARY                  ( 3 )   // Free form binary
#define REG_DWORD                   ( 4 )   // 32-bit number
#define REG_MULTI_SZ                ( 7 )   // Multiple Unicode strings
#define REG_QWORD                   ( 11 )  // 64-bit number

extern long RegCreateKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD dwReserved, LPTSTR lpClass, DWORD dwOption, DWORD dwSam, void* lpSecutiry, HKEY* phkResult, DWORD* lpdwDisposition, char *acLogMsg=NULL);
extern long RegQueryValueEx(HKEY hKey, LPCTSTR lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD dwMaxLen, DWORD* lpcbData, char *acLogMsg=NULL);
extern long RegSetValueEx(HKEY hKey, LPCTSTR lpValueName, DWORD dwReserved, DWORD dwType, const BYTE* lpData, DWORD cdData, char *acLogMsg=NULL);
extern VOID RegCloseKey(HKEY hKey);
extern long RegEnumKey(HKEY hKey, DWORD dwIndex, LPTSTR lpName, DWORD ccName);
extern long RegEnumValue(HKEY hKey, DWORD dwIndex, LPTSTR lpValueName, DWORD* lpcchValueName, DWORD* lpReserved, DWORD* lpType, LPBYTE lpData, DWORD* lpcbData);
extern long RegOpenKey(HKEY hKey, LPCTSTR lpSubKey, HKEY* phkResult, char *acLogMsg=NULL);
extern long RegOpenKeyEx(HKEY hKey, LPCTSTR lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY* phkResult, char *acLogMsg=NULL);
extern long RegDeleteKey(HKEY hKey, LPCTSTR lpSubKey, char *acLogMsg=NULL);
extern long RegDeleteValue(HKEY hKey, LPCTSTR lpValueName, char *acLogMsg=NULL);

#endif /* _AS_REGISTRY_H_ */


