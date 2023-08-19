#include<iostream>

#include"Min_Heap.cpp"

using namespace std;

int main()
{
 MinHeap h(50);

 h.insertKey(4);
 h.insertKey(7);
 h.insertKey(2);
 h.insertKey(8);
 h.insertKey(14);
 h.insertKey(18);
 h.insertKey(20);
 h.insertKey(5);
 h.insertKey(19);
 h.insertKey(1);

 cout << "After insertion Heap is: \n";
 h.print_heap();

 cout << "\nRemove One by one\n";
 for(int i =0; i<10; i++) {
     cout << h.deleteNode() << ' ';
     cout << "is deleted\n";
 }
    cout << "\nAfter delete Heap is: \n";
    h.print_heap();

    int size=11;
    int A[11]={4,7,2,8,1,14, 18, 20,5, 19,13};
    cout << "\n\nDescending order: \n";
    Heap_sort(A,size);
    system("pause");
 return 0;
}
