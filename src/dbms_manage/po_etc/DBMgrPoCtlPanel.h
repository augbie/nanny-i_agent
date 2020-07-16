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

#ifndef DBMgrPoCtlPanelH
#define DBMgrPoCtlPanelH
//---------------------------------------------------------------------------

class CDBMgrPoCtlPanel : public CDBMgrBase
{
public:
	INT32			SetInitalize();

public:
	INT32			LoadDB(TListDBPoCtlPanel& tDBPoCtlPanelList);

public:
    INT32			InsertPoCtlPanel(DB_PO_CTL_PANEL& dpcp);
    INT32			UpdatePoCtlPanel(DB_PO_CTL_PANEL& dpcp);
    INT32			DeletePoCtlPanel(UINT32 nID);    

public:
	virtual INT32	LoadExecute(PVOID lpTempletList);     
	virtual INT32	InsertExecute(PVOID lpTemplet);
	virtual INT32	UpdateExecute(PVOID lpTemplet);
	virtual INT32	DeleteExecute(UINT32 nID);


public:
	CDBMgrPoCtlPanel();
    ~CDBMgrPoCtlPanel();
};

extern CDBMgrPoCtlPanel*		t_DBMgrPoCtlPanel;

#endif
