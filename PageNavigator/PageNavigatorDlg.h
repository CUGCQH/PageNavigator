
// PageNavigatorDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "resource.h"

// CPageNavigatorDlg 对话框
class CPageNavigatorDlg : public CDialog
{
// 构造
public:
	CPageNavigatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PAGENAVIGATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
private:
	void Hide();
public:
	afx_msg void OnBnClickedButtonPre();
	afx_msg void OnBnClickedButtonNext();
	CButton m_BtPre;
	CButton m_BtNext;
	afx_msg void OnBnClickedButtonSet();
	void out_put(int start, int end, int cur);
	void SkipPage(int nIndex,int nPageNum);
	int m_nPage_total; //总数量
	int m_nPage_count; //总页数
	int m_nPage_cur;   //当前页
	int m_nPage_size;  //每页显示数量
	int	m_nPage_show;  //显示的页码个数
	afx_msg void OnBnClickedButtonPreMore();
	afx_msg void OnBnClickedButtonNextMore();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
