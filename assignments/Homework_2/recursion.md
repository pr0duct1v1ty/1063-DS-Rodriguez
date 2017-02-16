##Ricardo Rodriguez
###Part 1

####Q1: Trace A('C')

A
B
C

####Q2: Trace A('3')

empty

####Q3: Trace B(4)

4
3
2
1

####Q4: Trace C(16)

16
8
4
2

####Q5: Trace D(-2365)

2365
236
23
2

###Part 2

####Q6: Write a function that will count the number of digits in a nonnegative integer. Trace for 5679.

```cpp
int NumDigits(int num){
    // Returns the "length" of an integer
    if (num <= 0)
      return 1 + NumDigits(num/10);
}
```
