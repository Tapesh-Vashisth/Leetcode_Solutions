#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack <string> s;
    int temp = 0;
    while (temp < tokens.size()) {
        if (tokens[temp].size() == 1 && (tokens[temp][0] == '+' || tokens[temp][0] == '-' || tokens[temp][0] == '/' || tokens[temp][0] == '*')) {
            int first = stoi(s.top());
            s.pop();
            int second = stoi(s.top());
            s.pop();

            switch (tokens[temp][0])
            {
            case '+':
                s.push(to_string(second + first));
                break;
            case '-':
                s.push(to_string(second - first));
                /* code */
                break;
            case '/':
                s.push(to_string(second / first));
                /* code */
                break;
            default:
                s.push(to_string(second * first));
                break;
            }
        } else {
            s.push(tokens[temp]);
        }

        temp++;
    }

    return stoi(s.top());
}

int main() {
    return 0;
}