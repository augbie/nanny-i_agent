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


#ifndef PKTDEF_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define PKTDEF_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//------------------------------------------------------------------------------

#define	G_TYPE_AUTH									0x0001
#define G_CODE_AUTH_C_LOGIN							0x0011
#define G_CODE_AUTH_M_LOGIN							0x0012
#define G_CODE_AUTH_D_LOGIN							0x0013
#define G_CODE_AUTH_OTP_LOGIN						0x0014
#define G_CODE_AUTH_LOGIN							0x0021
#define G_CODE_AUTH_LOGIN_LAST						0x0022

//------------------------------------------------------------------------------

#define G_INIT_REQUEST_TYPE_COMM					0x0000000000000001
#define	G_INIT_REQUEST_TYPE_ADMIN					0x0000000000000010
#define	G_INIT_REQUEST_TYPE_GROUP					0x0000000000000020
#define	G_INIT_REQUEST_TYPE_HOST					0x0000000000000040
#define	G_INIT_REQUEST_TYPE_USER					0x0000000000000080
#define G_INIT_REQUEST_TYPE_ENV						0x0000000000001000
#define G_INIT_REQUEST_TYPE_LOCAL_ENV				0x0000000000002000
#define G_INIT_REQUEST_TYPE_LOG						0x0000000000004000
#define G_INIT_REQUEST_TYPE_POLICY					0x0000000001000000
#define G_INIT_REQUEST_TYPE_PENV					0x0000000002000000


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#define	G_TYPE_INIT									0x0002
#define G_CODE_INIT_REQUEST							0x0001

enum _ENUM_G_CODE_INIT_GROUP
{
	G_CODE_INIT_GROUP								= 0x0010,
	G_CODE_INIT_GROUP_POLICY,
	G_CODE_INIT_GROUP_PHYSICAL,
	G_CODE_INIT_GROUP_IP,

	G_CODE_INIT_GROUP_LAST,
	G_CODE_INIT_GROUP_PKT_NUMBER					= (G_CODE_INIT_GROUP_LAST - G_CODE_INIT_GROUP),
};

enum _ENUM_G_CODE_INIT_HOST
{
	G_CODE_INIT_HOST								= 0x0020,
	G_CODE_INIT_HOST_POLICY,
	G_CODE_INIT_HOST_HW,
	G_CODE_INIT_HOST_STATUS,
	G_CODE_INIT_HOST_SW,
	G_CODE_INIT_HOST_SYS,
	G_CODE_INIT_HOST_STATUS_PO,
	G_CODE_INIT_HOST_KEY,

	G_CODE_INIT_HOST_LAST,
	G_CODE_INIT_HOST_PKT_NUMBER						= (G_CODE_INIT_HOST_LAST - G_CODE_INIT_HOST),
};


enum _ENUM_G_CODE_INIT_ADMIN
{
	G_CODE_INIT_ADMIN								= 0x0030,
	G_CODE_INIT_ADMIN_ENV,
	G_CODE_INIT_ADMIN_ENV_DT,
	G_CODE_INIT_ADMIN_ENV_DT_UNIT,
	G_CODE_INIT_ADMIN_ENV_MN,

	G_CODE_INIT_ADMIN_LAST,
	G_CODE_INIT_ADMIN_PKT_NUMBER					= (G_CODE_INIT_ADMIN_LAST - G_CODE_INIT_ADMIN),
};

enum _ENUM_G_CODE_INIT_USER
{
	G_CODE_INIT_USER								= 0x0040,
	G_CODE_INIT_USER_POLICY,
	G_CODE_INIT_USER_GROUP,
	G_CODE_INIT_USER_GROUP_POLICY,
	G_CODE_INIT_USER_PC,

	G_CODE_INIT_USER_LAST,
	G_CODE_INIT_USER_PKT_NUMBER						= (G_CODE_INIT_USER_LAST - G_CODE_INIT_USER)
};

