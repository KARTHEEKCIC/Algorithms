#include<iostream>

using namespace std;

void insertionSort(int ar_size, int *  ar) 
{ static int i=1;
  int key=ar[i];
  for(int k=i;k>=0;k--)
  { 
    if(k==0)
    { ar[k]=key;
      break; 
    }
    if(key<ar[k-1])
      ar[k]=ar[k-1];
    else
    { ar[k]=key;
      break;
    }
  }
  i++;
  if(i<ar_size)
    insertionSort(ar_size,ar);

}

int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
         cin>>arr[i];
    insertionSort(n,arr);
    for(int j=0;j<n;j++)
         cout<<arr[j]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
