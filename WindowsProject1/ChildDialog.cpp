#include <Windows.h>
#include "resource.h"
#include "ChildDialog.h"
#include "VirtualMainDialog.h"

void ChildDialog::Handle_WM_INITDIALOG(HWND hDlg)
{
}
INT_PTR CALLBACK ChildDialog::DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_INITDIALOG:
		reinterpret_cast<ChildDialog*>(lParam)->Handle_WM_INITDIALOG(hDlg);
		SetWindowLongPtr(hDlg, DWLP_USER, lParam);
		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return TRUE;
		case IDC_BUTTON_CallParentFunction:
			//メッセージ送信
			//SendMessage(GetParent(hDlg), WM_USER_TEST, 0, 0);
			//関数呼び出し
			reinterpret_cast<VirtualMainDialog*>(GetWindowLongPtr(GetParent(hDlg), DWLP_USER))->test();
			return TRUE;
		default:
			return FALSE;
		}
	default:
		return FALSE;
	}
}

void ChildDialog::ShowDialog(HWND hWndParent)
{
	DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */(HINSTANCE)GetWindowLongPtr(hWndParent, GWLP_HINSTANCE)
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_Child)
	, /*_In_opt_ HWND      hWndParent    */hWndParent
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc
	, /*_In_     LPARAM    dwInitParam   */LPARAM(this)
	);
}
