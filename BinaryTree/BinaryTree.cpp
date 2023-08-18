#ifndef TREE
#define TREE

#include<iostream>

using namespace std;

class Node{
public:
    char data;
    Node* left;
    Node* right;
    Node(int d, Node* r = NULL, Node* l = NULL)
    {
        data = d;
        right = r;
        left = l;
    }
};

class BinaryTree{
    Node* root;
public:
    BinaryTree(Node* r = NULL)
    {
        root = r;
    }

    void InOrder(Node* root)
    {
        if (root==NULL)
			return;
		InOrder(root->left);
		cout << root->data << ' ';
		InOrder(root->right);
    }
    void PreOrder(Node* root)
    {
        if (root==NULL)
			return;
        cout << root->data << ' ';
		PreOrder(root->left);
		PreOrder(root->right);
    }
    void PostOrder(Node* root)
    {
        if (root==NULL)
			return;
		PostOrder(root->left);
		PostOrder(root->right);
        cout << root->data << ' ';
    }
};

#endif