//
// Created by amer0 on 10/6/2017.
//

#include "expression.h"
#include<iostream>
using namespace std;

/****Auxillary Function prototypes ****/

int getWeight(char ch);
bool IsOperator(char ch);
bool IsOperand(char ch);
int HasHigherPrecedence(char op1, char op2);
int eval(char op1, char op2, char op);


/****end function prototypes****/


expression::expression() {
    //This default constructor will call queue default constructor therefore leaving it blank.
}

expression::expression(std::string &input_expression) {
    // We will take the expression and add it to the infix stack

    for(int i=0; i<input_expression.length();i++)
    {
       infix.push(input_expression[i]);
    }

   -

}

void expression::convert_to_postfix(std::string &input_expression) {
    //iterate through the expression and apply the shunting yard algorithm to produce RPN ouput
    int i=0;
    char ch = input_expression[i];
    while(i<input_expression.length())
    {
        //If the ch is a number push it to the queue
       if(IsOperand(ch)== true)
       {
            output.enqueue(ch);
       }
        //if the operator is an operator
        if(IsOperator(ch)==true)
       {
            //While the stack is not empty and the operator is of higher precedence
           while(!operators.isEmpty()  && HasHigherPrecedence(operators.top(), ch))
           {
               //if the operator is of higher precedence then we pop the operators to the queue
               char c = operators.top();
               output.enqueue(c);
               operators.pop();

           }
            //else we are pushing to the stack
           operators.push(ch);
       }

        if(ch == '(')
        {
            operators.push(ch);

        }

        if(ch == ')')
        {
            while(operators.top() == '(')
            {
                char s = operators.top();
                if(s == '(' or ')')
                {
                    operators.pop();
                }
                output.enqueue(s);
                operators.pop();
            }
        }


    }
}

void expression::parse_to_infix(std::string &input_expression) {


}

int expression::calculate_postfix() {
    //since we saved our RPN in the output queue
    //The front of a queue will be a number
    stack result;

    while(!output.isEmpty())
    {
        char e = output.top();
        if(IsOperator(e))
        {
            int op1 = output.top();
            int op2 = output.top();

            if(e == '+')
            {
                char op3 = op1+op2;
                result.push(op3);
            }

            else if(e=='-')
            {
                char op3 = op1 - op2;
                result.push(op3);
            }

            else if(e == '*')
            {
                char op3 = op1*op2;
                result.push(op3)
            }
            else if(e == '/')
            {
                char op3 = op1/op2;
                result.push(op3);
            }


            else if(IsOperand(e))
            {
                result.push(e);
            }

        }

        cout<<"The answer is: "<<result.top()<<endl;



    }
    return result.top();
}

void expression::print_infix() {

    //Since infix the inputted expression print it out using cout!
    while(!infix.isEmpty())
    {
        cout<<infix.top();
        infix.pop();
    }

}

void expression::print_postfix() {
    while(!output.isEmpty())
    {
        cout<<output.top();
        output.dequeue();
    }
    
}

std::istream &operator>>(std::istream &steam, expression &RHS) {
    return <#initializer#>;
}


//auxillary functions

int eval(int op1, int op2, char operation)
{
    switch(operation)
            {
                    case '*': return op2 * op1;
                    case '/': return op2/op1;
                    case '+': return op2 + op1;
                    case '-': return op2 - op1;
                    default: return 0;

            }
}

int getWeight(char ch)
{
    switch (ch)
    {
        case '/': return 2;
        case '*': return 2;
        case '+': return 1;
        case '-': return 1;
        default: return 0;
    }
}

bool IsOperator(char ch)
{
if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
return true;
}
return false;
}

bool IsOperand(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return true;
    }
    return false;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = getWeight(op1);
    int op2Weight = getWeight(op2);
}




