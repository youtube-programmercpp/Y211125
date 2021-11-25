#pragma once
class ChildDialog
{
	static INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Handle_WM_INITDIALOG(HWND hDlg);
public:
	void ShowDialog(HWND hWndParent);
};
