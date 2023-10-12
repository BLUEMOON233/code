.686
.387
.model flat, stdcall
option casemap :none ;�رմ�Сд

;######################################
include windows.inc
include kernel32.inc
include shlwapi.inc
includelib kernel32.lib
includelib shlwapi.lib
;######################################

.data
	l1   REAL8  0.000001
	c1   REAL8  0.000001
	two  DD     2
	res  REAL8  ?
	sum  DD     ?

	arr equ this byte
	count = 1
	REPT 9
	DD count
	count = count + 1
	ENDM

.code
start:
	lea esi, arr
	mov ecx, 0
	mov cl, 9
	cld
	mov eax, 0
	mov ebx, 0
loop_1:
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
	fstp res

	invoke ExitProcess, 0
	end start