#pragma once

#include "common.h"
#include "CEntity.h"

class CPhysical : public CEntity
{
public:
	PHYSICAL_TYPE * GetPhysical();

	void GetMoveSpeed(Vector3 * vecMoveSpeed);
	void SetMoveSpeed(Vector3 vecMoveSpeed);
	void GetTurnSpeed(Vector3 * vecMoveSpeed);
	void SetTurnSpeed(Vector3 vecMoveSpeed);
};