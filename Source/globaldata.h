/*
AutoHotkey

Copyright 2003 Chris Mallett

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
*/

#ifndef globaldata_h
#define globaldata_h

#include "hook.h" // For KeyHistoryItem and probably other things.
#include "clipboard.h"  // For the global clipboard object
#include "script.h" // For the global script object and g_ErrorLevel
#include "os_version.h" // For the global OS_Version object

extern HINSTANCE g_hInstance;
extern bool g_DestroyWindowCalled;
extern HWND g_hWnd;  // The main window
extern HWND g_hWndEdit;  // The edit window, child of main.
extern HWND g_hWndSplash;  // The SplashText window.
extern HFONT g_hFontSplash;
extern HACCEL g_hAccelTable; // Accelerator table for main menu shortcut keys.
extern WNDPROC g_TabClassProc;

extern modLR_type g_modifiersLR_logical;   // Tracked by hook (if hook is active).
extern modLR_type g_modifiersLR_logical_non_ignored;
extern modLR_type g_modifiersLR_physical;  // Same as above except it's which modifiers are PHYSICALLY down.
extern modLR_type g_modifiersLR_persistent; // Maintained by SendKeys().

#ifdef FUTURE_USE_MOUSE_BUTTONS_LOGICAL
extern WORD g_mouse_buttons_logical; // A bitwise combination of MK_LBUTTON, etc.
#endif

#define STATE_DOWN 0x80
#define STATE_ON 0x01
extern BYTE g_PhysicalKeyState[VK_ARRAY_COUNT];

// If a SendKeys() operation takes longer than this, hotkey's modifiers won't be pressed back down:
extern int g_HotkeyModifierTimeout;

extern HHOOK g_KeybdHook;
extern HHOOK g_MouseHook;
#ifdef HOOK_WARNING
	extern HookType sWhichHookSkipWarning;
#endif
extern bool g_ForceLaunch;
extern bool g_WinActivateForce;
extern SingleInstanceType g_AllowOnlyOneInstance;
extern bool g_persistent;
extern bool g_NoTrayIcon;
#ifdef AUTOHOTKEYSC
	extern bool g_AllowMainWindow;
#endif
extern bool g_AllowSameLineComments;
extern char g_LastPerformedHotkeyType;
extern bool g_AllowInterruption;
extern bool g_MainTimerExists;
extern bool g_UninterruptibleTimerExists;
extern bool g_AutoExecTimerExists;
extern bool g_InputTimerExists;
extern bool g_SoundWasPlayed;
extern bool g_IsSuspended;
extern int g_nLayersNeedingTimer;
extern int g_nThreads;
extern int g_nPausedThreads;
extern bool g_UnpauseWhenResumed;

extern VarSizeType g_MaxVarCapacity;
// This value is the absolute limit:
#define MAX_THREADS_LIMIT 20
#define MAX_THREADS_DEFAULT 10
extern UCHAR g_MaxThreadsPerHotkey;
extern int g_MaxThreadsTotal;
extern int g_MaxHotkeysPerInterval;
extern int g_HotkeyThrottleInterval;
extern bool g_MaxThreadsBuffer;

extern MenuTypeType g_MenuIsVisible;
extern int g_nMessageBoxes;
extern int g_nInputBoxes;
extern int g_nFileDialogs;
extern int g_nFolderDialogs;
extern InputBoxType g_InputBox[MAX_INPUTBOXES];
extern SplashType g_Progress[MAX_PROGRESS_WINDOWS];
extern SplashType g_SplashImage[MAX_SPLASHIMAGE_WINDOWS];
EXTERN_GUI;
extern HWND g_hWndToolTip[MAX_TOOLTIPS];

extern bool g_SortCaseSensitive;
extern bool g_SortNumeric;
extern bool g_SortReverse;
extern int g_SortColumnOffset;

extern char g_delimiter;
extern char g_DerefChar;
extern char g_EscapeChar;

// Hot string vars:
extern char g_HSBuf[HS_BUF_SIZE];
extern int g_HSBufLength;
extern HWND g_HShwnd;

// Hot string global settings:
extern int g_HSPriority;
extern int g_HSKeyDelay;
extern bool g_HSCaseSensitive;
extern bool g_HSConformToCase;
extern bool g_HSDoBackspace;
extern bool g_HSOmitEndChar;
extern bool g_HSSendRaw;
extern bool g_HSEndCharRequired;
extern bool g_HSDetectWhenInsideWord;
extern char g_EndChars[HS_MAX_END_CHARS + 1];

// Global objects:
extern Var *g_ErrorLevel;
extern input_type g_input;
EXTERN_SCRIPT;
EXTERN_CLIPBOARD;
EXTERN_OSVER;

extern int g_IconTray;
extern int g_IconTraySuspend;

extern DWORD g_OriginalTimeout;

EXTERN_G;
extern global_struct g_default;

extern char g_WorkingDir[MAX_PATH];  // Explicit size needed here in .h file for use with sizeof().
extern char *g_WorkingDirOrig;

// This macro is defined because sometimes g.hWndLastUsed will be out-of-date and the window
// may have been destroyed.  It also returns NULL if the current settings indicate that
// hidden windows should be ignored:
#define g_ValidLastUsedWindow (!g.hWndLastUsed ? NULL\
	: (!IsWindow(g.hWndLastUsed) ? NULL\
	: ((!g.DetectHiddenWindows && !IsWindowVisible(g.hWndLastUsed)) ? NULL : g.hWndLastUsed)))

extern bool g_ForceKeybdHook;
extern ToggleValueType g_ForceNumLock;
extern ToggleValueType g_ForceCapsLock;
extern ToggleValueType g_ForceScrollLock;

extern ToggleValueType g_BlockInputMode;
extern bool g_BlockInput;  // Whether input blocking is currently enabled.

extern vk2_type g_sc_to_vk[SC_ARRAY_COUNT];
extern sc2_type g_vk_to_sc[VK_ARRAY_COUNT];

extern Action g_act[];
extern int g_ActionCount;
extern Action g_old_act[];
extern int g_OldActionCount;

extern key_to_vk_type g_key_to_vk[];
extern key_to_sc_type g_key_to_sc[];
extern int g_key_to_vk_count;
extern int g_key_to_sc_count;

extern KeyHistoryItem *g_KeyHistory;
extern int g_KeyHistoryNext;
extern DWORD g_HistoryTickNow;
extern DWORD g_HistoryTickPrev;
extern DWORD g_TimeLastInputPhysical;

#ifdef ENABLE_KEY_HISTORY_FILE
extern bool g_KeyHistoryToFile;
#endif

#endif
