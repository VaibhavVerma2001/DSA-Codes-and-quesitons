#include<iostream>
using namespace std ;


// Dynamic mem allocation
// Q1 - allocate integer -> in heap 
// Q2 - allocate array -> in heap 
// Q3 - allocate 2-d array -> in heap 

// Q4 - solve Q1 without new keyword
// Q5 - solve Q2 without new keyword
// Q6 - solve Q3 without new keyword


int main (){

    // Q1 - allocate integer -> in heap 
    int *p = new int(5);
    cout<<*p<<endl;


    // Q4 - solve Q1 without new keyword
    // new keyword was allocating mem in heap and then it was returning it's address.
    // malloc will allocates k bytes in heap

    // it returns void pointer, void means it don't know what kind of data is going to store at this location, so type cast it
    int *ptr  = (int *)malloc(4);
    *ptr = 10;

    cout<<*ptr<<endl;

    delete p; // for new
    free (ptr); // for malloc



    // Q2 - allocate 1-D array -> in heap 
    int *arr = new int[5]; // of size = 5
    

    // Q5 - solve Q2 without new keyword
    // for arr of size 5, space = 5*4 => 20
    int *arr3 =  (int *) malloc(20);

    for(int i = 0 ; i < 5 ; i++){
        // *(arr+i) = 10*i;
        arr[i] = 10*i;
        arr3[i] = 10*i;

    }

    for(int i = 0 ; i < 5 ; i++){
        // cout<<*(arr+i)<<" ";
        cout<<arr[i]<<" " <<arr3[i]<<endl;

    }

    delete []arr;
    free (arr3);



    // Q3 - allocate 2-d array -> in heap 4x5
    
    int row = 4, col = 5;
    int **arr4 = new int * [row]; // [rows] , means 4 rows

    // step 2 - loop and point col to each row
    for(int i = 0 ; i < row ; i++){
        arr4[i] = new int [col];
    }


    // Q6 - solve Q3 without new keyword
    
    // allocate rows
    int **arr5 = (int**) malloc (sizeof(int *) * row);

    for(int i = 0 ; i < row ; i++){
        arr5[i] = (int *) malloc(sizeof(int)*col);
    }



    // access
    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            arr5[i][j] = 10;
        }
    }

    for(int i = 0 ; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            cout<<arr5[i][j]<<" ";
        }
        cout<<endl;
    }

    

    // delete
    for(int i = 0 ; i < row; i++){
        delete [] arr4[i];
    }
    delete[] arr4;

    // free
    for(int i = 0 ; i < row; i++){
        free (arr5[i]);
    }
    free (arr5);


    return 0 ;
}