#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_max_edges = 0;

int SEARCH_CHILD(int T[], int parent, int size, int &i)
{   
    for(;i<size;i++)
        if(T[i] == parent)
        { 	i++;
        	return i;  }
    return -1;
}

void CREATE_FOREST(int T[], int root, int source, int size)
{   static int count =0 ;
    int i=0;
    while(root != -1)
    {   root =  SEARCH_CHILD(T,root,size,i);
        if(root != -1)
        {    CREATE_FOREST(T,root,source,size);
        if(T[root-1] == source)
        { if(count%2 == 0)
        {   count_max_edges++;
        	count=0;
            CREATE_FOREST(T,root,root,size);
        }
          else
        {
           	count=0;
            CREATE_FOREST(T,root,root,size);
        }	
        count = 0;
        }
        //get the root or parent
        root = T[root-1];
    	}
    }
    count++;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m;
    cin>>n>>m;
    int v1, v2;
    int T[n];
    for(int i=0;i<n;i++)
        T[i] = 0;
    int source = 1;
    for(int i=0;i<m;i++)
    {
        cin>>v1>>v2;
        T[v1-1] = v2;
    }
    CREATE_FOREST(T,1,1,n);
    cout<<count_max_edges;
    return 0;
}

