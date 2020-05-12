#include <windows.h>
// entry point for standard win32 application instead of the standard "int main" function with iostream header
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance, //HINSTANCE - pointers to structures that hold info about our program (where it's loaded into memory, etc.)
	_In_opt_ HINSTANCE hPrevInstance, //this second HINSTANCE will always be NULL
	_In_ LPSTR lpCmdLine, //very important - your command line; receive the whole command line as a string
	_In_ int nShowCmd) //indicator to windows of how the window should be shown when it is created for your program
{
	const auto pClassName = "hw3d";
	//register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc; //lpfnWndProc - pointer to a function that is going to handle all the messages for this window **Very Important** determines the behavior of the window and how it looks 
	wc.cbClsExtra = 0; //allows us to allocate extra bytes of data for every instance created - don't need extra data to be stored so we set it to 0
	wc.cbWndExtra = 0; //same as above, don't need the extra data, so we set it to 0
	wc.hInstance = hInstance;
	wc.hIcon = nullptr; //will be using DirectX for build so we do not need to use Icon, cursor, background, or menu name
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName; //name that will be used when we create windows of this class type
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);
	//create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName, //class we created above "hw3d"
		"My New Window", //name for our new window
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, //style
		200, 200, 640, 480, //first 2 are the position of the window, last 2 are the dimensions
		nullptr, nullptr, hInstance, nullptr //first is the window handle to the parent(none), second is menu(none), third is the instance we have above, last is a parameter we can pass in to configure this custom data 
	);
	//show the window
	ShowWindow(hWnd, SW_SHOW); //activates the window and display in its current size and position
	while (true);
	return 0; 
}