enum _ENUM_G_CODE_INIT_COMMON
{
	G_CODE_INIT_OS_TYPE								= 0x0100,
	G_CODE_INIT_OS_PD_TYPE,
	G_CODE_INIT_ERR_CODE,
	G_CODE_INIT_UPDATE_INFO,
	G_CODE_INIT_SITE_CPU,
	G_CODE_INIT_SITE_VULN,
	G_CODE_INIT_SITE_VULN_SCAN,
	G_CODE_INIT_SITE_VULN_REPAIR,
	G_CODE_INIT_SITE_VULN_LOCK,			//Order Socket

	G_CODE_INIT_SITE_SW,
	G_CODE_INIT_SITE_FILE,
	G_CODE_INIT_SITE_FILE_PUBLISHER,
	G_CODE_INIT_SITE_FILE_PRODUCT,
	G_CODE_INIT_SITE_FILE_CODE_SIGN,
	G_CODE_INIT_SITE_FILE_BANK,
	G_CODE_INIT_SITE_FILE_REF,
	G_CODE_INIT_SITE_PTN_FILE,
	G_CODE_INIT_SITE_PTN_PKG,
	G_CODE_INIT_SITE_PTN_PKG_UNIT,		//Data Socket

	G_CODE_INIT_SITE_LAST,
	G_CODE_INIT_COMMON_PKT_NUMBER					= (G_CODE_INIT_SITE_VULN_LOCK - G_CODE_INIT_OS_TYPE)
};

enum _ENUM_G_CODE_INIT_ENV
{
	G_CODE_INIT_ENV_SVR_INFO						= 0x0200,
	G_CODE_INIT_ENV_HOST_LICENSE,
	G_CODE_INIT_ENV_SOCKET,
	G_CODE_INIT_ENV_WEB_SVR,
	G_CODE_INIT_ENV_NOTIFY_INFO,
	G_CODE_INIT_ENV_LOG,
	G_CODE_INIT_ENV_LOG_UNIT,
	G_CODE_INIT_ENV_LICENSE,
	G_CODE_INIT_ENV_POLICY,
	G_CODE_INIT_ENV_RES_USAGE,
	G_CODE_INIT_ENV_RES_USAGE_HISTORY,
	G_CODE_INIT_ENV_SELF_PROTECT_AGT,
	G_CODE_INIT_ENV_SELF_PROTECT_SVR,
	G_CODE_INIT_ENV_TRUST_SUBJECT,
	G_CODE_INIT_ENV_SORG_LINK,
	G_CODE_INIT_ENV_SORG_LINK_DB,
	G_CODE_INIT_ENV_SORG_LINK_TB,	
	G_CODE_INIT_ENV_SUB_SVR_LGN,
	G_CODE_INIT_ENV_SUB_SVR_MGR,
	G_CODE_INIT_ENV_SUB_SVR_UDT,
	G_CODE_INIT_ENV_SVR_SECU,
	G_CODE_INIT_ENV_TRUST_SUBJECT_SVR,
	G_CODE_INIT_ENV_INFO_REC,
	G_CODE_INIT_ENV_INFO_REC_SITE_REF,
};

enum _ENUM_G_CODE_INIT_LOCAL_ENV
{
	G_CODE_INIT_LOCAL_ENV_DOC						= 0x0280,
	G_CODE_INIT_LOCAL_ENV_AUTH,
};

enum _ENUM_G_CODE_INIT_LOG
{
	G_CODE_INIT_LOG									= 0x0300,
	G_CODE_INIT_LOG_EVENT,
	G_CODE_INIT_LOG_DOC,
	G_CODE_INIT_LOG_SECU,
	G_CODE_INIT_LOG_DEPLOY_FILE,
	G_CODE_INIT_LOG_DOC_DSCAN,
};

