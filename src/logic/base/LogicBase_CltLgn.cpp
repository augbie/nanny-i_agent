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
#include "LogicBase.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void	CLogicBase::SendData_Lgn(PPKT_DATA pkt_data, MemToken& SendToken)
{
	SendData_Lgn(pkt_data->hdr.type, pkt_data->hdr.code, SendToken);
    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::SendData_Lgn(UINT16 nType, UINT16 nCode, MemToken& SendToken)
{
	t_LgnCltUtil->Send_CLD(nType, nCode, SendToken.GetLength(), SendToken.GetData());

    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::EditSKey_Lgn(UINT32 nSessionKey)
{
	t_LgnCltUtil->EditSessionKey_CLD(nSessionKey);

    return;
}
//---------------------------------------------------------------------------

void	CLogicBase::Disconnected_Lgn()
{
	t_LgnCltUtil->CloseSocket_CLD(0);
	return;
}
//---------------------------------------------------------------------------

String	CLogicBase::GetConnectAddr_Lgn()
{
	char pszAddr[CHAR_MAX_SIZE] = {0, };
	UINT32 nAddr = GetConnectIP_Lgn();

    return ConvertIP(nAddr);
}
//---------------------------------------------------------------------------

UINT32	CLogicBase::GetConnectIP_Lgn()
{
	UINT32 nAddr = 0;
	t_LgnCltUtil->GetLocalAddress_CLD(nAddr);

    return nAddr;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



