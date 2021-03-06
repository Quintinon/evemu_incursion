/*
	------------------------------------------------------------------------------------
	LICENSE:
	------------------------------------------------------------------------------------
	This file is part of EVEmu: EVE Online Server Emulator
	Copyright 2006 - 2011 The EVEmu Team
	For the latest information visit http://evemu.org
	------------------------------------------------------------------------------------
	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
	------------------------------------------------------------------------------------
	Author:		Zhur
*/

#ifndef __CERTIFICATE_MGR_SERVICE__H__INCL__
#define __CERTIFICATE_MGR_SERVICE__H__INCL__

#include "character/CertificateMgrDB.h"
#include "PyService.h"

class CertificateMgrService
: public PyService
{
public:
	CertificateMgrService(PyServiceMgr *mgr);
	~CertificateMgrService();

protected:
	class Dispatcher;
	Dispatcher *const m_dispatch;

	CertificateMgrDB m_db;

	PyCallable_DECL_CALL(GetMyCertificates)
	PyCallable_DECL_CALL(GetCertificateCategories)
	PyCallable_DECL_CALL(GetAllShipCertificateRecommendations)
	PyCallable_DECL_CALL(GetCertificateClasses)
	PyCallable_DECL_CALL(GrantCertificate)
	PyCallable_DECL_CALL(BatchCertificateGrant)
	PyCallable_DECL_CALL(BatchCertificateUpdate)
	PyCallable_DECL_CALL(GetCertificatesByCharacter)

	bool _GrantCertificate(uint32 characterID, uint32 certificateID);
	bool _UpdateCertificate(uint32 characterID, uint32 certificateID, bool pub);
};

#endif /* __CERTIFICATE_MGR_SERVICE__H__INCL__ */




