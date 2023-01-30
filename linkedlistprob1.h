#include <iostream>


using namespace std;

class node {
	int data;
	node* next;
public:
	node() {
		this->data = 0;
		this->next = NULL;

	}
	node(int data, node* next) {
		this->data = data;
		this->next = next;
	}
	void setdata(int data) {
		this->data = data;

	}
	void setnext(node* next) {
		this->next = next;
	}
	int getdata() {
		return this->data;
	}
	node* getnext() {
		return next;

	}
};

class LinkedList {
	node* head;
public:
	LinkedList() {
		this->head = NULL;
	}

	void setvalues(node* head) {
		this->head = head;
	}

	node* getvalue() {
		return head;
	}

	bool insertAtEnd(int data) {
		if (head == NULL) {
			head = new node();
			head->setdata(data); 
				return true;
		}
		else {
			node* temp = new node();
			temp = head;
			while (temp->getnext() != NULL) {
				temp = temp->getnext();
			}
			node* x = temp->getnext();
			x = new node();
			x->setdata(data);
			return true;
		}
		return false;
	}

	bool insertAfter(int pvalue, int ivalue) {

		if (head == NULL) {
			return false;
		}
		else {

			node* temp = head;
			while (temp != NULL) {
			
				if (temp->getdata() == pvalue) {
					node* prev = temp->getnext();
					temp->setnext(new node());
					temp->getnext()->setdata(ivalue);
					temp->getnext()->setnext(prev);
					return true;
				}
				temp = temp->getnext();
				return true;
			}
			if (temp == NULL || temp->getdata() != pvalue)
			{
				return false;
			}

		}
		

	}


	bool deleteatstart() {
		if (head == NULL) {
			return false;
		}
		else {
			node *temp = head;
			while(head != NULL){
				head = head->getnext();
				delete temp;						
			}
			return true;
		}
	}

	bool deleteAtEnd() {
		if (head == NULL) {
			return false;
		}
		else {
			node* temp = head;
			while (temp->getnext()->getnext() != NULL) {
				temp = temp->getnext();
			}
			temp->setnext(NULL);
			return true;
		}
	}

	bool deletenode(int x){
		node* temp = head;
		node* prev = NULL;
		if (temp != NULL && temp->getdata() == x) {
			head = temp->getnext();
			delete temp;
			return true;
		}
		else {
			while (temp != NULL && temp->getdata() != x) {
				prev = temp;
				temp = temp->getnext();
			}

			if (temp == NULL) {
				return false;
			}
			prev->setnext(temp->getnext());
			delete temp;

			return true;
		}
	
	
	}



	void display() {
		node* temp = head;
		while (temp != NULL) {
			cout << temp->getdata() << endl;
			temp = temp->getnext();
		}


	}


};
