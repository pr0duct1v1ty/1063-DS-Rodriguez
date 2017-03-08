```assembly
;Ricardo Rodriguez
  .MODEL  small
  .STACK  100h
  .DATA
TIE  DB  "it is a tie",13,10,'$'
NEW  DB  "New England wins",13,10,'$'
ATL  DB  "Atlanta wins",13,10,'$'
  .CODE
Main:  mov  ax,@data
       mov  ds,ax
	   ;start loop
	   mov  ch,0
	   
lup:
	   cmp  ch,3
	   je  done
	   ;get first 2 digit number(new england score)
	   mov  ah,1
	   int  21h
	   sub  al,30h
	   
	   mov  cl,10
	   mul  cl
	   
	   mov  bl,al
	   
	   mov  ah,1
	   int  21h
	   sub  al,30h
       ;stores first number (new england score) in bl
	   add  bl,al
	   ;get second 2 digit number (atlanta score)
	   mov  ah,1
	   int  21h
	   sub  al,30h
	   
	   mul  cl
	   
	   mov  bh,al
	   
	   mov  ah,1
	   int  21h
	   sub  al,30h
	   ;stores second number (atlanta score) in bh
	   add  bh,al
	   
	   cmp bh,bl
	   ;jump if bh (atlanta score) is greater than bl(new england score)
	   jg  alta
	   je  equal
	   
	   lea  dx,NEW
	   mov  ah,9
	   int  21h
	   jmp  endl
	   
alta:
       lea  dx,ATL
	   mov  ah,9
	   int  21h
	   jmp  endl
	   
equal:
       lea  dx,TIE
	   mov  ah,9
	   int  21h
	   
endl:
       add  ch,1
	   jmp  lup

done:
       mov  ah,4ch
	   int  21h
	   END  Main
```
