#include <afx.h>
#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame();
    
    DECLARE_DYNCREATE(CMainFrame)

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif
};

struct CSimpleApp : public CWinApp
{
    BOOL InitInstance();
};

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

// ¸Þ½ÃÁö ¸Ê
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
    // Create the window's frame
    Create(
        NULL, 
        L"Window Application", 
        WS_OVERLAPPEDWINDOW,
        CRect(120, 100, 700, 480),
        NULL
    );
}

// Frame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
    CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
    CFrameWnd::Dump(dc);
}
#endif // _DEBUG

INT CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    // Call the base class to create the window
    if (CFrameWnd::OnCreate(lpCreateStruct) == 0)
    {
        // If the window was successfully created, let the user know
        MessageBox(L"The window has been created!!!");
        // Since the window was successfully created, return 0
        return 0;
    }
    // Otherwise, return -1
    return -1;
}

BOOL CSimpleApp::InitInstance()
{
    // Use a pointer to the window's frame for the application
    // to use the window
    CMainFrame *Tester = new CMainFrame();
    m_pMainWnd = Tester;

    // Show the window
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();

    return TRUE;
}



CSimpleApp theApp;