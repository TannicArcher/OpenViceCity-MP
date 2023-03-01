#pragma once

#define MAX_TEXTS 128

class CTextManager
{
public:
	CTextManager();
	~CTextManager();

	EntityId New(DWORD color, const char * szFontName, int iSize, float posX, float posY, const char * szText);
	bool Delete(EntityId TextID);

	CText* GetAt(EntityId TextID)
	{
		if(TextID > MAX_TEXTS) { return NULL; }
		return m_pTexts[TextID];
	};

	EntityId GetFreeSlot();

	void InitForPlayer(EntityId playerId);
	void InitForWorld();

	bool GetSlotState(EntityId TextID)
	{
		if(TextID > MAX_TEXTS)
		{
			return false;
		}

		return m_bTextSlotState[TextID];
	};

private:
	bool m_bTextSlotState[MAX_TEXTS];
	CText * m_pTexts[MAX_TEXTS];
};
