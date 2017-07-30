#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
/*TODO=================//

//===================/*/
//All header definitions below
/* struct NODE ====================*/
template <class T>
struct Node {
	T data;
	//pointers
	Node<T> *next;
	Node<T> *prev;
	Node(T data)//initialize node with user data and set ptrs to null
		:data(data), next(nullptr), prev(nullptr) {};
};

/* ====== Class LINKED LIST  ========*/
/*Doubly Link List*/		
template <class T>
class LinkedList {
private:
	Node<T> *Head;
	unsigned nodes;
	Node<T> *Tail;
	//Helper functions
	void addRoot(T value);
	Node<T> *getNode(T value);
public:
	void printList();
	void printRevList();
	LinkedList();
	bool isEmpty();
	bool insertBefore(T currVal, T value);
	bool insertAfter(T currVal, T value);
	void deleteElement(T currVal);
	unsigned size();
	void addFront(T value);
	void addBack(T value);
	//indexes
	int find(T value);
	int indexEnd();
	int indexBegin();
	//added for stack and queue
	void deleteFront();
	void deleteBack();
	Node<T> *getHead();
	Node<T> *getTail();
	void decSize();
};

/* class definitions ===============*/
//Default Constructor
template<class T>
LinkedList<T>::LinkedList()
{
	//sets the size to 0 and points the head and tail to nullptrs
	nodes = 0;
	Head = nullptr;
	Tail = nullptr;

}
/*Function: printList
Author:	James Riback
Description: traverses to the end of the Linked list
printing values out as it goes
Output: console outputs data of nodes
*/
template<class T>
void LinkedList<T>::printList()
{
	if (isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}
	//set a pointer to the head
	Node<T>*p = this->Head;
	//Traverse to the end of the list
	//printing values as we go
	while (p != nullptr)
	{
		cout << p->data << endl;
		p = p->next;
	}

}
/*Function: getHead
Author:	James Riback
Description: returns the node the head is pointing at of the LL
Output: Head node
*/
template<class T>
Node<T>* LinkedList<T>::getHead()
{
	return Head;
}
/*Function: getTail
Author:	James Riback
Description: returns the node the tail is pointing at of the LL
Output: tail node
*/
template<class T>
Node<T>* LinkedList<T>::getTail()
{
	return Tail;
}
/*Function: decSize
Author:	James Riback
Description: decrements the size of the LL 
*/
template<class T>
void LinkedList<T>::decSize()
{
	nodes--;
}

/*Function: printRevList
Author:	James Riback
Description: starts at end of link list
printing values out as it goes to the Head node
Output: console outputs data of nodes
*/
template<class T>
void LinkedList<T>::printRevList()
{
	if (isEmpty())
	{
		cout << "List is empty." << endl;
		return;
	}
	Node<T>*p = this->Tail;
	while (p != nullptr)
	{
		cout << p->data << endl;
		p = p->prev;
	}
}
/*Function: isEmpty
Author:	James Riback
Description: returns true if the linked list is empty
*/
template<class T>
bool LinkedList<T>::isEmpty()
{
	return nodes == 0;
}
/*Function: size
Author:	James Riback
Description: returns the size of the LinkedList
*/
template<class T>
unsigned LinkedList<T>::size()
{
	return nodes;
}
/*Function: addFront
Author:	James Riback
Description: pushes front a value to the LinkedList
Inputs: template value
*/
template<class T>
void LinkedList<T>::addFront(T value)
{
	//If the list is empty add a root
	if (isEmpty())
	{
		addRoot(value);
	}
	else
	{
		//Create a new node and set the data using node constructor
		Node<T> *n = new Node<T>(value);
		//point our new node's next ptr to the head
		n->next = Head;
		//attatch the next nodes previous to the new node
		n->next->prev = n;
		//point head to new node
		Head = n;
		nodes++;

	}

}
/*Function: addBack
Author:	James Riback
Description: pushes back a value to the LinkedList
Inputs: template value
*/
template<class T>
void LinkedList<T>::addBack(T value)
{
	if (isEmpty())
	{
		addRoot(value);
	}
	else
	{
		//Create a new node and set the data using node constructor
		Node<T> *n = new Node<T>(value);
		//set the nodes previous to point to tail
		n->prev = Tail;
		//attatch the previous node's next to the new node
		n->prev->next = n;
		//point tail to new node
		Tail = n;
		nodes++;
	}
}
/*Function: find
Author:	James Riback
Description: return the index of where
node is located and -1 if it is not in the list
Inputs: user inputted value
Outputs: index or -1 if node not found
*/
template<class T>
int LinkedList<T>::find(T value)
{
	int index = 0;
	Node<T> *curr = Head;
	while (curr != nullptr) {
		if (curr->data == value)
			return index;
		++index;
		curr = curr->next;
	}
	//if node not found
	return -1;
}
/*Function: indexEnd
Author:	James Riback
Description: Returns the index of the last element of the LL
Outputs: index of last node
*/
template<class T>
int LinkedList<T>::indexEnd()
{
	int index = 0;
	Node<T> *curr = Head;
	while (curr != nullptr)
	{
		index++;
		curr = curr->next;
	}
	return index - 1;
}

