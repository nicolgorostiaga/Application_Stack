//--- LStack.cpp -------------------------------------------------
 
#include <new>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#include "LStack.h"

//--- Definition of Stack constructor
Stack::Stack(){myTop = NULL;}

//--- Definition of Stack copy constructor
Stack::Stack(const Stack & original)
{
   myTop = NULL;
   if (!original.empty())
   {
      // Copy first node
      myTop = new Stack::Node(original.top());

      // Set pointers to run through the stacksÕ linked lists
      Stack::NodePointer lastPtr = myTop,
                         origPtr = original.myTop->next;

      while (origPtr != NULL)
      {
         lastPtr->next = new Stack::Node(origPtr->data);
         lastPtr = lastPtr->next;
         origPtr = origPtr->next;
      }
   }
}// end copy constructor

//--- Definition of Stack destructor
Stack::~Stack()
{     
   // Set pointers to run through the stack
	Stack::NodePointer currPtr = myTop;  // node to be deallocated
                      
   while (currPtr != NULL)
   {
      myTop = myTop->next;
      delete currPtr;
      currPtr = myTop;
   }
}//end destructor

//--- Definition of assignment operator
const Stack & Stack::operator=(const Stack & rightHandSide)
{
   if (this != &rightHandSide)         // check that not st = st
   {
      this->~Stack();                  // destroy current linked list
     // if (rightHandSide.empty())       // empty stack
       //  myTop = 0;
      //else
      //{                                // copy rightHandSide's list
         // Copy first node
         myTop = new Stack::Node(rightHandSide.top());

         // Set pointers to run through the stacks' linked lists
         Stack::NodePointer lastPtr = myTop,
                            rhsPtr = rightHandSide.myTop->next;

         while (rhsPtr != 0)
         {
            lastPtr->next = new Stack::Node(rhsPtr->data);
            lastPtr = lastPtr->next;
            rhsPtr = rhsPtr->next;
         } 
      //}
   }
   return *this;
}// end overloaded assignment operator

//--- Definition of empty()
bool Stack::empty() const
{ 
   return (myTop == NULL); 
}// end empty

//--- Definition of push()
void Stack::push(const StackElement & value)
{
	Stack::NodePointer top = new Stack::Node(value);
	top->next = myTop;
	myTop = top;
   //myTop = new Stack::Node(value, myTop);
}// end push

//--- Definition of display()
void Stack::display(ostream & out) const
{
   Stack::NodePointer ptr;
   for (ptr = myTop; ptr != 0; ptr = ptr->next)
      out << ptr->data << endl;
}// end display

//--- Definition of top()
StackElement Stack::top() const
{
   if (!empty())
      return (myTop->data);
   else
   {
      cerr << "*** Stack is empty "
              " -- returning garbage ***\n";
      StackElement * temp = new(StackElement);  
      StackElement garbage = *temp;     // "Garbage" value
      delete temp;
      return garbage;
   }
}// end top

//--- Definition of pop()
void Stack::pop()
{
   if (!empty())
   {
      Stack::NodePointer ptr = myTop;
      myTop = myTop->next;
      delete ptr;
   }   
   else
      cerr << "*** Stack is empty -- can't remove a value ***\n";
}// end pop
int Stack::performOperation(char symbol, int operand1, int operand2) {
	switch (symbol) {
	case '+': return operand2 + operand1; 
	case '-':return operand2 - operand1; 
	case '*':return operand2 * operand1;
	case '/':return operand2 / operand1;
	default: return -1;// if operator is not found.
	}
}

bool Stack::isNum(const char &input) {
	if (input >= '0' && input <= '9')return true;
	return false;
}
bool Stack::isOperator(const char &input) {
	switch (input) {
	case '+':return true;
	case '-':return true;
	case '*':return true;
	case '/':return true;
	}
	return false;
}
void Stack::checkOperand(const int &input,const int &counter) {
	if (!isOperator(input) && counter < 2) {
		cout << "Error - malformed postfix expression." << endl;
		exit(1107);
	}
}
void Stack::postFixExpression(string &input) {
	Stack s;
	int result;
	for (int unsigned i = 0; i < input.length(); i++) {
		//if (input.at(i) == ' ')continue;// skip over space
		if (isOperator(input.at(i))) {
			cout << "\nToken: " << input.at(i) << "   ";
			int operand1 = s.top();
			checkOperand(operand1, i);
			cout << "Pop " << s.top() << "    ";
			s.pop();
			int operand2 = s.top();
			checkOperand(operand2, i);
			cout << "Pop " << s.top() << "    ";
			s.pop();
			result = performOperation(input.at(i), operand1, operand2);
			if (result < 0)
				cout << "error - malformed postfix expression." << endl;
			else {
				s.push(result);
				cout << "Push " << result << endl;
			}
		}
		//cout << "error - malformed postfix expression." << endl;
		//exit(1107);
		else if(isNum(input.at(i))){
			s.push(input.at(i) - '0');
			cout << "\nToken = " << input.at(i) << "   ";
			cout << "Push " << s.top() << endl;
		}
		else {
			cout << "\nToken = " << input.at(i) << "   ";
			cout << "Pop " << result << endl;
			exit(1107);
		}
	}//end for
}
		
