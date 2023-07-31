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
		if(front==((rear+1)%size))	
			return true;
		else 
			return false;
	}
	
	void Enque(int item) {
		if (!isFull()){
			rear=(rear+1)%size;
			queue[rear]=item;
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
			if(front==rear)
				front=rear=-1;
			else
				front=(front+1)%size;
		}
		else 
			cout << "\nQueue is empty";
		return element;
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
	cout << q.Deque() << endl;
	cout << q.Deque() << endl;
	cout << q.Deque() << endl;
	cout << "\n--------------\n";
	q.Enque(28);
	q.Enque(29);
	cout << q.Deque() << endl;
	cout << q.Deque() << endl;
	cout << q.Deque() << endl;
}
