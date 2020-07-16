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

#ifndef LogicMgrSiteFileH
#define LogicMgrSiteFileH
//---------------------------------------------------------------------------

class CLogicMgrSiteFile	: public CLogicBase
{
private:
	INT32		AnalyzePkt_FromMgr_Ext();
	INT32		AnalyzePkt_FromMgr_Add_Ext();
	INT32		AnalyzePkt_FromMgr_Edit_Ext();
	INT32		AnalyzePkt_FromMgr_Del_Ext();

	INT32		AnalyzePkt_FromMgr_Ext_Sync();

public:
	void		CheckSiteFile(PDB_SITE_FILE pdsf_src);
	void		SetSiteFile(DB_SITE_FILE& dsf);
	void		SendPkt_Sync(INT32 nOnceMaxNum = 1000);
	void		SendPkt_ReSend(INT32 nOnceMaxNum = 1000);

public:
	CLogicMgrSiteFile();
    ~CLogicMgrSiteFile();
};

extern CLogicMgrSiteFile*		t_LogicMgrSiteFile;

#endif
