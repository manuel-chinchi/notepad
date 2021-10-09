#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include "ntperrors.h"

#define DEFAULT_CAPTION "Notepad"

int _RegisterMainClass (HINSTANCE hInstance);
HWND _CreateMainWindow (HINSTANCE hInstance);
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
int _MessageLoop (HWND hWnd = NULL);

int WINAPI WinMain (
    HINSTANCE hThisInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpszArgument,
    int nCmdShow)
{
    HWND hWnd;
    int iMessageLoop;

    /* Register the window class, and if it fails quit the program */
    if (!_RegisterMainClass (hThisInstance))
    {
        MSG_ERROR("Failed to register main window!!!");
        return 0;
    }

    /* The class is registered, let's create the program*/
    hWnd = _CreateMainWindow (hThisInstance);

    if (!hWnd)
    {
        MSG_ERROR ("Failed to created main window!!!");
        return 0;
    }

    /* Make the window visible on the screen */
    ShowWindow (hWnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    iMessageLoop = _MessageLoop();

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return iMessageLoop;
}

LRESULT CALLBACK WindowProcedure (
    HWND hwnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

int _RegisterMainClass (HINSTANCE hInstance)
{
    WNDCLASSEX wce = {0};

    wce.cbSize        = sizeof (WNDCLASSEX);
    wce.style         = CS_DBLCLKS;
    wce.lpfnWndProc   = WindowProcedure;
    wce.cbClsExtra    = 0;
    wce.cbWndExtra    = 0;
    wce.hInstance     = hInstance;
    wce.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
    wce.hIconSm       = LoadIcon (NULL, IDI_APPLICATION);
    wce.hCursor       = LoadCursor (NULL, IDC_ARROW);
    wce.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wce.lpszMenuName  = NULL; // no menu
    wce.lpszClassName = _T("Notepad_Wnd");

    if (!RegisterClassEx(&wce))
        return 0;

    return 1;
}

HWND _CreateMainWindow (HINSTANCE hInstance)
{
    HWND hWnd = 0;

    hWnd = CreateWindowEx (
        0,                      // extended styles
        _T("Notepad_Wnd"),      // class name
        _T("Notepad"),          // window title
        WS_OVERLAPPEDWINDOW,    // styles
        CW_USEDEFAULT,          // x
        CW_USEDEFAULT,          // y
        640,                    // cx
        480,                    // cy
        NULL,                   // parent window
        NULL,                   // hmenu
        hInstance,              // app instance
        NULL                    // additional application data
    );

    if (!hWnd)
        return 0;

    return hWnd;
}

int _MessageLoop (HWND hWnd)
{
    MSG msg = {0};

    while ( GetMessage(&msg, NULL, 0, 0) )
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}