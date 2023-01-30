#include<iostream>
#include<string>
using namespace std;



class node {

	int data;
	node* next;

public:
	node() { data = ' '; next = NULL; }
	node(char v) {

		data = v;
	}

	char getdata() {

		return data;
	}

	void setdata(char  v) {

		data = v;
	}

	node* getnext() {

		return next;
	}

	void setnext(node* v) {

		next = v;
	}
};


class Queue : public node {

	node* front;
	node* rear;

public:

	Queue() {

		front = NULL;
		rear = NULL;
	}

	void enQueue(int x) {

		if (isEmpty()) {
			rear = new node(x);
			front = rear;
		}
		else {
			rear->setnext(new node(x));
			rear = rear->getnext();
		}
		
	}

	void deQueue()
	{

		if (front == NULL) {
			return;
		}
			
		node* temp = front;
		if (front == rear) {
			front = rear = NULL;
		}
		else {
			front = front->getnext();
		}
		
		delete (temp);
	}

	int showFront() {
		if (front == NULL) {
			return 0;
		}
		return front->getdata();
	}

	bool isEmpty() {
		if (front == NULL && rear == NULL) {
			return true;
		}
		else {
			return false;
		}
	}


	

};

bool checkalpha(char o) {
	if (o >= 'a' && o <= 'z' || o >= 'A' && o <= 'Z') {
		return true;
	}
	else {
		return false;
	}
}

bool checknum(int n) {
	if (n >= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool checkop(char o) {
	if (o == '+' || o == '-' || o == '*' || o == '/') {
		return true;
	}
	else {
		return false;
	}
}
int checkprecedence(char o) {
	if (o == '+' || o == '-') {
		return 1;
	}
	else if (o == '*' || o == '/') {
		return 2;
	}
}
string decryptPassword(string exp) {
	Queue alphaQ, numberQ, optQ, optQ1;
	string s1, s2, s3;

	for (int i = 0; i < exp.length(); i++) {
		char x = exp[i];
		if (checkalpha(x)) {
			alphaQ.enQueue(x);
			s1 += x;
		}
		else if (checknum(x)) {
			numberQ.enQueue(x);
		}
		else if (checkop(x)) {
			optQ.enQueue(x);
		}
	}
	Queue* temp = &optQ;
	while (temp != NULL) {
		int num1, num2, r = 0;
		char c1, c2;
		num1 = numberQ.showFront();
		numberQ.deQueue();
		num2 = numberQ.showFront();
		numberQ.deQueue();
		cout << num1 << num2 << endl;
		c1 = optQ.showFront();
		optQ.deQueue();
		c2 = optQ.showFront();
		if (checkprecedence(c1) > checkprecedence(c2)) {
			if (c1 == '*')
			{
				r = num1 * num2;
			}
			else
			{
				r = num1 / num2;
			}
		}

		else if (checkprecedence(c1) < checkprecedence(c2)) {
			if (c1 == '+')
			{
				r = num1 - num2;
			}
			else
			{
				r = num1 + num2;
			}

		}

		return s1 + to_string(r) + to_string(c1) + to_string(c2);

	}


	

	return s1;
}


//string findSmallestSubsequence(string c) {
	//		int num1, num2, r = 0;
	//		char c1, c2;
	//		num1 = numberQ.showFront();
	//		numberQ.deQueue();
	//		num2 = numberQ.showFront();
	//		numberQ.deQueue();
	//		cout << num1 << num2 << endl;
	//		c1 = optQ.showFront();
	//		optQ.deQueue();
	//		c2 = optQ.showFront();
	//}
