#ifndef INFIX_H
#define INFIX_H
#include "Stack.h"
#include <string>
#include "RPN_Calculator.h"
using std::string;
/* ====== Class INFIX_CALCULATOR ========*/
//A normal infix calculator derived from the RPN_Calculator class
class Infix_Calculator : public RPN_Calculator
{
public:
	double infixcalc(string value);
	string InfixToPostfix(string expression);
private:
	//Helper functions for infix conversion to postfix
	bool IsOperand(char C);
	bool IsOperator(char C);
	int IsRightAssociative(char op);
	int GetOperatorWeight(char op);
	int HasHigherPrecedence(char op1, char op2);
};

#endif

