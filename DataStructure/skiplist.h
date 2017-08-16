#ifndef SKIP_LIST
#define SKIP_LIST

#include "iostream"
#include "stdlib.h"

#define MAXLEVEL 4

template<class T>
class SLNode {
public: 
	SLNode() 
	{ }

	T info;
	SLNode<T> **links;
};

template<class T>
class SkipList {
public:
	SkipList();
	void Insert(T info);
	T* Search(T info);
	void ChoosePower();
	int ChooseLevel();
	void Display();

private:
	typedef SLNode<T>* nodePtr;
	nodePtr root[MAXLEVEL];
	int Powers[MAXLEVEL], HeadIndex;	
};

template<class T>
SkipList<T>::SkipList() {
	for(int i=0 ; i<MAXLEVEL ; i++) {
		root[i] = 0;
	}
	HeadIndex = 0;
}

template <class T>
void SkipList<T>::ChoosePower() {
	Powers[MAXLEVEL-1] = (2 << MAXLEVEL-1)-1;
	for(int i=MAXLEVEL-2, j=0;i>=0;i--,j++) {
		Powers[i] = Powers[i+1] - (2<<j);
	}
}

template<class T>
int SkipList<T>::ChooseLevel() {
	int i, RandomNumber = rand()%Powers[MAXLEVEL-1]+1;

	for(i=1 ; i<MAXLEVEL ; i++) {
		if(RandomNumber<Powers[i]) {
			return i-1;
		}
	}

	return i-1;
}

template<class T>
void SkipList<T>::Insert(T info) {
	if(root[0] == 0) {
		ChoosePower();
	}	
	
	//getting the level upto which the node should be promoted
	int level = ChooseLevel(), CurrentLevel=level;

	if(level > HeadIndex) {
		HeadIndex = level;
	}

	//creating a new node 
	nodePtr ptr = new SLNode<T>();
	ptr->info = info;
	ptr->links = new nodePtr[level+1];

	//initializing the new nodes links
	for(int i=0;i<=level;i++) {
		ptr->links[i] = 0;
	}

	//determining the position of the node in the list
	nodePtr front[level+1], back[level+1];

	front[CurrentLevel] = root[CurrentLevel];
	back[CurrentLevel] = 0;

	while(CurrentLevel >= 0) {
		if(root[CurrentLevel] == 0) {
			CurrentLevel--;
			front[CurrentLevel] = root[CurrentLevel];
			back[CurrentLevel] = 0;
		} else {
			while(front[CurrentLevel]!=0) {
				if(front[CurrentLevel]->info < info) {
					//move forward in the same level
					back[CurrentLevel] = front[CurrentLevel];
					front[CurrentLevel] = front[CurrentLevel]->links[CurrentLevel];
				} else if(front[CurrentLevel]->info == info) {
					//duplicate element found. Stop Insertion.
					std::cout<<"DUPLICATE ELEMENT !!";
					return;
				} else {
					break;  //break as we have inserted the element in the present level
				}
			}
			back[CurrentLevel-1] = back[CurrentLevel];
			if(back[CurrentLevel] == 0) {
				front[CurrentLevel-1] = front[CurrentLevel];
			}
			CurrentLevel--;
			if(back[CurrentLevel]) {
				front[CurrentLevel] = back[CurrentLevel]->links[CurrentLevel];
			}
		}
	}

	// inserting the node into the list
	for(int i=level ; i>=0 ; i--) {
		if(front[i] == 0 && back[i] == 0) {
			root[i] = ptr;
		} else if(back[i] == 0) {
			ptr->links[i] = front[i];
			root[i] = ptr;
		} else {
			back[i]->links[i] = ptr;
			ptr->links[i] = front[i];
		}
	}

}

template<class T>
T* SkipList<T>::Search(T info) {
	
	int CurrentLevel = HeadIndex;
	nodePtr curr = root[CurrentLevel], prev = curr;
	while(1) {
		if(curr == 0) {
			for(CurrentLevel--; CurrentLevel >= 0 && prev->links[CurrentLevel] == 0; CurrentLevel--);
			if(CurrentLevel >= 0) {
				curr = prev->links[CurrentLevel];
			} else {
				return 0;
			}
		}
		if(curr->info>info) {
			if(CurrentLevel == 0)
				return 0;
			else {
				if(curr == root[CurrentLevel]){
					CurrentLevel--;
					curr = prev = root[CurrentLevel];
				} else {
					CurrentLevel--;
					curr = prev->links[CurrentLevel];
				}
			}
		} else if(curr->info == info){
			return &(curr->info);
		} else {
			prev = curr;
			curr = curr->links[CurrentLevel];
		}
	}
}

template<class T>
void SkipList<T>::Display() {
	
	if(root[0]==0) {
		std::cout<<"EMPTY LIST"<<std::endl;
		return;
	}

	nodePtr ptr;
	int level = HeadIndex;
	while(level >= 0) {
		ptr = root[level];
		while(ptr != 0) {
			//print the info
			std::cout<<ptr->info<<" ";
			ptr = ptr->links[level];
		}
		std::cout<<std::endl;
		level--;
	}
}

#endif