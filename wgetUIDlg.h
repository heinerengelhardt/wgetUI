// wgetUIDlg.h : Header-Datei
//

#if !defined(AFX_WGETUIDLG_H__9A16258E_7616_4676_B039_130CA83C1BFF__INCLUDED_)
#define AFX_WGETUIDLG_H__9A16258E_7616_4676_B039_130CA83C1BFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWgetUIDlg Dialogfeld

class CWgetUIDlg : public CDialog
{
// Konstruktion
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CWgetUIDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CWgetUIDlg)
	enum { IDD = IDD_WGETUI_DIALOG };
	CButton	m_buttonBrowse;
	CButton	m_buttonWget;
	BOOL	m_bConvertlinks;
	BOOL	m_bLevel;
	BOOL	m_bNoparent;
	BOOL	m_bRecursive;
	CString	m_csURL;
	CString	m_csPassword;
	CString	m_csUser;
	int		m_iLevel;
	CString	m_csFile;
	int		m_radioURL;
	BOOL	m_bContinue;
	BOOL	m_bNoDirectories;
	BOOL	m_bPageRequesites;
	BOOL	m_bTimeout;
	int		m_iTimeout;
	BOOL	m_bTimestamping;
	BOOL	m_bAlwaysOnTop;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CWgetUIDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	CToolTipCtrl m_tooltip;
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CWgetUIDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonWget();
	afx_msg void OnButtonBrowse();
	afx_msg void OnRadioUrl();
	afx_msg void OnRadioFile();
	afx_msg void OnCheckOntop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_WGETUIDLG_H__9A16258E_7616_4676_B039_130CA83C1BFF__INCLUDED_)
