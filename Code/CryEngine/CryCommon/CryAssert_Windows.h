// CryEngine Source File.
// Copyright (C), Crytek, 1999-2015.
// CRY_ASSERT implementation for Windows

#pragma once
#if defined(USE_CRY_ASSERT) && CRY_PLATFORM_WINDOWS
#include "CryWindows.h"

#define IDD_DIALOG_ASSERT               101
#define IDC_CRYASSERT_EDIT_LINE         1000
#define IDC_CRYASSERT_EDIT_FILE         1001
#define IDC_CRYASSERT_EDIT_CONDITION    1002
#define IDC_CRYASSERT_BUTTON_CONTINUE   1003
#define IDC_CRYASSERT_EDIT_REASON       1004
#define IDC_CRYASSERT_BUTTON_IGNORE     1005
#define IDC_CRYASSERT_BUTTON_REPORT     1006
#define IDC_CRYASSERT_BUTTON_STOP       1007
#define IDC_CRYASSERT_BUTTON_BREAK      1008
#define IDC_CRYASSERT_BUTTON_IGNORE_ALL 1009

#define IDC_CRYASSERT_STATIC_TEXT 0

#define DLG_TITLE           L"Assertion Failed"
#define DLG_FONT            L"MS Sans Serif"
#define DLG_ITEM_TEXT_0     L"Continue"
#define DLG_ITEM_TEXT_1     L"Stop"
#define DLG_ITEM_TEXT_2     L"Info"
#define DLG_ITEM_TEXT_3     L""
#define DLG_ITEM_TEXT_4     L"Line"
#define DLG_ITEM_TEXT_5     L""
#define DLG_ITEM_TEXT_6     L"File"
#define DLG_ITEM_TEXT_7     L"Condition"
#define DLG_ITEM_TEXT_8     L""
#define DLG_ITEM_TEXT_9     L"failed"
#define DLG_ITEM_TEXT_10    L""
#define DLG_ITEM_TEXT_11    L"Reason"
#define DLG_ITEM_TEXT_12    L"Ignore"
#define DLG_ITEM_TEXT_13    L"Report as Bug"
#define DLG_ITEM_TEXT_14    L"Break"
#define DLG_ITEM_TEXT_15    L"Ignore All"
#define DLG_NB_ITEM         16

template<int iTitleSize>
struct SDlgItem
{
	// If use my struct instead of DLGTEMPLATE, or else (for some strange reason) it is not DWORD aligned !!
	DWORD style;
	DWORD dwExtendedStyle;
	short x;
	short y;
	short cx;
	short cy;
	WORD id;
	WORD ch;
	WORD c;
	WCHAR t[iTitleSize];
	WORD dummy;
};
#define SDLGITEM(TEXT,V) SDlgItem<sizeof(TEXT)/2> V;

struct SDlgData
{
	DLGTEMPLATE dlt;
	WORD _menu;
	WORD _class;
	WCHAR _title[sizeof(DLG_TITLE)/2];
	WORD pointSize;
	WCHAR _font[sizeof(DLG_FONT)/2];

	SDLGITEM(DLG_ITEM_TEXT_0, i0);
	SDLGITEM(DLG_ITEM_TEXT_12,i12);
	SDLGITEM(DLG_ITEM_TEXT_15,i15);
	SDLGITEM(DLG_ITEM_TEXT_14,i14);
	SDLGITEM(DLG_ITEM_TEXT_1, i1);
	SDLGITEM(DLG_ITEM_TEXT_2, i2);
	SDLGITEM(DLG_ITEM_TEXT_3, i3);
	SDLGITEM(DLG_ITEM_TEXT_4, i4);
	SDLGITEM(DLG_ITEM_TEXT_5, i5);
	SDLGITEM(DLG_ITEM_TEXT_6, i6);
	SDLGITEM(DLG_ITEM_TEXT_7, i7);
	SDLGITEM(DLG_ITEM_TEXT_8, i8);
	SDLGITEM(DLG_ITEM_TEXT_9, i9);
	SDLGITEM(DLG_ITEM_TEXT_10,i10);
	SDLGITEM(DLG_ITEM_TEXT_11,i11);
	SDLGITEM(DLG_ITEM_TEXT_13,i13);
};

//-----------------------------------------------------------------------------------------------------

