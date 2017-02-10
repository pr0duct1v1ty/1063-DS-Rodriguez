/**
* @ProgramName: Homework 1 - EndSert Method
* @Author: Ricardo Rodriguez
* @Description: 
*     This program runs several random numbers into a list and prints them out
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 02 08 1998
*/
#include <iostream>

struct Node {
	int Data;
	Node *Next;
};

using namespace std;


class List {
private:
	Node *Head;
	Node *Tail;
public:
	List() {
		Head = NULL;
		Tail = NULL;
	}

	void FrontSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Head) {
			Temp->Next = Head;
		}
		else {
			Tail = Temp;
		}

		Head = Temp;

	}

	void PrintList() {
		if (!Head) {
			cout << "Empty" << endl;
			return;
		}
		else {
			Node *Temp = Head;
			while (Temp != NULL) {
				cout << Temp->Data << "->";
				Temp = Temp->Next;
			}
		}
	}
	/**
* @FunctionName: EndSert
* @Description: 
*    
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
	void EndSert(int x) {
		Node *Temp = new Node;
		Temp->Data = x;
		Temp->Next = NULL;

		if (Tail != NULL) {
			Tail->Next = Temp;
		}
		else
		{
			Head = Temp;
		}

		Tail = Temp;

	}

};


int main() {
	srand(97097807);
	List L;
	for (int i = 0; i<10; i++) {
		L.EndSert(rand() % 100);
	}
	L.PrintList();

	system("Pause");
	return 0;
}
