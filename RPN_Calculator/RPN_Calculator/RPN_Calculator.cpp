#include "RPN_Calculator.h"	
#include <string>
#include <cmath>

/*Function: calc
Author:	James Riback
Description: parses a user inputted string, and calculates mathematical expression.
Input: User string value
Outputs: the result of the expression
*/
double RPN_Calculator::calc(std::string value)
{ 
	//make some space just incase
	value.append(" ");

	for (int x = 0; x < value.length(); x++)
	{
		//push nums on the stack until an operator is found
		if (isalnum(value[x]))
		{
			//get the char
			std::string sNum(1, value[x]);
			// number of times to increment x (how many chars our number was)
			int numIncx = 1;
			//while the char after our found digit is not a space and not an operator
			while ((value[x + numIncx]) != ' ' && (!IsOperator(value[x + numIncx])))
			{
				//add the char to the value and inc x
				sNum += value[x + numIncx];
				numIncx++;
			}
			//check for trig function
			if (isTrig(sNum))
			{
				std::string decimal;
				double trigNum;
				for (int x = sNum.find('(') + 1; sNum[x] != ')'; x++)
				{
					decimal += sNum[x];
				}
				//convert our string to a double
				trigNum = atof(decimal.c_str());
				//check for the specific trig function and perform the trig operation
				if (sNum.substr(0, 3) == "sin")
					trigNum = sin(trigNum);
				if (sNum.substr(0, 3) == "cos")
					trigNum = cos(trigNum);
				if (sNum.substr(0, 3) == "tan")
					trigNum = tan(trigNum);
				//push on the stack the trignum
				rpnStack.push(trigNum);
				x = x + numIncx;
			}
			else {
				//convert our string to a double
				double num = atof(sNum.c_str());
				rpnStack.push(num);
				x = x + numIncx;
			}
		}
		//else if operator
		else if (IsOperator(value[x]))
		{
			//pop 2 nums off and calculate nums, push result onto stack
			//get first num
			double numHold = rpnStack.peek();
			//pop that num off stack
			rpnStack.pop();

			//get second num
			double numHold2 = rpnStack.peek();
			//pop that num off stack
			rpnStack.pop();

			//calculate numHold with new num
			if (value[x] == '+')
				numHold += numHold2;
			else if (value[x] == '-')
				numHold = numHold2 - numHold;
			else if (value[x] == '*')
				numHold *= numHold2;
			else
				numHold = numHold2 / numHold;
			//push back result
			rpnStack.push(numHold);
		}
	}
	
	return rpnStack.peek();
}
/*Function: isOperator
Author:	James Riback
Description: helper function determines if an operator char is encountered
Input: char C the possible operator
Outputs: boolean expression depending on if IsOperator
*/
bool RPN_Calculator::IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}
/*Function: isTrig
Author:	James Riback
Description: helper function determines if a trig function is encoutered in the string
Input: string value containing the possible trig function
Outputs: boolean expression
*/
bool RPN_Calculator::isTrig(std::string value)
{
	if ((value.substr(0, 3) == "sin") || (value.substr(0, 3) == "cos") || (value.substr(0, 3) == "tan"))
		return true;
	return false;
}
