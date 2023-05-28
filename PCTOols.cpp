// PCTOols.cpp : Defines the entry point for the application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "PCTOols.h"



#define MAX_LOADSTRING 100
#define windowH 720
#define windowW 1280
#define SleepTimer 5

HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hwndButton;
HWND hEditA;
bool Flag = false;
char nyannyan[150];
wchar_t nyannyanW[150];


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPWSTR    lpCmdLine,_In_ int       nCmdShow){
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PCTOOLS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PCTOOLS));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PCTOOLS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   SetPriorityClass(GetCurrentProcess(),HIGH_PRIORITY_CLASS);

   curl_global_init(CURL_GLOBAL_ALL);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX,
      CW_USEDEFAULT, 0, windowW, windowH, nullptr, nullptr, hInstance, nullptr);
   hwndButton = CreateWindowW(
       L"BUTTON",  // Predefined class; Unicode assumed 
       L"BLAST SOME NIGGAZ",      // Button text 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       windowW/2-150,         // x position 
       windowH/2-50,         // y position 
       300,        // Button width
       100,        // Button height
       hWnd,     // Parent window
       NULL,       // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);      // Pointer not needed.
   hEditA = CreateWindowA("Edit", "cookies", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER | ES_LEFT, windowW / 2 - 200, windowH / 2 - 80, 400, 25, hWnd, NULL, NULL, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}




void Meow() {
    //CURL STUFF

    CURL* hnd;
    struct curl_slist* slist1;
    slist1 = NULL;
    slist1 = curl_slist_append(slist1, "User-Agent: Mozilla/5.0 (Windows NT 10.0; rv:112.0) Gecko/20100101 Firefox/112.0");
    slist1 = curl_slist_append(slist1, "Accept: */*");
    slist1 = curl_slist_append(slist1, "Accept-Language: en-US,en;q=0.5");
    slist1 = curl_slist_append(slist1, "Accept-Encoding: gzip, deflate, br");
    slist1 = curl_slist_append(slist1, "Content-Type: application/x-www-form-urlencoded; charset=UTF-8");
    slist1 = curl_slist_append(slist1, "X-Requested-With: XMLHttpRequest");
    slist1 = curl_slist_append(slist1, "Origin: https://web.spaggiari.eu");
    slist1 = curl_slist_append(slist1, "DNT: 1");
    slist1 = curl_slist_append(slist1, "Connection: keep-alive");
    slist1 = curl_slist_append(slist1, "Referer: https://web.spaggiari.eu/col/app/default/corso.php\?view=sta");
    slist1 = curl_slist_append(slist1, nyannyan);
    slist1 = curl_slist_append(slist1, "Sec-Fetch-Dest: empty");
    slist1 = curl_slist_append(slist1, "Sec-Fetch-Mode: cors");
    slist1 = curl_slist_append(slist1, "Sec-Fetch-Site: same-origin");
    slist1 = curl_slist_append(slist1, "Sec-GPC: 1");
    slist1 = curl_slist_append(slist1, "TE: trailers");
    hnd = curl_easy_init();
    curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
    curl_easy_setopt(hnd, CURLOPT_URL, "https://web.spaggiari.eu/col/app/default/corso.xhr.php");
    curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, "act=regTempo&tipo=reg&durata=1&duratatot=0&lezione=sta");
    curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)54);
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
    curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/8.0.1");
    curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
    curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
    while (Flag) {
        Sleep(SleepTimer);
        curl_easy_perform(hnd);
    }
    curl_easy_cleanup(hnd);
    hnd = NULL;
    curl_slist_free_all(slist1);
    slist1 = NULL;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        if (wParam == BN_CLICKED) {
            Flag = !Flag;
            SendMessage(hwndButton, WM_SETTEXT, 0, (LPARAM)(Flag?L"chill nigga CHILL!!!":L"BLAST SOME NIGGAZ"));
            SendMessage(hEditA, WM_GETTEXT, (WPARAM)150, (LPARAM)nyannyanW);
            wcstombs(nyannyan,nyannyanW,sizeof(char)*149);
            //MessageBoxA(NULL,nyannyan,"",MB_OK);
            //strcpy(nyannyan,"Cookie: LAST_REQUESTED_TARGET=cvv; PHPSESSID=3id6rpdplf8a9dspmiafj5sl34jo2vgv; webrole=gen; webidentity=S8223588Y");
            if (Flag) {
                std::thread t(Meow);
                t.detach();
                std::thread t2(Meow);
                t2.detach();
                std::thread t3(Meow);
                t3.detach();
                std::thread t4(Meow);
                t4.detach();
            }
        }
        break;
    case WM_PAINT:
        {
            HBITMAP hImage = LoadBitmap((HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), MAKEINTRESOURCE(IDB_BITMAP1));
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            HDC hdcMem = CreateCompatibleDC(hdc); // hDC is a DC structure supplied by Win32API
            SelectObject(hdcMem, hImage);
            StretchBlt(
                hdc,         // destination DC
                0,        // x upper left
                0,         // y upper left
                windowW,       // destination width
                windowH,      // destination height
                hdcMem,      // you just created this above
                0,
                0,          // x and y upper left
                768,          // source bitmap width
                585,          // source bitmap height
                SRCCOPY);   // raster operation
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        curl_global_cleanup();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}





