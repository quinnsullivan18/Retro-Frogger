#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <cwchar>

#include "GameController.h"
#include "Graphics.h"
#include "Level_Loading.h"

Graphics *graphics;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow) {
	HRESULT comResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(comResult)) {
		MessageBoxW(NULL, L"Unable to initialize Windows image support.", L"Frogger Game", MB_OK | MB_ICONERROR);
		return -1;
	}

	wchar_t executablePath[MAX_PATH];
	DWORD executablePathLength = GetModuleFileNameW(NULL, executablePath, MAX_PATH);
	wchar_t* lastSeparator = executablePathLength > 0 && executablePathLength < MAX_PATH
		? std::wcsrchr(executablePath, L'\\')
		: NULL;
	if (!lastSeparator) {
		MessageBoxW(NULL, L"Unable to locate the game asset folder.", L"Frogger Game", MB_OK | MB_ICONERROR);
		CoUninitialize();
		return -1;
	}

	lastSeparator[1] = L'\0';
	if (!SetCurrentDirectoryW(executablePath)) {
		MessageBoxW(NULL, L"Unable to open the game asset folder.", L"Frogger Game", MB_OK | MB_ICONERROR);
		CoUninitialize();
		return -1;
	}

	srand(static_cast<unsigned int>(time(NULL)));
	WNDCLASSEX windowClass;
	ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowClass.hInstance = hInstance;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.lpszClassName = "MainWindow";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassEx(&windowClass);

	//We want the main window to be SCREENWIDTHxSCREENHEIGHT not including the menu and border, this adjusts the size to that	
	RECT rect = { 0, 0, SCREENWIDTH, SCREENHEIGHT };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

	HWND windowHandle = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", GAMETITLE, WS_OVERLAPPEDWINDOW, 100, 100, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, hInstance, 0);

	if (!windowHandle) {
		CoUninitialize();
		return -1;
	}

	graphics = new Graphics();

	Level_Game::Init(graphics);

	if (!graphics->Init(windowHandle)) {
		delete graphics;
		DestroyWindow(windowHandle);
		CoUninitialize();
		return -1;
	}

	ShowWindow(windowHandle, nCmdShow);


	//MSG message;

	//GetMessage checks the queue and then waits until there is a message
	//while (GetMessage(&message, NULL, 0, 0)) {
	//	DispatchMessage(&message);
	//}

	//PeekMessage checks the message queue and if there is a message allows Dispatch
	//OTHERWISE it returns control to the program

	MSG message;
	message.message = WM_NULL;

	GameController::LoadInitialLevel(new Level_Loading());

	while (message.message != WM_QUIT) {

		//Can put windowHandle for the 2nd option
		//NULL is any message passed to any windows owned by this thread
		//Windowshandle will limit messages to the current window only
		//Options 3 and 4 can filter out (read the last keyboard or mouse message for ex.)
		//Last option is what you want to happen to the message (We want it removed)

		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			DispatchMessage(&message);
		}
		else {
			//UPDATE

			GameController::Update();
			graphics->BeginDraw();
			GameController::Render();
			graphics->EndDraw();
		}
	}

	GameController::Shutdown();
	delete graphics;
	CoUninitialize();

	return 0;
}