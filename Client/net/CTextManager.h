#pragma once

#define MAX_TEXTS 128

class CTextManager
{
public:
	CTextManager();
	~CTextManager();

	EntityId New(EntityId TextID, DWORD color, char * szFontName, int iSize, float posX, float posY, char * szText);
	bool Delete(EntityId TextID);

	CText* GetAt(EntityId TextID)
	{
		if(TextID > MAX_TEXTS) { return NULL; }
		return m_pTexts[TextID];
	};

	BOOL GetSlotState(EntityId TextID)
	{
		if(TextID > MAX_TEXTS) { return FALSE; }
		return m_bTextSlotState[TextID];
	};

	EntityId GetFreeSlot();

	void Process();

private:
	BOOL m_bTextSlotState[MAX_TEXTS];
	CText * m_pTexts[MAX_TEXTS];
};
