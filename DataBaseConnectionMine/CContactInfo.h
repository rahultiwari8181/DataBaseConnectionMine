#pragma once


// CContactInfo dialog

class CContactInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CContactInfo)

public:
	CContactInfo(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CContactInfo();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Contact_Info };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ctr_contact_info;
};
