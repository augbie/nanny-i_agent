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
#include "ManageSiteVuln.h"

//---------------------------------------------------------------------------

CManageSiteVuln*	t_ManageSiteVuln = NULL;

//---------------------------------------------------------------------------

CManageSiteVuln::CManageSiteVuln()
{
	t_DBMgrSiteVuln	= new CDBMgrSiteVuln();
}
//---------------------------------------------------------------------------

CManageSiteVuln::~CManageSiteVuln()
{
	if(t_DBMgrSiteVuln)	{	delete t_DBMgrSiteVuln;	t_DBMgrSiteVuln = NULL;	}
}
//---------------------------------------------------------------------------

INT32		CManageSiteVuln::LoadDBMS()
{
	TListDBSiteVuln tDBSiteVulnList;
    TListDBSiteVulnItor begin, end;
	if(SetER(t_DBMgrSiteVuln->LoadExecute(&tDBSiteVulnList)))
    {
    	return g_nErrRtn;
    }

    begin = tDBSiteVulnList.begin();	end = tDBSiteVulnList.end();
    for(begin; begin != end; begin++)
    {
    	AddItem(begin->nID, *begin);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::InitHash()
{
	TListID tIDList;
	TListIDItor begin, end;

	String strOrgValue;
	
	GetItemIDList(tIDList);
	begin = tIDList.begin();		end = tIDList.end();
	for(begin; begin != end; begin++)
	{
		String strValue;
		GetHashData(*begin, strValue);

		strOrgValue += strValue;
	}	

	{
		char pszHashValue[CHAR_MAX_SIZE] = {0, };
		SHAString(ASIHASH_SHA_LEN_TYPE_128, strOrgValue.c_str(), strOrgValue.length(), pszHashValue, CHAR_MAX_SIZE);
		m_strFullHash = pszHashValue;
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::GetHashData(UINT32 nID, String& strOrgValue)
{
	PDB_SITE_VULN pdata 			= NULL;
	{
		if( (pdata = FindItem(nID)) == NULL)
		{
			WriteLogE("not find site_vuln by hash : [%d]", ERR_INFO_NOT_OP_BECAUSE_NOT_FIND);
			return ERR_INFO_NOT_OP_BECAUSE_NOT_FIND;
		}
	}

	{
		strOrgValue = SPrintf("%u,%u,%u,%u,%u,%u,"
							"%s,%s,"
							"%u,%I64u,%u,"
							"%u,%u,", 
							pdata->nID, pdata->nUsedFlag, pdata->nRegDate, pdata->nUsedMode, pdata->nAdminID, pdata->nExtOption,
							pdata->strName.c_str(), pdata->strDescr.c_str(), 
							pdata->nOsType, pdata->nOsID, pdata->nOsPa, 
							pdata->nRiskLevel, pdata->nDefScore);	
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::AddSiteVuln(DB_SITE_VULN&	data)
{
	if(SetER(t_DBMgrSiteVuln->InsertExecute(&data)))
    {
    	return g_nErrRtn;
    }

    AddItem(data.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::EditSiteVuln(DB_SITE_VULN&	data)
{
	PDB_SITE_VULN pdata = FindItem(data.nID);
	if(!pdata)	return ERR_DBMS_UPDATE_FAIL;

	if(SetER(t_DBMgrSiteVuln->UpdateExecute(&data)))
    {
    	return g_nErrRtn;
    }

    EditItem(data.nID, data);

    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::DelSiteVuln(UINT32 nID)
{
	PDB_SITE_VULN pdata = FindItem(nID);
	if(!pdata)	return ERR_DBMS_DELETE_FAIL;

	if(SetER(t_DBMgrSiteVuln->DeleteExecute(pdata->nID)))
    {
    	return g_nErrRtn;
    }

    DeleteItem(nID);
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::ApplySiteVuln(DB_SITE_VULN&	data)
{
	if(FindItem(data.nID))
	{
		return EditSiteVuln(data);
	}
	return AddSiteVuln(data);
}
//---------------------------------------------------------------------------

String					CManageSiteVuln::GetName(UINT32 nID)
{
	PDB_SITE_VULN pdata = FindItem(nID);
    if(!pdata)	return "";
    return pdata->strName;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::SetPkt(MemToken& SendToken)
{
    SendToken.TokenAdd_32(m_tMap.size());

	TMapDBSiteVulnItor begin, end;
    begin = m_tMap.begin();	end = m_tMap.end();
    for(begin; begin != end; begin++)
    {
    	SetPkt(&(begin->second), SendToken);
    }
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::SetPkt(UINT32 nID, MemToken& SendToken)
{
	PDB_SITE_VULN pdata = FindItem(nID);
	if(!pdata)	return -1;

	SetPkt(pdata, SendToken);
	
	return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::SetPkt(PDB_SITE_VULN pdata, MemToken& SendToken)
{
	SendToken.TokenAdd_32(pdata->nID);
	SendToken.TokenAdd_32(pdata->nUsedFlag);
	SendToken.TokenAdd_32(pdata->nRegDate);
	SendToken.TokenAdd_32(pdata->nUsedMode);
	SendToken.TokenAdd_32(pdata->nAdminID);
	SendToken.TokenAdd_32(pdata->nExtOption);

	SendToken.TokenAdd_String(pdata->strName);
	SendToken.TokenAdd_String(pdata->strDescr);

	SendToken.TokenAdd_32(pdata->nOsType);
	SendToken.TokenAdd_64(pdata->nOsID);
	SendToken.TokenAdd_32(pdata->nOsPa);

	SendToken.TokenAdd_32(pdata->nRiskLevel);
	SendToken.TokenAdd_32(pdata->nDefScore);

	SendToken.TokenSet_Block();
    return 0;
}
//---------------------------------------------------------------------------

INT32					CManageSiteVuln::GetPkt(MemToken& RecvToken, DB_SITE_VULN& data)
{
	if (!RecvToken.TokenDel_32(data.nID))					goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nUsedFlag))				goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nRegDate))				goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nUsedMode))				goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nAdminID))				goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nExtOption))			goto INVALID_PKT;

	if ( RecvToken.TokenDel_String(data.strName) < 0)		goto INVALID_PKT;
	if ( RecvToken.TokenDel_String(data.strDescr) < 0)		goto INVALID_PKT;

	if (!RecvToken.TokenDel_32(data.nOsType))				goto INVALID_PKT;
	if (!RecvToken.TokenDel_64(data.nOsID))					goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nOsPa))					goto INVALID_PKT;

	if (!RecvToken.TokenDel_32(data.nRiskLevel))			goto INVALID_PKT;
	if (!RecvToken.TokenDel_32(data.nDefScore))				goto INVALID_PKT;

	RecvToken.TokenSkip_Block();

	return 0;
INVALID_PKT:
	return -1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



