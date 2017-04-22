#include<iostream>

using namespace std;

struct GRAPH_NODE
{
	int data;
	int exploration_status;
	int previous;
	int f;
	int d;
};

struct EDGE
{
	int data;
	EDGE *link1;
	EDGE *link2;
};

EDGE *top=NULL;
int n;
int time=0;

void DFS_VISIT(GRAPH_NODE G[], int vertex);

void DFS(GRAPH_NODE G[], int source)
{
	G[source-1].previous=0;
	DFS_VISIT(G,source);
	for(int i=0;i<n;i++)
	{
		if(G[i].exploration_status==0)
		{	
			G[i].previous=0;
			DFS_VISIT(G,i+1);
		}
	}
}

void DFS_VISIT(GRAPH_NODE G[], int vertex)
{
	time=time+1;
	G[vertex-1].exploration_status=1;
	G[vertex-1].f=time;
	EDGE *ptr=new EDGE;
	EDGE *ptr1;
	ptr=top;
	while(1)
	{
		if(ptr->data==vertex)
			break;
		ptr=ptr->link1;
	}
	ptr1=ptr;
	cout<<ptr1->data;
	while(ptr->link2!=NULL)
	{	
		if(G[ptr->link2->data-1].exploration_status==0)
		{	G[ptr->link2->data-1].previous=vertex;
			DFS_VISIT(G,ptr->link2->data);
		}
		ptr=ptr->link2;
	}
	cout<<ptr1->data;
	G[vertex-1].exploration_status+=2;
	time+=1;
	G[vertex-1].d=time;
}

int main()
{
	int m;  //n is no of vertex and m is no of edge
	cin>>n>>m;
	int s;  // s is the source vertex
	int v1, v2; //(v1,v2) is an edge
	EDGE *ptr;
	for(int i=n-1;i>=0;i--)  // creating a list of vertex to create a adjacency list
	{
		EDGE *ptr1=new EDGE;
		ptr1->data=i+1;
		ptr1->link2=NULL;
		ptr1->link1=top;
		top=ptr1;
	}
	for(int i=0;i<m;i++) // creating a adjacency list
	{
		cin>>v1>>v2;
		EDGE *ptr1=new EDGE;
		ptr1->data=v2; 
		ptr1->link1=NULL;
		ptr1->link2=NULL; 
		ptr=top;
		while(1)
		{
			if(ptr->data==v1)
			{
				ptr1->link2=ptr->link2;
				ptr->link2=ptr1;
				break;
			}
			ptr=ptr->link1;
		}
	}
	cin>>s;
	GRAPH_NODE G[n];
	for(int i=0;i<n;i++)
	{
			G[i].data=i+1;
			G[i].exploration_status=0;
			G[i].previous=-1;
			G[i].f=-1;
			G[i].d=-1;
	}
	DFS(G,s);
	system("pause");
	return 0;
}
