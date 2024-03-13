// declaring and initializing 2-D array
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int row,col,i,j;
    cout<<"enter no. of rows and colums\n";
    cin>>row>>col;
    int a[row][col];
    cout<<"enter the elements\n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cin>>a[i][j];
      }
    }
    cout<<"matrix is \n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cout<<a[i][j]<<" ";
      }cout<<endl;
    }

    return 0;
}
*/
// transpose of matrix
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int row,col,i,j;
    cout<<"enter no. of rows and colums\n";
    cin>>row>>col;
    int a[row][col];
    cout<<"enter the elements\n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cin>>a[i][j];
      }
    }
    cout<<"transpose of matrix is \n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cout<<a[j][i]<<" ";
      }cout<<endl;
    }

    return 0;
}
*/
// trace of matrix
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int row,col,i,j,sum=0;
    cout<<"enter no. of rows and colums\n";
    cin>>row>>col;
    int a[row][col];
    cout<<"enter the elements\n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cin>>a[i][j];
      }
    }
    cout<<"traces of matrix is \n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        if (i==j)
         {
          sum=sum+a[i][j];
         }
      }
    }
    cout<<sum;
    return 0;
}
*/
// searching element of a matrix
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int row,col,i,j;
    cout<<"enter no. of rows and colums\n";
    cin>>row>>col;
    int a[row][col];
    cout<<"enter the elements\n";
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        cin>>a[i][j];
      }
    }
    int key;
    cout<<"enter the element u want to search\n";
    cin>>key;
    for(i=0;i<row;i++)
    {
      for (j=0; j<col;j++)
      {
        if(a[i][j]==key)
        {
          cout<<"found at index"<<i<<" "<<j<<endl;
        }
      }
    }

    return 0;
}
*/
