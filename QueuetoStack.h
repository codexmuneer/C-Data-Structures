#include<iostream>
using namespace std;


class node {

	int data;
	node* next;

public:
	node() { data = 0; next = NULL; }
	node(int v) {

		data = v;
	}

	void setdata(int  v) {

		data = v;
	}

    void setnext(node* v) {
		next = v;
	}

	node* getnext() {

		return next;
	}
    int getdata() {

		return data;
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

    void display(){
        node* temp = front;
        while(temp != NULL){
            cout<<temp->getdata()<<" ";
            temp = temp->getnext();
        }
    }

	

};




 
class Stack {
    Queue q1, q2;
 
public:
    void push(int x)
    {
        q2.enQueue(x);
 
        while (!q1.isEmpty()) {
            q2.enQueue(q1.showFront());
            q1.deQueue();
        }
        Queue q = q1;
        q1 = q2;
        q2 = q;
    }
 
    void pop()
    {
        if (q1.isEmpty())
            return;
        q1.deQueue();
    }
 
    int peek()
    {
        if (q1.isEmpty()){
            return -1;
        }
            
        return q1.showFront();
    }
 
};
