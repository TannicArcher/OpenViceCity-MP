#pragma once

class CPickup
{
private:
	DWORD		m_dwGTAId;

public:
	CPickup(int iModel, int iType, Vector3 * vecPos);
	~CPickup();
};