// bookwormDlg.h : header file
//

#if !defined(AFX_BOOKWORMDLG_H__1090BC1C_145D_4EA4_B31D_11EBBA5DA184__INCLUDED_)
#define AFX_BOOKWORMDLG_H__1090BC1C_145D_4EA4_B31D_11EBBA5DA184__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBookwormDlg dialog

class CBookwormDlg : public CDialog
{
// Construction
public:
	CBookwormDlg(CWnd* pParent = NULL);	// standard constructor
	
	int m_nDlgWidth,m_nDlgHeight;
	int m_nWidth,m_nHeight;
	float m_Multiple_width,m_Mutiple_heith;
	bool change_flag;
	void ReSize(int nID);

	int k;

	int any;
	int flag[26];
	int top;
	bool ciku;
	char str[10000][30];

	int max[10000];
	char ans[10000][30];
	int top_ans;
	CString m_output,m_input;
	bool find(int i);
	// Dialog Data
	//{{AFX_DATA(CBookwormDlg)
	enum { IDD = IDD_BOOKWORM_DIALOG };
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookwormDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBookwormDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDic();
	afx_msg void OnButton1();
	afx_msg void OnAbout();
	afx_msg void OnHelp();
	afx_msg void OnK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKWORMDLG_H__1090BC1C_145D_4EA4_B31D_11EBBA5DA184__INCLUDED_)
