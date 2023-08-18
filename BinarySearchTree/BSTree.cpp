#ifndef TREE
#define TREE
#include <iostream>
#include"queue.cpp"

using namespace std;

class BTNode{
public:
    int data;
    BTNode *left, *right;
    BTNode (int d, BTNode *left=NULL, BTNode *right=NULL){
        data = d;
        this->left = left;
        this->right = right;
    }
};
class BTree{	//Linked Implementation
    BTNode *root;
public:
    BTree(){	root = NULL;}
    BTNode* insert(int d, BTNode *temp){
        if (temp==NULL){
            BTNode *t = new BTNode(d);
            return t;
        }
        if (temp->data > d)
            temp -> left = insert (d, temp->left);
        else
            temp -> right = insert (d, temp->right);
        return temp;
    }
    //Wrapper Function
    void insert(int d){
        root = insert (d, root);
    }
    void inorder(BTNode *temp){
        if (temp!=NULL){
            inorder(temp->left);
            cout << temp -> data << ' ';
            inorder(temp->right);
        }
    }
    void inorder(){
        inorder(root);
        cout << '\n';
    }

    void preorder(BTNode *temp){
        if (temp!=NULL){
            cout << temp -> data << ' ';
            preorder(temp->left);
            preorder(temp->right);
        }
    }
    void preorder(){
        preorder(root);
        cout << '\n';
    }

    void postorder(BTNode *temp){
        if (temp!=NULL){
            postorder(temp->left);
            postorder(temp->right);
            cout << temp -> data << ' ';
        }
    }
    void postorder(){
        postorder(root);
        cout << '\n';
    }


    void LevelOrder(){
        Queue <BTNode*> q;
        BTNode *temp=root;
        q.enqueue(temp);
        while(!q.isEmpty()){
            temp=q.dequeue();
            cout << temp->data << ' ';
            if(temp->left!=NULL)
            {
                q.enqueue(temp->left);
            }
            if(temp->right!=NULL) {

                q.enqueue(temp->right);
            }

        }
    }

    bool search(int d, BTNode *temp){
        if (temp==NULL)		return false;
        if (temp->data == d)	return true;
        if (temp->data > d)		return search(d, temp->left);
        return search(d, temp->right);
    }
    bool search(int d){
        return search(d, root);
    }
    //left most node address required
    BTNode* leftMost(BTNode *temp){
        if (temp->left==NULL)	return temp;
        return leftMost(temp->left);
    }
    //Right most node address required
    BTNode* rightMost(BTNode *temp){
        if (temp->right==NULL)	return temp;
        return rightMost(temp->right);
    }
    BTNode* deleteNode(int d, BTNode *temp){
        BTNode *next;
        if (temp==NULL)		return NULL;
        else if (temp->data>d)	temp->left = deleteNode(d, temp->left);
        else if (temp->data<d)	temp->right = deleteNode(d, temp->right);
        else{//Node found and to be deleted
            if (temp->left == NULL && temp->right == NULL){ //leaf node
                delete temp;
                return NULL;
            }
            else if (temp->left == NULL){ //only left node
                next = temp->right;
                delete temp;
                temp = next;
            }
            else if (temp->right == NULL){ //only right node
                next = temp->left;
                delete temp;
                temp = next;
            }
            else{
                next = rightMost (temp->left); // with both right and left node
                temp->data = next->data;
                temp->left = deleteNode(next->data, temp->left);
            }
            return temp;
        }
    }
    void deleteNode(int d){
        root = deleteNode (d, root);
    }
    BTNode *getroot(){
        return root;
    }
};
#endif
