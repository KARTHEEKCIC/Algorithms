#include<iostream>
using namespace std;

int type;
int flag=0;
int z=0;

struct NODE
{	
	int data;
	NODE *leftchild;
	NODE *rightchild;
};
NODE* CREATE_NODE(int item)
{
	NODE *ptr=new NODE;
	ptr->data=item;
	ptr->leftchild=NULL;
	ptr->rightchild=NULL;
	return ptr;
}
void INSERTION(NODE *&root, int item)
{
	if(root==NULL)
	{
		root=CREATE_NODE(item);
		return;	
	}

	if (z%2==0)
	{	INSERTION(root->rightchild,item);	
		z++;
	}
	else 
	{	INSERTION(root->leftchild,item);
		z++;
	}
}

void DISPLAY(NODE *root)
{
	if(root!=NULL)
	{
		DISPLAY(root->leftchild);
		cout<<root->data<<endl;
		DISPLAY(root->rightchild);
	}
}

void CHECK_BST(NODE *root)
{
	if(root!=NULL && flag==0)
	{
		CHECK_BST(root->leftchild);
		CHECK_BST(root->rightchild);
		if(root->leftchild!=NULL)
		 if(root->data < root->leftchild->data)
			flag++;
		if(root->rightchild!=NULL)
		 if(root->data > root->rightchild->data)
			flag++;
    }
}

int main()
{
    NODE *root=NULL;
	char ch;
	int n;
	do
	{
		cout<<"1. INSERTION"<<endl<<"2. DISPLAY"<<endl<<"3. CHECK BST"<<endl;
		cout<<"ENTER YOUR CHOICE : - ";
		cin>>n;
		switch(n)
		{
			case 1 : int item;
					 cout<<"ENTER THE DATA :- ";
					 cin>>item;
					 INSERTION(root,item);
					 break;
			case 2 : DISPLAY(root);
					 break;
			case 3 : CHECK_BST(root);
					 if(flag!=0)
					 	cout<<"IT IS NOT A BINARY SEARCH TREE"<<endl;
					 else 
					 	cout<<"IT IS BINARY SEARCH TREE"<<endl;
					 break;
			default : cout<<"INVALID CHOICE...";

		}
	cout<<"DO YOU WANT TO CONTINUE :- ";
	cin>>ch;

	} while(ch=='y' || ch=='Y');
	system("pause");
	return 0;
}
