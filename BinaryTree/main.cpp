#include <iostream>
#include <cstdlib>
#include "stack.cpp"
#include "BinaryTree.cpp"

using namespace std;

bool isOperator(char s);

int main()
{
    Stack<Node*> stack;
    Node* root;
    string s = "AB/C*D*E+";
    for(int i = 0; i<s.length(); i++)
    {
        if(!isOperator(s[i]))
        {
            Node* temp = new Node(s[i]);
            stack.push(temp);
        }
        else{
            Node* temp1 = new Node(s[i]);
            Node* t1 = stack.pop();
            Node* t2 = stack.pop();
            temp1->left = t2;
            temp1->right = t1;
            stack.push(temp1);
        }
    }
    root = stack.pop();
    BinaryTree tree(root);
    cout << "Infix Notation: \n";
    tree.InOrder(root);
    cout << "\nPostfix Notation: \n";
    tree.PostOrder(root);
    cout << "\nPrefix Notation: \n";
    tree.PreOrder(root);
}

bool isOperator(char s){
    if(s == '+')
        return true;
    else if(s == '*')
        return true;
    return false;
}
