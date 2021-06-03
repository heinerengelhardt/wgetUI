// wgetUIDlg.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "wgetUI.h"
#include "wgetUIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWgetUIDlg Dialogfeld

CWgetUIDlg::CWgetUIDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWgetUIDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWgetUIDlg)
	m_bConvertlinks = FALSE;
	m_bLevel = FALSE;
	m_bNoparent = FALSE;
	m_bRecursive = FALSE;
	m_csURL = _T("");
	m_csPassword = _T("");
	m_csUser = _T("");
	m_iLevel = 0;
	m_csFile = _T("");
	m_radioURL = -1;
	m_bContinue = FALSE;
	m_bNoDirectories = FALSE;
	m_bPageRequesites = FALSE;
	m_bTimeout = FALSE;
	m_iTimeout = 0;
	m_bTimestamping = FALSE;
	m_bAlwaysOnTop = FALSE;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWgetUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWgetUIDlg)
	DDX_Control(pDX, IDC_BUTTON_BROWSE, m_buttonBrowse);
	DDX_Control(pDX, IDC_BUTTON_WGET, m_buttonWget);
	DDX_Check(pDX, IDC_CHECK_CONVERTLINKS, m_bConvertlinks);
	DDX_Check(pDX, IDC_CHECK_LEVEL, m_bLevel);
	DDX_Check(pDX, IDC_CHECK_NOPARENT, m_bNoparent);
	DDX_Check(pDX, IDC_CHECK_RECURSIVE, m_bRecursive);
	DDX_Text(pDX, IDC_EDIT_URL, m_csURL);
	DDV_MaxChars(pDX, m_csURL, 1000);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_csPassword);
	DDV_MaxChars(pDX, m_csPassword, 1000);
	DDX_Text(pDX, IDC_EDIT_USER, m_csUser);
	DDV_MaxChars(pDX, m_csUser, 1000);
	DDX_Text(pDX, IDC_EDIT_LEVEL, m_iLevel);
	DDV_MinMaxInt(pDX, m_iLevel, 0, 100);
	DDX_Text(pDX, IDC_EDIT_FILE, m_csFile);
	DDV_MaxChars(pDX, m_csFile, 1000);
	DDX_Radio(pDX, IDC_RADIO_URL, m_radioURL);
	DDX_Check(pDX, IDC_CHECK_CONTINUE, m_bContinue);
	DDX_Check(pDX, IDC_CHECK_NODIRECTORIES, m_bNoDirectories);
	DDX_Check(pDX, IDC_CHECK_PAGEREQUISITES, m_bPageRequesites);
	DDX_Check(pDX, IDC_CHECK_TIMEOUT, m_bTimeout);
	DDX_Text(pDX, IDC_EDIT_TIMEOUT, m_iTimeout);
	DDV_MinMaxInt(pDX, m_iTimeout, 0, 1000);
	DDX_Check(pDX, IDC_CHECK_TIMESTAMPING, m_bTimestamping);
	DDX_Check(pDX, IDC_CHECK_ONTOP, m_bAlwaysOnTop);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWgetUIDlg, CDialog)
	//{{AFX_MSG_MAP(CWgetUIDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_WGET, OnButtonWget)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_RADIO_URL, OnRadioUrl)
	ON_BN_CLICKED(IDC_RADIO_FILE, OnRadioFile)
	ON_BN_CLICKED(IDC_CHECK_ONTOP, OnCheckOntop)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWgetUIDlg Nachrichten-Handler

