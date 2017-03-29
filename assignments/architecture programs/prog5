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
       cmp  al,13
	   je   done
	   
	   and  al,31
	   
	   mov  bl,al
	   and  al,24
	   and  bl,7
	   
	   shr  al,1
	   shl  bl,1
	   
	   or   al,65
	   or   bl,65
	   
	   mov  dl,al
	   mov  ah,2
	   int  21h
	   
	   mov  dl,bl
	   mov  ah,2
	   int  21h
	   
	   jmp  lup
		 
done:       
       mov  ah,4ch
	   int  21h
	   END  Main
```