enum _ENUM_G_CODE_INIT_POLICY_SAMS
{
	G_CODE_INIT_PO_UPDATE							= 0x0500,
	G_CODE_INIT_PO_SVR_INFO_LGN,
	G_CODE_INIT_PO_HOST_RM_INFO,
	G_CODE_INIT_PO_HOST_RUN,
	G_CODE_INIT_PO_HOST_CLEAR,
	G_CODE_INIT_PO_HOST_CLEAR_PKG,
	G_CODE_INIT_PO_HOST_CLEAR_UNIT,
	G_CODE_INIT_PO_SVR_INFO_UDT,
	G_CODE_INIT_PO_SVR_INFO_MGR,
	G_CODE_INIT_PO_SCH,
	G_CODE_INIT_PO_SCH_PKG,
	G_CODE_INIT_PO_SCH_UNIT,
	G_CODE_INIT_PO_SCH_INFO,
};

enum _ENUM_G_CODE_INIT_POLICY_WMS
{
	G_CODE_INIT_PO_POWER							= 0x0600,
	G_CODE_INIT_PO_POWER_PKG,
	G_CODE_INIT_PO_POWER_UNIT,
	G_CODE_INIT_PO_CTL_PANEL,
	G_CODE_INIT_PO_CTL_PANEL_PKG,
	G_CODE_INIT_PO_CTL_PANEL_UNIT,
	G_CODE_INIT_PO_DEPLOY_FILE,
	G_CODE_INIT_PO_DEPLOY_FILE_PKG,
	G_CODE_INIT_PO_DEPLOY_FILE_UNIT,
	G_CODE_INIT_PO_DEPLOY_FILE_UNIT_INFO_PKG,
	G_CODE_INIT_PO_DEPLOY_FILE_UNIT_CHK_PKG,
	G_CODE_INIT_PO_DEPLOY_FILE_UNIT_TAR_PKG,
	G_CODE_INIT_PO_DEPLOY_FILE_UNIT_SCH_PKG,
	G_CODE_INIT_PO_DEPLOY_FILE_INFO_UNIT,
	G_CODE_INIT_PO_DEPLOY_FILE_CHK_UNIT,
	G_CODE_INIT_PO_DEPLOY_FILE_TAR_UNIT,
	G_CODE_INIT_PO_DEPLOY_FILE_SCH_UNIT,
	G_CODE_INIT_PO_WIN_RUN,	
};

enum _ENUM_G_CODE_INIT_POLICY_ACMS
{
	G_CODE_INIT_PO_CTL_PROC							= 0x0700,
	G_CODE_INIT_PO_CTL_PROC_PKG,
	G_CODE_INIT_PO_CTL_PROC_UNIT,
	G_CODE_INIT_PO_SELF_PROTECT,
	G_CODE_INIT_PO_SELF_PROTECT_PKG,
	G_CODE_INIT_PO_SELF_PROTECT_UNIT,
	G_CODE_INIT_PO_CTL_MEDIA,
};

enum _ENUM_G_CODE_INIT_POLICY_NIMS
{
	G_CODE_INIT_PO_FA_CLEAR							= 0x0800,
	G_CODE_INIT_PO_FA_CLEAR_PKG,
	G_CODE_INIT_PO_FA_CLEAR_UNIT,
	G_CODE_INIT_PO_FA_PROC,
	G_CODE_INIT_PO_FA_PROC_PKG,
	G_CODE_INIT_PO_FA_PROC_UNIT,
	G_CODE_INIT_PO_FA_OP,
	G_CODE_INIT_PO_FA_OP_PKG,
	G_CODE_INIT_PO_FA_OP_UNIT,
	G_CODE_INIT_PO_FA_OP_UNIT_SUB_PKG,
	G_CODE_INIT_PO_FA_OP_UNIT_OBJ_PKG,
	G_CODE_INIT_PO_FA_OP_UNIT_SCH_PKG,
	G_CODE_INIT_PO_FA_OP_UNIT_RUL_PKG,
	G_CODE_INIT_PO_FA_OP_SUB_UNIT,
	G_CODE_INIT_PO_FA_OP_OBJ_UNIT,
	G_CODE_INIT_PO_FA_OP_SCH_UNIT,
	G_CODE_INIT_PO_FA_ENV,
	G_CODE_INIT_PO_FA_ENV_PKG,
	G_CODE_INIT_PO_FA_ENV_UNIT,
	G_CODE_INIT_PO_FA_BK,
	G_CODE_INIT_PO_FA_NOTIFY,
	G_CODE_INIT_PO_FA_NOTIFY_PKG,
};

