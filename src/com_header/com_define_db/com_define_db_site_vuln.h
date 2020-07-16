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


#ifndef COM_DEFINE_DB_SITE_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_SITE_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------

#define SS_SITE_VULN_TYPE_NONE							0x00000000
#define SS_SITE_VULN_TYPE_FILE							0x00000001
#define SS_SITE_VULN_TYPE_REGISTRY						0x00000002
#define SS_SITE_VULN_TYPE_WMI							0x00000004
#define SS_SITE_VULN_TYPE_PROCESS						0x00000008
#define SS_SITE_VULN_TYPE_CUSTOM						0x00000010
//-------------------------------------------------------------------

typedef enum
{
	SS_SITE_VULN_OP_TYPE_NONE					= 0,
	SS_SITE_VULN_OP_TYPE_ADD,
	SS_SITE_VULN_OP_TYPE_EDIT,
	SS_SITE_VULN_OP_TYPE_DELETE,
	SS_SITE_VULN_OP_TYPE_START,
	SS_SITE_VULN_OP_TYPE_STOP,
};
//-------------------------------------------------------------------

#define SS_SITE_VULN_RISK_LEVEL_NONE					0x00000000
#define SS_SITE_VULN_RISK_LEVEL_LOW						0x00000001
#define SS_SITE_VULN_RISK_LEVEL_MEDIUM					0x00000002
#define SS_SITE_VULN_RISK_LEVEL_HIGH					0x00000003
//--------------------------------------------------------------------

typedef enum
{
	SS_SITE_VULN_CUSTOM_ID_NONE					= 0,
	SS_SITE_VULN_CUSTOM_ID_VC_PROCESS,
	SS_SITE_VULN_CUSTOM_ID_VC_PATCH,
	SS_SITE_VULN_CUSTOM_ID_WIN_UPDATE,
	SS_SITE_VULN_CUSTOM_ID_HWP_UPDATE,
	SS_SITE_VULN_CUSTOM_ID_WIN_PW_SAFE,
	SS_SITE_VULN_CUSTOM_ID_WIN_PW_CHANGE,
	SS_SITE_VULN_CUSTOM_ID_WIN_SCREEN_SAFE,
	SS_SITE_VULN_CUSTOM_ID_WIN_SHARE_FOLDER,
	SS_SITE_VULN_CUSTOM_ID_WIN_USB_RUN,
	SS_SITE_VULN_CUSTOM_ID_WIN_ACTIVEX,
	SS_SITE_VULN_CUSTOM_ID_PDF_UPDATE,
	SS_SITE_VULN_CUSTOM_ID_EDIT_PROGRAM,
	SS_SITE_VULN_CUSTOM_ID_WIRELESS_CARD,
	SS_SITE_VULN_CUSTOM_ID_SECU_USB_PROGRAM,
	SS_SITE_VULN_CUSTOM_ID_NONCONFIRM_PROGRAM,

	SS_SITE_VULN_CUSTOM_ID_ACTIVE_FIREWALL = 100,
	SS_SITE_VULN_CUSTOM_ID_SECURITY_CENTER_ALERT,

}SS_SITE_VULN_CUSTOM_ID;
//--------------------------------------------------------------------

#define SS_SITE_VULN_VALUE_TYPE_UNKNOWN				0x00000000
#define SS_SITE_VULN_VALUE_TYPE_STR					0x00000001

#define SS_SITE_VULN_VALUE_TYPE_INT8				0x00000010
#define SS_SITE_VULN_VALUE_TYPE_INT16				0x00000011
#define SS_SITE_VULN_VALUE_TYPE_INT32				0x00000012
#define SS_SITE_VULN_VALUE_TYPE_INT64				0x00000013
#define SS_SITE_VULN_VALUE_TYPE_UINT8				0x00000015
#define SS_SITE_VULN_VALUE_TYPE_UINT16				0x00000016
#define SS_SITE_VULN_VALUE_TYPE_UINT32				0x00000017
#define SS_SITE_VULN_VALUE_TYPE_UINT64				0x00000018

