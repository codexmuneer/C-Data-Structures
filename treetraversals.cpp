#include <iostream>
using namespace std;


void Inorder_Traversal(int l, char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			
			Inorder_Traversal(l,arr, 2 * size);
			cout << arr[size]<< "  ";
			Inorder_Traversal(l,arr, 2 * size + 1);
		}
	}
}


void Preorder_Traversal(int l,char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			cout << arr[size] << " ";
			Inorder_Traversal(l,arr, 2 * size);

			Inorder_Traversal(l,arr, 2 * size + 1);
		}
	}
}

void Postorder_Traversal(int l,char arr[], int size)
{
	if (size >= l)
	{
		return;
	}

	else
	{
		if (arr[size] != '\0')
		{
			
			Inorder_Traversal(l,arr, 2 * size);

			Inorder_Traversal(l,arr, 2 * size + 1);
			cout << arr[size]<< "  ";
		}
	}
}

int main()
{
	int l = 15;
	char tree[] = { '\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L' };
	int size=1;
	
	char press='1';
	while (press != '4')
	{
        cout<<"Press 1 to traverse inorderly"<<endl;
        cout<<"Press 2 to traverse preorderly"<<endl;
        cout<<"Press 3 to traverse postorderly"<<endl;
        cout<<"Press 4 to exit the program"<<endl;
		cin >> press;
		
		if (press == '1')
		{
			Inorder_Traversal(l, tree, size);
			cout << endl;1
		}

		else if (press == '2')
		{
			Preorder_Traversal(l, tree, size);
			cout << endl;
		}

		else if (press == '3')
		{
			Postorder_Traversal(l, tree, size);
			cout << endl;
		}

		else
		{
			cout << "invalid option!"<< endl;
		}
	}
}
