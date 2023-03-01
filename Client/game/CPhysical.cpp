#include "StdInc.h"

//----------------------------------------------------------

PHYSICAL_TYPE * CPhysical::GetPhysical()
{
	return (PHYSICAL_TYPE *)GetEntity();
}

//----------------------------------------------------------

void CPhysical::GetMoveSpeed(Vector3 * vecMoveSpeed)
{
	PHYSICAL_TYPE * pPhysical = (PHYSICAL_TYPE *)GetEntity();

	if(pPhysical)
	{
		memcpy(vecMoveSpeed, &pPhysical->vecMoveSpeed, sizeof(Vector3));
	}
}

//-----------------------------------------------------------

void CPhysical::SetMoveSpeed(Vector3 vecMoveSpeed)
{
	PHYSICAL_TYPE * pPhysical = (PHYSICAL_TYPE *)GetEntity();

	if(pPhysical)
	{
		memcpy(&pPhysical->vecMoveSpeed, &vecMoveSpeed, sizeof(Vector3));
	}
}

//-----------------------------------------------------------

void CPhysical::GetTurnSpeed(Vector3 * vecTurnSpeed)
{
	PHYSICAL_TYPE * pPhysical = (PHYSICAL_TYPE *)GetEntity();

	if(pPhysical)
	{
		memcpy(vecTurnSpeed, &pPhysical->vecTurnSpeed, sizeof(Vector3));
	}
}

//-----------------------------------------------------------

void CPhysical::SetTurnSpeed(Vector3 vecTurnSpeed)
{
	PHYSICAL_TYPE * pPhysical = (PHYSICAL_TYPE *)GetEntity();

	if(pPhysical)
	{
		memcpy(&pPhysical->vecTurnSpeed, &vecTurnSpeed, sizeof(Vector3));
	}
}

//-----------------------------------------------------------
