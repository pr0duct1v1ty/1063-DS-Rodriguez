#Homework 3
###Ricardo Rodriguez - 1063 Data Structures - Spring 2017 - 27/02/2017

```cpp
/**
* @FunctionName: Print
* @Description: 
*     I added a Count variable to keep track of how many times the while loop repeated in the
*     case that the Queue was full
* @Params:
*    NONE
* @Returns:
*    NONE
*/
void Print(){
    //FIX ME!
    int Index = Front;
    int Count = ArraySize;

    while(Full() && Count > 0 || Full() == false && Index != Rear){
      cout<<Q[Index]<<" ";
      Index = ((Index + 1) % (ArraySize));
      Count--;
    }
    cout<<endl;
  }
```
