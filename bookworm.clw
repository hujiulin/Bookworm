; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDIALOGK
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bookworm.h"

ClassCount=5
Class1=CBookwormApp
Class2=CBookwormDlg
Class3=CAboutDlg

ResourceCount=6
Resource1=IDD_BOOKWORM_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG2
Resource4=IDD_DIALOG1
Class4=CDiaHelp
Resource5=IDD_ABOUTBOX
Class5=CDIALOGK
Resource6=IDR_MENU1

[CLS:CBookwormApp]
Type=0
HeaderFile=bookworm.h
ImplementationFile=bookworm.cpp
Filter=N

[CLS:CBookwormDlg]
Type=0
HeaderFile=bookwormDlg.h
ImplementationFile=bookwormDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CBookwormDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=bookwormDlg.h
ImplementationFile=bookwormDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BOOKWORM_DIALOG]
Type=1
Class=CBookwormDlg
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC_frame2,button,1342177287
Control3=IDC_EDIT1,edit,1352728596
Control4=IDC_STATIC_frame1,button,1342177287
Control5=IDC_STATIC_USER,static,1342312961
Control6=IDC_EDIT2,edit,1350631568
Control7=IDC_BUTTON1,button,1342242816
Control8=IDC_BMP,static,1342177806

[MNU:IDR_MENU1]
Type=1
Class=?
Command1=ID_DIC
Command2=ID_K
Command3=ID_HELP
Command4=ID_ABOUT
CommandCount=4

[DLG:IDD_DIALOG1]
Type=1
Class=CDiaHelp
ControlCount=3
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342312448
Control3=IDC_STATIC,static,1342177283

[CLS:CDiaHelp]
Type=0
HeaderFile=DiaHelp.h
ImplementationFile=DiaHelp.cpp
BaseClass=CDialog
Filter=D
LastObject=CDiaHelp

[DLG:IDD_DIALOG2]
Type=1
Class=CDIALOGK
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342312961
Control3=IDC_EDIT1,edit,1350631552

[CLS:CDIALOGK]
Type=0
HeaderFile=DIALOGK.h
ImplementationFile=DIALOGK.cpp
BaseClass=CDialog
Filter=D
LastObject=CDIALOGK
VirtualFilter=dWC

