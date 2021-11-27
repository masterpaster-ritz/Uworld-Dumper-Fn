#include "stdafx.h"


void main() {
	std::cout << "Uworld Dumper By Ritz (:" << std::endl; //if (remove) {gay = true}  if (gay) {cout u gay}
	std::cout << "Starting..." << std::endl;
	// UWorld
	define::UWorld_Offset = Utilities::occurance->Find(GetModuleHandleW(nullptr), ("\x48\x89\x05\x00\x00\x00\x00\x48\x8B\x8B\x00\x00\x00\x00"),
		"xxx????xxx????", 0);
	define::UWorld_Offset = reinterpret_cast<decltype(define::UWorld_Offset)>(rva(define::UWorld_Offset, 7));
	std::cout << "UWorld: 0x%x", define::UWorld_Offset - (uintptr_t)GetModuleHandle(L"FortniteClient-Win64-Shipping.exe");


	// GObjects
	define::GObjects = Utilities::occurance->Find(GetModuleHandleW(NULL), "\x48\x8B\x05\x00\x00\x00\x00\x48\x8B\x0C\xC8\x48\x8B\x04\xD1",
		"xxx????xxxxxxxx", 0);
	auto offset = *reinterpret_cast<uint32_t*>(define::GObjects + 3);
	define::GObjects = reinterpret_cast<decltype(define::GObjects)>(define::GObjects + 7 + offset);
	std::cout << "\nGObjects: 0x%x", define::GObjects - (PBYTE)GetModuleHandleW(nullptr);


	// GNames
	define::GNames = Utilities::occurance->Find(GetModuleHandleW(nullptr), ("\x0F\x84\x00\x00\x00\x00\x48\x8D\x05\x00\x00\x00\x00\x48\x83\xC4\x28\xC3"),
		"xx????xxx????xxxxx", 0);
	offset = *reinterpret_cast<uint32_t*>(define::GNames + 9);
	define::GNames = reinterpret_cast<decltype(define::GNames)>(define::GNames + 13 + offset);
	std::cout << "\nGNames: 0x%x\n", define::GNames - (PBYTE)GetModuleHandleW(nullptr);


	// BoneMatrix
	define::GetBoneMatrix = Utilities::occurance->Find(GetModuleHandleW(nullptr), "\xE8\x00\x00\x00\x00\x48\x8B\x47\x30\xF3\x0F\x10\x45\x00",
		("x????xxxxxxxx?"), 0);
	define::GetBoneMatrix = reinterpret_cast<decltype(define::GetBoneMatrix)>(rva(define::GetBoneMatrix, 5));
	std::cout << "GetBoneMatrix: 0x%x\n", define::GetBoneMatrix - (PBYTE)GetModuleHandleW(nullptr);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:

		DisableThreadLibraryCalls(hModule);
		AllocConsole();
		freopen("conin$", "r", stdin);
		freopen("conout$", "w", stdout);
		freopen("conout$", "w", stderr);
		main();

		return TRUE;
	}

	return FALSE;
}
