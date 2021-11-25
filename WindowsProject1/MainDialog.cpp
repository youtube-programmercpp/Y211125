#include <windows.h>
#include "resource.h"

#include "MainDialog.h"
#include "ChildDialog.h"

void MainDialog::Handle_WM_INITDIALOG(HWND hDlg)
{
}
void MainDialog::Handle_WM_USER_TEST(HWND hDlg)
{
	OutputDebugStringA("WM_USER_TEST メッセージが届きました。\n");
}
MainDialog::MainDialog()
{
	lstrcpyA(s, "MainDialogクラス");
}
auto MainDialog::FromHandle(HWND hDlg)->MainDialog*
{
	return static_cast<MainDialog*>(reinterpret_cast<VirtualMainDialog*>(GetWindowLongPtr(hDlg, DWLP_USER)));
}
INT_PTR CALLBACK MainDialog::DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		reinterpret_cast<MainDialog*>(lParam)->Handle_WM_INITDIALOG(hDlg);
		SetWindowLongPtr(hDlg, DWLP_USER, LONG_PTR(static_cast<VirtualMainDialog*>(reinterpret_cast<MainDialog*>(lParam))));
		return true;
	case WM_USER_TEST:
		FromHandle(hDlg)->Handle_WM_USER_TEST(hDlg);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		case IDC_BUTTON_ChildDialog:
			{
				ChildDialog dlg;
				dlg.ShowDialog(hDlg);
			}
			return TRUE;
		default:
			return FALSE;
		}
	default:
		return FALSE;
	}
}
void MainDialog::test()
{
	OutputDebugStringA("test 関数が呼び出されました。\n");
}
void MainDialog::ShowDialog(HINSTANCE hInstance)
{
	DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */hInstance
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_Main)
	, /*_In_opt_ HWND      hWndParent    */NULL
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc
	, /*_In_     LPARAM    dwInitParam   */LPARAM(this)
	);
}
