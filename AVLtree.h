#include <iostream>
#include <fstream>
using namespace std;
// Add rotation and balancing functionality.
// a. Begin by adding rotateLeft() and rotateRight() functions to your tree class.
// b. Now, add a getNodeHeight() function that returns the height of a particular
// node.
// c. Implement getBalance() function to the tree class that uses the getNodeHeight()
// function to determine if a node is imbalanced. If there is an imbalance, perform
// the appropriate rotations in setBalance() function.
template <typename T>
class AVL{
    public:
        class node{
            public:
                T key;
                int height;
                node * left;
                node * right;
                node(T k){
                    height = 1;
                    key = k;
                    left = NULL;
                    right = NULL;
                }
        };

        node * root = NULL; 
        int n;
        void insert(T x){
            root=insertUtil(root, x);
        }
        void inorder(){
            inorderUtil(root);
            cout<<endl;
        }
    private:
        int getNodeHeight(node * head){
            if(head==NULL) return 0;
            return head->height;
        }
        node * rotateRight(node * head){
            node * newhead = head->left;
            head->left = newhead->right;
            newhead->right = head;
            head->height = 1+max(getNodeHeight(head->left), getNodeHeight(head->right));
            newhead->height = 1+max(getNodeHeight(newhead->left), getNodeHeight(newhead->right));
            return newhead;
        }

        node * rotateLeft(node * head){
            node * newhead = head->right;
            head->right = newhead->left;
            newhead->left = head;
            head->height = 1+max(getNodeHeight(head->left), getNodeHeight(head->right));
            newhead->height = 1+max(getNodeHeight(newhead->left), getNodeHeight(newhead->right));
            return newhead;
        }

        void inorderUtil(node * head){
            if(head==NULL) return ;
            inorderUtil(head->left);
            cout<<head->key<<" ";
            inorderUtil(head->right);
        }

        node * insertUtil(node * head, T x){
            if(head==NULL){
                n+=1;
                node * temp = new node(x);
                return temp;
            }
            if(x < head->key) head->left = insertUtil(head->left, x);
            else if(x > head->key) head->right = insertUtil(head->right, x);
            head->height = 1 + max(getNodeHeight(head->left), getNodeHeight(head->right));
            head = getBalance(head, x);

            return head;

        }

        node* getBalance(node* head,T x){
            int bal = getNodeHeight(head->left) - getNodeHeight(head->right);
            if(bal > 1 || bal < -1){
                return setBalance(head,x);
            }
            return head;
        }
        node* setBalance(node * head,T x){
            int bal = getNodeHeight(head->left) - getNodeHeight(head->right);
            
            if(bal>1){
                if(x < head->left->key){
                    return rotateRight(head);
                }else{
                    head->left = rotateLeft(head->left);
                    return rotateRight(head);
                }
            }else if(bal<-1){
                if(x > head->right->key){
                    return rotateLeft(head);
                }else{
                    head->right = rotateRight(head->right);
                    return rotateLeft(head);
                }
            }
            return head;
        }

};

int main(){
    AVL<float> t;
    int n;
	fstream file;
	file.open("Numbers (1).txt", ios::in);
	while (file) {
		file >> n;
        t.insert(n);
		

	}
    t.inorder();

}
