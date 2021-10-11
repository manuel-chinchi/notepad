#include "Common.h"
using namespace Common;

void Common::SetFont (HWND hWnd, TFont tFont)
{
    LOGFONT lf = {0};
    HFONT hf = {0};

    switch (tFont.eStyle)
    {
        case FontStyle::FontStyleRegular:
            lf.lfItalic = 0; lf.lfWeight = 400;
        break;
        case FontStyle::FontStyleItalic:
            lf.lfItalic = 255; lf.lfWeight = 400;
        break;
        case FontStyle::FontStyleBold:
            lf.lfItalic = 0; lf.lfWeight = 700;
        break;
        case FontStyle::FontStyleBoldItalic:
            lf.lfItalic = 255; lf.lfWeight = 700;
        break;
        default:
            lf.lfItalic = 0; lf.lfWeight = 400;
        break;
    }
    strcpy (lf.lfFaceName, tFont.pszName);

    HDC hDC = GetDC (hWnd);
    int heigth = MulDiv (tFont.iSize, GetDeviceCaps (hDC, LOGPIXELSY), 72);
    ReleaseDC (hWnd, hDC);

    lf.lfHeight         = -heigth;
    lf.lfOutPrecision   = 3;
    lf.lfClipPrecision  = 2;
    lf.lfQuality        = 1;
    lf.lfPitchAndFamily = 49;

    hf = CreateFontIndirect (&lf);
    SendMessage (hWnd, WM_SETFONT, (WPARAM)hf, TRUE);
}