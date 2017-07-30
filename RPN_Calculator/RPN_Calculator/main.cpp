#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "RPN_Calculator.h"
#include "Infix_Calculator.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;
int main()
{
	cout << "=========DOUBLY LINKED LIST===========" << endl;
	LinkedList<int> mylist;
	mylist.addFront(42);
	mylist.addFront(37);
	mylist.addBack(24);
	mylist.addBack(33);
	mylist.printList();
	cout << endl;
	cout << "Reverse List: " << endl;
	mylist.printRevList();
	cout << endl;
	cout << "24 is at position " << mylist.find(24) << " in our Linked List." << endl;
	cout << endl;
	cout << "Beggining index: " << mylist.indexBegin() << " Ending index: " << mylist.indexEnd() << endl;
	mylist.deleteElement(42);
	mylist.deleteElement(37);
	mylist.deleteElement(24);
	mylist.deleteElement(33);
	cout << endl;
	cout << "After Deleting element(s): " << endl;
	mylist.printList();
	cout << endl;
	cout << "=========STACK===========" << endl;
	//I chose to use composition for my stack and queue because inheritance would give the openess of all of the functions
	//of the linked list, which we don't need. If we are limiting to push/pop/peek activity, then it
	//would make more sense to utilize composition. This limits the complications of the linked list
	//class, utilizing the notion of abstraction.
	Stack<int> stack;
	cout << "Pushing onto the stack nums 1, 2, 3.." << endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << "Peeking the top" << endl;
	cout << stack.peek() << endl;
	stack.pop();
	cout << "Peeking the top after pop" << endl;
	cout << stack.peek() << endl;
	stack.pop();
	cout << "Peeking the top after pop" << endl;
	cout << stack.peek() << endl;
	stack.pop();
	cout << "Pop once more, Stack is empty? " << boolalpha << stack.empty() << endl;
	stack.pop();
	cout << "=========QUEUE===========" << endl;
	Queue<string> q;
	q.enqueue("James");
	q.enqueue("Snowy");
	q.enqueue("Sunny");
	cout << "Filling the queue with 3 people... ";
	cout << "Peaking the next in line: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Peeking after dequeud a person: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Peeking after dequeud a person: " << endl;
	cout << q.peek() << endl;
	q.dequeue();
	cout << "Dequed once more, is Queue empty? : " << boolalpha << q.isEmpty() << endl;
	cout << endl;

	//INSTRUCTIONS FOR CALCULATORS: Since the function uses spaces to parse your input, 
	//please leave some space in between your numbers and operators, as well as the beggining and end of your inputted string.
	//Be careful putting trig functions inside parantheses, keep them spaced: " ( 42 * tan(45) ) "

	cout << "=========POSTFIX/INFIX CALCULATORS===========" << endl;
	RPN_Calculator calculator;
	// 10.56  1.3 + 4.2 * = (10.56 + 1.3 * 4.2) = 49.812
	cout << "Postfix Expression: 10.56 1.3 + 4.2 *\n";
	cout << "Postfix Calculator result: " << calculator.calc("10.56  1.3 + 4.2 *") << endl << endl;

	cout << "Postfix Expression: 4 2 / 2 cos(0) * +\n"; //as many spaces as you want!
	cout << "Postfix Calculator result: " << calculator.calc(" 4   2 /     2 cos(0) *      +   ") << endl << endl;

	Infix_Calculator c;
	cout << "Infix Expression: 4 / 2 + 2 * cos(0)\n";
	cout << "Infix to Postfix conversion: " << c.InfixToPostfix(" 4 / 2 + 2 * cos(0) ") << endl;
	cout << "Infix Calculator result: " << c.infixcalc(" 4 / 2  +  2 *   cos(0) ") << endl << endl; //result should be 4

	cout << "3 * 2 - sin(45) = " << c.infixcalc("( 3 *  2  - sin(45) )") << endl;
	cout << "(3+2) * 5 = " << c.infixcalc(" (3+2) * 5 ") << endl; //parantheses test
	cout << "3 + 2 * 5 = " << c.infixcalc(" 3 + 2 * 5 ") << endl;
	cout << "7 - 4 + 9 / 4 = " << c.infixcalc(" 7 - 4 + 9 / 4") << endl; //5.25 because division has higher precedence
	cout << "(7 - 4 + 9) / 4 = " << c.infixcalc(" (7 - 4 + 9) / 4") << endl << endl; //3 because parans
	//SUPER DOOPER TEST
	cout << "Infix to Postfix conversion: " << c.InfixToPostfix(" sin(12) + 947.63 + ( 27.22 - tan(0) ) * 6 / 123.54) - 442.488 + cos(2) ") << endl;
	//should be 505.511281217 according to google calculator
	cout << "Infix Calculator result: " << c.infixcalc(" sin(12) + 947.63 + ( 27.22 - tan(0) ) * 6 / 123.54) - 442.488 + cos(2) ") << endl;

	return 0;
}