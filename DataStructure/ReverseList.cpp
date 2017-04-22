#include<iostream>

using namespace std;

struct NODE
{
	int data;
	NODE *link;
};

void REVERSE_LIST(NODE *&top)
{
	NODE *ptr=NULL;
	NODE *ptr1=NULL;
	while(1)  // algo to reverse the list
	{ 
		if(top!=NULL)
			ptr=top->link;
		else
		{	top=ptr1;
			break;
		}
		top->link=ptr1;
		if(ptr!=NULL)
			ptr1=ptr->link;
		else 
			break;
		ptr->link=top;
		if(ptr1!=NULL)
			top=ptr1->link;
		else
		{	top=ptr;
			break;
		}
		ptr1->link=ptr;
	}
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
	system("pause");
	return 0;
}
