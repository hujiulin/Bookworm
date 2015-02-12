#if !defined(AFX_DIAHELP_H__26C76C88_7DB0_4F5C_A873_B367529351D4__INCLUDED_)
#define AFX_DIAHELP_H__26C76C88_7DB0_4F5C_A873_B367529351D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaHelp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDiaHelp dialog

class CDiaHelp : public CDialog
{
// Construction
public:
	CDiaHelp(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDiaHelp)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiaHelp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDiaHelp)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAHELP_H__26C76C88_7DB0_4F5C_A873_B367529351D4__INCLUDED_)
