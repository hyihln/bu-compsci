	.intel_syntax noprefix
	.text
	.global reverse_asm

reverse_asm:
	push ebx

	mov eax, 0x0
	mov ebx, eax
	mov ecx, eax
	mov edx, eax

	#hex 0x8
	mov eax, [esp + 8]
	cmp eax, 0
	je null_ret

	#hex 0x12
	add eax, [esp + 12]
	mov ebx, eax

while_start:

	cmp ebx, 0x0
	je while_done

	mov ecx, [ebx]

	mov [ebx], edx

	mov edx, ebx

	mov ebx, ecx

	jmp while_start

while_done:

	mov eax, edx
	sub eax, [esp + 12]

null_ret:
	pop ebx
	ret
