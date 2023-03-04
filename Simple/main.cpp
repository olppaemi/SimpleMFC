#include <afx.h>
#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame();
    
    DECLARE_DYNCREATE(CMainFrame)

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
    afx_msg void OnPaint();

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

    DECLARE_MESSAGE_MAP()
};

struct CSimpleApp : public CWinApp
{
    BOOL InitInstance();
};

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

// ¸Þ½ÃÁö ¸Ê
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SHOWWINDOW()
    ON_WM_ACTIVATE()
    ON_WM_PAINT()
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

void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
    CFrameWnd::OnShowWindow(bShow, nStatus);

    ShowWindow(SW_MAXIMIZE);
}

void CMainFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized)
{
    CFrameWnd::OnActivate(nState, pWndOther, bMinimized);

    // TODO: Add your message handler code here
    //switch (nState)
    //{
    //case WA_ACTIVE:
    //    MessageBox(L"This window has been activated, without the mouse!");
    //    break;
    //case WA_INACTIVE:
    //    MessageBox(L"This window has been deactivated and cannot be changed now!!");
    //    break;
    //case WA_CLICKACTIVE:
    //    MessageBox(L"This window has been activated using the mouse!!!");
    //    break;
    //}
}

void CMainFrame::OnPaint()
{
    CFrameWnd::OnPaint();

    MessageBox(L"The window has been painted<==>");
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
