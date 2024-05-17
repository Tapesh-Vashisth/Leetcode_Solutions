#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue <int> studentQueue;
    stack <int> sandwichStack;
    for (int i = 0; i < students.size(); i++) {
        studentQueue.push(students[i]);
        sandwichStack.push(sandwiches[students.size() - i - 1]);
    }    


    while (true) {
        int size = studentQueue.size();

        for (int i = 0; i < size; i++) {
            int hold = studentQueue.front();
            studentQueue.pop();

            if (hold == sandwichStack.top()) {
                sandwichStack.pop();
            } else {
                studentQueue.push(hold);
            }
        }

        if (studentQueue.size() == size) {
            return size;
        }
    }

    return 0;
}

int main() {
    return 0;
}