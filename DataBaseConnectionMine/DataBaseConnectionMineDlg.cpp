
// DataBaseConnectionMineDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DataBaseConnectionMine.h"
#include "DataBaseConnectionMineDlg.h"
#include "afxdialogex.h"
#include "Connection.h"
#include "CContactInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDataBaseConnectionMineDlg dialog



CDataBaseConnectionMineDlg::CDataBaseConnectionMineDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATABASECONNECTIONMINE_DIALOG, pParent)
	, m_str_name(_T(""))
	, m_str_mobile_number(_T(""))
	,m_str_Department(_T(" "))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataBaseConnectionMineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_name, m_str_name);
	DDX_Text(pDX, IDC_EDIT_mobile_number, m_str_mobile_number);
	DDX_Text(pDX, IDC_EDIT_Department, m_str_Department);
}

BEGIN_MESSAGE_MAP(CDataBaseConnectionMineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CDataBaseConnectionMineDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDataBaseConnectionMineDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_clear, &CDataBaseConnectionMineDlg::OnBnClickedButtonclear)
	ON_BN_CLICKED(IDC_BUTTON_contact_info, &CDataBaseConnectionMineDlg::OnBnClickedButtoncontactinfo)
	ON_BN_CLICKED(IDC_BUTTON_update, &CDataBaseConnectionMineDlg::OnBnClickedButtonupdate)
	ON_BN_CLICKED(IDC_BUTTON_delete, &CDataBaseConnectionMineDlg::OnBnClickedButtondelete)
END_MESSAGE_MAP()


// CDataBaseConnectionMineDlg message handlers

BOOL CDataBaseConnectionMineDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDataBaseConnectionMineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDataBaseConnectionMineDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDataBaseConnectionMineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDataBaseConnectionMineDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	CDialogEx::OnOK();
}


void CDataBaseConnectionMineDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Connection objConnection;

	CString sqlString;
	sqlString.Format(_T("INSERT INTO Contact_info values('%s','%s','%s')"),m_str_name,m_str_mobile_number,m_str_Department);
	objConnection.executeString(sqlString);

	objConnection.close();
	OnBnClickedButtonclear();
}


void CDataBaseConnectionMineDlg::OnBnClickedButtonclear()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_str_name = _T("");
	m_str_mobile_number = _T("");
	m_str_Department =_T(" "); 
	UpdateData(FALSE);
}


void CDataBaseConnectionMineDlg::OnBnClickedButtoncontactinfo()
{
	// TODO: Add your control notification handler code here
	CContactInfo objCContactInfo;
	objCContactInfo.DoModal();

}


void CDataBaseConnectionMineDlg::OnBnClickedButtonupdate()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Connection objConnection;
	CString sqlString;
	sqlString.Format(_T("UPDATE Contact_info SET Mobile_Number = '%s' WHERE Name = '%s'"),m_str_mobile_number,m_str_name);

	objConnection.executeString(sqlString);

	objConnection.close();
	OnBnClickedButtonclear();

}




void CDataBaseConnectionMineDlg::OnBnClickedButtondelete()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Connection objConnection;
	CString sqlString;
	sqlString.Format(_T("DELETE FROM Contact_info WHERE Mobile_Number='%s' AND NAME='%s' AND Department = '%s';"), m_str_mobile_number,m_str_name, m_str_Department);

	objConnection.executeString(sqlString);
	objConnection.close();
	OnBnClickedButtonclear();
}
