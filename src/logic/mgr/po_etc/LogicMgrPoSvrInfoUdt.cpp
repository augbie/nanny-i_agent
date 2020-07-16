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
#include "LogicMgrPoSvrInfoUdt.h"

//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoUdt*		t_LogicMgrPoSvrInfoUdt = NULL;

//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoUdt::CLogicMgrPoSvrInfoUdt()
{
	t_ManagePoSvrInfoUdt		= new CManagePoSvrInfoUdt();	
	t_ManagePoSvrInfoUdt->LoadDBMS();
	
	t_ManagePoSvrInfoUdt->InitHash();

	m_strLogicName		= "mgr agt po svr info udt";
	
	m_nPolicyType		= SS_POLICY_TYPE_SVR_INFO_UDT;
	m_nSSPoSeqIdx		= SS_POLICY_INDEX_SVR_INFO_UDT;
	m_nAgtPktEditCode	= G_CODE_COMMON_EDIT;

	m_nEvtObjType		= EVENT_OBJECT_TYPE_POLICY;
	m_nEvtObjCode		= EVENT_OBJECT_CODE_POLICY_SVR_INFO_UDT;
}
//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoUdt::~CLogicMgrPoSvrInfoUdt()
{
	SAFE_DELETE(t_ManagePoSvrInfoUdt);
}
//---------------------------------------------------------------------------
INT32		CLogicMgrPoSvrInfoUdt::AnalyzePkt_FromMgr_Ext()
{
	return SetHdrAndRtn(AZPKT_CB_RTN_SUCCESS);
}
//---------------------------------------------------------------------------

INT32		CLogicMgrPoSvrInfoUdt::AnalyzePkt_FromMgr_Edit_Ext()
{
	//PDB_PO_SVR_INFO_UDT pdpsiu = NULL;
	DB_PO_SVR_INFO_UDT dpsiu;

	m_tDPH = &(dpsiu.tDPH);
	
	if( t_ManagePoSvrInfoUdt->GetPkt(RecvToken, dpsiu))	
		return SetHdrAndRtn(AZPKT_CB_RTN_PKT_INVALID);	

	//pdpsiu = (PDB_PO_SVR_INFO_UDT)t_DeployPolicyUtil->GetCurPoPtr(m_nPolicyType);	
	{
		if(SetER(t_ManagePoSvrInfoUdt->ApplyPoSvrInfoUdt(dpsiu)))
		{
			SetDLEA_EC(g_nErrRtn);
			WriteLogE("[%s] apply policy information : [%d]", m_strLogicName.c_str(), g_nErrRtn);
			return SetHdrAndRtn(AZPKT_CB_RTN_DBMS_FAIL);
		}

		//m_strEvtDesc = SPrintf("%s,%s", dpsiu.strChkSvrInfoList, dpsiu.strDataSvrInfoList);
	}

	return SetHdrAndRtn(AZPKT_CB_RTN_SUCCESS);
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
