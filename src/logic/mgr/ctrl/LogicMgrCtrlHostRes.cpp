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
#include "LogicMgrCtrlHostRes.h"

//---------------------------------------------------------------------------

CLogicMgrCtrlHostRes*		t_LogicMgrCtrlHostRes = NULL;

//---------------------------------------------------------------------------

CLogicMgrCtrlHostRes::CLogicMgrCtrlHostRes()
{
	m_strLogicName = "logic mgr ctrl hostres";
	
	m_nControlType	= SS_CONTROL_TYPE_ASMS_HOSTSTATUS;	
	m_nEvtObjType	= EVENT_OBJECT_TYPE_HOST;
	m_nEvtObjCode	= 0;
}
//---------------------------------------------------------------------------

CLogicMgrCtrlHostRes::~CLogicMgrCtrlHostRes()
{
	SAFE_DELETE(t_ManageHost)
	SAFE_DELETE(t_ManageHostSys);
}
//---------------------------------------------------------------------------

INT32		CLogicMgrCtrlHostRes::AnalyzePkt_FromMgr_Ext()
{
	UINT32 nRtn = AZPKT_CB_RTN_SUCCESS;
	switch(m_nPktCode)
	{
		case G_CODE_HOST_RESINFO:			nRtn = AnalyzePkt_FromMgr_Ext_HostResInfo();	break;
		default:
		{	
			nRtn = AZPKT_CB_RTN_PKT_NOT_DEFINE_CODE;
			break;
		}
	}

	return SetHdrAndRtn(nRtn);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
INT32		CLogicMgrCtrlHostRes::AnalyzePkt_FromMgr_Ext_HostResInfo()
{

	INT32 nConSessionID = 0, nResType = 0, nCnt = 0;

	SendToken.Clear();
	if( RecvToken.TokenDel_32(nConSessionID) < 0)		return AZPKT_CB_RTN_PKT_INVALID;
	if( RecvToken.TokenDel_32(m_nHostID) < 0)		return AZPKT_CB_RTN_PKT_INVALID;
	if( RecvToken.TokenDel_32(nResType) < 0)		return AZPKT_CB_RTN_PKT_INVALID;
	SendToken.TokenAdd_32(nConSessionID);
	SendToken.TokenAdd_32(m_nHostID);
	SendToken.TokenAdd_32(nResType);

	TListResInfoProcInfo tProcList;
	if(nResType & HOST_RESINFO_PROCESS)
	{
		t_ProcInfoDLLUtil->GetProcessInfo(tProcList);
		SendToken.TokenAdd_32(tProcList.size());
		if(tProcList.size() > 0)
		{
			TListResInfoProcInfoItor begin, end;
			begin = tProcList.begin();	end = tProcList.end();
			for(begin; begin != end; begin++)
			{
				SendToken.TokenAdd_String(begin->pbi.szProcessName);
				SendToken.TokenAdd_String(begin->pbi.szProcessFullName);
				SendToken.TokenAdd_32(begin->pbi.nPID);
				SendToken.TokenAdd_32(begin->pbi.nPPID);
				SendToken.TokenAdd_32(begin->pbi.nBasePri);
				SendToken.TokenAdd_32(begin->psi.nThreadCount);
				SendToken.TokenAdd_32(begin->psi.nHandleCount);
				SendToken.TokenAdd_32(begin->psi.nCpuValue);
				SendToken.TokenAdd_32(begin->psi.nMemValue);
				SendToken.TokenAdd_String(begin->pti.szStartTime);
				SendToken.TokenAdd_String(begin->pti.szCPUTime);
				SendToken.TokenAdd_String(begin->pai.szUserName);
				SendToken.TokenAdd_String(begin->pai.szFileVersion);
				SendToken.TokenAdd_String(begin->pai.szProductName);
				SendToken.TokenAdd_String(begin->pai.szCompanyName);

				SendToken.TokenSet_Block();    
			}
		}
	}

	TListResInfoNetStat tNetList;
	if(nResType & HOST_RESINFO_NETSTAT)
	{
		t_ProcInfoDLLUtil->GetNetWorkInfo(tNetList);
		SendToken.TokenAdd_32(tNetList.size());
		if(tNetList.size() > 0)
		{
			TListResInfoNetStatItor begin, end;
			begin = tNetList.begin();	end = tNetList.end();
			for(begin; begin != end; begin++)
			{
				SendToken.TokenAdd_32(begin->nProtocol);
				SendToken.TokenAdd_32(begin->nStatus);
				SendToken.TokenAdd_String(begin->szLocalAddr);
				SendToken.TokenAdd_32(begin->nLocalPort);
				SendToken.TokenAdd_String(begin->szRemoteAddr);
				SendToken.TokenAdd_32(begin->nRemotePort);

				SendToken.TokenSet_Block();    
			}
		}
	}

	TListDeviceInfo tDviList;
	if(nResType & HOST_RESINFO_DEVICE)
	{
		t_DevInfoDLLUtil->GetDeviceInfo(tDviList);
		SendToken.TokenAdd_32(tDviList.size());
		if(tDviList.size() > 0)
		{
			TListDeviceInfoItor begin, end;
			begin = tDviList.begin();	end = tDviList.end();
			for(begin; begin != end; begin++)
			{
				SendToken.TokenAdd_String(begin->strClassName);
				SendToken.TokenAdd_String(begin->strDeviceName);
				SendToken.TokenAdd_String(begin->strGUID);
				SendToken.TokenAdd_String(begin->strDeviceInstanceID);
				SendToken.TokenAdd_String(begin->strPaDeviceInstanceID);
				SendToken.TokenAdd_32(begin->nUsed);
				SendToken.TokenAdd_32(begin->nIconIndex);

				SendToken.TokenSet_Block();    
			}
		}
	}

	SendData(G_TYPE_CTL_RESINFO, m_nPktCode, SendToken);
	SendToken.Clear();
	m_nHostID = 0;

	return AZPKT_CB_RTN_SUCCESS_END;
}
//---------------------------------------------------------------------------
