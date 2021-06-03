// wgetUI.h : Haupt-Header-Datei für die Anwendung WGETUI
//

#if !defined(AFX_WGETUI_H__B0A5478A_2342_47AD_B6AA_18CFA75D40FE__INCLUDED_)
#define AFX_WGETUI_H__B0A5478A_2342_47AD_B6AA_18CFA75D40FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CWgetUIApp:
// Siehe wgetUI.cpp für die Implementierung dieser Klasse
//

class CWgetUIApp : public CWinApp
{
public:
	CWgetUIApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CWgetUIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CWgetUIApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_WGETUI_H__B0A5478A_2342_47AD_B6AA_18CFA75D40FE__INCLUDED_)
