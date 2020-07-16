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

#ifndef DB_PO_SELF_PROTECT_UNIT_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467
#define DB_PO_SELF_PROTECT_UNIT_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467

typedef struct _db_po_self_protect_unit
{
	_db_po_self_protect_unit()
	{
		nProtectType	= 0;
	}

	DB_PO_HEADER		tDPH;

	UINT32				nProtectType;
	String				strProtectInfo;

}DB_PO_SELF_PROTECT_UNIT, *PDB_PO_SELF_PROTECT_UNIT;

typedef list<DB_PO_SELF_PROTECT_UNIT>			TListDBPoSelfProtectUnit;
typedef TListDBPoSelfProtectUnit::iterator		TListDBPoSelfProtectUnitItor;

typedef map<UINT32, DB_PO_SELF_PROTECT_UNIT>	TMapDBPoSelfProtectUnit;
typedef TMapDBPoSelfProtectUnit::iterator		TMapDBPoSelfProtectUnitItor;

#endif //DB_PO_SELF_PROTECT_H_4D39CDDB_PO_E289_4d56_9F98_FE42776F4467



