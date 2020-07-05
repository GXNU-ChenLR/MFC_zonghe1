
// MFC_zonghe1View.h : CMFC_zonghe1View 类的接口
//

#pragma once

class CMFC_zonghe1Set;

class CMFC_zonghe1View : public CRecordView
{
protected: // 仅从序列化创建
	CMFC_zonghe1View();
	DECLARE_DYNCREATE(CMFC_zonghe1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_ZONGHE1_FORM };
#endif
	CMFC_zonghe1Set* m_pSet;
	CString path;
// 特性
public:
	CMFC_zonghe1Doc* GetDocument() const;
	void draw_pic(CString file);

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFC_zonghe1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFC_zonghe1View.cpp 中的调试版本
inline CMFC_zonghe1Doc* CMFC_zonghe1View::GetDocument() const
   { return reinterpret_cast<CMFC_zonghe1Doc*>(m_pDocument); }
#endif

