//Program to find the union and intersection of two sorted arrays
#include<iostream>

using namespace std;

void INTERSECTION(int A[], int n, int B[], int m)
{
	int i=0, j=0;
	cout<<"THE INTERSECTION IS :- "<<endl;
	while(i<n && j<m)
	{
		while(A[i]>=B[j])
			if(A[i]==B[j++])
				cout<<A[i]<<" ";
		i++;
	}
}

void UNION(int A[], int n, int B[], int m)
{
	int i=0, j=0;
	cout<<"THE UNION IS :- "<<endl;
	while(i<n && j<m)
	{
		if(A[i]<B[j])
			cout<<A[i++]<<" ";
		else
			cout<<B[j++]<<" ";
	}
	while(i<n)
		cout<<A[i++]<<" ";
	while(j<m)
		cout<<B[j++]<<" ";
}

int main()
{
	int n, m;
	cin>>n>>m;
	int A[n], B[m];
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<m;++i)
		cin>>B[i];
	INTERSECTION(A,n,B,m);
	UNION(A,n,B,m);
	system("pause");
	return 0;
}
