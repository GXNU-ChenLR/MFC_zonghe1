
// MFC_zonghe1Doc.h : CMFC_zonghe1Doc ��Ľӿ�
//


#pragma once
#include "MFC_zonghe1Set.h"


class CMFC_zonghe1Doc : public CDocument
{
protected: // �������л�����
	CMFC_zonghe1Doc();
	DECLARE_DYNCREATE(CMFC_zonghe1Doc)

// ����
public:
	CMFC_zonghe1Set m_MFC_zonghe1Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_zonghe1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
