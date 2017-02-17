##Ricardo Rodriguez
###Part 1
---
###Q1: Trace A('C')

|Case |ch = |
|:---:|:---:|
|1    |C    |
|2    |B    |
|3    |A    |
|4    |@    |
**Output:**
>A  
>B  
>C

---

###Q2: Trace A('3')

|Case |ch = |
|:---:|:---:|
|1    |3    |
**Output**
>empty

---

###Q3: Trace B(4)

|Case |n =  |Returns|
|:---:|:---:|:-----:|
|1    |4    |24     |
|2    |3    |6      |
|3    |2    |2      |
|4    |1    |1      |
|5    |0    |1      |
**Output:**
>4  
>3  
>2  
>1

---

###Q4: Trace C(16)

|Case |n =  |Returns|
|:---:|:---:|:-----:|
|1    |16   |4      |
|2    |8    |3      |
|3    |4    |2      |
|4    |2    |1      |
|5    |1    |0      |
**Output:**
>16  
>8  
>4  
>2

---

###Q5: Trace D(-2365)

|Case |n =  |Returns|
|:---:|:---:|:-----:|
|1    |-2365|2      |
|2    |2365 |2      |
|3    |236  |2      |
|4    |23   |2      |
|5    |2    |2      |
**Output:**
>2365  
>236  
>23  
>2

---
###Part 2
---

###Q6: Write a function that will count the number of digits in a nonnegative integer. Trace for 5679.

```cpp
int NumDigits(int num){
    if (num <= 0)
        return 0;
    cout << num << endl;
    return 1 + NumDigits(num/10);
}
```

|Case |num =|Returns|
|:---:|:---:|:-----:|
|1    |5679 |4      |
|2    |567  |3      |
|3    |56   |2      |
|4    |5    |1      |
|5    |0    |0      |
**Output:**
>5679  
>567  
>56  
>5

---

###Q7: Write a function `MyPow()` - Which will raise a given number to a power. Trace for 2<sup>3</sup>.

```cpp
int MyPow(int base, int exp){
    if (exp == 0)
        return 1;
    cout << base << '^' << exp << endl;
    return base * MyPow(base,exp-1);
}
```

|Case |base=|pow =|Returns|
|:---:|:---:|:---:|:-----:|
|1    |2    |3    |8      |
|2    |2    |2    |4      |
|3    |2    |1    |2      |
|4    |2    |0    |1      |
**Output:**
>2^3  
>2^2  
>2^1

---

###Q8: Complete the function and trace for A[2,4,5,7,8,11]

```cpp
int SumArray(int A[], int n)
    // Return sum of A[0] + A[1] + … + A[n-1]
    if (n==0)
        return 0;
    cout << A[n-1] << endl;
    return A[n-1] + SumArray(A[],n-1);
    
)
```

|Case |n =  |Returns|
|:---:|:---:|:-----:|
|1    |6    |37     |
|2    |5    |26     |
|3    |4    |18     |
|4    |3    |11     |
|5    |2    |6      |
|6    |1    |2      |
|7    |0    |0      |
**Output:**
>11  
>8  
>7  
>5  
>4  
>2

---
