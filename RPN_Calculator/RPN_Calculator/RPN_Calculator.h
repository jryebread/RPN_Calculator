#ifndef RPN_H
#define RPN_H
#include "Stack.h"
#include <string>
/* ====== Class RPN_CALCULATOR ========*/
//An postfix calculator implemented with a stack
class RPN_Calculator
{
public:
	double calc(std::string value);
private:
	Stack <double> rpnStack;
	//helper functions for RPNcalc
	bool IsOperator(char C);
	bool isTrig(std::string value);
};

#endif
