// bookworm.h : main header file for the BOOKWORM application
//

#if !defined(AFX_BOOKWORM_H__058F440B_29F6_41D0_B9CC_6EA0DB2FE644__INCLUDED_)
#define AFX_BOOKWORM_H__058F440B_29F6_41D0_B9CC_6EA0DB2FE644__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBookwormApp:
// See bookworm.cpp for the implementation of this class
//

class CBookwormApp : public CWinApp
{
public:
	CBookwormApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookwormApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBookwormApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKWORM_H__058F440B_29F6_41D0_B9CC_6EA0DB2FE644__INCLUDED_)
