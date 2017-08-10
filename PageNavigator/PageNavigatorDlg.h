
// PageNavigatorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "resource.h"

// CPageNavigatorDlg �Ի���
class CPageNavigatorDlg : public CDialog
{
// ����
public:
	CPageNavigatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PAGENAVIGATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	// ���ɵ���Ϣӳ�亯��
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
	int m_nPage_total; //������
	int m_nPage_count; //��ҳ��
	int m_nPage_cur;   //��ǰҳ
	int m_nPage_size;  //ÿҳ��ʾ����
	int	m_nPage_show;  //��ʾ��ҳ�����
	afx_msg void OnBnClickedButtonPreMore();
	afx_msg void OnBnClickedButtonNextMore();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