/*Function: indexBegin()
Author:	James Riback
Description: returns index of beginning node
Outputs: returns 0 (index of beginning node) or -1 if empty
*/
template<class T>
int LinkedList<T>::indexBegin()
{
	if (isEmpty())
		return -1;
	else
		return 0;
}


/*Function: insertBefore
Author:	James Riback
Description:  inserts a node BEFORE another value in the LL
Inputs: user inputted current node value and new value
Outputs: true if node found and insert operation was sucessfull else returns false
*/
template<class T>
bool LinkedList<T>::insertBefore(T currVal, T value) {
	//find the node to insert before
	Node<T> *curr = getNode(currVal);
	if (curr != nullptr) {
		//create new new node
		Node<T> *n = new Node<T>(value);
		//attatch new node inbetween prev node and curr
		n->prev = curr->prev;
		n->next = curr;
		curr->prev->next = n;
		curr->prev = n;

		nodes++;
		return true;
	}
	return false;
}
/*Function: insertAfter
Author:	James Riback
Description:  inserts a node AFTER another value in the LL
Inputs: user inputted current node value and new value
Outputs: true if node found and insert operation was sucessfull else returns false
*/
template<class T>
bool LinkedList<T>::insertAfter(T currVal, T value) {
	// find the node to insert after
	Node<T> *curr = getNode(currVal);
	if (curr != nullptr) {
		// create new new node
		Node<T> *n = new Node<T>(value);
		// attach new node inbetween curr and next node
		n->next = curr->next;
		n->prev = curr;
		curr->next->prev = n;
		curr->next = n;

		nodes++;
		return true;
	}
	return false;
}
/*Function: deleteElement
Author:	James Riback
Description:  deletes a node in the LinkedList
Inputs: user inputted current node value
*/
template<class T>
void LinkedList<T>::deleteElement(T currVal)
{
	if (size() == 1)
	{
		Node<T> *p = Head;
		Head = nullptr;
		Tail = nullptr;
		delete p;
		nodes--;
	}
	//If the currVal = first node or last node
	else if (find(currVal) == indexBegin())
	{
		deleteFront();
	}
	else if (find(currVal) == indexEnd())
	{
		deleteBack();
	}
	else
	{
		Node<T> *p = Head;
		//Stop at the node before the one you want to delete
		while (p->next->data != currVal)
		{
			p = p->next;
		}
		//set up the next node for deletion
		Node<T> *delptr = p->next;
		//reset pointers
		p->next = p->next->next;
		p->next->prev = p; //disconnect garbage node
						   //delete garbage node
		delete delptr;
		nodes--;
	}
}


/*Function: deleteFront
Author:	James Riback
Description:  deletes a node at the front of the LL
*/
template<class T>
void LinkedList<T>::deleteFront()
{
	if (size() == 1)
	{
		Node<T> *p = Head;
		Head = nullptr;
		Tail = nullptr;
		delete p;
		nodes--;
		return;
	}
	Node<T> *delptr = Head;
	//disconnect garbage node
	Head = Head->next;
	Head->prev = nullptr;
	delete delptr;
	nodes--;
}
/*Function: deleteFront
Author:	James Riback
Description:  deletes a node at the back of the LL
*/
template<class T>
void LinkedList<T>::deleteBack()
{
	if (size() == 1)
	{
		Node<T> *p = Tail;
		Head = nullptr;
		Tail = nullptr;
		delete p;
		nodes--;
		return;
	}
	Node<T> *delptr = Tail;
	//disconnect garbage node
	Tail = Tail->prev;
	Tail->next = nullptr;
	delete delptr;
	nodes--;
}
/* Class helper function definitions =========================== */

/*Function: addRoot
Author:	James Riback
Description:  adds a root node that both the head and tail can point to
Inputs: user inputted node value
*/
template<class T>
void LinkedList<T>::addRoot(T value) {
	// create new node
	Head = new Node<T>(value);
	// create Tail, bloop
	Tail = Head;
	nodes++;
}

/*Function: getNode
Author:	James Riback
Description:  searches through the LL to find a node corresponding to the inputted value
Inputs: user inputted node value
Outputs:  a pointer to a node
*/
template<class T>
Node<T> *LinkedList<T>::getNode(T value) {
	Node<T> *curr = Head;
	while (curr != nullptr)
	{
		if (curr->data == value)
			return curr;
		curr = curr->next;
	}
	return nullptr;
}

#endif
