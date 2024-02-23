//subarray - contiguous part of an array

#include <iostream>
using namespace std;
int main() {
    int a[20],i,j,k,n;
    cout<<"how many values u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"subarrays are"<<endl;
    for ( i = 0; i <n; i++)
    {
      for (j = i;  j<n; j++) // fixing strarting and ending points
       {
         for(k=i;k<=j;k++)// printing values btw strarting and ending points
         {
           cout<<a[k]<<" ";
         }cout<<endl;
      }
    }

    return 0;
}

// sum of each max subarray
/*
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
    int a[20],i,j,k,n;
    cout<<"how many values u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"sum is "<<endl;
    for(int i=0;i<n;i++) {
			int sum=0;
			for(int j=i;j<n;j++) {
				sum+=a[j];
				cout<<sum<<endl;
		  	}
	  	}


    return 0;
}
*/
/*
#include <iostream>
#include <climits>
using namespace std;
int main(int argc, char const *argv[]) {
    int a[20],i,j,k,n,sum=0,maxsum=INT_MIN;
    cout<<"how many values u want to insert"<<endl;
    cin>>n;
    cout<<"enter the values"<<endl;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"subarrays are"<<endl;
    for ( i = 0; i <n; i++)
    {
      for (j = i;  j<n; j++) // fixing strarting and ending points
       {
         for(k=i;k<=j;k++)// printing values btw strarting and ending points
         {

          sum=sum+a[k];
         }cout<<endl;
         maxsum=max(maxsum,sum);
      }
    }
    cout<<maxsum;
    return 0;
}
*/