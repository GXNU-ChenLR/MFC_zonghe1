
// MFC_zonghe1View.h : CMFC_zonghe1View ��Ľӿ�
//

#pragma once

class CMFC_zonghe1Set;

class CMFC_zonghe1View : public CRecordView
{
protected: // �������л�����
	CMFC_zonghe1View();
	DECLARE_DYNCREATE(CMFC_zonghe1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_ZONGHE1_FORM };
#endif
	CMFC_zonghe1Set* m_pSet;
	CString path;
// ����
public:
	CMFC_zonghe1Doc* GetDocument() const;
	void draw_pic(CString file);

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFC_zonghe1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString Picname;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
};

#ifndef _DEBUG  // MFC_zonghe1View.cpp �еĵ��԰汾
inline CMFC_zonghe1Doc* CMFC_zonghe1View::GetDocument() const
   { return reinterpret_cast<CMFC_zonghe1Doc*>(m_pDocument); }
#endif

