#if !defined(AFX_DIALOGK_H__E21BF7A4_655A_4567_B705_9C4C4FAA1482__INCLUDED_)
#define AFX_DIALOGK_H__E21BF7A4_655A_4567_B705_9C4C4FAA1482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIALOGK.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIALOGK dialog

class CDIALOGK : public CDialog
{
// Construction
public:
	CDIALOGK(CWnd* pParent = NULL);   // standard constructor
	int k;
// Dialog Data
	//{{AFX_DATA(CDIALOGK)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIALOGK)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIALOGK)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGK_H__E21BF7A4_655A_4567_B705_9C4C4FAA1482__INCLUDED_)
