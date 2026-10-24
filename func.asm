extern cbrtf : proc

.code

func proc
;int func(int a, int b, int s);

	mov eax, ecx

	cmp r8d, 1
	je _plus

	cmp r8d, 2
	je _minus

	cmp r8d, 3
	je _multiply

	cmp r8d, 4
	je _divide

	cmp r8d, 5
	je _raise

	xor eax, eax
	jmp _ret

_plus:
	add eax, edx
	jmp _ret

_minus:
	sub eax, edx
	jmp _ret

_multiply:
	imul eax, edx
	jmp _ret

_divide:
	cmp edx, 0
	je _ret_zero

	mov ecx, edx
	cdq
	idiv ecx
	jmp _ret

_raise:
	mov ecx, eax

	cmp edx, 0
	je _ret_one
	jl _ret_zero

	cmp edx, 1
	je _ret

_while_raise:
	imul eax, ecx
	dec edx

	cmp edx, 1
	je _ret
	jmp _while_raise

_ret_zero:
	xor eax, eax
	jmp _ret

_ret_one:
	mov eax, 1
	jmp _ret

_ret:
	ret

func endp


func_f proc
; float func_f(float a, float b, int s);

	divss xmm0, xmm1
	jmp _ret_f

_ret_f:
	ret

func_f endp


func_two proc
; int func_two(int a);

	mov eax, ecx

	cmp eax, 0
	jge _ret_t

	neg eax

_ret_t:
	ret

func_two endp

func_two_f proc
; float func_two_f(float a, int s);
    cmp  edx, 101
    je   _c

    cmp  edx, 102
    je   _k

    xorps xmm0, xmm0
    ret

_c:
    sqrtss xmm0, xmm0
    ret

_k:
    sub  rsp, 28h
    call cbrtf
    add  rsp, 28h

    ret

func_two_f endp

end

