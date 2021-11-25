#pragma once
enum 
{ WM_USER_TEST	 = WM_USER + 0x1000
};
#include "VirtualMainDialog.h"
class MainDialog : public VirtualMainDialog
{
	char s[256];



	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Handle_WM_INITDIALOG(HWND hDlg);
	void Handle_WM_USER_TEST(HWND hDlg);
public:
	MainDialog();
	static auto FromHandle(HWND hDlg)->MainDialog*;
	void ShowDialog(HINSTANCE hInstance);

	// VirtualMainDialog ‚ğ‰î‚µ‚ÄŒp³‚³‚ê‚Ü‚µ‚½
	virtual void test() override;
};
