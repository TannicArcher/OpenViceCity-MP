#include "../main.h"
#include "CScripts.h"

void RegisterFunction(HSQUIRRELVM pVM, char * szFunc, SQFUNCTION func, int params, const char * szTemplate);
void RegisterVariable(HSQUIRRELVM pVM, const char * szVarName, bool bValue);
void RegisterVariable(HSQUIRRELVM pVM, const char * szVarName, int iValue);
void RegisterVariable(HSQUIRRELVM pVM, const char * szVarName, float fValue);
void RegisterVariable(HSQUIRRELVM pVM, const char * szVarName, const char * szValue);