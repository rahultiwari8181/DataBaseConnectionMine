
// DataBaseConnectionMineDlg.h : header file
//

#pragma once


// CDataBaseConnectionMineDlg dialog
class CDataBaseConnectionMineDlg : public CDialogEx
{
// Construction
public:
	CDataBaseConnectionMineDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATABASECONNECTIONMINE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CString m_str_name;
	CString m_str_mobile_number;
	afx_msg void OnBnClickedButtonclear();
	afx_msg void OnBnClickedButtoncontactinfo();
	afx_msg void OnBnClickedButtonupdate();
	afx_msg void OnBnClickedButtondelete();
	CString m_str_Department;
};
