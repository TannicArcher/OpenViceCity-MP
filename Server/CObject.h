#pragma once

class CObject 
{
private:
	EntityId m_ObjectID;
	int m_iModel;
	BOOL m_bIsActive;

	Vector3 m_vecPos;
	Vector3 m_vecRot;
public:
	CObject(int iModel, Vector3 * vecPos, Vector3 * vecRot);
	~CObject();

	void SetID(EntityId objectID) { m_ObjectID = objectID; };
	BOOL IsActive() { return m_bIsActive; };
	
	void SpawnForPlayer(EntityId forPlayerID);
	void DestroyForPlayer(EntityId forPlayerID);
	void SpawnForWorld();
};