#pragma once
#include "odbcinst.h"
#include "afxdb.h"
#include <vector>
#include <iostream>
using namespace std;


class Connection
{
public:
	Connection();
	void close();
	void executeString(CString);
	vector<CString> fetchData(CString);

protected:

	CDatabase m_database;

};

