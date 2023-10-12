.686
.387
.model flat, stdcall
option casemap :none ;关闭大小写

;######################################
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\shlwapi.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\shlwapi.lib
includelib \test\exp_5_disp.lib
;######################################
extrn result:qword
extrn disp:near
;######################################

.data
	l1   REAL8  0.000001
	c1   REAL8  0.000001
	two  DD     2
	sum  DD     ?
	arr equ this byte
		count = 1
		REPT 9
		DD count
		count = count + 1
		ENDM

.code
main:
	lea esi, arr
	mov ecx, 0
	mov cl, 9
	cld
	mov eax, 0
	mov ebx, 0
loop_1:
	;循环计算1-9的加和，保存至sum对应内存中
	lodsd
	add ebx, eax
	loop loop_1
	mov sum, ebx

	fld l1
	fmul c1
	fsqrt
	fimul two
	fldpi
	fmul
	fld1
	fdivr
	fimul sum
	fstp result

	call disp

	invoke ExitProcess, NULL

	end main