BOOL CWgetUIDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	// wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// Erstellen Sie das QuickInfo-Steuerelement
	m_tooltip.Create( this );
	m_tooltip.Activate( TRUE );

	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_RECURSIVE ), _T("recursive web-suck -- use with care!") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_NOPARENT ), _T("don't ascend to the parent directory") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_LEVEL ), _T("maximum recursion depth (inf or 0 for infinite)") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_CONVERTLINKS ), _T("convert non-relative links to relative") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_CONTINUE ), _T("restart getting an existing file") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_TIMESTAMPING ), _T("don't retrieve files if older than local") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_NODIRECTORIES ), _T("don't create directories") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_TIMEOUT ), _T("set the read timeout to SECONDS") );
	m_tooltip.AddTool( GetDlgItem( IDC_CHECK_PAGEREQUISITES ), _T("get all images, etc. needed to display HTML page") );

    m_csURL    = _T("http://");
	m_radioURL = 0;

	GetDlgItem( IDC_EDIT_FILE )->EnableWindow( FALSE );
	GetDlgItem( IDC_BUTTON_BROWSE )->EnableWindow( FALSE );

    UpdateData( FALSE );

	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CWgetUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CWgetUIDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CWgetUIDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWgetUIDlg::OnButtonWget() 
{
    UpdateData( TRUE );

    CString csExec = _T("wget.exe ");

	CFile f;
	if( f.Open( csExec, CFile::modeRead ) ) {
		f.Close();
	}
	else {
		AfxMessageBox( _T("The wget.exe is not in the working directory.\r\n")
			           _T("Please download it at http://wget.sunsite.dk/") );
		return;
	}

    if( m_csURL.Find( _T("http://"), 0 ) ) {
        AfxMessageBox( _T("Please specify a valid URL!") );
        return;
    }
    
    if( m_bRecursive ) {
        csExec += _T("-r ");
    }
    if( m_bNoparent ) {
        csExec += _T("-np ");
    }
    if( m_bLevel ) {
        csExec += _T("--level=");
        CString csTmp = _T("");
        csTmp.Format( _T("%d "), m_iLevel );
        csExec += csTmp;
    }
    if( m_bTimeout ) {
        csExec += _T("--timeout=");
        CString csTmp = _T("");
        csTmp.Format( _T("%d "), m_iTimeout );
        csExec += csTmp;
    }
    if( m_bConvertlinks ) {
        csExec += _T("-k ");
    }
    if( m_bContinue ) {
        csExec += _T("-c ");
    }
    if( m_bPageRequesites ) {
        csExec += _T("-p ");
    }
    if( m_bTimestamping ) {
        csExec += _T("--timestamping ");
    }
    if( m_bNoDirectories ) {
        csExec += _T("-nd ");
    }
    if( m_csUser != _T("") ) {
        csExec += _T("--http-user=");
        csExec += m_csUser;
        csExec += _T(" ");
    }
    if( m_csPassword != _T("") ) {
        csExec += _T("--http-passwd=");
        csExec += m_csPassword;
        csExec += _T(" ");
    }

	if( m_radioURL == 0 ) {
		csExec += m_csURL;
	}
	else {
		csExec += _T("--input-file=");
		csExec += m_csFile;
	}

    WinExec( csExec, SW_MINIMIZE );
}

void CWgetUIDlg::OnButtonBrowse() 
{
	OPENFILENAME ofn;
	ZeroMemory( &ofn, sizeof(OPENFILENAME) );

	CHAR szNdir[MAX_PATH]  = {"\0"};
    CHAR szNname[MAX_PATH] = {"\0"};

	ofn.lStructSize     = sizeof(OPENFILENAME);
	ofn.hwndOwner       = m_hWnd;
	ofn.hInstance       = AfxGetInstanceHandle();
	ofn.lpstrFile       = szNname;
	ofn.nMaxFile        = sizeof(szNname);
	ofn.lpstrFilter     = (LPCTSTR) _T("TXT Files (*.txt)\0*.TXT\0");
	ofn.nFilterIndex    = 1;
	ofn.lpstrFileTitle  = NULL;
	ofn.lpstrTitle      = NULL;
	ofn.nMaxFileTitle   = 0;
	ofn.lpstrInitialDir = szNdir;
	ofn.Flags           = OFN_PATHMUSTEXIST | OFN_EXPLORER | OFN_HIDEREADONLY;

	GetOpenFileName(&ofn);

    CString csFile = ofn.lpstrFile;
    m_csFile = (csFile == _T("")) ? m_csFile : csFile;

    UpdateData(FALSE);	
}

void CWgetUIDlg::OnRadioUrl() 
{
	GetDlgItem( IDC_EDIT_URL )->EnableWindow( TRUE );
	GetDlgItem( IDC_EDIT_FILE )->EnableWindow( FALSE );
	GetDlgItem( IDC_BUTTON_BROWSE )->EnableWindow( FALSE );
	m_radioURL = 0;

	UpdateData( FALSE );
}

void CWgetUIDlg::OnRadioFile() 
{
	GetDlgItem( IDC_EDIT_URL )->EnableWindow( FALSE );
	GetDlgItem( IDC_EDIT_FILE )->EnableWindow( TRUE );
	GetDlgItem( IDC_BUTTON_BROWSE )->EnableWindow( TRUE );

	m_radioURL = 1;

	UpdateData( FALSE );
}

void CWgetUIDlg::OnCheckOntop() 
{
    UpdateData( TRUE );

  	CRect rect;
   	GetWindowRect( rect );

    if( m_bAlwaysOnTop ) {
        ::SetWindowPos( m_hWnd, HWND_TOPMOST, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW );
    }
    else {
        ::SetWindowPos( m_hWnd, HWND_NOTOPMOST, rect.left, rect.top, rect.Width(), rect.Height(), SWP_SHOWWINDOW );
    }	
}

BOOL CWgetUIDlg::PreTranslateMessage(MSG* pMsg)
{
	m_tooltip.RelayEvent( pMsg );
	return CDialog::PreTranslateMessage( pMsg );
}

void CWgetUIDlg::OnBnClickedCancel()
{
	UINT uiRet = AfxMessageBox( _T("Really Exit wgetUI?"), MB_YESNO | MB_ICONQUESTION );

	if( uiRet == IDYES ) {
		OnCancel();
	}
}
