#include "skiplist.h"

using namespace std;

int main() {
	char ch;
	SkipList<int> list;
	do {
		int n;
		cout<<"1. SEARCH"<<endl
			<<"2. INSERTION"<<endl
			<<"3. DISPLAY"<<endl;
		cout<<"ENTER YOUR CHOICE : ";
		cin>>n;
		switch(n) {
			case 1 : cout<<"ENTER THE ELEMENT TO BE SEARCHED FOR : ";
					 int e;
					 cin>>e;
					 int *element;
					 element = list.Search(e);
					 if(element == 0) {
					 	cout<<"ELEMENT NOT FOUND"<<endl;
					 	break;
					 }
					 cout<<*(element)<<endl;
					 break;
			case 2 : int e1;
					 cout<<"ENTER THE ELEMENT TO BE INSERTED : ";
					 cin>>e1;
					 list.Insert(e1);
					 break;
			case 3 : list.Display();
					 break;
			default : cout<<"WRONG INPUT !!"<<endl;
					  break;
		}
		cout<<"DO YOU WANT TO CONTINUE : ";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	return 0;
}