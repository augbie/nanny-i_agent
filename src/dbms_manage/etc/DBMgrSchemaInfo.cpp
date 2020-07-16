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

//---------------------------------------------------------------------------
#include "stdafx.h"
#include "com_struct.h"
#include "DBMgrSchemaInfo.h"

//---------------------------------------------------------------------------

//CDBMgrSchemaInfo*		t_DBMgrSchemaInfo;

//---------------------------------------------------------------------------

CDBMgrSchemaInfo::CDBMgrSchemaInfo()
{
	m_strDBTName = "schema_info";
	//SetInitalize();
}
//---------------------------------------------------------------------------

CDBMgrSchemaInfo::~CDBMgrSchemaInfo()
{
}
//---------------------------------------------------------------------------

INT32			CDBMgrSchemaInfo::SetInitalize()
{
    return 0;
}
//---------------------------------------------------------------------------

INT32			CDBMgrSchemaInfo::GetDBVer()
{
    INT32 nIndex = 0;
	INT32 nVer = 0;

    m_strQuery = SPrintf("SELECT db_ver FROM schema_info;") ;
    if(DBOP_Check(ExecuteQuery(m_strQuery)))
		return 0;

    do
    {    	
    	nIndex = 0;

        nVer					= GetDBField_UInt(nIndex++);
    }while(Next());
    return nVer;
}
//---------------------------------------------------------------------------

INT32			CDBMgrSchemaInfo::UpdateDatabase(TListStr& tQueryList)
{
	TListStrItor begin, end;
	begin = tQueryList.begin();	end = tQueryList.end();
	for(begin; begin != end; begin++)
	{
		if(DBOP_Check(ExecuteQuery(*begin)))
		{
			return ERR_DBMS_INSERT_FAIL;
		}
	}
	return 0;
}
//---------------------------------------------------------------------------   
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------