#define SS_SITE_VULN_VALUE_TYPE_STR_INT8			0x00000020
#define SS_SITE_VULN_VALUE_TYPE_STR_INT16			0x00000021
#define SS_SITE_VULN_VALUE_TYPE_STR_INT32			0x00000022
#define SS_SITE_VULN_VALUE_TYPE_STR_INT64			0x00000023
#define SS_SITE_VULN_VALUE_TYPE_STR_UINT8			0x00000025
#define SS_SITE_VULN_VALUE_TYPE_STR_UINT16			0x00000026
#define SS_SITE_VULN_VALUE_TYPE_STR_UINT32			0x00000027
#define SS_SITE_VULN_VALUE_TYPE_STR_UINT64			0x00000028

#define SS_SITE_VULN_VALUE_TYPE_BINARY				0x00000020
//--------------------------------------------------------------------

typedef enum
{
	SS_SITE_VULN_COMPARE_TYPE_UNKNOWN				= 0,
	SS_SITE_VULN_COMPARE_TYPE_EQUAL,
	SS_SITE_VULN_COMPARE_TYPE_EQUAL_OVER,
	SS_SITE_VULN_COMPARE_TYPE_EQUAL_UNDER,
	SS_SITE_VULN_COMPARE_TYPE_EQUAL_RANGE_IN,
	SS_SITE_VULN_COMPARE_TYPE_EQUAL_RANGE_OUT,
	
	SS_SITE_VULN_COMPARE_TYPE_NOT_EQUAL				= 100,			
	SS_SITE_VULN_COMPARE_TYPE_OVER,
	SS_SITE_VULN_COMPARE_TYPE_UNDER,
	SS_SITE_VULN_COMPARE_TYPE_RANGE_IN,
	SS_SITE_VULN_COMPARE_TYPE_RANGE_OUT,
	
	SS_SITE_VULN_COMPARE_TYPE_EXIST					= 200,
	SS_SITE_VULN_COMPARE_TYPE_NOT_EXIST,

	SS_SITE_VULN_COMPARE_TYPE_MATCH					= 300,
	SS_SITE_VULN_COMPARE_TYPE_NOT_MATCH,
	SS_SITE_VULN_COMPARE_TYPE_FIND,

}SS_SITE_VULN_COMPARE_TYPE;
//--------------------------------------------------------------------

#define SS_SITE_VULN_DECISION_CRITERIA_AND			0
#define SS_SITE_VULN_DECISION_CRITERIA_OR			1

//--------------------------------------------------------------------

#define SS_SITE_VULN_PERM_RENEXT						0x00000800
#define SS_SITE_VULN_PERM_FILELOG						0x00000400
#define SS_SITE_VULN_PERM_TKILL							0x00000200
#define SS_SITE_VULN_PERM_PEND							0x00000100
#define SS_SITE_VULN_PERM_HIDE							0x00000080
#define SS_SITE_VULN_PERM_PROCKILL						0x00000040
#define SS_SITE_VULN_PERM_CREATE						0x00000020
#define SS_SITE_VULN_PERM_DELETE						0x00000010
#define SS_SITE_VULN_PERM_RENAME						0x00000008
#define SS_SITE_VULN_PERM_READ							0x00000004
#define SS_SITE_VULN_PERM_WRITE							0x00000002
#define SS_SITE_VULN_PERM_EXEC							0x00000001
#define SS_SITE_VULN_PERM_NONE							0x00000000

#define SS_SITE_VULN_PERM_PKG_READ						SS_SITE_VULN_PERM_READ | SS_SITE_VULN_PERM_EXEC
#define SS_SITE_VULN_PERM_PKG_WRITE						SS_SITE_VULN_PERM_PKG_READ |\
														SS_SITE_VULN_PERM_WRITE |\
														SS_SITE_VULN_PERM_RENAME | SS_SITE_VULN_PERM_DELETE | SS_SITE_VULN_PERM_CREATE |\
														SS_SITE_VULN_PERM_PROCKILL | SS_SITE_VULN_PERM_RENEXT

#define SS_SITE_VULN_PERM_PKG_ALL						SS_SITE_VULN_PERM_PKG_READ | SS_SITE_VULN_PERM_PKG_WRITE
//--------------------------------------------------------------------

#define SS_SITE_VULN_EXT_OPTION_SUPPORT_SCAN			0x00000001
#define SS_SITE_VULN_EXT_OPTION_SUPPORT_REPAIR			0x00000002
#define SS_SITE_VULN_EXT_OPTION_SUPPORT_LOCK			0x00000004
//--------------------------------------------------------------------

#endif	//COM_DEFINE_DB_SITE_VULN_H_938EF200_F60B_452A_BD30_A10E8507EDCC