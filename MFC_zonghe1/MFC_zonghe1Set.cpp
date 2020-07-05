
// MFC_zonghe1Set.cpp : CMFC_zonghe1Set ���ʵ��
//

#include "stdafx.h"
#include "MFC_zonghe1.h"
#include "MFC_zonghe1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_zonghe1Set ʵ��

// ���������� 2020��7��5��, 20:29

IMPLEMENT_DYNAMIC(CMFC_zonghe1Set, CRecordset)

CMFC_zonghe1Set::CMFC_zonghe1Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_1 = L"";
	m_2 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFC_zonghe1Set::GetDefaultConnect()
{
	return _T("DBQ=C:\\USERS\\BUG\\Documents\\db1.mdb;DriverId=25;");
}

CString CMFC_zonghe1Set::GetDefaultSQL()
{
	return _T("[��Ƭ]");
}

void CMFC_zonghe1Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);

}
/////////////////////////////////////////////////////////////////////////////
// CMFC_zonghe1Set ���

#ifdef _DEBUG
void CMFC_zonghe1Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFC_zonghe1Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

