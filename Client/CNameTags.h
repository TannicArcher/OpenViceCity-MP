
#pragma once

//----------------------------------------------------

class CNameTags
{
public:
	void Draw();

	CNameTags(IDirect3DDevice8 *pD3DDevice);
	~CNameTags();

	IDirect3DDevice8	*m_pD3DDevice;
};

//----------------------------------------------------
// EOF