static SDlgData g_dialogRC =
{
	{ DS_SETFOREGROUND|DS_MODALFRAME|DS_3DLOOK|DS_SETFONT|DS_CENTER|WS_POPUP|WS_CAPTION|WS_SYSMENU|WS_VISIBLE, 0, DLG_NB_ITEM, 0, 0, 330, 134 },
	0, 0, DLG_TITLE, 8, DLG_FONT,
	{ BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,                       0, 12,          113, 50,  14,  IDC_CRYASSERT_BUTTON_CONTINUE,   0xFFFF, 0x0080, DLG_ITEM_TEXT_0,  0},
	{ BS_DEFPUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,                    0, 66,          113, 50,  14,  IDC_CRYASSERT_BUTTON_IGNORE,     0xFFFF, 0x0080, DLG_ITEM_TEXT_12, 0},
	{ BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,                       0, 120,         113, 50,  14,  IDC_CRYASSERT_BUTTON_IGNORE_ALL, 0xFFFF, 0x0080, DLG_ITEM_TEXT_15, 0},
	{ BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,                       0, 214,         113, 50,  14,  IDC_CRYASSERT_BUTTON_BREAK,      0xFFFF, 0x0080, DLG_ITEM_TEXT_14, 0},
	{ BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,                       0, 268,         113, 50,  14,  IDC_CRYASSERT_BUTTON_STOP,       0xFFFF, 0x0080, DLG_ITEM_TEXT_1,  0},
	{ BS_GROUPBOX|WS_CHILD|WS_VISIBLE,                                    0, 7,           7,   316, 100, IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0080, DLG_ITEM_TEXT_2,  0},
	{ ES_LEFT|ES_AUTOHSCROLL|ES_READONLY|WS_BORDER|WS_CHILD|WS_VISIBLE,   0, 50,          48,  25,  13,  IDC_CRYASSERT_EDIT_LINE,         0xFFFF, 0x0081, DLG_ITEM_TEXT_3,  0},
	{ WS_CHILD|WS_VISIBLE,                                                0, 14,          50,  14,  8,   IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0082, DLG_ITEM_TEXT_4,  0},
	{ ES_LEFT|ES_AUTOHSCROLL|ES_READONLY|WS_BORDER|WS_CHILD|WS_VISIBLE,   0, 50,          32,  240, 13,  IDC_CRYASSERT_EDIT_FILE,         0xFFFF, 0x0081, DLG_ITEM_TEXT_5,  0},
	{ WS_CHILD|WS_VISIBLE,                                                0, 14,          34,  12,  8,   IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0082, DLG_ITEM_TEXT_6,  0},
	{ WS_CHILD|WS_VISIBLE,                                                0, 13,          18,  30,  8,   IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0082, DLG_ITEM_TEXT_7,  0},
	{ ES_LEFT|ES_AUTOHSCROLL|ES_READONLY|WS_BORDER|WS_CHILD|WS_VISIBLE,   0, 50,          16,  240, 13,  IDC_CRYASSERT_EDIT_CONDITION,    0xFFFF, 0x0081, DLG_ITEM_TEXT_8,  0},
	{ WS_CHILD|WS_VISIBLE,                                                0, 298,         19,  18,  8,   IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0082, DLG_ITEM_TEXT_9,  0},
	{ ES_LEFT|ES_AUTOHSCROLL|ES_READONLY|WS_BORDER|WS_CHILD|WS_VISIBLE,   0, 50,          67,  240, 13,  IDC_CRYASSERT_EDIT_REASON,       0xFFFF, 0x0081, DLG_ITEM_TEXT_10, 0},
	{ WS_CHILD|WS_VISIBLE,                                                0, 15,          69,  26,  8,   IDC_CRYASSERT_STATIC_TEXT,       0xFFFF, 0x0082, DLG_ITEM_TEXT_11, 0},
	{ BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE,                                  0, 127,         88,  72,  12,  IDC_CRYASSERT_BUTTON_REPORT,     0xFFFF, 0x0080, DLG_ITEM_TEXT_13, 0},
};

//-----------------------------------------------------------------------------------------------------

struct SCryAssertInfo
{
	const char *pszCondition;
	const char *pszFile;
	const char *pszMessage;
	unsigned int uiLine;

