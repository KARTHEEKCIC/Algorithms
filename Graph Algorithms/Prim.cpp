#include<iostream>

using namespace std;

struct NODE
{
	int data;
	int distance;
	int previous;
	NODE *link;
};

struct G_NODE
{
	int data;
	int distance;
	int previous;
};

SWAP(G_NODE P_Queue[], int i, int j)
{
	G_NODE G;
	G.data=P_Queue[i].data;
	G.distance=P_Queue[i].distance;
	G.previous=P_Queue[i].previous;
	P_Queue[i].data=P_Queue[j].data;
	P_Queue[i].distance=P_Queue[j].distance;
	P_Queue[i].previous=P_Queue[j].previous;
	P_Queue[j].data=G.data;
	P_Queue[j].distance=G.distance;
	P_Queue[j].previous=G.previous;
}

void MIN_HEAPIFY(G_NODE P_Queue[], int i, int Q_size)  // function to maintain the heap property
{
		int c1, c2, smaller;
		c1=2*i+1;
		c2=2*i+2;
		smaller=i;
		if(P_Queue[i].distance>P_Queue[c1].distance && c1<Q_size)	// checking the heap property
			smaller=c1;
		if(P_Queue[smaller].distance>P_Queue[c2].distance && c2<Q_size)
			smaller=c2;
		if(smaller==i)
			return;
		SWAP(P_Queue,smaller,i);
		i=smaller;
		if(i<Q_size/2)
			MIN_HEAPIFY(P_Queue,i,Q_size);
}

int EXTRACT_MIN(G_NODE P_Queue[], int &Q_size)  // extract the element with the minimum weight
{
	SWAP(P_Queue,0,Q_size-1);
	Q_size--;
	MIN_HEAPIFY(P_Queue,0,Q_size);
	return P_Queue[Q_size].data;
}

int P_CONTAIN(G_NODE P_Queue[], int data, int Q_size)  // to check whether the given element is present in the priority queue
{
	for(int i=0;i<Q_size;i++)
		if(P_Queue[i].data==data)
			return i;
	return -1;
}

void DECREASE_KEY(G_NODE P_Queue[], int key, int i)  // decreases the weight of the given index and maintains the heap property
{
	P_Queue[i].distance=key;
	int p=(i-1)/2;
	while(p>=0)
	{
		if(P_Queue[i].distance<P_Queue[p].distance)
		{	SWAP(P_Queue,i,p);
			i=p;
			p=(i-1)/2;
		}
		else 
			break;
	}
}

void PRIM(G_NODE P_Queue[], int source, NODE *Adj_list[], int no_of_vertex)
{
	int Q_size=no_of_vertex;
	for(int i=0;i<no_of_vertex;i++)  // initializing the priority queues elements
	{	
		if((i+1)==source)
		{	
			P_Queue[i].data=i+1;
			P_Queue[i].distance=0;
			P_Queue[i].previous=0;
		}
		else
		{
			P_Queue[i].data=i+1;
			P_Queue[i].distance=1000;
			P_Queue[i].previous=-1;
		}
	}
	SWAP(P_Queue,source-1,0); // swapping to maintain the heap property in the priority queue
	int u;  // u is the present point or point just visited by the edge of the tree
	NODE *ptr; // contains the adjacent elements of present point
	int index; // index of ptr's data element in the priority queue
	while(Q_size>0)
	{
		u=EXTRACT_MIN(P_Queue,Q_size);
		ptr=Adj_list[u-1];
		while(ptr!=NULL)
		{
			index=P_CONTAIN(P_Queue,ptr->data,Q_size);
			if(index!=-1)
			{
				if(P_Queue[index].distance>ptr->distance)  // checking whether the distance of a given node in the priority is less than the distance in the adjacency list
				{
					P_Queue[index].previous=u;
					DECREASE_KEY(P_Queue,ptr->distance,index);  // if it is less then will decrease the value in the Priority queue acc to the prims greedy algo
				}
			}
			ptr=ptr->link;  //going through all the edges of present edge u
		}
	}
}

int main()
{
	int n, m; // n and m are the no of vertices and edges in the graph respectively
	cin>>n>>m;
	int v1, v2, w;
	NODE *Adj_list[n];
	for(int i=0;i<n;i++)
		Adj_list[i]=NULL;
	NODE *ptr;
	for(int i=0;i<m;i++)  // creating the adjacency list of an undirected graph
	{
		cin>>v1>>v2>>w;
		ptr=Adj_list[v1-1];
		NODE *ptr1=new NODE;
		ptr1->data=v2;
		ptr1->distance=w;
		ptr1->previous=v1;
		ptr1->link=NULL;
		if(ptr==NULL)
			Adj_list[v1-1]=ptr1;
		else
		{	
			while(ptr->link!=NULL)
				ptr=ptr->link;
			ptr->link=ptr1;
		}
		ptr=Adj_list[v2-1];
		NODE *ptr2=new NODE;
		ptr2->data=v1;
		ptr2->distance=w;
		ptr2->previous=v2;
		ptr2->link=NULL;
		if(ptr==NULL)
			Adj_list[v2-1]=ptr2;
		else
		{	
			while(ptr->link!=NULL)
				ptr=ptr->link;
			ptr->link=ptr2;
		}
	}
	int s;  // source or root of the MST
	cin>>s;
	G_NODE P_Queue[n]; // priority queue of the prims algorithm
	PRIM(P_Queue,s,Adj_list,n);
	for(int i=n-2;i>=0;i--)  // printing the result 
		cout<<P_Queue[i].previous<<" "<<P_Queue[i].data<<" "<<P_Queue[i].distance<<endl;
	system("pause");
	return 0;
}
