
#ifndef HEAP
#define HEAP
#include<iostream>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class MinHeap{
 int *heap; // pointer to array of elements in heap
 int capacity; // maximum possible size of min heap
 int heap_size; // Current number of elements in min heap
public:
 // Constructor
 MinHeap(int cap=50){
     heap_size = 0;
     capacity = cap;
     heap = new int[cap];
     for(int i=0; i<cap; i++)
         heap[i]= -111;
 }
 bool is_Full(){
      if(heap_size==capacity)
          return true;
      return false;
 }

 bool is_Empty(){
     if(heap_size==0)
         return true;
     return false;
 }

// Inserts a new key 'k'
void insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    heap[i] = k;

    // check if previously all are not violating min heap property i.e parent is smaller than child
    while (i != 0 && heap[(i-1)/2] > heap[i]){
        swap(heap[i], heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void print_heap(){
    if(is_Empty())
            cout << "Heap is empty\n";
    else {
        for (int i = 0; i < heap_size; i++) {
            if (heap[i] != -111)
                cout << heap[i] << ' ';
        }
        cout << "\n";
    }
 }

 int deleteNode()
 {
     if(is_Empty())
         cout << "Error:( Heap is already empty";
     if (heap_size == 1)
     {
         heap_size--;
         return heap[0];
     }

     // Store the minimum value, and remove it from heap
     int root = heap[0];
     heap[0] = heap[heap_size-1];
     heap_size--;
     MinHeapify(0);

     return root;
 }

    void MinHeapify(int i)
    {
        int l = (2*i + 1);
        int r = (2*i + 2);
        int smallest = i;
        if (l < heap_size && heap[l] < heap[i])
            smallest = l;
        if (r < heap_size && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            MinHeapify(smallest);
        }
    }

    ~MinHeap(){
        delete[]heap;
    }
};

void Heap_sort(int *A, int n){
    int *store;
    MinHeap h;
    for(int i=0; i<n; i++)
        h.insertKey(A[i]);

    store=new int[n];
    for(int i=n-1;i>=0;i--)
        store[i]=h.deleteNode();

    for(int i=0;i<n;i++)
        cout << store[i] << ' ';
    cout << "\n";
}

#endif