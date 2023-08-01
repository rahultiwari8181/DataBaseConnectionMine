// CContactInfo.cpp : implementation file
//

#include "pch.h"
#include "DataBaseConnectionMine.h"
#include "CContactInfo.h"
#include "Connection.h"
#include "afxdialogex.h"
#include <vector>
#include <iostream>
using namespace std;


// CContactInfo dialog

IMPLEMENT_DYNAMIC(CContactInfo, CDialogEx)

CContactInfo::CContactInfo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_Contact_Info, pParent)
{

}

CContactInfo::~CContactInfo()
{
}

void CContactInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctr_contact_info);
}


BEGIN_MESSAGE_MAP(CContactInfo, CDialogEx)
END_MESSAGE_MAP()


// CContactInfo message handlers


BOOL CContactInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	m_ctr_contact_info.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_ctr_contact_info.InsertColumn(0, L"Name", LVCFMT_CENTER, 250);
	m_ctr_contact_info.InsertColumn(1, L"Mobile Number", LVCFMT_CENTER, 250);

	Connection objConnection;
	CString sqlString, sqlString2;
	sqlString.Format(_T("SELECT Name FROM Contact_info"));
	sqlString2.Format(_T("SELECT Mobile_Number FROM Contact_info"));
	vector<CString> itemData = objConnection.fetchData(sqlString);
	vector<CString> itemData2 = objConnection.fetchData(sqlString2);

	for (int i = 0; i < itemData.size(); i++)
	{
		UpdateData(TRUE);
		LVITEM lvitem;
		int nItem = m_ctr_contact_info.GetItemCount();

		lvitem.mask = LVFIF_TEXT;
		lvitem.iItem = i;
		lvitem.iSubItem = 0;
		lvitem.pszText = _T(""); 
		m_ctr_contact_info.InsertItem(&lvitem);

		m_ctr_contact_info.SetItemText(nItem, 0, (LPCTSTR)itemData[i]);
		m_ctr_contact_info.SetItemText(nItem, 1, (LPCTSTR)itemData2[i]);
		
	}
	UpdateData(FALSE);
	objConnection.close();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
