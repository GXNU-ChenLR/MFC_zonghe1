
// MFC_zonghe1View.cpp : CMFC_zonghe1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_zonghe1.h"
#endif

#include "MFC_zonghe1Set.h"
#include "MFC_zonghe1Doc.h"
#include "MFC_zonghe1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_zonghe1View

IMPLEMENT_DYNCREATE(CMFC_zonghe1View, CRecordView)

BEGIN_MESSAGE_MAP(CMFC_zonghe1View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &CMFC_zonghe1View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFC_zonghe1View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFC_zonghe1View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFC_zonghe1View::OnRecordLast)
END_MESSAGE_MAP()

// CMFC_zonghe1View ����/����

CMFC_zonghe1View::CMFC_zonghe1View()
	: CRecordView(IDD_MFC_ZONGHE1_FORM)
	, Picname(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\Users\\Bug\\Source\\Repos\\");
}

CMFC_zonghe1View::~CMFC_zonghe1View()
{
}

void CMFC_zonghe1View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFC_zonghe1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFC_zonghe1View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFC_zonghe1Set;
	CRecordView::OnInitialUpdate();

}


// CMFC_zonghe1View ���

#ifdef _DEBUG
void CMFC_zonghe1View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFC_zonghe1View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFC_zonghe1Doc* CMFC_zonghe1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_zonghe1Doc)));
	return (CMFC_zonghe1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_zonghe1View ���ݿ�֧��
CRecordset* CMFC_zonghe1View::OnGetRecordset()
{
	return m_pSet;
}



// CMFC_zonghe1View ��Ϣ�������


void CMFC_zonghe1View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1,s);
	filename = path + s;
	draw_pic(filename);
}


void CMFC_zonghe1View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFC_zonghe1View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsBOF())
		m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}


void CMFC_zonghe1View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s);
	filename = path + s;
	draw_pic(filename);
}

void CMFC_zonghe1View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_ratio = 1.0*rect.Width() / rect.Height();
	float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

	if (rect_ratio > img_ratio)
	{
		h = rect.Height();
		w = img_ratio*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_ratio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
	ReleaseDC(pDC);
}
