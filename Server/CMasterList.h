#include <string>
#include "CHttpClient.h"

class CMasterList
{
private:
	std::string m_strAddress;
	std::string m_strPostPath;
	DWORD m_dwLastPulse;

public:
	CMasterList(char * szAddress, char * szPath, int iServerPort);
	~CMasterList();
	
	void Process();
};
