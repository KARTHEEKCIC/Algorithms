#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Q_NODE
{
  int data;
  Q_NODE *next_link;
};

struct NODE
{
  int data;
  int exploration_status;
  int previous;
  int distance;
};

Q_NODE *front=NULL;
Q_NODE *rear=NULL;
int Adj_Mat[1000][1000];


void PUSH(int x)
{ 
  Q_NODE *ptr=new Q_NODE;
  ptr->data=x;
  ptr->next_link=NULL;
  if(front==NULL)
    front=rear=ptr;
  else
  {
    rear->next_link=ptr;
    rear=ptr;
  }  
}

int POP()
{
  Q_NODE *ptr=new Q_NODE;
  if(front==rear)
  { 
    ptr=front;
    front=rear=NULL;
  }
  else
  {
    ptr=front;
    front=front->next_link;    
    ptr->next_link=NULL;
  }
  return ptr->data;
}
  
void BFS(NODE G[], int s, int vertex)
{ 
  PUSH((G[s-1].data));
  int u;
  while(front!=NULL)
  {
    u=POP();
    for(int i=0; i<vertex ;i++)
    { if(Adj_Mat[u-1][i]==1 && G[i].exploration_status==0)
      {
        G[i].exploration_status=1;
        G[i].previous=u;
        G[i].distance=G[u-1].distance+6;
        PUSH((G[i].data));
      } 
    }   
    G[u-1].exploration_status=2;
  }
}

int main() {  
    int q;
    cin>>q;
    int n[q], m[q];
    NODE G[q][1000];
    for(int i=0; i<q; i++)
    {
       cin>>n[i]>>m[i];
       for(int j=0;j<n[i];j++)
         for(int k=0;k<n[i];k++)
            Adj_Mat[j][k]=0;
       int v1, v2; 
       int s;
       for(int j=0;j<m[i];j++)
       { cin>>v1>>v2;
         Adj_Mat[v1-1][v2-1]=1;
         Adj_Mat[v2-1][v1-1]=1;
       }     
       cin>>s; 
       for(int j=0;j<n[i];j++)
       { if((j+1)==s)
         {
            G[i][j].data=j+1;
            G[i][j].exploration_status=1;
            G[i][j].previous=0;
            G[i][j].distance=0;
         }
         else
         {  G[i][j].data=j+1;
            G[i][j].exploration_status=0;
            G[i][j].previous=0;
            G[i][j].distance=-1;
         }
       }
       BFS(G[i],s,n[i]);
    } 
    for(int i=0;i<q;i++)
    {
      for(int j=0;j<n[i];j++)
       if(G[i][j].distance!=0) 
        cout<<G[i][j].distance<<" ";
      cout<<endl;
    }
    system("pause");
    return 0;
}
