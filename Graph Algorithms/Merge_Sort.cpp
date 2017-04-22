#include<iostream>

using namespace std;

void MERGE(int A[], int b, int m, int e)
{
	int i=b;
	int j=m+1;
	int k=0;
	int B[e-b+1];
	while(i<=m && j<=e)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	while(i<=m)
		B[k++]=A[i++];
	while(j<=e)
		B[k++]=A[j++];
	i=b;
	k=0;
	while(i<=e)
		A[i++]=B[k++];	
}

void MERGE_SORT(int A[], int begin, int end)
{
	int m=(begin+end)/2;
	if(begin!=end)
	{	MERGE_SORT(A,begin,m);
		MERGE_SORT(A,m+1,end);
		MERGE(A,begin,m,end);
	}
}

int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	MERGE_SORT(A,0,n-1);
	for(int i=0;i<n;i++)
		cout<<A[i]<<" ";
	system("pause");
	return 0;
}