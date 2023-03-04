#include <afx.h>
#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
public:
    CMainFrame();
    
    DECLARE_DYNCREATE(CMainFrame)
    DECLARE_MESSAGE_MAP()

#ifdef _DEBUG
    virtual void AssertValid() const;
    virtual void Dump(CDumpContext& dc) const;
#endif

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
    afx_msg void OnPaint();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
    afx_msg void OnMove(int x, int y);
    afx_msg void OnMoving(UINT fwSide, LPRECT pRect);
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

struct CSimpleApp : public CWinApp
{
    BOOL InitInstance();
};

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

// 메시지 맵
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
    ON_WM_SHOWWINDOW()
    ON_WM_ACTIVATE()
    ON_WM_PAINT()
    ON_WM_SIZE()
    ON_WM_SIZING()
    ON_WM_MOVE()
    ON_WM_MOVING()
    ON_WM_KEYDOWN()
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
    
    //ShowWindow(SW_MAXIMIZE);
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

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
    CFrameWnd::OnSize(nType, cx, cy);

    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
    //WCHAR *MsgToShow = new WCHAR[20];
    //WCHAR *MsgCoord = new WCHAR[20];

    //switch (nType)
    //{
    //case SIZE_MINIMIZED:
    //    wcscpy(MsgToShow, L"Minimized ");
    //    break;
    //case SIZE_MAXIMIZED:
    //    wcscpy(MsgToShow, L"Maximized ");
    //    break;
    //case SIZE_RESTORED:
    //    wcscpy(MsgToShow, L"Restored ");
    //    break;
    //case SIZE_MAXHIDE:
    //    wcscpy(MsgToShow, L"Maximized Not Me ");
    //    break;
    //case SIZE_MAXSHOW:
    //    wcscpy(MsgToShow, L"Restored Not Me ");
    //    break;
    //}

    //wsprintf(MsgCoord, L"Left = %d | Top = %d", cx, cy);
    //wcscat(MsgToShow, MsgCoord);
    //MessageBox(MsgToShow);
}

void CMainFrame::OnSizing(UINT fwSide, LPRECT pRect)
{
    CFrameWnd::OnSizing(fwSide, pRect);

    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CMainFrame::OnMove(int x, int y)
{
    CFrameWnd::OnMove(x, y);

    // TODO: 여기에 메시지 처리기 코드를 추가합니다.

}

void CMainFrame::OnMoving(UINT fwSide, LPRECT pRect)
{
    CFrameWnd::OnMoving(fwSide, pRect);

    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    switch(nChar)
    {
    case VK_RETURN:
        MessageBox(L"You pressed Enter");
        break;
    case VK_F1:
        MessageBox(L"Help is not available at the moment");
        break;
    case VK_DELETE:
        MessageBox(L"Can't Delete This");
        break;
    default:
        MessageBox(L"Whatever");
    }

    CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
