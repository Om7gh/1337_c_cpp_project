
#include "RPN.hpp"

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void addNumber(std::stack<int>& stack, char c)
{
    int n1, n2;
    int sum;

    if (stack.size() < 2)
        throw std::runtime_error("Stack does not satisfy condition");
    n2 = stack.top();
    stack.pop();
    n1 = stack.top();
    stack.pop();
    switch(c)
    {
        case '+':  sum = n1 + n2;
                break;
        case '-':  sum = n1 - n2;
                break;
        case '*':  sum = n1 * n2;
                break;
        case '/':
                if (n2 == 0)
                        std::runtime_error("Can´t divide into 0");
                sum = n1 / n2;
                break;
        default:
                throw std::runtime_error("Invalid operator");
    }
    stack.push(sum);
}

int RPN(std::string& input)
{
    std::stack<int> stack;

    for (std::string::iterator it = input.begin(); it != input.end(); ++it)
    {
        if (std::isspace(*it))
            continue;

        if (std::isdigit(*it))
        {
                if (*(it + 1) != ' ' && (it + 1) != input.end() && std::isdigit(*(it + 1)))
                        throw std::runtime_error("Invalid input: Numbers must be less than 10");
                stack.push(*it - '0');
        }
        else if (isOperator(*it))
        {
            addNumber(stack, *it);
        }
        else
        {
            throw std::runtime_error("Invalid input");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Invalid input: Extra number or operator");
    return stack.top();
}