enum _ENUM_G_CODE_INIT_POLICY_NCMS
{
	G_CODE_INIT_PO_FE_PTN_OP						= 0x0900,
	G_CODE_INIT_PO_FE_PTN_BL,
	G_CODE_INIT_PO_FE_PTN_BL_PKG,
	G_CODE_INIT_PO_FE_PTN_WL,
	G_CODE_INIT_PO_FE_PTN_WL_PKG,
	G_CODE_INIT_PO_FE_PTN_FILE,
	G_CODE_INIT_PO_FE_EXCLUDE,
	G_CODE_INIT_PO_FE_EXCLUDE_PKG,
	G_CODE_INIT_PO_FE_EXCLUDE_UNIT,
	G_CODE_INIT_PO_FE_NOTIFY,
	G_CODE_INIT_PO_FE_NOTIFY_PKG,
	G_CODE_INIT_PO_FE_SINGLE_PTN,
	G_CODE_INIT_PO_FE_SINGLE_PTN_UNIT,
	G_CODE_INIT_PO_FE_PTN_LO,
};
 
enum _ENUM_G_CODE_INIT_POLICY_NOMS
{
	G_CODE_INIT_PO_IN_PTN_OP					= 0x1000,
	G_CODE_INIT_PO_IN_PTN_OP_PKG,
	G_CODE_INIT_PO_IN_PTN_OP_UNIT,
	G_CODE_INIT_PO_IN_PTN_BL,
	G_CODE_INIT_PO_IN_PTN_BL_PKG,
	G_CODE_INIT_PO_IN_PTN_BL_UNIT,
	G_CODE_INIT_PO_IN_PTN_BL_FILE,
	G_CODE_INIT_PO_IN_PTN_WL,
	G_CODE_INIT_PO_IN_PTN_WL_PKG,
	G_CODE_INIT_PO_IN_PTN_WL_UNIT,
	G_CODE_INIT_PO_IN_PTN_WL_FILE,
	G_CODE_INIT_PO_IN_PTN_EX,
	G_CODE_INIT_PO_IN_PTN_EX_PKG,
	G_CODE_INIT_PO_IN_PTN_EX_UNIT,
	G_CODE_INIT_PO_IN_PTN_SP,
	G_CODE_INIT_PO_IN_PTN_SP_PKG,
	G_CODE_INIT_PO_IN_PTN_SP_UNIT,
	G_CODE_INIT_PO_IN_PTN_SP_RULE,
	G_CODE_INIT_PO_IN_PTN_NO,
	G_CODE_INIT_PO_IN_PTN_NO_PKG,

	G_CODE_INIT_PO_IN_AC_DOC,
	G_CODE_INIT_PO_IN_AC_DOC_PKG,
	G_CODE_INIT_PO_IN_AC_DOC_UNIT,
	G_CODE_INIT_PO_IN_AC_DOC_UNIT_SUB_PKG,
	G_CODE_INIT_PO_IN_AC_DOC_UNIT_OBJ_PKG,	
	G_CODE_INIT_PO_IN_AC_DOC_SUB_UNIT,
	G_CODE_INIT_PO_IN_AC_DOC_OBJ_UNIT,	
	G_CODE_INIT_PO_IN_AC_SF,
	G_CODE_INIT_PO_IN_AC_SF_PKG,
	G_CODE_INIT_PO_IN_AC_SF_UNIT,
	G_CODE_INIT_PO_IN_AC_SF_UNIT_SUB_PKG,
	G_CODE_INIT_PO_IN_AC_SF_UNIT_OBJ_PKG,	
	G_CODE_INIT_PO_IN_AC_SF_SUB_UNIT,
	G_CODE_INIT_PO_IN_AC_SF_OBJ_UNIT,	
	G_CODE_INIT_PO_IN_AC_FILE,
	G_CODE_INIT_PO_IN_AC_FILE_PKG,
	G_CODE_INIT_PO_IN_AC_FILE_UNIT,	
	G_CODE_INIT_PO_IN_AC_FILE_UNIT_SUB_PKG,
	G_CODE_INIT_PO_IN_AC_FILE_UNIT_OBJ_PKG,
	G_CODE_INIT_PO_IN_AC_FILE_UNIT_SCH_PKG,
	G_CODE_INIT_PO_IN_AC_FILE_UNIT_RUL_PKG,
	G_CODE_INIT_PO_IN_AC_FILE_SUB_UNIT,
	G_CODE_INIT_PO_IN_AC_FILE_OBJ_UNIT,
	G_CODE_INIT_PO_IN_AC_FILE_SCH_UNIT,

