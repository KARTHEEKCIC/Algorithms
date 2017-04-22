#include<iostream>

using namespace std;

struct SET
{
	int data;
	int rank;
	SET *parent;
};

void INSERTION_SORT(int arr[][3], int n)
{
	int key, key1, key2;
	for(int i=1;i<n;i++)
	{
		key=arr[i][2];
		key1=arr[i][1];
		key2=arr[i][0];
		for(int j=i-1;j>=0;j--)
			if(arr[j][2]>key)
			{	arr[j+1][2]=arr[j][2];
				arr[j][2]=key;
				arr[j+1][1]=arr[j][1];
				arr[j][1]=key1;
				arr[j+1][0]=arr[j][0];
				arr[j][0]=key2;			
			}
			else
				break;
	}
}

SET* MAKE_SET(int v)  // function to make every vertex into a set
{
	SET *ptr=new SET;
	ptr->data=v;
	ptr->rank=0;
	ptr->parent=ptr;
	return ptr;
}

int FIND_SET(int vertex, SET *Sets[])  // to find the representative element of the set
{
	SET *ptr=Sets[vertex-1];
	while(ptr->parent!=ptr)
		ptr=ptr->parent->parent;
	Sets[vertex-1]->parent=ptr;
	return ptr->data;
}

void UNION(int u, int v, SET *Sets[])  // to form an edge between two vertex u and v
{
	int r1=FIND_SET(u,Sets);
	int r2=FIND_SET(v,Sets);
	if(Sets[r1-1]->rank>Sets[r2-1]->rank)
		Sets[r2-1]->parent=Sets[r1-1];
	else
		Sets[r1-1]->parent=Sets[r2-1];
	if(Sets[r1-1]==Sets[r2-1])
		Sets[r2-1]->rank+=1;
}

void KRUSKAL(int no_of_vertex, int no_of_edges, int arr[][3], int A[][3])
{
	int u, v;
	SET *Sets[no_of_vertex];  // stores the different dijoint sets roots or representative elements
	for (int i = 0; i < no_of_vertex; ++i)
		Sets[i]=MAKE_SET(i+1);
	for(int i=0, j=0 ; i<no_of_edges ;i++)
	{	
		u=arr[i][0];
		v=arr[i][1];
		if(FIND_SET(u,Sets)!=FIND_SET(v,Sets))
		{	
			A[j][0]=arr[i][0];
			A[j][1]=arr[i][1];
			A[j][2]=arr[i][2];
			j++;
			UNION(u,v,Sets);  // connecting the two safe edges of the graph to form the minimum spanning tree
		}
	}
}

int main()
{
	int n, m;  // n is the no of vertices and m is the no of edges
	cin>>n>>m;
	int v1, v2, w; // (v1,v2) is an edge of the graph and w is the weight of the edge
	int EDGES[m][3];
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>w;  // inserting edges into a 2-D array along with weights to store the graph
		EDGES[i][0]=v1;
		EDGES[i][1]=v2;
		EDGES[i][2]=w;
	}
	INSERTION_SORT(EDGES,m);
	int A[n-1][3];
	KRUSKAL(n,m,EDGES,A);
	cout<<"THE EDGES OF THE MINIMUM SPANNING TREE IS :- "<<endl;
	for(int i=0;i<n-1;i++)
	{	cout<<A[i][0]<<" "<<A[i][1]<<" "<<A[i][2]<<endl;
	}
	system("pause");
	return 0;
}