	enum
	{
		BUTTON_CONTINUE,
		BUTTON_IGNORE,
		BUTTON_IGNORE_ALL,
		BUTTON_BREAK,
		BUTTON_STOP,
		BUTTON_REPORT_AS_BUG,
	} btnChosen;

	unsigned int uiX;
	unsigned int uiY;
};

//-----------------------------------------------------------------------------------------------------

static INT_PTR CALLBACK DlgProc(HWND _hDlg, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	static THREADLOCAL SCryAssertInfo* pAssertInfo;
	switch (_uiMsg)
	{
	case WM_INITDIALOG:
		{
			pAssertInfo = (SCryAssertInfo*)_lParam;

			SetWindowTextA(GetDlgItem(_hDlg, IDC_CRYASSERT_EDIT_CONDITION), pAssertInfo->pszCondition);
			SetWindowTextA(GetDlgItem(_hDlg, IDC_CRYASSERT_EDIT_FILE), pAssertInfo->pszFile);

			char szLine[MAX_PATH];
			sprintf(szLine, "%d", pAssertInfo->uiLine);
			SetWindowTextA(GetDlgItem(_hDlg, IDC_CRYASSERT_EDIT_LINE), szLine);

			if(pAssertInfo->pszMessage && pAssertInfo->pszMessage[0] != '\0')
			{
				SetWindowTextA(GetDlgItem(_hDlg, IDC_CRYASSERT_EDIT_REASON), pAssertInfo->pszMessage);
			}
			else
			{
				SetWindowTextA(GetDlgItem(_hDlg, IDC_CRYASSERT_EDIT_REASON), "No Reason");
			}

			SetWindowPos(_hDlg, HWND_TOPMOST, pAssertInfo->uiX, pAssertInfo->uiY, 0, 0, SWP_SHOWWINDOW | SWP_NOSIZE);
		}
		break;

	case WM_COMMAND:
		{
			switch (LOWORD(_wParam))
			{
			case IDCANCEL:
			case IDC_CRYASSERT_BUTTON_CONTINUE:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_CONTINUE;
				EndDialog(_hDlg, 0);
				break;

			case IDC_CRYASSERT_BUTTON_IGNORE:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_IGNORE;
				EndDialog(_hDlg, 0);
				break;

			case IDC_CRYASSERT_BUTTON_IGNORE_ALL:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_IGNORE_ALL;
				EndDialog(_hDlg, 0);
				break;

			case IDC_CRYASSERT_BUTTON_BREAK:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_BREAK;
				EndDialog(_hDlg, 0);
				break;

			case IDC_CRYASSERT_BUTTON_STOP:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_STOP;
				EndDialog(_hDlg, 1);
				break;

			case IDC_CRYASSERT_BUTTON_REPORT:
				pAssertInfo->btnChosen = SCryAssertInfo::BUTTON_REPORT_AS_BUG;
				EndDialog(_hDlg, 0);
				break;
			}
		}
		break;

	case WM_DESTROY:
		{
			if(pAssertInfo)
			{
				RECT rcWindowBounds;
				GetWindowRect(_hDlg, &rcWindowBounds);
				pAssertInfo->uiX = rcWindowBounds.left;
				pAssertInfo->uiY = rcWindowBounds.top;
			}
		}
		break;

	default:
		return FALSE;
	}

	return TRUE;
}

//-----------------------------------------------------------------------------------------------------

static THREADLOCAL char gs_szMessage[MAX_PATH];

//-----------------------------------------------------------------------------------------------------

void CryAssertTrace(const char *_pszFormat,...)
{
	if (gEnv == 0)
	{
		return;
	}
	if(!gEnv->bIgnoreAllAsserts || gEnv->bTesting)
	{
		if(NULL == _pszFormat)
		{
			gs_szMessage[0] = '\0';
		}
		else
		{
			va_list args;
			va_start(args, _pszFormat);
			vsnprintf_s(gs_szMessage, sizeof(gs_szMessage), _TRUNCATE, _pszFormat,args);
			va_end(args);
		}
	}
}

//-----------------------------------------------------------------------------------------------------

static const char* gs_strRegSubKey	= "Software\\Crytek\\AssertWindow";
static const char* gs_strRegXValue	= "AssertInfoX";
static const char* gs_strRegYValue	= "AssertInfoY";

//-----------------------------------------------------------------------------------------------------

