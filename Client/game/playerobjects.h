#pragma once

#include "game.h"
#include "physical.h"
#include "aimstuff.h"

//-----------------------------------------------------------

class CPlayerObjects
{
private:
	DWORD		m_dwGTAId;

public:
	// Constructor/Destructor.	
	CPlayerObjects();
	CPlayerObjects(int iModel, float fX, float fY,float fZ);
	//~CPlayerObjects();

	void Create(int iModel, float fX, float fY, float fZ);
	void Delete();
	void SetObjectTargetable( );
	int HasObjectBeenDamaged( );
};

//-----------------------------------------------------------
