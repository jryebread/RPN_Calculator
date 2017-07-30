#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
/* ====== Class STACK  ========*/
//A stack data structure (LIFO) 
template<class T>
class Stack
{
public:
	bool empty();
	void push(T data);
	void pop();
	T peek();
private:
	LinkedList<T> stackData;
};

/*Function: empty
Author:	James Riback
Description: returns true if stack is empty, false if not empty
Outputs: boolean expression
*/
template<class T>
bool Stack<T>::empty()
{
	return this->stackData.isEmpty();
}

/*Function: push
Author:	James Riback
Description: pushes data onto the top of the stack
Inputs: user value
*/
template<class T>
void Stack<T>::push(T data)
{
	this->stackData.addFront(data);
}

/*Function: pop
Author:	James Riback
Description: if not empty, delete the top of the stack (pop off an element)
*/
template<class T>
void Stack<T>::pop()
{
	if (empty())
	{
		return;
	}
	else //if not empty
	{
		//delete the top element (Head) of stack
		stackData.deleteFront();
	}
}

/*Function: peek
Author:	James Riback
Description: returns top element's data (Head's Data in LL)
Outputs: Head's data
*/
template<class T>
T Stack<T>::peek()
{
	return stackData.getHead()->data;
}
#endif