void RegistryReadUInt32(const char* _strSubKey,const char* _strRegName,unsigned int *_puiValue,unsigned int _uiDefault)
{
	HKEY hKey;
	RegCreateKeyExA(HKEY_CURRENT_USER, _strSubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	DWORD dwType;
	DWORD dwLength = sizeof(DWORD);

	if(ERROR_SUCCESS != RegQueryValueExA(hKey, _strRegName, 0, &dwType, (BYTE*)_puiValue, &dwLength))
	{
		*_puiValue = _uiDefault;
	}

	RegCloseKey(hKey);
}

//-----------------------------------------------------------------------------------------------------

void RegistryWriteUInt32(const char* _strSubKey,const char* _strRegName,unsigned int _uiValue)
{
	HKEY hKey;
	RegCreateKeyExA(HKEY_CURRENT_USER, _strSubKey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);
	RegSetValueExA(hKey, _strRegName, 0, REG_DWORD, (BYTE*)&_uiValue, sizeof(DWORD));
	RegCloseKey(hKey);
}

//-----------------------------------------------------------------------------------------------------

class CCursorShowerWithStack
{
public:
	void StoreCurrentAndShow()
	{
		m_numberOfShows = 1;

		while (ShowCursor(TRUE) < 0)
		{
			++m_numberOfShows;
		}
	}

	void RevertToPrevious()
	{
		while (m_numberOfShows > 0)
		{
			ShowCursor(FALSE);
			--m_numberOfShows;
		}
	}

private:
	int m_numberOfShows;
};

bool CryAssert(const char* _pszCondition, const char* _pszFile, unsigned int _uiLine, bool* _pbIgnore)
{
	if(!gEnv)
	{
		return false;
	}

	if (!gEnv->bNoAssertDialog && !gEnv->bIgnoreAllAsserts)
	{
		SCryAssertInfo assertInfo;

		assertInfo.pszCondition = _pszCondition;
		assertInfo.pszFile      = _pszFile;
		assertInfo.pszMessage   = gs_szMessage;
		assertInfo.uiLine       = _uiLine;
		assertInfo.btnChosen    = SCryAssertInfo::BUTTON_CONTINUE;

		gEnv->pSystem->SetAssertVisible(true);
		RegistryReadUInt32(gs_strRegSubKey, gs_strRegXValue, &assertInfo.uiX, 10);
		RegistryReadUInt32(gs_strRegSubKey, gs_strRegYValue, &assertInfo.uiY, 10);

		CCursorShowerWithStack cursorShowerWithStack;
		cursorShowerWithStack.StoreCurrentAndShow();

		DialogBoxIndirectParam(GetModuleHandle(NULL), (DLGTEMPLATE*)&g_dialogRC, GetDesktopWindow(), DlgProc, (LPARAM)&assertInfo);

		cursorShowerWithStack.RevertToPrevious();

		RegistryWriteUInt32(gs_strRegSubKey, gs_strRegXValue, assertInfo.uiX);
		RegistryWriteUInt32(gs_strRegSubKey, gs_strRegYValue, assertInfo.uiY);
		gEnv->pSystem->SetAssertVisible(false);

		switch (assertInfo.btnChosen)
		{
		case SCryAssertInfo::BUTTON_IGNORE:
			*_pbIgnore = true;
			break;
		case SCryAssertInfo::BUTTON_IGNORE_ALL:
			gEnv->bIgnoreAllAsserts = true;
			break;
		case SCryAssertInfo::BUTTON_BREAK:
			return true;
		case SCryAssertInfo::BUTTON_STOP:
			abort();
			return true;
		case SCryAssertInfo::BUTTON_REPORT_AS_BUG:
			if (gEnv && gEnv->pSystem)
			{
				const char *pszSafeMessage = (assertInfo.pszMessage && assertInfo.pszMessage[0]) ? assertInfo.pszMessage : "<no reason>";
				gEnv->pSystem->ReportBug("Assert: %s - %s", assertInfo.pszCondition, pszSafeMessage);
			}
			break;
		}
	}
	if (gEnv)
	{
		gEnv->pSystem->OnAssert(_pszCondition, gs_szMessage, _pszFile, _uiLine);
	}
	return false;
}

#endif // defined(USE_CRY_ASSERT) && CRY_PLATFORM_WINDOWS
