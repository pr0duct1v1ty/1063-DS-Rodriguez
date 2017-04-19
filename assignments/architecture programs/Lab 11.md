```assembly
;Ricardo Rodriguez
  .MODEL  small
  .STACK  100h
  .DATA
VAL    DB   30 DUP(?)
  .CODE
MAIN:  mov  ax,@data
       mov  ds,ax

	   lea  bx,VAL
lup:   
       mov  ah,1
	   int  21h
       cmp  al,13 ;13 = ascii return/enter key
	   je   done
	   mov  ch,al
	   
	   mov  ah,1
	   int  21h
       cmp  al,13 ;13 = ascii return/enter key
	   je   done
	   mov  cl,al
	   
	   and  ch,12 ;12 = 0000 1100
	   and  cl,14 ;14 = 0000 1110
	   
	   shl  ch,1
	   shr  cl,1
	   
	   or   ch,cl
	   add  ch,64 ;64 = 0100 0000
	   
;	   mov  dl,ch
;	   mov  ah,2
;	   int  21h

       mov  [bx],ch
	   add  bx,1
	   
	   jmp  lup
		 
done:  
       mov  dl,'$'
       mov  [bx],dl
	   
	   lea  dx,VAL
	   mov  ah,9
	   int  21h

       mov  ah,4ch
	   int  21h
	   END  Main
     ```
