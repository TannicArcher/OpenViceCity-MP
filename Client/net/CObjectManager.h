#pragma once

#define MAX_OBJECTS 100

class CObjectManager
{
public:
	CObjectManager();
	~CObjectManager();

	BOOL New(EntityId ObjectID, int iModel, Vector3 vecPos, Vector3 vecRot);
	BOOL Delete(EntityId ObjectID);
private:
	BOOL m_bObjectSlotState[MAX_OBJECTS];
	CObject * m_pObjects[MAX_OBJECTS];
};