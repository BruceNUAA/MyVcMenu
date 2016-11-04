
// MyVcMenuView.cpp : CMyVcMenuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MyVcMenu.h"
#endif

#include "MyVcMenuDoc.h"
#include "MyVcMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyVcMenuView

IMPLEMENT_DYNCREATE(CMyVcMenuView, CView)

BEGIN_MESSAGE_MAP(CMyVcMenuView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMyVcMenuView ����/����

CMyVcMenuView::CMyVcMenuView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMyVcMenuView::~CMyVcMenuView()
{
}

BOOL CMyVcMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyVcMenuView ����

void CMyVcMenuView::OnDraw(CDC* /*pDC*/)
{
	CMyVcMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMyVcMenuView ��ӡ

BOOL CMyVcMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyVcMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyVcMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMyVcMenuView ���

#ifdef _DEBUG
void CMyVcMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CMyVcMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyVcMenuDoc* CMyVcMenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyVcMenuDoc)));
	return (CMyVcMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyVcMenuView ��Ϣ�������


void CMyVcMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//�˷�ʽ����ݲ˵���ʾλ�ò���
	CMenu* menu_bar = AfxGetMainWnd()->GetMenu();
	CMenu* file_menu = menu_bar->GetSubMenu(0);    
	ASSERT(file_menu);

	//ClientToScreen(&point);
	file_menu->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON, point.x, 
	   point.y, this);


	CView::OnRButtonDown(nFlags, point);
}
