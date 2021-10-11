#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <windows.h>
#include <gdiplus.h>

#define MIN_TFONT_SIZE  8
#define DEF_TFONT_SIZE  12

using namespace Gdiplus; // enum FontStyle

namespace Common
{
    struct TFont
    {
        // members of struct public by default
        const char *pszName = "Consolas";
        int iSize = DEF_TFONT_SIZE;
        FontStyle eStyle = FontStyle::FontStyleRegular;
    };

    void SetFont(HWND hWnd, TFont tFont);
}

#endif // COMMON_H_INCLUDED
