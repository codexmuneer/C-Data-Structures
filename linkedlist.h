#include <iostream>
#include <string>
#include <fstream>
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
	void setnext(node *next) {
		this->next = next;
	}
	int getdata() {
		return this->data;
	}
	node *getnext() {
		return next;

	}
};

class linkedlist {
	node* head;
public:
	linkedlist() {
		this->head = NULL;
	}

	void setvalues(node* head) {
		this->head = head;
	}

	node* getvalue() {
		return head;
	}

	void insertathead(int num) {
		if (head == NULL) {
			head = new node();
			head->setdata(num);
		}
		else {
			node* temp = new node();
			temp->setnext(head);
			head = temp;
			head->setdata(num);
		}
	}
	void insertdata() {
		int num;
		fstream file;
		file.open("Numbers.txt", ios::in);
		while(file){
			file >> num;
			insertathead(num);
		}

		}


	bool isempty() {
		if (head == NULL) {
			return true;
		}
		else {
			return false;
		}
		
	}

	int checksize() {
		int count = 0;
		node* temp = head;
		while (temp != NULL) {
			count += 1;
			temp->getnext();
		}

		return count;
	}


	void searchnreplace( int n,int r) {
		node* temp = head;
		while (temp != head) {
			if (temp->getdata() == n) {
				temp->setdata(r);
			}
			temp->getnext();
		}
	}

	void Delete() {
		node* temp;
		temp = head;
		while (temp != NULL){
			temp->getnext();
			delete(temp);
			temp = head;
			}
	}
};

