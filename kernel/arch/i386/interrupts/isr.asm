global isr0 
isr0:
  push 0    ; dummy error code
  push 0    ; interrupt index 
  call common_stub 

global isr1 
isr1: 
  push 0 ; dummy error code 
  push 1 ; interrupt index 
  call common_stub

global isr2
isr2: 
  push 0 ; dummy error code 
  push 2 ; interrupt index  
  call common_stub

global isr3
isr3: 
  push 0 ; dummy error code 
  push 3 ; interrupt index  
  call common_stub

global isr4
isr4: 
  push 0 ; dummy error code 
  push 4 ; interrupt index  
  call common_stub

global isr5
isr5: 
  push 0 ; dummy error code 
  push 5 ; interrupt index  
  call common_stub

global isr6
isr6: 
  push 0 ; dummy error code 
  push 6 ; interrupt index  
  call common_stub

global isr7
isr7: 
  push 0 ; dummy error code 
  push 7 ; interrupt index  
  call common_stub

global isr8
isr8: 
  push 8 ; interrupt index  
  call common_stub

global isr9
isr9: 
  push 0 ; dummy error code 
  push 9 ; interrupt index  
  call common_stub

global isr10
isr10: 
  push 10 ; interrupt index  
  call common_stub

global isr11
isr11: 
  push 11 ; interrupt index  
  call common_stub

global isr12
isr12: 
  push 12 ; interrupt index  
  call common_stub

global isr13
isr13:
  push 13 ; interrupt index 
  call common_stub

global isr14
isr14: 
  push 14 ; interrupt index  
  call common_stub

global isr15
isr15: 
  push 0 ; dummy error code 
  push 15 ; interrupt index  
  call common_stub

global isr16
isr16: 
  push 0 ; dummy error code 
  push 16 ; interrupt index  
  call common_stub

global isr17
isr17: 
  push 17 ; interrupt index  
  call common_stub

global isr18
isr18: 
  push 0 ; dummy error code 
  push 18 ; interrupt index  
  call common_stub

global isr19
isr19: 
  push 0 ; dummy error code 
  push 19 ; interrupt index  
  call common_stub

global isr20
isr20: 
  push 0 ; dummy error code 
  push 20 ; interrupt index  
  call common_stub

global isr21
isr21: 
  push 21 ; interrupt index  
  call common_stub

global isr22
isr22: 
  push 0 ; dummy error code 
  push 22 ; interrupt index  
  call common_stub

global isr23
isr23: 
  push 0 ; dummy error code 
  push 23 ; interrupt index  
  call common_stub

global isr24
isr24: 
  push 0 ; dummy error code 
  push 24 ; interrupt index  
  call common_stub

global isr25
isr25: 
  push 0 ; dummy error code 
  push 25 ; interrupt index  
  call common_stub

global isr26
isr26: 
  push 0 ; dummy error code 
  push 26 ; interrupt index  
  call common_stub

global isr27
isr27: 
  push 0 ; dummy error code 
  push 27 ; interrupt index  
  call common_stub

global isr28
isr28: 
  push 0 ; dummy error code 
  push 28 ; interrupt index  
  call common_stub

global isr29
isr29: 
  push 0 ; dummy error code 
  push 29 ; interrupt index  
  call common_stub

global isr30
isr30: 
  push 0 ; dummy error code 
  push 30 ; interrupt index  
  call common_stub

global isr31
isr31: 
  push 0 ; dummy error code 
  push 31 ; interrupt index  
  call common_stub

common_stub:
  ; testing isr 
  cli
  hlt
  
