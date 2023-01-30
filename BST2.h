#include <iostream>
using namespace std;



class node
{
public:
	int data;
	node* left;
	node* right;

	node()
	{
		data = 0;
		left = NULL;
		right = NULL;

	}
};

class BST
{
private:
	node* root;


	void display(node* root)
	{
		if (root == NULL)
		{
			return;
		}

		else
		{


			display(root->left);
			cout << root->data;
			display(root->right);

		}
	}


	bool del(node*& rt) {
		node* t = rt;
		if (rt->left == NULL && rt->right == NULL) {
			node* temp = rt;
			delete temp;
			rt->right = NULL;
		}
		else if (rt->left != NULL && rt->right != NULL) {
			node* temp2 = rt->right;
			while (temp2->left != NULL) {
				temp2 = temp2->left;
			}
			temp2->left = rt->left;

			temp2 = rt;
			rt = rt->right;

		}

	}



public:
	BST()
	{
		root = NULL;

	}
	void setroot(node * r) {
		root = r;

	}
	node* getroot() {
		return root;
	}

	void setrootdata(int d) {
		root->data = d;
	}
	int getrootdata() {
		return root->data;
	}

	bool insert(int data)
	{
		if (root == NULL)
		{
			root = new node;
			root->data = data;
			return true;
		}

		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (temp->data == data)
				{
					return false;
				}

				else if (temp->data > data)
				{
					if (temp->left == NULL)
					{
						node* t = new node;
						t->data = data;
						temp->left = t;
						return true;
					}
					else
					{
						temp = temp->left;
					}
				}

				else if (temp->data < data)
				{
					if (temp->right == NULL)
					{
						node* t = new node;
						t->data = data;
						temp->right = t;
						return true;
					}
					else
					{
						temp = temp->right;
					}
				}
			}

		}
	}

	bool search(int d)
	{
		if (root == NULL)
		{
			return false;
		}

		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (temp->data == d)
				{
					return true;
				}

				else if (temp->data > d)
				{
					temp = temp->left;
				}

				else
				{
					temp = temp->right;
				}

			}
		}
		return false;
	}

	void displayInOrder()
	{
		display(root);
	}

	void remove(int v) {
		del(root);
	}



};


