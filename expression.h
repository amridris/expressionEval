//
// Created by amer0 on 10/6/2017.
//

#ifndef STACKS_QUEUE_LAB5_EXPRESSION_H
#define STACKS_QUEUE_LAB5_EXPRESSION_H


#include "queue.h"
#include "stack.h"

class expression {
    stack  operators;
    queue output;
    stack infix;


    void convert_to_postfix(std::string &input_expression);
    void parse_to_infix(std::string &input_expression);
public:
    expression();
    expression(std::string& input_expression);

    int calculate_postfix();
    void print_infix();
    void print_postfix();
    friend std::istream& operator>>(std::istream& steam, expression& RHS);
};



#endif //STACKS_QUEUE_LAB5_EXPRESSION_H
