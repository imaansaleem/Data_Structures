#include <iostream>
#include<stdlib.h>
#include"BSTree.cpp"
#include"queue.cpp"

using namespace std;

int main()
{
    BTree tree;
	tree.insert(45);
	tree.insert(35);
	tree.insert(25);
	tree.insert(95);
	tree.insert(15);
	tree.insert(65);
	tree.insert(85);
	tree.insert(5);
    cout << "Inorder Traversal\n";
    tree.inorder();
    cout << "\nPreorder Traversal\n";
    tree.preorder();
    cout << "\nPostorder Traversal\n";
    tree.postorder();
    cout << "\nLevelOrder Traversal\n";
    tree.LevelOrder();
    return 0;
}
