#pragma once

class CNetStats
{
private:

	float m_dwLastTotalBytesSent;
	float m_dwLastTotalBytesRecv;
	DWORD m_dwLastUpdateTick;
	float m_dwBPSUpload;
	float m_dwBPSDownload;

public:
	CNetStats();
	~CNetStats() {};

	void Draw();
};