	G_CODE_INIT_PO_IN_VULN_OP,
	G_CODE_INIT_PO_IN_VULN_OP_PKG,
	G_CODE_INIT_PO_IN_VULN_SCAN,
	G_CODE_INIT_PO_IN_VULN_SCAN_PKG,
	G_CODE_INIT_PO_IN_VULN_SCAN_UNIT,
	G_CODE_INIT_PO_IN_VULN_SCAN_UNIT_PKG,
};


#define G_CODE_INIT_LAST							0xFFFF

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#define	G_CODE_COMMON_ADD							0x0001
#define	G_CODE_COMMON_EDIT							0x0002
#define	G_CODE_COMMON_DEL							0x0003
#define	G_CODE_COMMON_MOVE							0x0004
#define	G_CODE_COMMON_INFO							0x0005
#define	G_CODE_COMMON_ROLLBACK						0x0006
#define	G_CODE_COMMON_SET							0x0007
#define	G_CODE_COMMON_HASH							0x0008
#define G_CODE_COMMON_APPLY							0x0100
#define G_CODE_COMMON_RELEASE						0x0200
#define G_CODE_COMMON_SYNC							0x0300
#define G_CODE_COMMON_CTRL							0x0301
#define G_CODE_COMMON_LOAD							0x0302
#define G_CODE_COMMON_CHECK							0x0303
#define G_CODE_COMMON_INIT							0x0304
#define G_CODE_COMMON_LAST							0x0305
#define G_CODE_COMMON_SCAN							0x0306
#define G_CODE_COMMON_FIND							0x0307
#define G_CODE_COMMON_END							0x0308
#define G_CODE_COMMON_PROGRESS						0x0309
#define G_CODE_COMMON_AUTH							0x030A
#define G_CODE_COMMON_REGIST						0x030B
#define G_CODE_COMMON_TOSS							0x030C
#define G_CODE_COMMON_MAKE							0x030D
#define G_CODE_COMMON_REQUEST						0x030E

#define G_CODE_COMMON_LOCK_INFO						0x0380
#define G_CODE_COMMON_MULTI_BEGIN					0x0400
#define G_CODE_COMMON_MULTI_LOOP					0x0401
#define G_CODE_COMMON_MULTI_END						0x0402
#define G_CODE_COMMON_CHANGE						0x0403

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

