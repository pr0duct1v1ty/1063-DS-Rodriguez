```assembly
;Ricardo Rodriguez
  .MODEL  small
  .STACK  100h
  .DATA
  .CODE
MAIN:  mov  ax,@data
       mov  ds,ax

lup:   
       mov  ah,1
	   int  21h
       cmp  al,13 ;13 = ascii return/enter key
	   je   done
	   mov  bh,al
	   
	   mov  ah,1
	   int  21h
       cmp  al,13 ;13 = ascii return/enter key
	   je   done
	   mov  bl,al
	   
	   and  bh,12 ;12 = 0000 1100
	   and  bl,14 ;14 = 0000 1110
	   
	   shl  bh,1
	   shr  bl,1
	   
	   or   bh,bl
	   add  bh,64 ;64 = 0100 0000
	   
	   mov  dl,bh
	   mov  ah,2
	   int  21h
	   
	   jmp  lup
		 
done:       
       mov  ah,4ch
	   int  21h
	   END  Main
```
