/*program to check a graph for hamiltonian cycles*/

#include<iostream>

using namespace std;

int count = 0;  //variable to check whether cycle is formed or not

/*function which checks for the hamiltonian cycle*/
void CHECK_HAMILTONIAN(int G[100][100], int no_of_vertex, int node, int hVertex[], int &hCount){
	
	/*function for entering the given node and checking for the next node which can be included in the hamiltonian cycle*/
	hVertex[hCount++] = node;    //pushing the current node in the hamiltonian cycle
	/*checking for the next node*/
	for(int j=0;j<no_of_vertex;j++)           
	{	
		if(G[node-1][j]==1) // checking if an edge exists b/w j+1 vertex and present node
		{	int flag = 0;    //flag to check whether the given node is not already included in the hamiltonian cycle
			if(hCount == no_of_vertex)    //checking whether all vertices of the graph are included in the cycle 
				{	if(G[node-1][0] == 1)  //if it is the case then checking whether the given vertex has a edge with the first vertex i.e, whether cycle is formed or not
						hVertex[hCount++] = 1;  //if cycle is formed, then push 1 in to the cycle
					else
						hCount--;		//else decrease the length of cycle that is remove the present node as it not forming the cycle
					return;			//now go to the previous node check for any other node if it can form cycle
				}
			for (int k=0;k<hCount;++k)   //checking whether the j+1 vertex to be inserted in the cycle is not already present in the cycle
			{
				if(hVertex[k] == j+1)
					flag++;
			}
			if(flag == 0)  // when flag is 0 i.e, the j+1 vertex is not present in the cycle and can be included in the cycle
			{	
				//now including the j+1 vertex in to the cycle and checking for the next vertex if possible
				CHECK_HAMILTONIAN(G,no_of_vertex,j+1,hVertex,hCount);
			}
		}
	}

	// if all the above conditions fail and we are not able to achieve the cycle then we move back to previous vertex and try making cycle from adjacent vertices 
	// of that node
	if(hCount != no_of_vertex+1)
		hCount--;
}

/*function which to form hamiltonian cycle if possible and if not then update count accordingly*/
void HAMILTONIAN_GRAPH(int G[100][100], int no_of_vertex, int node, int hVertex[], int &hCount){
	
	CHECK_HAMILTONIAN(G,no_of_vertex,node,hVertex,hCount);
	//checking whether the cycle is formed or not
	if(hCount != no_of_vertex+1)
		count++;  // if count is non zero then cycle is not achieved
}

int main()
{	int n, m; //n is the no of vertices and m is the no of edges
	cin>>n>>m;
	
	int G[100][100] ={};	//adjacency matrix
	int hVertex[n+1], hCount=0;		//hamiltonian cycle and length of cycle
	
	int v1, v2;    // (v1,v2) an edge of the graph G
	//making adjacency matrix
	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2;
		G[v2-1][v1-1] = 1;
		G[v1-1][v2-1] = 1;
	}

	HAMILTONIAN_GRAPH(G,n,1,hVertex,hCount);  
	
	//Checking for the hamiltonian graph
	if(count != 0)			
		cout<<"NOT HAMILTONIAN"<<endl;
	else 
	{	cout<<"HAMILTONIAN"<<endl;
		for(int i=0;i<hCount;i++)   //printing the hamiltonian cycle if it exists
			cout<<hVertex[i]<<" ";  
		cout<<endl;
	}
	return 0;
}