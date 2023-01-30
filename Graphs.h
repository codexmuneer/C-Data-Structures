#include <iostream>
#include <fstream>
using namespace std;


class node1 {

	int data;
	node1* next;

public:
	node1() { data = 0; next = NULL; }
	node1(int v) {

		data = v;
	}

	void setdata(int  v) {

		data = v;
	}

	void setnext(node1* v) {
		next = v;
	}

	node1* getnext() {

		return next;
	}
	int getdata() {

		return data;
	}


};



class Stack : public node1 {
	node1* head;
public:
	Stack() {
		head = NULL;
	}
	void sethead(node1* head) {
		this->head = head;
	}
	node1* gethead() {
		return this->head;
	}

	void push(int v) {
		if (head == NULL) {
			head = new node1();
			head->setdata(v);
			return;
		}
		node1* temp = new node1();
		temp->setnext(head);
		temp->setdata(v);
		head = temp;

	}
	char peek() {
		node1* temp = head;
		return temp->getdata();
	}

	void pop() {
		if (head != NULL) {
			node1* temp = head;
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

};

class Queue : public node1 {

	node1* front;
	node1* rear;

public:

	Queue() {

		front = NULL;
		rear = NULL;
	}

	void enQueue(int x) {

		if (isEmpty()) {
			rear = new node1(x);
			front = rear;
		}
		else {
			rear->setnext(new node1(x));
			rear = rear->getnext();
		}

	}

	int deQueue()
	{
		int x;

		if (front == NULL) {
			return 0;
		}

		node1* temp = front;
		if (front == rear) {
			front = rear = NULL;
		}
		else {
			x = front->getdata();
			front = front->getnext();
		}

		delete (temp);

		return x;
	}

	int showFront() {
		if (front == NULL) {
			return 0;
		}
		return front->getdata();
	}

	int showRear() {
		if (rear == NULL) {
			return 0;
		}
		return rear->getdata();
	}

	bool isEmpty() {
		if (front == NULL && rear == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	int sizeofQueue() {
		node1* temp = front;
		int count = 0;
		while (temp != NULL) {
			count += 1;
			temp = temp->getnext();
		}

		return count;
	}

	void display() {
		node1* temp = front;
		while (temp != NULL) {
			cout << temp->getdata() << " ";
			temp = temp->getnext();
		}
	}



};



// Structure of Linked Lists
struct node {
	int data;
	int weight;
	node* next;
};

class Graph
{
public:
	// Pointer To Pointer Array
	node** head;
	bool* visited;
	// Array of pointers to info struct
	// of size


	Graph(int size) {
		head = new node * [size];
		// Initialize pointer array to NULL
		for (int i = 0; i < size; ++i) {
			*(head + i) = NULL;
		}
		visited = new bool[size];
		for (int i = 0; i < size; i++) {
			visited[i] = false;
		}
	}

	void addEdge(int x, int y) {
		node* n1 = new node;
		node* n2 = new node;
		n1->data = y;
		n1->next = NULL;
		n2->data = x;
		n2->next = NULL;

		if (*(head + x) == NULL) {
			*(head + x) = n1;
			*(head + (n1->data)) = n2;
		}
		else {
			node* temp1 = *(head + x);
			while (temp1->next != NULL) {
				temp1 = temp1->next;
			}
			temp1->next = n1;
			if (*(head + (n1->data)) == NULL) {
				*(head + (n1->data)) = n2;
			}
			else {
				node* temp2 = *(head + (n1->data));
				while (temp2->next != NULL) {
					temp2 = temp2->next;
				}
				temp2->next = n2;
			}

		}


	}

	void BFS(int startVertex, int size) {
		Queue q;
		visited[startVertex] = true;
		q.enQueue(startVertex);

		while (!q.isEmpty()) {
			int currVertex = q.showFront();
			cout << "Visited " << currVertex << " ";
			q.deQueue();
			node* temp = *(head + currVertex);
			while (temp != NULL) {
				int adjVertex = temp->data;
				if (!visited[adjVertex]) {
					visited[adjVertex] = true;
					q.enQueue(adjVertex);
				}
				temp = temp->next;
			}
		}

	}


	void DFS(int startVertex) {


		visited[startVertex] = true;
		node* temp = *(head + startVertex);
		cout << startVertex << " ";


		while (temp != NULL) {
			int adjVertex = temp->data;
			if (!visited[adjVertex])
				DFS(adjVertex);
			temp = temp->next;
		}


	}


	int VertexDegree(int v) {
		int count = 0;
		node* temp = *(head + v);
		while (temp != NULL) {
			count += 1;
			temp = temp->next;
		}


		return count;

	}



	void showGraphStructure(int size) {
		// Print the array of linked list

		for (int i = 0; i < size; ++i) {
			node* temp = *(head + i);

			// Linked list number
			cout << i << "-->\t";

			// Print the Linked List
			while (temp != NULL) {
				cout << temp->data << " " ;
				temp = temp->next;
			}

			cout << '\n';
		}

	}

};
