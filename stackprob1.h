#include <iostream>


using namespace std;

class node {
	char data;
	node* next;
public:
	node() {
		this->data = ' ';
		this->next = NULL;

	}
	node(char data, node* next) {
		this->data = data;
		this->next = next;
	}
	void setdata(char data) {
		this->data = data;

	}
	void setnext(node* next) {
		this->next = next;
	}
	char getdata() {
		return this->data;
	}
	node* getnext() {
		return next;

	}
};

class Stack {
	node* head;
public:
	Stack() {
		head = NULL;
	}
	void sethead(node* head) {
		this->head = head;
	}
	node* gethead() {
		return this->head;
	}

	void push(int v) {
		if (head == NULL) {
			head = new node();
			head->setdata(v);
			return;
		}
		node* temp = new node();
		temp->setnext(head);
		temp->setdata(v);
		head = temp;
			
	}
	char peek() {
		node * temp = head;
		return temp->getdata();
	}

	void pop() {
		if (head != NULL) {
			node* temp = head;
			head = head->getnext();
			delete temp;
		}

	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	int checkprecedence(char op) {
		if (op == '+' || op == '-') {
			return 1;
		}
		else if (op == '*' || op == '/') {
			return 2;
		}
		else {
			return 0;
		}
	}

	bool checkoperand(char o) {
		if (o >= 'a' && o <= 'z' || o >= 'A' && o <= 'z') {
			return true;
		}
		else {
			return false;
		}
	}
	bool checkoperator(char o) {
		if (o == '+' || o == '-' || o == '*' || o == '/') {
			return true;
		}
		else {
			return false;
		}
	}

	string infixToPostfix(string input) {
		Stack s;
		string output = " ";
		for (int i = 0; i < sizeof(input); i++) {
			if (input[i] == '(') {
				s.push(input[i]);
			}
			else if (checkoperand(input[i]) == true) {
				output = output + input[i];
			}
			else if (checkoperator(input[i]) == true) {
				if (s.isEmpty()) {
					s.push(input[i]);
				}
				else {
					while (checkprecedence(input[i]) <= checkprecedence(s.peek())) {
						output = output + s.peek();
						s.pop();
					}

				}
				
			}
			else {
				while (s.peek() != '(') {
					output += s.peek();
					s.pop();
				}
				s.pop();
			}


			return output;

		}
	}




};
