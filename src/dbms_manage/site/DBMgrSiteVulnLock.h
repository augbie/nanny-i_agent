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

#ifndef DBMgrSiteVulnLockH
#define DBMgrSiteVulnLockH
//---------------------------------------------------------------------------

class CDBMgrSiteVulnLock : public CDBMgrBase
{
public:
	INT32			SetInitalize();

public:
	INT32			LoadDB(TListDBSiteVulnLock& tDBSiteVulnLockList);

public:
    INT32			InsertSiteVulnLock(DB_SITE_VULN_LOCK& data);
    INT32			UpdateSiteVulnLock(DB_SITE_VULN_LOCK& data);
    INT32			DeleteSiteVulnLock(UINT32 nID);

public:
	virtual INT32	LoadExecute(PVOID lpTempletList);
	virtual INT32	InsertExecute(PVOID lpTemplet);
	virtual INT32	UpdateExecute(PVOID lpTemplet);
	virtual INT32	DeleteExecute(UINT32 nID);


public:
	CDBMgrSiteVulnLock();
    ~CDBMgrSiteVulnLock();
};

extern CDBMgrSiteVulnLock*		t_DBMgrSiteVulnLock;

#endif
