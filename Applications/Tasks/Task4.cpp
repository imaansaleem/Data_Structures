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
	
	void AddNodeHead(int d){
		Node* node = new Node(d);
		node->next=head;
		head=node;
		if(tail==NULL)
			tail=head;
	}
	
	void AddNodeTail(int d){
		if(tail!=NULL){
			tail->next=new Node(d);
			tail=tail->next;
		}
		else
			head=tail=new Node(d);	
	}
	
	void InsertNode(int d1, int position){
		Node *i;
		Node *j=head;
		int count=1;
		for(i=head;count!=position;i=i->next){
			if(i!=head){
				j=j->next;
				
			}
			count++;
		}
			Node *newNode=new Node(d1);
			j->next=newNode;
			newNode->next=i;
	
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
	LinkedList list2;
	cout << "Input Number of Nodes: ";
	cin >> no_of_nodes;
	for(int i=0;i<no_of_nodes;i++){
		cout << "Input data for node " << i+1 << ": ";
		cin >> e;
		list2.AddNodeTail(e);
	//	list.AddNodeHead(e);
	}

	cout << "Data Entered in the list is: \n";
	list2.show();
	
	list2.InsertNode(5,3-1);
	cout << "List now";
	list2.show();
	return 0;
}
