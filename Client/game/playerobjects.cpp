#include "../../raknet/WindowsIncludes.h"

#include "../main.h"
#include "game.h"
#include "util.h"
#include "pools.h"
#include "keystuff.h"
#include "aimstuff.h"

extern CGame *pGame;
extern CNetGame *pNetGame;
extern CChatWindow   *pChatWindow;


CPlayerObjects::CPlayerObjects()
{
	m_dwGTAId = 1; // 0x001
}

CPlayerObjects::CPlayerObjects(int iModel, float fX, float fY,float fZ)
{
	m_dwGTAId=0;

	Create(iModel, fX, fY, fZ);
}

void CPlayerObjects::Create(int iModel, float fX, float fY, float fZ)
{
	ScriptCommand(&create_object, iModel, fX, fY, fZ, m_dwGTAId);
}

void CPlayerObjects::Delete()
{
	ScriptCommand(&destroy_object, m_dwGTAId);
}

void CPlayerObjects::SetObjectTargetable( )
{
	ScriptCommand(&set_target_state, m_dwGTAId);
}

int CPlayerObjects::HasObjectBeenDamaged( )
{
	int iDamage;

	ScriptCommand(&get_object_state, m_dwGTAId, iDamage);

	return iDamage;
}