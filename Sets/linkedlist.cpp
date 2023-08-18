#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node *previous;
	
	Node(int d, Node *n=NULL, Node *p=NULL){
		data=d;
		next=n;
		previous=p;
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

    LinkedList(const LinkedList &l){
        list_copy(l);
    }

    void list_copy(const LinkedList &list){
        for(Node *i=list.head; i!=NULL; i=i->next){
            AddNodeTail(i->data);
        }
    }

    void operator = (const LinkedList &l){
        list_copy(l);
    }
	
	void AddNodeHead(int d){
        if(head==NULL)
            tail=head=new Node(d);

        else{
		    head=new Node(d,head,NULL);
		    head->next->previous=head;
        }
	}
	
	void AddNodeTail(int d){
		if(tail!=NULL){
			tail=new Node(d,NULL,tail);
			tail->previous->next=tail;
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
	
	int Delete_From_Head(){
		int digit;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=head->data;
			if(head==tail)
				head=tail=NULL;
			else{
				head=head->next;
				delete head->previous;
				head->previous=NULL;
			}
		}
		return digit;
	}
	
	int Delete_From_Tail(){
		Node *i;
		int digit;
		if(IsEmpty())
			cout << "Can't Display! List is Empty ^_^";
		else{
			digit=tail->data;
			if(head==tail)
				head=tail=NULL;
			else{
				tail=tail->previous;
				delete tail->next;
				tail->next=NULL;
			}
		}
		return digit;
	}
	
	int delete_Node_centre(int position){
		Node *i;
		int count;
		for(i=head,count=1;count!=position;i=i->next,count++);
			int e=i->data;
			i->previous->next=i->next;
			i->next->previous=i->previous;
			delete i;
		return e;
	}


	void insert_Node(int d, int position){
		Node *i;
		int count;
		for(i=head,count=1;count!=position;i=i->next,count++);
		i->next=new Node(d,i->next,NULL);
		i->next->previous=i;
		i->next->next->previous=i->next;

	}

    bool find_element(int data){
		if(head==NULL && tail==NULL) //if no element is in the list it will not be matched
			return 0;
		else{
			for(Node *i=head; i!=NULL; i=i->next){
				if(i->data==data)
					return 1;
			}
		}
		return 0;
	}

	void show(){
		for(Node *i=head; i!=tail->next; i=i->next){
			cout << i->data << ' ';
		}
	}
};
#endif