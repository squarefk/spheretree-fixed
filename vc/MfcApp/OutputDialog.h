/*************************************************************************\

                             C O P Y R I G H T

  Copyright 2003 Image Synthesis Group, Trinity College Dublin, Ireland.
                        All Rights Reserved.

  Permission to use, copy, modify and distribute this software and its
  documentation for educational, research and non-profit purposes, without
  fee, and without a written agreement is hereby granted, provided that the
  above copyright notice and the following paragraphs appear in all copies.


                             D I S C L A I M E R

  IN NO EVENT SHALL TRININTY COLLEGE DUBLIN BE LIABLE TO ANY PARTY FOR 
  DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING,
  BUT NOT LIMITED TO, LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE 
  AND ITS DOCUMENTATION, EVEN IF TRINITY COLLEGE DUBLIN HAS BEEN ADVISED OF 
  THE POSSIBILITY OF SUCH DAMAGES.

  TRINITY COLLEGE DUBLIN DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED 
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
  PURPOSE.  THE SOFTWARE PROVIDED HEREIN IS ON AN "AS IS" BASIS, AND TRINITY 
  COLLEGE DUBLIN HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
  ENHANCEMENTS, OR MODIFICATIONS.

  The authors may be contacted at the following e-mail addresses:

          Gareth_Bradshaw@yahoo.co.uk    isg@cs.tcd.ie

  Further information about the ISG and it's project can be found at the ISG
  web site :

          isg.cs.tcd.ie

\**************************************************************************/

#if !defined(AFX_OUTPUTDIALOG_H__153F66C1_4345_11D7_BEA8_00104B9D2B6D__INCLUDED_)
#define AFX_OUTPUTDIALOG_H__153F66C1_4345_11D7_BEA8_00104B9D2B6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputDialog dialog
class COutputDialog : public CDialog
{
// Construction
public:
	COutputDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputDialog)
	enum { IDD = IDD_OUTPUTDIALOG };
	CEdit	c_outputBox;
	CString	m_outputString;
	//}}AFX_DATA


// Overrides
	//{{AFX_VIRTUAL(COutputDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutputDialog)
	afx_msg void OnCancel();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnHide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
   //  additional functions
   void clearOutput();
   void addText(const char *text);
   void hideWindow();

private:
   void updateAndShow();
   void handleMessages();
   bool inLoop; 
};

//  exception that is thrown when the operation is to be cancelled
class CancelException{
};

//{{AFX_INSERT_LOCATION}}
#endif // !defined(AFX_OUTPUTDIALOG_H__153F66C1_4345_11D7_BEA8_00104B9D2B6D__INCLUDED_)
