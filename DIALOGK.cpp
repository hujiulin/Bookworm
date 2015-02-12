// DIALOGK.cpp : implementation file
//

#include "stdafx.h"
#include "bookworm.h"
#include "DIALOGK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOGK dialog


CDIALOGK::CDIALOGK(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOGK::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOGK)
	//}}AFX_DATA_INIT
}


void CDIALOGK::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOGK)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP

	CString tmp;
	m_edit1.GetWindowText(tmp);
	if(tmp.Compare("") != 0)k = atoi( LPCTSTR(tmp) );
}


BEGIN_MESSAGE_MAP(CDIALOGK, CDialog)
	//{{AFX_MSG_MAP(CDIALOGK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOGK message handlers

