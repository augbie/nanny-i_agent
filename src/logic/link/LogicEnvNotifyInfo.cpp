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
#include "LogicEnvNotifyInfo.h"

//---------------------------------------------------------------------------

CLogicEnvNotifyInfo*		t_LogicEnvNotifyInfo = NULL;

//---------------------------------------------------------------------------

CLogicEnvNotifyInfo::CLogicEnvNotifyInfo()
{	
	m_strLogicName		= "link env notify info";
		
	m_nEvtObjType		= 0;
	m_nEvtObjCode		= 0;
}
//---------------------------------------------------------------------------

CLogicEnvNotifyInfo::~CLogicEnvNotifyInfo()
{

}
//---------------------------------------------------------------------------

INT32	CLogicEnvNotifyInfo::AnalyzePkt_FromLink_Ext()
{
	switch(m_nPktCode)
	{
		case G_CODE_COMMON_INFO:		AnalyzePkt_FromLink_Ext_Notify_Sch_info();		break;
		default:						break;
	}
	return 0;
}
//---------------------------------------------------------------------------

INT32	CLogicEnvNotifyInfo::AnalyzePkt_FromLink_Ext_Notify_Sch_info()
{
	if( !RecvToken.TokenDel_32(m_nPktRst))		goto INVALID_PKT;

	// 알림 정책 확장시 사용예정.
	return 0;

INVALID_PKT:
	WriteLogE("[%s] recv invalid pkt from link : [%s][%x]:[%x]", m_strLogicName.c_str(), Int64ToHex(m_nPktType).c_str(), m_nPktCode, m_nDbgPos);
	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void		CLogicEnvNotifyInfo::SendPkt_Notify_Sch_info(MEM_ENV_NOTIFY_INFO_SCH& menis)
{
	SendToken.TokenAdd_DPH(menis.tDPH);

	SendToken.TokenAdd_32(menis.nNotifyType);
	SendToken.TokenAdd_32(menis.nPolType);
	SendToken.TokenAdd_32(menis.nOpType);
	SendToken.TokenAdd_32(menis.nSchType);
	SendToken.TokenAdd_32(menis.nSchTime);
	SendData_Link(G_TYPE_ENV_NOTIFY_INFO, G_CODE_COMMON_INFO, SendToken);
	SendToken.Clear();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
