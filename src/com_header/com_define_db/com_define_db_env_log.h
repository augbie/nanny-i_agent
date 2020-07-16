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


#ifndef COM_DEFINE_DB_ENV_LOG_H_938EF200_F60B_452A_BD30_A10E8507EDCC
#define COM_DEFINE_DB_ENV_LOG_H_938EF200_F60B_452A_BD30_A10E8507EDCC

//-------------------------------------------------------------------
//option ext

//-------------------------------------------------------------------
//record mode
#define SS_ENV_LOG_RECORD_FLAG_MONITOR				0x00000001 // 
#define SS_ENV_LOG_RECORD_FLAG_DBMS					0x00000002 // 
#define SS_ENV_LOG_RECORD_FLAG_SMS					0x00000004 //
//-------------------------------------------------------------------

#define SS_ENV_LOG_TYPE_ALL							0x00000000
#define SS_ENV_LOG_TYPE_EVENT						0x00000001
#define SS_ENV_LOG_TYPE_DOC							0x00000002
#define SS_ENV_LOG_TYPE_SECU						0x00000004
#define SS_ENV_LOG_TYPE_DEPLOY_FILE					0x00000008
#define SS_ENV_LOG_TYPE_STATUS						0x00000010
//-------------------------------------------------------------------

#define SS_ENV_LOG_OPTION_FLAGE_SKIP_SAVE_AGENT				0x00000001
#define SS_ENV_LOG_OPTION_FLAGE_SKIP_SAVE_SERVER			0x00000002
#define SS_ENV_LOG_OPTION_FLAGE_SKIP_SAVE_SERVER_SELF_LOG	0x00000004
//-------------------------------------------------------------------

enum _ENUM_SS_ENV_LOG_INDEX
{
	SS_ENV_LOG_INDEX_EVENT = 0,
	SS_ENV_LOG_INDEX_DOC,
	SS_ENV_LOG_INDEX_SECU,
	SS_ENV_LOG_INDEX_DEPLOY_FILE,
	SS_ENV_LOG_INDEX_DOC_DSCAN,
	SS_ENV_LOG_INDEX_STATUS,
	SS_ENV_LOG_INDEX_TOTAL_NUMBER,
};
//-------------------------------------------------------------------

#define SS_ENV_LOG_LOAD_MODE_TYPE_DAY				0
#define SS_ENV_LOG_LOAD_MODE_TYPE_COUNT				1
//-------------------------------------------------------------------


#endif	//COM_DEFINE_DB_ENV_LOG_H_938EF200_F60B_452A_BD30_A10E8507EDCC