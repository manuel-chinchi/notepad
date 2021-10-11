#include "CEditor.h"

CEditor::CEditor () {}
CEditor::~CEditor () {}

void CEditor::Create(
    HWND hParent,
    size_t width,
    size_t heigh,
    const char *text)
{
    if (!m_hHandler)
    {
        m_hHandler = CreateWindowEx (
            WS_EX_CLIENTEDGE,
            "Edit",
            text,
            WS_CHILD | WS_VISIBLE | WS_VSCROLL  | WS_HSCROLL | WS_OVERLAPPED |
            ES_LEFT | ES_MULTILINE | ES_NOHIDESEL,
            0,
            0,
            width,
            heigh,
            hParent,
            NULL,
            GetModuleHandle(NULL),
            NULL);
        m_hParent = hParent;
    }
}

HWND CEditor::GetHandler ()
{
    return m_hHandler;
}