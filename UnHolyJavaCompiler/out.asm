.386
.model flat, stdcall
option casemap :none

include /masm32/include/kernel32.inc
includelib /masm32/lib/kernel32.lib

.data
.code
main:
invoke ExitProcess, 501
end main