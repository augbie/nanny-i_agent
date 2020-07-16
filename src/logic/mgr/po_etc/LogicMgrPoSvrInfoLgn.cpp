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
#include "LogicMgrPoSvrInfoLgn.h"

//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoLgn*		t_LogicMgrPoSvrInfoLgn = NULL;

//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoLgn::CLogicMgrPoSvrInfoLgn()
{
	t_ManagePoSvrInfoLgn		= new CManagePoSvrInfoLgn();	
	t_ManagePoSvrInfoLgn->LoadDBMS();
	
	t_ManagePoSvrInfoLgn->InitHash();

	m_strLogicName		= "mgr agt po svr info lgn";
	
	m_nPolicyType		= SS_POLICY_TYPE_SVR_INFO_LGN;
	m_nSSPoSeqIdx		= SS_POLICY_INDEX_SVR_INFO_LGN;
	m_nAgtPktEditCode	= G_CODE_COMMON_EDIT;

	m_nEvtObjType		= EVENT_OBJECT_TYPE_POLICY;
	m_nEvtObjCode		= EVENT_OBJECT_CODE_POLICY_SVR_INFO_LGN;
}
//---------------------------------------------------------------------------

CLogicMgrPoSvrInfoLgn::~CLogicMgrPoSvrInfoLgn()
{
	SAFE_DELETE(t_ManagePoSvrInfoLgn);
}
//---------------------------------------------------------------------------

INT32		CLogicMgrPoSvrInfoLgn::AnalyzePkt_FromMgr_Ext()
{
	return SetHdrAndRtn(AZPKT_CB_RTN_SUCCESS);
}
//---------------------------------------------------------------------------

INT32		CLogicMgrPoSvrInfoLgn::AnalyzePkt_FromMgr_Edit_Ext()
{
	PDB_PO_SVR_INFO_LGN pdpsil = NULL;
	DB_PO_SVR_INFO_LGN dpsil;
	INT32 nDisconMode = 0;

	m_tDPH = &(dpsil.tDPH);
	
	if( t_ManagePoSvrInfoLgn->GetPkt(RecvToken, dpsil))			return SetHdrAndRtn(AZPKT_CB_RTN_PKT_INVALID);	
	pdpsil = (PDB_PO_SVR_INFO_LGN)t_DeployPolicyUtil->GetCurPoPtr(m_nPolicyType);
	if(pdpsil)
	{	
		if(_stricmp(pdpsil->strSvrInfoList.c_str(), dpsil.strSvrInfoList.c_str()))
		{
			nDisconMode = 1;
		}

		if(pdpsil->tDPH.nID != dpsil.tDPH.nID)
		{
			t_ManagePoSvrInfoLgn->DelPoSvrInfoLgn(pdpsil->tDPH.nID);
		}
	}
	
	{
		if(SetER(t_ManagePoSvrInfoLgn->ApplyPoSvrInfoLgn(dpsil)))
		{
			SetDLEA_EC(g_nErrRtn);
			WriteLogE("[%s] apply policy information : [%d]", m_strLogicName.c_str(), g_nErrRtn);
			return SetHdrAndRtn(AZPKT_CB_RTN_DBMS_FAIL);
		}	
	}
	{
		if(nDisconMode)	Disconnected_Mgr();
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
