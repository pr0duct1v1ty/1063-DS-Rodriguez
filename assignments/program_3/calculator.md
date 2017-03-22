```cpp
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// array based Stack class
class Stack {
private:
	char *S;
	int top;
	int size;
public:
	Stack(int s) {
		size = s;
		top = -1;
		S = new char[size];
	}
	void push(char x) {
		if (!full()) {
			S[++top] = x;
		}
		else {
			cout << "Stack Overflow!" << endl;
		}
	}
	char pop() {
		if (!empty())
			return S[top--];
		else
			return -1;
	}
	void printStack() {
		for (int i = top; i >= 0; i--) {
				cout << S[i] << " ";
		}
		cout << endl;
	}
	bool empty() {
		return top == -1;
	}
	bool full() {
		return top == size - 1;
	}
	char Top() {
		return S[top];
	}
};
// array based Queue class
class Queue {
private:
	int ArraySize;
	char *Q;
	int Front;
	int Rear;
	int NumItems;
public:
	Queue(int size) {
		ArraySize = size;
		Q = new char[ArraySize];
		Front = Rear = NumItems = 0;
	}
	void Push(char value) {
		Q[Rear++] = value;
		NumItems++;
	}
	char Pop() {
		char Temp = Q[Front++];
		NumItems--;
		return Temp;
	}
	bool Empty() {
		return (NumItems == 0);
	}
	bool Full() {
		return (NumItems == ArraySize);
	}
	void Print() {
		for (int i = Front; i < NumItems + Front; i++) {
			cout << Q[i] << " ";
		}
		cout << endl;
	}
};
// converts infix to postfix
Queue toPostFix(string infix)
{
	Stack InFix(100);
	Queue PostFix(100);

	InFix.push('(');
	infix.resize(infix.length() + 1);
	infix[infix.length() - 1] = ')';
	for (unsigned int i = 0; i < infix.length(); i++)
	{
		if (!InFix.empty() && infix[i] != ' ')
		{
			if (infix[i] >= 48 && infix[i] <= 57)
				PostFix.Push(infix[i]);
			else if (infix[i] == '(')
				InFix.push(infix[i]);
			else if (infix[i] >= 42 && infix[i] <= 47 || infix[i] == 37 || infix[i] == 94)
			{
				while (InFix.Top() != 'z' && InFix.Top() != '(')
				{
					if (infix[i] == '+' || infix[i] == '-')
					{
						PostFix.Push(InFix.pop());
						if (InFix.Top() == '(')
							InFix.push('z');
					}
					else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
					{
						if (InFix.Top() != '+' && InFix.Top() != '-')
							PostFix.Push(InFix.pop());
						if (InFix.Top() == '+' || InFix.Top() == '-' || InFix.Top() == '(')
							InFix.push('z');
					}
					else if (infix[i] == '^')
					{
						if (InFix.Top() == '^')
							PostFix.Push(InFix.pop());
						if (InFix.Top() != '^')
							InFix.push('z');
					}
//					cout << "error" << endl;

				}
				if (InFix.Top() == 'z')
					InFix.pop();
				InFix.push(infix[i]);
//				cout << "done2" << endl;

			}
			else if (infix[i] == ')')
			{
				while (InFix.Top() != '(')
				{
					PostFix.Push(InFix.pop());
					//					cout << "error" << endl;
				}
				InFix.pop();
				//				cout << "done3" << endl;

			}
			//			InFix.printStack();
			//			PostFix.Print();
		}

	}

	return PostFix;
}
// evaluates postfix and returns and integer answer
int evaluatePostFix(Queue PostFix)
{
	Stack Order(100);
	int x, y, integerValue;
	int Answer;
	char next;
	
	while (!PostFix.Empty())
	{
		next = PostFix.Pop();

		if (next >= 48 && next <= 57) {
			integerValue = next - 48;
			Order.push(integerValue);
		}
		else if (next >= 42 && next <= 47 || next == 37 || next == 94)
		{
			y = Order.pop();
			x = Order.pop();

			switch (next)
			{
			case '+':
				Order.push(x + y);
				break;
			case '-':
				Order.push(x - y);
				break;
			case '*':
				Order.push(x * y);
				break;
			case '/':
				Order.push(x / y);
				break;
			case '^':
				Order.push(x ^ y);
				break;
			case '%':
				Order.push(x % y);
				break;
			default:
				break;
			}
		}
	}

	Answer = Order.pop();
	return Answer;
}
// inputs a string in infix expression then converts it to postfix and evalutes the expression and output it to the file "Output.txt"
int main() {
	ofstream Output;
	Output.open("Output.txt", ios::out | ios::app);

	string infixString;
	Queue postfix(20);
	int answer;

	getline(cin, infixString);
	postfix = toPostFix(infixString);
	answer = evaluatePostFix(postfix);

	Output << infixString << " = " << answer << endl;

	Output.close();
}
```
