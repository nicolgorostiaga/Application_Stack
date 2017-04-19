/*-- LStack.h --------------------------------------------------------------
  This header file defines a Stack data type.
  Basic operations:
    constructor:  Constructs an empty stack
    empty:        Checks if a stack is empty
    push:         Modifies a stack by adding a value at the top
    top:          Accesses the top stack value; leaves stack unchanged
    pop:          Modifies stack by removing the value at the top
    display:      Displays all the stack elements
	postFixExpression: evaluate postfix expression.
	isOperator: checks if correct operator is used.
	checkOperand: check if first two operands are not operators.
	isNum: Check if operand is within the range 0 - 9.
  Note: Execution terminates if memory isn't available for a stack element.
  Student Name: Nicol Gorostiaga
--------------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

#ifndef LSTACK
#define LSTACK

typedef int StackElement; // comment out or remove after testing.

class Stack
{
 public:
 /***** Methods *****/
 /***** Constructors *****/
   Stack();
   /*-----------------------------------------------------------------------
    Construct a Stack object.
    Precondition:  None.
    Postcondition: An empty Stack object has been constructed
        (myTop is initialized to a null pointer).
  ------------------------------------------------------------------------*/

  Stack(const Stack & original);
   /*-----------------------------------------------------------------------
    Copy constructor to create another Stack object.
    Precondition:  Another stack
    Postcondition: A copy of the stack has been created.
  ------------------------------------------------------------------------*/


 /***** Destructor *****/
  ~Stack(); 
  /*------------------------------------------------------------------------
    Class destructor 

    Precondition:  None
    Postcondition: The linked list in the stack has been deallocated.
  ------------------------------------------------------------------------*/

 /***** Assignment *****/
  const Stack & operator= (const Stack & rightHandSide);
  /*------------------------------------------------------------------------
    Assignment Operator 
    Precondition:  rightHandSide is the stack to be assigned and is 
        received as a const reference parameter.
    Postcondition: The current stack becomes a copy of rightHandSide
        and a const reference to it is returned.
  ------------------------------------------------------------------------*/

  bool empty() const;
  /*------------------------------------------------------------------------
    Check if stack is empty.
    Precondition: None
    Postcondition: Returns true if stack is empty and false otherwise.
   -----------------------------------------------------------------------*/

  void push(const StackElement & value);
  /*------------------------------------------------------------------------
    Add a value to a stack.

    Precondition:  value is to be added to this stack
    Postcondition: value is added at top of stack provided there is space;
         otherwise, a stack-full message is displayed and execution is
         terminated.
   -----------------------------------------------------------------------*/

  void display(ostream & out) const;
  /*------------------------------------------------------------------------
    Display values stored in the stack. 

    Precondition:  ostream out is open.
    Postcondition: Stack's contents, from top down, have been output to out.
   -----------------------------------------------------------------------*/

  StackElement top() const;
  /*------------------------------------------------------------------------
    Retrieve value at top of stack (if any).

    Precondition:  Stack is nonempty
    Postcondition: Value at top of stack is returned, unless the stack is 
        empty; in that case, an error message is displayed and a "garbage
        value" is returned.
   -----------------------------------------------------------------------*/

  void pop();
  /*------------------------------------------------------------------------
    Remove value at top of stack (if any).

    Precondition:  Stack is nonempty.
    Postcondition: Value at top of stack has been removed, unless the stack
        is empty; in that case, an error message is displayed and
        execution allowed to proceed.
   -----------------------------------------------------------------------*/ 
  int performOperation(char symbol, int operand1, int operand2);
  /*------------------------------------------------------------------------
  Remove value at top of stack (if any).

  Precondition:  Stack is nonempty.
  Postcondition: Value at top of stack has been removed, unless the stack
  is empty; in that case, an error message is displayed and
  execution allowed to proceed.
  -----------------------------------------------------------------------*/
  bool isNum(const char &);
  /*------------------------------------------------------------------------
  Is it a number between 0 and 9.

  Precondition:  char of string array.
  Postcondition: return true is it is between the range.
  -----------------------------------------------------------------------*/
  void postFixExpression(string &);
  /*------------------------------------------------------------------------
  Evaluate postfix Expression.

  Precondition:  string.
  Postcondition: evaluates a string postfix expression.
  -----------------------------------------------------------------------*/
  bool isOperator(const char &);
  /*------------------------------------------------------------------------
  Checks if correct operator is used.

  Precondition:  char operator from string array.
  Postcondition: returns true if operator is +,-,/,*.
  -----------------------------------------------------------------------*/
  void checkOperand(const int &, const int &);
  /*------------------------------------------------------------------------
  check if first two operands are not an operator.

  Precondition:  accepts integer operand and counter of token pushed.
  Postcondition: displays error if the postfix expression is malformed.
  -----------------------------------------------------------------------*/
 private:
   /*** Node class ***/
   class Node
   {
    public:
      StackElement data;
      Node * next;
      //--- Node constructor
	  Node(StackElement value){data = value; next = NULL;}
      /*-------------------------------------------------------------------
        Precondition:  None.
        Postcondition: A Node has been constructed with value in its data 
            part and its next part set to link (default 0).
       -------------------------------------------------------------------*/
  }; // end of class Node

  typedef Node * NodePointer;
  
  /***** Data Members *****/
  NodePointer myTop;      // pointer to top of stack

}; // end of class declaration

#endif
