#include<iostream>
using namespace std;
void SWAP(int A[], int i, int j)	//function to swap two variables
{	A[0]=A[i];
	A[i]=A[j];
	A[j]=A[0];	  }

void MAX_HEAPIFY(int A[], int i, int n)
{	int j;
	if( i==n/2 && n%2==0 )
	{	if( A[i]<A[2*i] )
		{ 	SWAP(A,i,2*i);
			j=2*i;    }	
	}
	else
	if( A[i]<A[2*i] || A[i]<A[2*i+1] )
	{	if( A[2*i] > A[2*i+1] )  
		{ 	j=2*i;
            SWAP(A,i,j);  }
		else 
		{	j=2*i+1;
            SWAP(A,i,j);    }
	}

	if( j<=n/2 )
		MAX_HEAPIFY(A,j,n);
}

void BUILD_HEAP(int A[], int n)
{	for(int i=n/2 ; i>0 ; i--)
		MAX_HEAPIFY(A,i,n);   }

void HEAP_SORT(int A[], int n)
{    int i=n;
	while( i>2 )
	{	SWAP(A,1,i);
		i--;
		MAX_HEAPIFY(A,1,i);
    }
    SWAP(A,1,2);
}

int main()
{	int n, A[100];
	cin>>n;
	for(int i=1 ; i<=n ; i++)
		cin>>A[i];
	BUILD_HEAP(A,n);
	HEAP_SORT(A,n);	
	for(int i=1 ; i<=n ; i++)
		cout<<A[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
