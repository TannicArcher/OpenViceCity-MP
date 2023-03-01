#pragma once

#include "CGame.h"
#include "CPhysical.h"

//-----------------------------------------------------------

class CObject : public CPhysical
{
private:
	DWORD		m_dwGTAId;

public:
	// Constructor/Destructor.	
	CObject(int iModel, Vector3 * vecPos, Vector3 * vecRot);
	~CObject();

	void SetObjectTargetable( );
	int HasObjectBeenDamaged( );
};

//-----------------------------------------------------------
