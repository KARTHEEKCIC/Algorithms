#include<iostream>

using namespace std;

int flag=0;
int flag1=0;
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
	if(root->data>item)
		INSERTION(root->leftchild,item);
	else
		INSERTION(root->rightchild,item);
}

void DELETION(NODE *&root, int item)
{
	if(root!=NULL)
	{
		DELETION(root->leftchild,item);
		if(root->data==item)
		{
			flag++;
			NODE *ptr1=root;
			if(root->leftchild!=NULL)
				root=root->leftchild;
			else if(root->rightchild!=NULL)
				 {	root=root->rightchild;
				 	return;
				 }
				 else 
				 {	root=NULL;
				 	return;
				 }
			NODE *ptr=root;
			while(ptr->rightchild!=NULL)
				ptr=ptr->rightchild;
			ptr->rightchild=ptr1->rightchild;
		}	
		DELETION(root->rightchild,item);
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

void SEARCH(NODE *root, int item)
{
	if(root!=NULL)
	{
		SEARCH(root->leftchild,item);
		if(root->data==item)
		{
			cout<<root->data<<endl;
			flag1++;
		}
		SEARCH(root->rightchild,item);
	}
}

int main()
{
	NODE *root=NULL;
	int n;
	char ch;
	do
	{
		cout<<"1. INSERTION"<<endl<<"2. DELETION"<<endl<<"3. DISPLAY"<<endl<<"4. SEARCH"<<endl;
		cout<<"ENTER YOUR CHOICE :- ";
		cin>>n;
		switch(n)
		{
			case 1 : int item;
					 cout<<"ENTER DATA :- ";
					 cin>>item;
					 INSERTION(root,item);
					 break;
			case 2 : int item1;
					 cout<<"ENTER DATA :- ";
					 cin>>item1;
					 DELETION(root,item1);
					 if(flag!=0)
					 	flag=0;
					 else
					 	cout<<"ELEMENT NOT FOUND"<<endl;
					 break;
			case 3 : DISPLAY(root);
					 break;
			case 4 : int item2;
					 cout<<"ENTER THE DATA :- ";
					 cin>>item2;
					 SEARCH(root,item2);
					 if(flag1!=0)
					 	flag1=0;
					 else
					 	cout<<"ELEMENT NOT FOUND"<<endl;
					 break;
		}
		cout<<"DO YOU WANT TO CONTINUE :- ";
		cin>>ch;
	} while(ch=='y' || ch=='Y');
	system("pause");
	return 0;
}
