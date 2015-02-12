// DiaHelp.cpp : implementation file
//

#include "stdafx.h"
#include "bookworm.h"
#include "DiaHelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiaHelp dialog


CDiaHelp::CDiaHelp(CWnd* pParent /*=NULL*/)
	: CDialog(CDiaHelp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDiaHelp)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDiaHelp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDiaHelp)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDiaHelp, CDialog)
	//{{AFX_MSG_MAP(CDiaHelp)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiaHelp message handlers
