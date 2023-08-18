#include <iostream>
#include "linkedlist.cpp"

using namespace std;


class Sets{
    LinkedList list;
    int size;

    public:
    Sets(){}

    Sets(const Sets &set){
        size=set.size;
        list=set.list;
    }
    
    Sets union_of_sets(Sets set){
		int i,integer_element;
        Sets set1=*this;
        Sets set2=set;
		Sets new_list;
		for(i=0;i<size;i++){
            integer_element=set1.list.Delete_From_Head();
			if(!(new_list.list.find_element(integer_element)))
				new_list.list.AddNodeTail(integer_element);
		}
		
		for(i=0;i<set.size;i++){
            integer_element=set2.list.Delete_From_Head();
			if(!(new_list.list.find_element(integer_element))){
				new_list.list.AddNodeTail(integer_element);
			}
		}
		return new_list;
	}

	Sets intersection_of_sets(Sets set){
		int i,integer_element;
        Sets set1=*this;
		Sets new_list;
		for(i=0;i<size;i++){
            integer_element=set1.list.Delete_From_Head();
			if(set.list.find_element(integer_element))
                new_list.list.AddNodeTail(integer_element);
		}
		return new_list;
	}

	Sets difference_of_sets(Sets set){
		int i,integer_element;
        Sets set1=*this;
		Sets new_list;
		for(i=0;i<size;i++){
            integer_element=set1.list.Delete_From_Head();
			if(!(set.list.find_element(integer_element)))
				new_list.list.AddNodeTail(integer_element);
		}
		return new_list;
	}

	friend istream & operator >>(istream& in , Sets& x){
		int integer;
		in >> x.size;
		for(int j=0;j<x.size;j++){
			cout << "Enter " << j+1 << " integer: ";
			in >> integer;
			while(x.list.find_element(integer)){
				cout << "Already in the set add distinct elements ";
				cin >> integer;
			}
			x.list.AddNodeTail(integer);
		}
		return in;
	}

    void show(){
        list.show();
    }
};

int main()
{
	Sets set1, set2, set3, set4, set5;
	cout << "\nEnter no of nodes of first list: and values" << endl;
	cin >> set1;
	cout << "List1\n";
	set1.show();
	cout << "\nEnter no of nodes of second list: and values" << endl;
	cin >> set2;
	cout << "\nlist2\n";
	set2.show();
	set3=set1.union_of_sets(set2);
	cout << "\nunion\n";
	set3.show();
	cout << "\nintersection\n";
	set4=set1.intersection_of_sets(set2);
	set4.show();
	cout << "\nDifference\n";
	set5=set1.difference_of_sets(set2);
	set5.show();
	return 0;
}
