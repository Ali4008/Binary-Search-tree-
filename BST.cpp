// ConsoleApplication181.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node* right;
    node* left;

    node(int v) {
        val = v;
        right = NULL;
        left = NULL;
    }

};


class bst {
    node* min(node* r) {
        if (r == NULL) {
            return NULL;
        }
        else {
            if (r->left == NULL) {
                return r;
            }
            else {
                return min(r->left);
            }
        }
    }

public:
    node* root;
public:
    bst() {
        root = NULL;
    }


    void insert(int data) {
     
        node* newnode = new node(data);
        node* ptr;
        if (!root) {
            root = newnode;
        }
        else {
            ptr = root;
            while (ptr != NULL) {
                if (data < ptr->val) {
                    if (ptr->left) {
                        ptr = ptr->left;
                    }
                    else {
                        ptr->left = newnode;
                        break;
                    }
               
                }
                else if (data > ptr->val) {
                    if (ptr->right) {
                        ptr = ptr->right;
                    }
                    else {
                        ptr->right = newnode;
                        break;
                    }
                }
            }
        }




    }

    void inorder(node *root) {
        if (root) {

            inorder(root->left);
            cout << root->val << " ";
            inorder(root->right);
        }

    }
    void print() {
        inorder(root);
  }

    bool search(int v) {
        node* ptr = root;
        while (ptr!=NULL) {
            if (ptr->val == v) {
                return true;
           }
            else if (v > root->val) {
                ptr = ptr->right;
            }
            else {
                ptr = ptr->left;
            }
        }
        return false;

    }

   
   node * findmin() {
       return min(root);
    }
    


    node* del(node* root, int key) {

        if (root == NULL) {
            return root;
        }

        if (root->val < key) {
            root->right = del(root->right, key);
        }

        else if (root->val > key) {
            root->left = del(root->left, key);
        }

        else {

             if (root->left == NULL) {
                node* temp = root->right;
                delete[] root;
                return temp;
            }

            else if (root->right == NULL) {
                node* temp = root->left;
                delete[]root;
                return temp;
            }

            else {
                node* temp = min(root->right);
                root->val = temp->val;
                root->right = del(root->right, temp->val);
            }
        }
        return root;
    }
    node* getroot() {
        return root;
    }

   bool search2(node *r,int num) {
        if(r==NULL) {
            return NULL;
        }
        if (r->val == num) {
            return true;
        }
        if (num > r->val) {
            return search2(r->right, num);
        }
        else if (num < r->val) {
            return search2(r->left, num);
        }
    }

   node* insert2(node* root, int val) {
       if (root == NULL) {
           node* temp = new node(val);
           return temp;
       }
       if (val > root->val) {
           root->right = insert2(root->right, val);
       }
       else if (val < root->val) {
           root->left = insert2(root->left, val);
       }
       return root;
   }

};
int main()
{
    bst b;
    b.insert(1);
    b.insert(2);
    b.insert(11);
    b.insert(23);
    b.print();
    if (b.search2(b.getroot(),23)) {
        cout<<"\nFound\n";
    }
    else {
         cout << "\nNot found\n";
    }

    b.del(b.getroot(), 2);
    b.insert2(b.getroot(), 23);
    b.print();
}
