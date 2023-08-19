#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	Node(int d, Node *n=NULL){
		data=d;
		next=n;
	}
};

class LinkedList{
	Node *head;
	Node *tail;
	
	public:
	LinkedList(){ 
		head=NULL;
		tail=NULL; 
	}
	
	void AddNodeTail(int d){
		if(tail!=NULL){
			tail->next=new Node(d);
			tail=tail->next;
		}
		else
			head=tail=new Node(d);	
	}
	
	void show(){
		for(Node *i=head; i!=tail->next; i=i->next)
			cout << "Data = " << i->data << ' ' << endl;
	}
};

int main()
{
	int no_of_nodes,e;
	LinkedList list;
	cout << "Input Number of Nodes: ";
	cin >> no_of_nodes;
	for(int i=0;i<no_of_nodes;i++){
		cout << "Input data for node " << i+1 << ": ";
		cin >> e;
		list.AddNodeTail(e);
	}

	cout << "Data Entered in the list is: \n";
	list.show();
	return 0;
}
