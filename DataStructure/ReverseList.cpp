#include<iostream>

using namespace std;

struct NODE
{
	int data;
	NODE *link;
};

void REVERSE_LIST(NODE *&top)
{
	NODE *curr = top, *prev = 0, *tmp;
    while(curr!=0) {
    	tmp = curr->link;
    	curr->link = prev;
    	prev = curr;
    	curr = tmp;
    }
    top = prev;
}

int main()
{
	NODE *front=NULL, *rear=NULL;
	int n;
	for(int i=0;i<5;i++)
	{
		NODE *ptr=new NODE;
		cin>>n;
		ptr->data=n;
		ptr->link=NULL;
		if(front==NULL)
			front=rear=ptr;
		else
		{	rear->link=ptr;
			rear=ptr;
		}
	}
	rear=front;
	REVERSE_LIST(front);
	NODE *ptr=front;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->link;
	}
	return 0;
}
