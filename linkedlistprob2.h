#include <iostream>

using namespace std;


//bool insertAtHead(int data)
//
//insert the data at headand return true if insertion is successful otherwise return
//false.
//
//2. bool insertAtEnd(int data)
//
//insert the data at end and return true if insertion is successful otherwise return
//false.
//
//3. bool deleteMidNode()
//
//find the middle node, delete itand return true.
//
//4. void display()
//5. bool isPalindrome()
//
//return true if the list is palindrome otherwise return false.
//
//6. int middleNode()
//
//find the middle node and return the index of it.
//
//7. Node * createLeftList(int mid_node)
//return the head of newly created list.
//8. Node * createRightList(int mid_node)
//return the head of newly created list.
//
//9. int sumAll()
//
//find the sum of the list and return it.

class node {
	int data;
	node* next;
	node* prev;
public:
	node() {
		this->data = 0;
		this->next = NULL;
		this->prev = NULL;

	}
	node(int data, node* next, node* prev) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
	void setdata(int data) {
		this->data = data;

	}
	void setnext(node* next) {
		this->next = next;
	}
	void setprev(node *prev) {
		this->prev = prev;
	}
	int getdata() {
		return this->data;
	}
	node* getnext() {
		return next;

	}
	node* getprev() {
		return prev;

	}
};

class LinkedList {
	node* head;
public:
	LinkedList() {
		this->head = NULL;
	}
	void sethead(node* t) {
		this->head = t;
	}
	node* gethead() {
		return head;
	}
	//void insertnode(int v) {
	//	node* temp = new node();
	//	temp->data = v;
	//	temp->next = NULL;
	//	temp->prev = NULL;
	//}
	bool insertAtHead(int v) {
		if (head == NULL) {
			head = new node();
			head->setdata(v);
			return true;
		}
		else {
			node* temp = new node();
			head->setprev(temp);
			temp->setnext(head);
			head = temp;
			return true;
		}
		return false;
	}

	bool insertAtEnd(int v) {
		if (head == NULL) {
			head = new node();
			head->setdata(v);
			return true;
		}
		else {
			node* temp = new node();
			temp = head;
			while (temp->getnext() != NULL) {
				temp = temp->getnext(); 
			}
			node* newnode = new node();
			temp->setnext(newnode);
			newnode->setprev(temp);
			newnode->setdata(v);
			return true;

		}
	}


	bool deleteMidNode() {
		if (head == NULL) {
			cout << "empty list!!" << endl;
			return false;
		}
		else if (listsize() < 3)
			return false;
		else {
			node* temp = head;
			int count = 0, size = listsize() / 2;
			while (count < size) {
				temp = temp->getnext();
				count++;
			}
			temp->getprev()->setnext(temp->getnext());
			temp->getnext()->setprev(temp->getprev());
			delete temp;
			return true;
		}
	}
	bool isPalindrome() {
		if (head == NULL)
			return false;
		else {
			node* temp1 = head;
			node* temp2 = head;
			while (temp2->getnext() != NULL) {
				temp2 = temp2->getnext();
			}
			while ((temp1 != temp2) && (temp1->getdata() == temp2->getdata())) {
				temp1 = temp1->getnext();
				temp2 = temp2->getprev();
			}
			if (temp1 == temp2)
				return true;
			else
				return false;
		}
	}
	int listsize() {
		int size = 0;
		if (head != NULL) {
			node* temp = head;
			while (temp != NULL) {
				temp = temp->getnext();
				size++;
			}
		}
		return size;
	}

	int middleNode() {
		if (head != NULL)
			return listsize() / 2;
		return 0;
	}

	node* createLeftList(int midnode) {
		if (isPalindrome() && midnode != 0) {
			LinkedList l;
			node* temp = head;
			int ind = 0;
			while (ind < midnode) {
				l.insertAtEnd(temp->getdata());
				temp = temp->getnext();
				ind++;
			}
			return l.gethead();
		}
	}

	node* createRightList(int midnode) {
		if (isPalindrome() && midnode != 0) {
			LinkedList l;
			node* temp = head;
			int ind = 0;
			while (ind <= midnode) {
				temp = temp->getnext();
				ind++;
			}
			while (temp != NULL) {
				l.insertAtEnd(temp->getdata());
				temp = temp->getnext();
			}
			return l.gethead();
		}
	}

	int sumAll() {
		if (head == NULL) {
			return -1;
		}
		else {
			node* temp = head;
			int sum = 0;
			while (temp != NULL) {
				sum += temp->getdata();
				temp = temp->getnext();
			}
			return sum;
		}
	}



	void display() {
		node* temp = head;
		while (temp != NULL) {

			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
	}

};

