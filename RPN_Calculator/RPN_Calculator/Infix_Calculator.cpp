#include "Infix_Calculator.h"
#include <string>
using std::string;

/*Function: infixcalc
Author:	James Riback
Description: converts infix value, performs postfix operation, and returns the result of the expression.
Input: User string value
Outputs: the result of the expression
*/
double Infix_Calculator::infixcalc(std::string value)
{
	//convert string value from infix to postfix
	std::string postfix = InfixToPostfix(value);
	//calculate postfix string with RPN_Calculator function
	return calc(postfix);
}

/*Function: InfixToPostfix
Author:	[majority of algorithm from here: https://gist.github.com/mycodeschool/7867739, 
James Riback -> made the tweaks to get it working with the RPN Calculator
and added the ability to parse trig functions]
Description: algorithm to take infix expression string and returns a postfix one
Input: infix string expression
Outputs: postfix string expression
*/
string Infix_Calculator::InfixToPostfix(string expression)
{
	// Declaring a stack we created
	Stack <char> S;
	string postfix = ""; // Initialize postfix as empty string.
	for (int i = 0; i < expression.length(); i++) {

		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if (expression[i] == ' ' || expression[i] == ',') continue;

		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(expression[i]))
		{
			while (!S.empty() && S.peek() != '(' && HasHigherPrecedence(S.peek(), expression[i]))
			{
				postfix += S.peek();
				S.pop();
			}
			S.push(expression[i]);
		}
		// Else if character is an operand or a decimal
		else if (IsOperand(expression[i]) || expression[i] == '.')
		{
			postfix += expression[i];
			//if the char after is an empty space or an operator, append a space in the postfix conversion string
			if (expression[i + 1] == ' ' || (IsOperator(expression[i + 1]) == true))
				postfix.append(" ");
		}
		//================================additional trig functions
		//else if its a letter like s, c , or t TRIG FUNCTIONS
		else if (isalpha(expression[i]))
		{
			//initialize string with first letter
			string trigExpression(1, expression[i]);
			//track num of increments we will go through getting all of the trig function
			int numInc = 1;
			while (expression[i + numInc] != ')')
			{
				trigExpression += expression[i + numInc];
				numInc++;
			}
			//+1 for the last parantheses )
			i = i + numInc + 1;
			trigExpression.append(")");
			postfix += trigExpression;
			postfix.append(" ");
		}
		else if (expression[i] == '(')
		{
			S.push(expression[i]);
		}

		else if (expression[i] == ')')
		{
			while (!S.empty() && S.peek() != '(') {
				//make space before and after adding operators
				postfix.append(" ");
				postfix += S.peek();
				postfix.append(" ");
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		postfix.append(" ");
		postfix += S.peek();
		S.pop();
	}
	return postfix;
}
//==========HELPER FUNCTIONS FOR INFIX CONVERSION FUNCTION=========

/*Function: isOperand
Author: from here: https://gist.github.com/mycodeschool/7867739
Description: returns true if a digit false if not
Input: char C
Outputs: boolean expression
*/
bool Infix_Calculator::IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	return false;
}

/*Function: isOperator
Author: from here: https://gist.github.com/mycodeschool/7867739
Description: function to verify whether a character is operator symbol or not. 
Input: char C
Outputs: boolean expression
*/
bool Infix_Calculator::IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

/*Function: isRightAssociative
Author: from here: https://gist.github.com/mycodeschool/7867739
Description: Function to verify whether an operator is right associative or not. 
Input: char op
Outputs: boolean expression
*/
int Infix_Calculator::IsRightAssociative(char op)
{
	if (op == '$') return true;
	return false;
}

/*Function: GetOperatorWeight
Author: from here: https://gist.github.com/mycodeschool/7867739
Description: Function to get weight of an operator. An operator with higher weight will have higher precedence. 
Input: char operator
Outputs: the weight of the operator
*/
int Infix_Calculator::GetOperatorWeight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
	case '%':
		weight = 2;
	}
	return weight;
}

/*Function: HasHigherPrecedence
Author: from here: https://gist.github.com/mycodeschool/7867739
Description: Function to determine higher precedence
Input: char operator 1 and 2
Outputs: the operator with the higher precedence
*/
int Infix_Calculator::HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if (op1Weight == op2Weight)
	{
		if (IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ? true : false;
}