enum _ENUM_G_TYPE_GROUP
{
	G_TYPE_GROUP									= 0x0010,
	G_TYPE_GROUP_POLICY,
	G_TYPE_GROUP_PHYSICAL,
	G_TYPE_GROUP_IP,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
enum _ENUM_G_TYPE_HOST
{
	G_TYPE_HOST										= 0x0020,
	G_TYPE_HOST_POLICY,
	G_TYPE_HOST_HW,
	G_TYPE_HOST_STATUS,
	G_TYPE_HOST_SW,
	G_TYPE_HOST_SYS,
	G_TYPE_HOST_STATUS_PO,
	G_TYPE_HOST_KEY,
};

enum _ENUM_G_TYPE_HOST_CODE_HOST
{
	G_CODE_HOST_SET_WORK_GROUP						= 0x0010,
	G_CODE_HOST_SET_WORK_GROUP_ALIAS,
	G_CODE_HOST_SET_NAME,
	G_CODE_HOST_SET_NAME_ALIAS,
	G_CODE_HOST_SET_SYSTEM_INFO,
	G_CODE_HOST_SET_MODULE_HASH_CHK,
	G_CODE_HOST_SET_VERSION_ID,
	G_CODE_HOST_SET_USED_FLAG,
	G_CODE_HOST_SET_GROUP_ID,
	G_CODE_HOST_SET_HARDWARE,
	G_CODE_HOST_SET_CON_STATUS,
	G_CODE_HOST_SET_CON_STATUS_LIST,
	G_CODE_HOST_CHK_REFRESH_INFO,
	G_CODE_HOST_RESINFO,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_ADMIN
{
	G_TYPE_ADMIN									= 0x0030,
	G_TYPE_ADMIN_ENV,
	G_TYPE_ADMIN_ENV_DT,
	G_TYPE_ADMIN_ENV_DT_UNIT,
	G_TYPE_ADMIN_ENV_MN,
};

enum _ENUM_G_TYPE_ADMIN_CODE_ADMIN
{
	G_CODE_ADMIN_EDIT_PW							= 0x0010,
	G_CODE_ADMIN_CON_STATUS,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_USER
{
	G_TYPE_USER										= 0x0040,
	G_TYPE_USER_POLICY,
	G_TYPE_USER_GROUP,
	G_TYPE_USER_GROUP_POLICY,
	G_TYPE_USER_PC,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_COMMON
{
	G_TYPE_OS_TYPE									= 0x0100,
	G_TYPE_ERR_CODE,
	G_TYPE_SITE_CPU,
	G_TYPE_SITE_SW,
	G_TYPE_UPDATE_INFO,
	G_TYPE_SITE_PATH,
	G_TYPE_SITE_FILE,
	G_TYPE_SITE_FILE_PUBLISHER,
	G_TYPE_SITE_FILE_PRODUCT,
	G_TYPE_SITE_FILE_CODE_SIGN,
	G_TYPE_SITE_FILE_BANK,
	G_TYPE_SITE_FILE_REF,
	G_TYPE_SITE_PTN_FILE,
	G_TYPE_SITE_PTN_PKG,
	G_TYPE_SITE_PTN_PKG_UNIT,
	G_TYPE_SITE_VULN,
	G_TYPE_SITE_VULN_SCAN,
	G_TYPE_SITE_VULN_REPAIR,
	G_TYPE_SITE_VULN_LOCK,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_ENV
{
	G_TYPE_ENV_SVR_INFO								= 0x0200,
	G_TYPE_ENV_HOST_LICENSE,
	G_TYPE_ENV_SOCKET,
	G_TYPE_ENV_WEB_SVR,
	G_TYPE_ENV_NOTIFY_INFO,
	G_TYPE_ENV_LOG,
	G_TYPE_ENV_LOG_UNIT,
	G_TYPE_ENV_LICENSE,
	G_TYPE_ENV_POLICY,
	G_TYPE_ENV_RES_USAGE,
	G_TYPE_ENV_SELF_PROTECT_AGT,
	G_TYPE_ENV_SELF_PROTECT_SVR,
	G_TYPE_ENV_TRUST_SUBJECT,
	G_TYPE_ENV_DESKTOP,
	G_TYPE_ENV_SORG_LINK,
	G_TYPE_ENV_SORG_LINK_DB,
	G_TYPE_ENV_SUB_SVR_LGN,
	G_TYPE_ENV_SUB_SVR_MGR,
	G_TYPE_ENV_SUB_SVR_UDT,
	G_TYPE_ENV_SUB_SVR_RPT,
	G_TYPE_ENV_SVR_SECU,
	G_TYPE_ENV_TRUST_SUBJECT_SVR,
	G_TYPE_ENV_INFO_REC,
	G_TYPE_ENV_INFO_REC_SITE_REF,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_LOCAL_ENV
{
	G_TYPE_LOCAL_ENV_DOC							= 0x0280,
	G_TYPE_LOCAL_ENV_AUTH,
};
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_LOG
{
	G_TYPE_LOG_EVENT								= 0x0300,
	G_TYPE_LOG_DOC,
	G_TYPE_LOG_SECU,
	G_TYPE_LOG_DEPLOY_FILE,
	G_TYPE_LOG_DOC_DSCAN,
	G_TYPE_LOG_STATUS,
};

enum _ENUM_G_TYPE_LOG_CODE_LOG
{
	G_CODE_LOG_DOC_ROLLBACK_EACH_HOST				= 0x0010,
};

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

enum _ENUM_G_TYPE_POLICY_SAMS
{
	G_TYPE_PO_UPDATE								= 0x0500,
	G_TYPE_PO_SVR_INFO_LGN,
	G_TYPE_PO_HOST_RM_INFO,
	G_TYPE_PO_HOST_RUN,
	G_TYPE_PO_HOST_CLEAR,
	G_TYPE_PO_HOST_CLEAR_PKG,
	G_TYPE_PO_HOST_CLEAR_UNIT,
	G_TYPE_PO_SVR_INFO_UDT,
	G_TYPE_PO_SVR_INFO_MGR,
	G_TYPE_PO_SCH,
	G_TYPE_PO_SCH_PKG,
	G_TYPE_PO_SCH_UNIT,
	G_TYPE_PO_SCH_INFO,
};

enum _ENUM_G_TYPE_POLICY_WMS
{
	G_TYPE_PO_POWER									= 0x0600,
	G_TYPE_PO_POWER_UNIT,
	G_TYPE_PO_CTL_PANEL,
	G_TYPE_PO_CTL_PANEL_UNIT,
	G_TYPE_PO_DEPLOY_FILE,
	G_TYPE_PO_DEPLOY_FILE_UNIT,
	G_TYPE_PO_DEPLOY_FILE_INFO_UNIT,
	G_TYPE_PO_DEPLOY_FILE_CHK_UNIT,
	G_TYPE_PO_DEPLOY_FILE_TAR_UNIT,
	G_TYPE_PO_DEPLOY_FILE_SCH_UNIT,
	G_TYPE_PO_WIN_RUN,
};

enum _ENUM_G_TYPE_POLICY_ACMS
{
	G_TYPE_PO_CTL_PROC								= 0x0700,
	G_TYPE_PO_CTL_PROC_UNIT,
	G_TYPE_PO_SELF_PROTECT,
	G_TYPE_PO_SELF_PROTECT_UNIT,
};

enum _ENUM_G_TYPE_POLICY_NIMS
{
	G_TYPE_PO_FA_CLEAR								= 0x0800,
	G_TYPE_PO_FA_CLEAR_UNIT,
	G_TYPE_PO_FA_PROC,
	G_TYPE_PO_FA_PROC_UNIT,
	G_TYPE_PO_FA_ENV,
	G_TYPE_PO_FA_ENV_UNIT,
	G_TYPE_PO_FA_OP,
	G_TYPE_PO_FA_OP_UNIT,
	G_TYPE_PO_FA_OP_SUB_UNIT,
	G_TYPE_PO_FA_OP_OBJ_UNIT,
	G_TYPE_PO_FA_OP_SCH_UNIT,
	G_TYPE_PO_FA_BK,
	G_TYPE_PO_FA_NOTIFY,
};

enum _ENUM_G_TYPE_POLICY_NCMS
{
	G_TYPE_PO_FE_PTN_OP								= 0x0900,
	G_TYPE_PO_FE_PTN_BL,
	G_TYPE_PO_FE_PTN_WL,
	G_TYPE_PO_FE_EXCLUDE,
	G_TYPE_PO_FE_EXCLUDE_UNIT,
	G_TYPE_PO_FE_NOTIFY,
	G_TYPE_PO_FE_SINGLE_PTN,
	G_TYPE_PO_FE_SINGLE_PTN_UNIT,
	G_TYPE_PO_FE_PTN_LO,
};

enum _ENUM_G_TYPE_ASMS
{
	G_TYPE_ASMS_SW									= 0x1000,
	G_TYPE_ASMS_HW,
	G_TYPE_ASMS_SYS,
	G_TYPE_ASMS_AGENTSTATUS,
};

enum _ENUM_G_TYPE_NOMS
{
	G_TYPE_PO_IN_PTN_OP								= 0x1100,
	G_TYPE_PO_IN_PTN_OP_UNIT,
	G_TYPE_PO_IN_PTN_BL,
	G_TYPE_PO_IN_PTN_BL_UNIT,
	G_TYPE_PO_IN_PTN_BL_FILE,
	G_TYPE_PO_IN_PTN_WL,
	G_TYPE_PO_IN_PTN_WL_UNIT,
	G_TYPE_PO_IN_PTN_WL_FILE,
	G_TYPE_PO_IN_PTN_EX,
	G_TYPE_PO_IN_PTN_EX_UNIT,
	G_TYPE_PO_IN_PTN_EX_TRUST,
	G_TYPE_PO_IN_PTN_SP,
	G_TYPE_PO_IN_PTN_SP_UNIT,
	G_TYPE_PO_IN_PTN_SP_RULE,
	G_TYPE_PO_IN_PTN_NO,

	G_TYPE_PO_IN_AC_DOC,
	G_TYPE_PO_IN_AC_DOC_UNIT,
	G_TYPE_PO_IN_AC_DOC_SUB_UNIT,
	G_TYPE_PO_IN_AC_DOC_OBJ_UNIT,	
	G_TYPE_PO_IN_AC_SF,
	G_TYPE_PO_IN_AC_SF_UNIT,
	G_TYPE_PO_IN_AC_SF_SUB_UNIT,
	G_TYPE_PO_IN_AC_SF_OBJ_UNIT,
	G_TYPE_PO_IN_AC_SF_SCH_UNIT,
	G_TYPE_PO_IN_AC_FILE,
	G_TYPE_PO_IN_AC_FILE_UNIT,
	G_TYPE_PO_IN_AC_FILE_SUB_UNIT,
	G_TYPE_PO_IN_AC_FILE_OBJ_UNIT,		
	G_TYPE_PO_IN_AC_FILE_SCH_UNIT,

	G_TYPE_PO_IN_VULN_OP,
	G_TYPE_PO_IN_VULN_OP_UNIT,
	G_TYPE_PO_IN_VULN_SCAN,
	G_TYPE_PO_IN_VULN_SCAN_UNIT,
};

enum _ENUM_G_TYPE_CONTROL
{
	G_TYPE_CTL_REMOTE								= 0x5000,
	G_TYPE_CTL_REMOTE_POWER,
	G_TYPE_CTL_INSTANT_MSG,
	G_TYPE_CTL_RESINFO,
	G_TYPE_CTL_RESTORE,
	G_TYPE_CTL_REMOTE_ORDER,
};

enum _ENUM_G_TYPE_PO_CODE_UPDATE
{
	G_CODE_PO_UPDATE_CHANGE_UP_INFO					= 0x0010
};

enum _ENUM_TYPE_HOST_RESINFO
{
	HOST_RESINFO_PROCESS		= 0x01,
	HOST_RESINFO_NETSTAT		= 0x02,
	HOST_RESINFO_SERVICE		= 0x04,
	HOST_RESINFO_ACTIVEX		= 0x08,
	HOST_RESINFO_DEVICE			= 0x10,
};

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include "pktdef_agt.h"
#include "pktdef_lcn.h"
#include "pktdef_link.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

#endif //PKTDEF_H_938EF200_F60B_452A_BD30_A10E8507EDCC


