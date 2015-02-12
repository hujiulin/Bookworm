// bookwormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "bookworm.h"
#include "bookwormDlg.h"
#include "DiaHelp.h"
#include "DIALOGK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
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
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookwormDlg dialog

CBookwormDlg::CBookwormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBookwormDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookwormDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookwormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookwormDlg)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBookwormDlg, CDialog)
	//{{AFX_MSG_MAP(CBookwormDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_COMMAND(ID_DIC, OnDic)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_HELP, OnHelp)
	ON_COMMAND(ID_K, OnK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookwormDlg message handlers

BOOL CBookwormDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CRect rect; 
	::GetWindowRect(m_hWnd,rect); 
	ScreenToClient(rect); 
	m_nDlgWidth = rect.right - rect.left; 
	m_nDlgHeight = rect.bottom - rect.top;
	//计算分辨率
	m_nWidth = GetSystemMetrics(SM_CXSCREEN); 
	m_nHeight = GetSystemMetrics(SM_CYSCREEN);
	//计算放大倍数
	m_Multiple_width = float(m_nWidth)/float(m_nDlgWidth); 
	m_Mutiple_heith = float(m_nHeight)/float(m_nDlgHeight); 
	change_flag=false;//这个是成员变量bool形，用来判断onsize执行时

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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	change_flag = true;
	//ShowWindow(SW_MAXIMIZE);
	
	top = 0;
	ciku = false;
	k = 2;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBookwormDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBookwormDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBookwormDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBookwormDlg::ReSize(int nID)
{
	
	CRect Rect; 
	
	GetDlgItem(nID)->GetWindowRect((LPRECT)Rect);
	ScreenToClient(Rect); 
	//计算控件左上角点 
	CPoint OldTLPoint,TLPoint; 
	OldTLPoint = Rect.TopLeft(); 
	TLPoint.x = long(OldTLPoint.x *m_Multiple_width); 
	TLPoint.y = long(OldTLPoint.y * m_Mutiple_heith );
	//计算控件右下角点
	CPoint OldBRPoint,BRPoint; 
	OldBRPoint = Rect.BottomRight(); 
	BRPoint.x = long(OldBRPoint.x *m_Multiple_width); 
	BRPoint.y = long(OldBRPoint.y * m_Mutiple_heith ); 
	//移动控件到新矩形
	Rect.SetRect(TLPoint,BRPoint); 
	GetDlgItem(nID)->MoveWindow(Rect,TRUE); 
}

void CBookwormDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (change_flag == true)//如果确定oninitdlg已经调用完毕.
	{
	   ReSize(IDC_EDIT1);
	   ReSize(IDC_EDIT2);
	   ReSize(IDC_BMP);
	   ReSize(IDC_STATIC_USER);
	   ReSize(IDCANCEL);
	   ReSize(IDC_STATIC_frame1);
	   ReSize(IDC_STATIC_frame2);
	   ReSize(IDC_BUTTON1);

	   //恢复放大倍数，并保存 (确保还原时候能够还原到原来的大小)
	   m_Multiple_width = float(1)/ m_Multiple_width ; 
	   m_Mutiple_heith = float(1)/m_Mutiple_heith ; 
	}
}

void CBookwormDlg::OnDic() 
{
	// TODO: Add your command handler code here
	CString filter;
	filter = "TXT文件(*.txt)|*.txt||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);

    if(dlg.DoModal() == IDOK)
	{

		FILE * in;
		in = fopen((LPCTSTR)dlg.GetPathName(),"r");//只供读取
		while(fscanf(in,"%s",&str[top++]) != EOF)
		{
		
		}
		fclose(in);
		ciku = true;
	}
}

void CBookwormDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if(ciku == false)
	{
		MessageBox("请导入词库!",NULL,MB_OK);
		return ;
	}
	/*26个英文字母*/
	int i;
	for(i = 0; i < 26;i++)
	{
		flag[i] = 0;
	}
	/*任意字母*/
	any = 0;
	m_edit2.GetWindowText(m_input);
	for(i = 0;i < m_input.GetLength(); i++)
	{
		if(m_input.GetAt(i) == '*')
		{
			any++;
		}
		else	
		{
			flag[m_input.GetAt(i) - 'a']++;
		}
	}
	
	top_ans = 0;	
	for(i = 0;i < top;i++)
	{
		if(find(i))
		{		
			max[top_ans] = strlen(str[i]);
			strcpy(ans[top_ans++],str[i]);
			if (top_ans >= 100)
			{
				// just find 100 words
				break;
			}
		}
	}
	if(top_ans > 0)
	{
		int maxx = 0;
		for(i = 0;i < top_ans - 1;i++)
		{
			if(max[i] > maxx)
			{
				maxx = max[i];
			}
		}
		m_output.Empty();
		for(i = 0;i < top_ans - 1;i++)
		{
			if(maxx <= 2)
			{
				//printf("%s %d\n",ans[i],max[i]);
				CString tmp;
				tmp.Format("%d", max[i]);

				m_output.Insert(m_output.GetLength(),ans[i]);
				if(strlen(ans[i]) < 8)
				{
					m_output.Insert(m_output.GetLength(),"\t\t\t");
				}
				else
					if(strlen(ans[i]) < 16)
					{
						m_output.Insert(m_output.GetLength(),"\t\t");
					}
					else
						if(strlen(ans[i]) < 24)
						{
							m_output.Insert(m_output.GetLength(),"\t");
						}
				m_output.Insert(m_output.GetLength(),tmp);
				m_output.Insert(m_output.GetLength(),"\r\n");				
				m_edit1.SetWindowText(m_output);
			}
			else
			{
				if(max[i] >= maxx - k)
				{
					CString tmp;
					tmp.Format("%d", max[i]);

					m_output.Insert(m_output.GetLength(),ans[i]);
					if(strlen(ans[i]) < 8)
					{
						m_output.Insert(m_output.GetLength(),"\t\t\t");
					}
					else
						if(strlen(ans[i]) < 16)
						{
							m_output.Insert(m_output.GetLength(),"\t\t");
						}
						else
							if(strlen(ans[i]) < 24)
							{
								m_output.Insert(m_output.GetLength(),"\t");
							}
					m_output.Insert(m_output.GetLength(),tmp);
					m_output.Insert(m_output.GetLength(),"\r\n");					
					m_edit1.SetWindowText(m_output);
				}
			}
		}
	}
	else
	{
		m_output.Empty();
		m_output.Insert(m_output.GetLength(),"can not find it...\r\n");
		m_edit1.SetWindowText(m_output);
	}
}

bool CBookwormDlg::find(int i)
{
	 int flag_tmp[26];
	 int any_tmp;
	 int j;
	 for(j = 0;j < 26;j++)
	 {
		flag_tmp[j] = flag[j];
	 }
	 any_tmp = any;
	 bool f = true;
	 for(j = 0;j < (int)strlen(str[i]);j++)
	 {
		if(flag_tmp[str[i][j] - 'a'] <= 0 && any_tmp <= 0)
		{
			f = false;
			break;
		}
		else
		{
			if(flag_tmp[str[i][j] - 'a'] > 0)
			{
				flag_tmp[str[i][j] - 'a']--;
			}
			else
			{
				any_tmp--;
			}
		}
	 }

	 if(f == false)
	 {
		return false;
	 }
	 else
	 {
		 return true;
	 }
}

void CBookwormDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	if(IDOK == dlg.DoModal())
	{
	
	}
}

void CBookwormDlg::OnHelp() 
{
	// TODO: Add your command handler code here
	CDiaHelp help;
	if(IDOK == help.DoModal())
	{
	
	}
}

void CBookwormDlg::OnK() 
{
	// TODO: Add your command handler code here
	CDIALOGK dlg;
	
	if(IDOK == dlg.DoModal())
	{
		k = dlg.k;
	}
}
