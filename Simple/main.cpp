#include <afx.h>
#include <afxwin.h>

class CSimpleFrame : public CFrameWnd
{
public:
    CSimpleFrame();

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif
};

struct CSimpleApp : public CWinApp
{
    BOOL InitInstance();
};

CSimpleFrame::CSimpleFrame()
{
    // Create the window's frame
    Create(NULL, L"Window Application");
}

// Frame diagnostics

#ifdef _DEBUG
void CSimpleFrame::AssertValid() const
{
    CFrameWnd::AssertValid();
}

void CSimpleFrame::Dump(CDumpContext& dc) const
{
    CFrameWnd::Dump(dc);
}
#endif // _DEBUG



BOOL CSimpleApp::InitInstance()
{
    // Use a pointer to the window's frame for the application
    // to use the window
    CSimpleFrame *Tester = new CSimpleFrame();
    m_pMainWnd = Tester;

    // Show the window
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}

CSimpleApp theApp;