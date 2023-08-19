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
	
	bool IsEmpty(){
		if(head==NULL)
			return 1;
		else
			return 0;
	}
	
	int SearchNode(int d){
		int count=0;
		Node *i;
		for(i=head; i->data!=d ; i=i->next)
			count++;
			
		if(count==0)
			cout << "Element not found";
		return count;
	}
	
	void show(){
		for(Node *i=head; i!=tail->next; i=i->next)
			cout << "Data = " << i->data << ' ' << endl;
	}
};

int main()
{
	int no_of_nodes,e,element;
	LinkedList list;
	LinkedList list2;
	cout << "Input Number of Nodes: ";
	cin >> no_of_nodes;
	for(int i=0;i<no_of_nodes;i++){
		cout << "Input data for node " << i+1 << ": ";
		cin >> e;
		list.AddNodeTail(e);
	}

	cout << "\nData Entered in the list is: \n";
	list.show();
	
	cout << "\nInput Element to be searched: ";
	cin >> element;
	
	cout << "\nElement found at node: " <<list.SearchNode(element)+1;
	return 0;
}
