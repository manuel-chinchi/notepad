#ifndef CEDITOR_H_INCLUDED
#define CEDITOR_H_INCLUDED

#include <windows.h>

class CEditor
{
    public:
        CEditor();
        ~CEditor();

        void Create(
            HWND hParent,
            size_t width,
            size_t heigh,
            const char *text = NULL);
        HWND GetHandler();

    private:
        HWND m_hHandler;
        HWND m_hParent;
};

#endif // CEDITOR_H_INCLUDED
