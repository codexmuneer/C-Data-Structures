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

public:
	BST()
	{
		root = NULL;

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


};