/*
    BOOL  bResults = FALSE;
    char ReqBuffer[] = "act=regTempo&tipo=reg&durata=1&duratatot=0&lezione=sta";
    wchar_t Headers[] = L"User-Agent: Mozilla/5.0 (Windows NT 10.0; rv:112.0) Gecko/20100101 Firefox/112.0\r\nAccept: *\/*\r\nAccept - Language: en - US, en; q = 0.5\r\nAccept - Encoding: gzip, deflate, br\r\nContent - Type: application / x - www - form - urlencoded; charset = UTF - 8\r\nX - Requested - With: XMLHttpRequest\r\nOrigin: https://web.spaggiari.eu\r\nDNT: 1\r\nConnection: keep-alive\r\nReferer: https://web.spaggiari.eu/col/app/default/corso.php?view=sta\r\nCookie: PHPSESSID=88v4cg3r70nbh3l38ph31rmcbjjskdio; webrole=gen; webidentity=S8223588Y\r\nSec-Fetch-Dest: empty\r\nSec-Fetch-Mode: cors\r\nSec-Fetch-Site: same-origin\r\nSec-GPC: 1\r\nTE: trailers\r\n";
HINTERNET hSession = NULL,
hConnect = NULL,
hRequest = NULL;
hSession = WinHttpOpen(L"A WinHTTP Example Program/1.0",
    WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
    WINHTTP_NO_PROXY_NAME,
    WINHTTP_NO_PROXY_BYPASS, 0);

// Specify an HTTP server.
if (hSession)
hConnect = WinHttpConnect(hSession, L"web.spaggiari.eu",
    INTERNET_DEFAULT_HTTP_PORT, 0);

// Create an HTTP Request handle.
if (hConnect)
hRequest = WinHttpOpenRequest(hConnect, L"POST",
    L"/col/app/default/corso.xhr.php",
    NULL, WINHTTP_NO_REFERER,
    WINHTTP_DEFAULT_ACCEPT_TYPES,
    0);

// Send a Request.
if (hRequest)
bResults = WinHttpSendRequest(hRequest,
    Headers,
    -1L, ReqBuffer, sizeof(ReqBuffer),
    sizeof(ReqBuffer) + sizeof(Headers), 0);


if (!bResults)
MessageBoxA(NULL, std::to_string(GetLastError()).c_str(), "dioc", MB_OK);

// Close any open handles.
if (hRequest) WinHttpCloseHandle(hRequest);
if (hConnect) WinHttpCloseHandle(hConnect);
if (hSession) WinHttpCloseHandle(hSession); */