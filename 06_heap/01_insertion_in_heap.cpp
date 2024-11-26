#include<iostream>
using namespace std;

// Iteratively heapify
void heapify(int *arr, int index){
    while(index >= 0){
        int parentIndex = (index-1)/2;
        if(arr[parentIndex] < arr[index]){
            swap(arr[parentIndex], arr[index]);
        } else {
            break;
        }
        index = parentIndex; // go to parent index
    }
}


// Recursive heapify
void heapifyRec(int *arr, int index){
    // BC
    if(index <=0){
        return ;
    }

    int parentIndex = (index-1)/2;

    if(arr[parentIndex] > arr[index]){
        return ;
    } 

    swap(arr[parentIndex], arr[index]);
    heapifyRec(arr, parentIndex);
}

// Inserting in a max-heap
class Heap {
    public : 

    int capacity;
    int size ;
    int *arr;

    Heap(int capacity){
        this -> size = -1;
        this -> capacity = capacity;
        this -> arr = new int[capacity];
    }


    void insert(int val){
        if(size + 1 >= capacity){
            cout << "Heap overflow" << endl;
            return ;
        }

        // insert at last pos
        size++;
        arr[size] = val;

        // heapify
        int index = size;
        // heapify(arr,index);   
        heapifyRec(arr,index);
    }

    void displayHeap(){
        cout << "Printing heap" << endl;
        for(int i = 0 ; i <= size ; i++){
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};



//TC FOR HEAPIFY = O(log n)
// For inserting n elements = O(n *log n)

int main(){
    Heap h(10);
    h.insert(10);
    h.insert(5);
    h.insert(3);
    h.insert(2);
    h.insert(4);
    h.insert(15);

    h.displayHeap();
}