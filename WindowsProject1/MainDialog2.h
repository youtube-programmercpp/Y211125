#pragma once
#include <string>
enum 
{ WM_USER_TEST	 = WM_USER + 0x1000
};
#include "VirtualMainDialog.h"
class MainDialog2 : public VirtualMainDialog
{
	std::string s;


	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Handle_WM_INITDIALOG(HWND hDlg);
	void Handle_WM_USER_TEST(HWND hDlg);
public:
	MainDialog2();
	static auto FromHandle(HWND hDlg)->MainDialog2*;
	virtual void test() override;
	void ShowDialog(HINSTANCE hInstance);
};
