#include <iostream>
#include<stdlib.h>

using namespace std;

class Queue{
	
    int *queue;
    int size;
    int rear;
    int front;
    
    public:
    Queue(int size=5){
    	this->size=size;
    	rear=-1;
    	front=-1;
    	queue= new int[size];
	}
	
	bool isEmpty(){	
		if(front==-1 && rear==-1)
			return true;
		else 
			return false;
	}
	
	bool isFull(){
		if(rear==size-1)	
			return true;
		else 
			return false;
	}
	
	void Enque(int item) {
		if (!isFull()){
			queue[++rear]=item;
			if(front==-1)
				front=0;
		}
		else
			cout << "\nQueue is Full";
	}
	
	int Deque() {
		int element;
		if (!isEmpty()){
			element=queue[front];
			return element;
			front++;
			if(front==rear)
				front=rear=-1;
		}
		
		else 
			cout << "\nQueue is empty";
	}
	
	friend ostream & operator<<(ostream& out, const Queue& x){
		for(int i=x.front;i<=x.rear;i++)
			out << x.queue[i] << ' ';
		return out;
	}
	
	~Queue(){		
		delete []queue;		
	}
	
};


int main(){
	Queue q;
	q.Enque(23);
	q.Enque(24);
	q.Enque(25);
	q.Enque(26);
	q.Enque(27);
	cout << "Pushed Elements are: \n";
	cout << q;
	if(q.isFull())
		cout << "\nQueue is full "<< endl;
	else 
		cout << "Queue is not full: "<< endl;
	q.Deque();
	q.Deque();
	q.Deque(); 
	cout << "\nElements left: \n";
	cout << q;
	q.Deque();
	q.Deque();
}
