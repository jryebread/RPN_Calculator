#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"
/* ====== Class QUEUE ========*/
//A queue data structure (FIFO)
template<class T>
class Queue
{
public:
	bool isEmpty();
	void enqueue(T value);
	void dequeue();
	T peek();
private:
	LinkedList<T> qdata;
};
#endif

/*Function: isEmpty
Author:	James Riback
Description: returns true if queue is empty, false if not empty
Outputs: boolean expression
*/
template<class T>
bool Queue<T>::isEmpty()
{
	return qdata.isEmpty();
}

/*Function: enqueue
Author:	James Riback
Description: adds a value to the back of the queue
Inputs: user inputted value
*/
template<class T>
void Queue<T>::enqueue(T value)
{
	//create new node add to back of line (enqueue)
	this->qdata.addBack(value);
}

/*Function: dequeue
Author:	James Riback
Description: if not empty, delete the front of the queue (dequeue)
*/
template<class T>
void Queue<T>::dequeue()
{
	if (qdata.isEmpty())
	{
		return;
	}
	else //if not empty
	{
		//delete the next element in line (Head)
		qdata.deleteFront();
	}
}

/*Function: peek
Author:	James Riback
Description: return the next in line of the queue's data (Head's data)
Outputs: Head data
*/
template<class T>
T Queue<T>::peek()
{
	return qdata.getHead()->data;
}
