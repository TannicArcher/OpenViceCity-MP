#include "main.h"

#define MAX_SPAWNS 100

//----------------------------------------------------

class CSpawnSelection
{
private:
	PLAYER_SPAWN_INFO	m_AvailableSpawns[MAX_SPAWNS];
	int					m_iAvailableSpawnCount;
public:

	int AddPlayerClass(int team, int model, float x, float y, float z, float rot, int weapon1, int ammo1, int weapon2, int ammo2, int weapon3, int ammo3);
	int HandleSpawnClassRequest(EntityId playerID, int iSpawnType);
	
	CSpawnSelection();
	~CSpawnSelection();
};


//----------------------------------------------------
// EOF