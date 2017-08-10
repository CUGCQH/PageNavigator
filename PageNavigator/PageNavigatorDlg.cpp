
// PageNavigatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PageNavigator.h"
#include "PageNavigatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CPageNavigatorDlg::CPageNavigatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPageNavigatorDlg::IDD, pParent)
{
}

void CPageNavigatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_PRE, m_BtPre);
	DDX_Control(pDX, IDC_BUTTON_NEXT, m_BtNext);
}

BEGIN_MESSAGE_MAP(CPageNavigatorDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_PRE, &CPageNavigatorDlg::OnBnClickedButtonPre)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, &CPageNavigatorDlg::OnBnClickedButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CPageNavigatorDlg::OnBnClickedButtonSet)	
	ON_BN_CLICKED(IDC_BUTTON_PRE_MORE, &CPageNavigatorDlg::OnBnClickedButtonPreMore)
	ON_BN_CLICKED(IDC_BUTTON_NEXT_MORE, &CPageNavigatorDlg::OnBnClickedButtonNextMore)
END_MESSAGE_MAP()


// CPageNavigatorDlg 消息处理程序

BOOL CPageNavigatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	Hide();
	m_nPage_cur = 0;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void  CPageNavigatorDlg::Hide()
{
	GetDlgItem(IDC_BUTTON_PRE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_NEXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_PRE_MORE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_NEXT_MORE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_10)->ShowWindow(SW_HIDE);
}
void CPageNavigatorDlg::OnBnClickedButtonSet()
{
	CString str;
	GetDlgItemText(IDC_EDIT_NUM,str);
	m_nPage_total = _wtoi(str);
	m_nPage_count = m_nPage_total;
	GetDlgItemText(IDC_EDIT_CURNUM, str);
	m_nPage_cur = _wtoi(str);
	SkipPage(m_nPage_cur, m_nPage_total);
	
}

void CPageNavigatorDlg::OnBnClickedButtonPre()
{
	if (m_nPage_cur>0)
	{
		SkipPage(--m_nPage_cur, m_nPage_total);
	}
}


void CPageNavigatorDlg::OnBnClickedButtonNext()
{
	if (m_nPage_cur <m_nPage_total)
	{
		SkipPage(++m_nPage_cur, m_nPage_total);
	}
}
void CPageNavigatorDlg::out_put(int start, int end, int cur){
	int i = start;
	for (; i <= end; i++){
		if (i == cur) printf("* ");
		else printf("%d ", i);
	}
}
void  CPageNavigatorDlg::SkipPage(int cur, int page)
{
	Hide();
	if (cur>page)
	{
		return;
	}
	m_nPage_cur = cur;
	CString strCurPage;
	strCurPage.Format(L"%d", m_nPage_cur);
	SetDlgItemText(IDC_STATIC_NUM, strCurPage);
	int show = 9, hf = show / 2;
	if (cur != 1)
	{
		printf("Prev ");
		GetDlgItem(IDC_BUTTON_PRE)->ShowWindow(SW_SHOW);
		
	}
	else
	{
		GetDlgItem(IDC_BUTTON_PRE)->ShowWindow(SW_HIDE);
	}
	int nID = IDC_BUTTON_1;
	if (page <= show){
		out_put(1, page, cur);	
		for (int i = 0; i < page;i++)
		{
			GetDlgItem(IDC_BUTTON_1 + i)->ShowWindow(SW_SHOW);
			CString strPage;
			strPage.Format(L"%d", i + 1);
			GetDlgItem(IDC_BUTTON_1 + i)->SetWindowText(strPage);
		}
		CString strCur;
		strCur.Format(L"*%d", cur);
		GetDlgItem(IDC_BUTTON_1 + cur - 1)->SetWindowText(strCur);
	}
	else {
		if (cur - 1 < hf + 2){
			out_put(1, cur, cur);
			{
				for (int i = 0; i < cur; i++)
				{
					GetDlgItem(nID)->ShowWindow(SW_SHOW);
					CString strPage;
					strPage.Format(L"%d", i + 1);
					GetDlgItem(nID++)->SetWindowText(strPage);
				}
				CString strCur;
				strCur.Format(L"*%d", cur);
				GetDlgItem(IDC_BUTTON_1 + cur - 1)->SetWindowText(strCur);
			}
			
		}
		else {
			printf("1");
			GetDlgItem(nID)->ShowWindow(SW_SHOW);
			GetDlgItem(nID++)->SetWindowText(L"1");
			if (page != show + 1) 
			{ 
				printf("... "); 
				GetDlgItem(IDC_BUTTON_PRE_MORE)->ShowWindow(SW_SHOW);
			}
			int m = cur - hf + (page - cur - hf > 0 ? 0 : page - cur - hf)-1;
			out_put(cur - hf + (page - cur - hf > 0 ? 0 : page - cur - hf), cur, cur);
			{
				for (int i =m ; i < cur; i++)
				{
					GetDlgItem(nID)->ShowWindow(SW_SHOW);
					CString strPage;
					strPage.Format(L"%d", i + 1);
					GetDlgItem(nID++)->SetWindowText(strPage);
				}
				CString strCur;
				strCur.Format(L"*%d", cur);
				GetDlgItem(nID-1)->SetWindowText(strCur);
			}
		}
		if (page - cur < hf + 2){
			out_put(cur + 1, page, cur);
			{
				for (int i = cur+1; i < page+1; i++)
				{
					GetDlgItem(nID)->ShowWindow(SW_SHOW);
					CString strPage;
					strPage.Format(L"%d", i );
					GetDlgItem(nID++)->SetWindowText(strPage);
				}
			}
		}
		else {
			out_put(cur + 1, cur + hf - (cur - hf > 1 ? 0 : cur - hf - 1), cur);
			{
				for (int i = cur; i < (cur + hf - (cur - hf > 1 ? 0 : cur - hf - 1)); i++)
				{
					GetDlgItem(nID)->ShowWindow(SW_SHOW);
					CString strPage;
					strPage.Format(L"%d", i + 1);
					GetDlgItem(nID++)->SetWindowText(strPage);
				}
			}
			
			if (page != show + 1)
			{
				printf("... ");
				GetDlgItem(IDC_BUTTON_NEXT_MORE)->ShowWindow(SW_SHOW);
			}
			printf("%d ", page);
			CString strPage;
			strPage.Format(L"%d",page);
			GetDlgItem(IDC_BUTTON_10)->SetWindowText(strPage);
			GetDlgItem(IDC_BUTTON_10)->ShowWindow(SW_SHOW);
		}
	}
	if (cur != page) 
	{
		printf("Next");
		GetDlgItem(IDC_BUTTON_NEXT)->ShowWindow(SW_SHOW);
	}
	else
		GetDlgItem(IDC_BUTTON_NEXT)->ShowWindow(SW_HIDE);
}



void CPageNavigatorDlg::OnBnClickedButtonPreMore()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CPageNavigatorDlg::OnBnClickedButtonNextMore()
{
	// TODO:  在此添加控件通知处理程序代码
}


BOOL CPageNavigatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	int nButtonID = GetWindowLong(pMsg->hwnd, GWL_ID);

	if (pMsg->message==WM_LBUTTONDOWN)
	{
		if (nButtonID<=IDC_BUTTON_10&&nButtonID>=IDC_BUTTON_1)
		{
			CString str;
			GetDlgItemText(nButtonID, str);
			str.Replace(L"*", L"");
			int i = _wtoi(str);
			SkipPage(i, m_nPage_count);
			GetDlgItem(nButtonID)->PostMessage(WM_KILLFOCUS, 0, 0);
			return FALSE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
