#pragma once

#define VCMP_SAFECALL __stdcall

int VCMP_SAFECALL GameGetWeaponModelFromWeapon(int iWeaponID);
void VCMP_SAFECALL GameToggleCheatCodes(bool bToggle);
PED_TYPE * VCMP_SAFECALL GamePool_FindPlayerPed();
DWORD VCMP_SAFECALL TranslateColorCodeToRGBA(int iCode);
void VCMP_SAFECALL InitPlayerPedPtrRecords();
void VCMP_SAFECALL SetPlayerPedPtrRecord(BYTE bytePlayer, DWORD dwPedPtr);
BYTE VCMP_SAFECALL FindPlayerNumFromPedPtr(DWORD dwPedPtr);
void Unprotect(DWORD dwAddress, size_t sSize);

//-----------------------------------------------------------
