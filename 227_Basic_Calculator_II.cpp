#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int parseInt(string & s, int & start) {
    int num = 0;
    while (start < s.size() && s[start] >= '0' && s[start] <= '9') {
        num = (num * 10) + (s[start] - '0');
        start++;
    }

    return num;
}

int getPrecedence(char opera) {
    if (opera == '+' || opera == '-') {
        return 1;
    } else {
        return 2;
    }
}

int calculate(string s) {
    int index = 0;

    stack <int> numbers;
    stack <char> operators;
    while (index < s.size()) {
        if (s[index] == ' ') {
            index++;
        } else if (s[index] >= '0' && s[index] <= '9') {
            int hold = parseInt(s, index);
            numbers.push(hold);
        } else {
            int precedence = getPrecedence(s[index]);
            while (precedence <= getPrecedence(operators.top())) {
                int second = numbers.top();
                numbers.pop()    ;

                int first = numbers.top();
                numbers.pop();

                if (operators.top() == '+') {
                    numbers.push(first + second);
                } else if (operators.top() == '-') {
                    numbers.push(first - second);
                } else if (operators.top() == '*') {
                    numbers.push(first * second);
                } else if (operators.top() == '/') {
                    numbers.push(first / second);
                }

                operators.pop();
            }

            operators.push(s[index]);
        }   
    }

    return numbers.top();
}

int main() {
    return 0;
}