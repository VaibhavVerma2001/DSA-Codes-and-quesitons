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

void heapifyRec (int *arr, int index){
    if(index <= 0){
        return ;
    }
    
    int parentIndex = (index-1)/2;
    if(arr[parentIndex] >= arr[index]){
        return;
    }

    swap(arr[parentIndex], arr[index]);
    index = parentIndex; // go to parent index
    heapifyRec(arr, index);
}

class Heap {
    int size;
    int capacity;
    int *arr;

    public:

    Heap(int capacity){
        this -> size = -1;
        this -> capacity = capacity;
        this -> arr = new int[capacity];
    }

    ~Heap(){
        cout << "Distructor called" << endl;
        delete[] arr;
    }

    void insert(int num){
        if((size + 1) >= capacity){
            cout << "Heap overflow" << endl;
            return ;
        }
        cout << "inserting at pos : " << num << " : " << size << endl; 
        arr[size++] = num;
        

        int index = size;
        // heapify(arr, index);
        heapifyRec(arr, index);
    }

    void displayHeap(){
        cout << "Heap is : ";
        for(int i = 0 ; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

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