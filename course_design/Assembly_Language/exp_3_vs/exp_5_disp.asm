.686
.387
.model flat, stdcall
option casemap :none

;######################################
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\user32.inc
include \masm32\include\shlwapi.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\shlwapi.lib
;######################################
public disp
public result
_sprintf typedef PROTO C:DWORD, :VARARG
sprintf typedef ptr _sprintf
;######################################

.data
	cp db 'windows 2015', 0
	dll_name db 'msvcrt.dll', 0
	fuc_name db 'sprintf', 0
	message db '浮点数的结果是：%f', 0

	result dq 0

	fuc_addr sprintf ?
	buf db 256 dup(?)
	
.code
disp proc c
	invoke LoadLibrary, addr dll_name
	invoke GetProcAddress, eax, addr fuc_name
	mov fuc_addr, eax
	invoke fuc_addr, addr buf, addr message, result
	invoke MessageBox, NULL, addr buf, addr cp, MB_OK
	ret
disp endp
end