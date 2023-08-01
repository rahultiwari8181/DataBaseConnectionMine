#include "pch.h"
#include "Connection.h"
#include <vector>
#include <iostream>
using namespace std;

Connection::Connection()
{
	TRY
	{
		CString connectionString;
		connectionString = _T("DSN=ODBC_MFC_CONNECTION_DSN;UID=sa;PWD=12345;DATABASE=RahulTiwari;");
		m_database.OpenEx(connectionString, CDatabase::noOdbcDialog);
		AfxMessageBox(_T("Database Connected Successfully"));
	}
	CATCH(CDBException,e)
	{
		AfxMessageBox(_T("Data Connection Failed : ") + e->m_strError);
	}
	END_CATCH;
}
void Connection::close()
{
	TRY
	{
		m_database.Close();
	}
	CATCH(CDBException, e)
	{

	}
	END_CATCH;
}
void Connection::executeString(CString str)
{
	TRY
	{
		m_database.ExecuteSQL(str);
	}
	CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Error in Executing File : ") + e->m_strError);
	}
	END_CATCH;
	
}
vector<CString> Connection::fetchData(CString str)
{
	TRY
	{
		CRecordset rs(&m_database);
		rs.Open(CRecordset::forwardOnly, str);

		CString message;
		CDBVariant varValue;

		vector<CString> dataMessage;

		while (!(rs.IsEOF()))
		{
			for (short i = 0; i < rs.GetODBCFieldCount(); i++)
			{

				// Get the value of the current column as a string
				CString columnValue;
				rs.GetFieldValue(i, columnValue);

				// Append the value to the result string
				message += columnValue + _T("  ");
			}

			dataMessage.push_back(message);
			message = _T("");
			

			rs.MoveNext();
		}

		rs.Close();
		return dataMessage;
	}
	CATCH(CDBException, e)
	{
		AfxMessageBox(_T("Database Fetching Error : ") + e->m_strError);
	}
	END_CATCH;
}
