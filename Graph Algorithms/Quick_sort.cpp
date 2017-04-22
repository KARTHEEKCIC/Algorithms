#include<iostream>

using namespace std;

void SWAP(int A[], int i, int j)
{
	int temp;
	temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

void QUICK_SORT(int A[], int begin, int end)
{
	int i=begin-1;
	int j=begin; 
	while(j<end)
	{
		if(A[end]>A[j])
		{	SWAP(A,i+1,j);
			i++;
			j++;
		}
		else
			j++;
	}
	SWAP(A,i+1,end);
	if(begin!=i)
		QUICK_SORT(A,begin,i);
	if((i+1)!=end)
		QUICK_SORT(A,i+1,end);
}

int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	QUICK_SORT(A,0,n-1);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	system("pause");
	return 0;
}