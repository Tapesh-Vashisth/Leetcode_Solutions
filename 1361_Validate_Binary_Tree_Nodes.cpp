#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    vector <int> inorder(n, 0);

    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            inorder[leftChild[i]]++;
        }

        if (rightChild[i] != -1) {
            inorder[rightChild[i]]++;
        }
    }      

    queue <int> store;  

    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (inorder[i] > 1) {
            return false;
        }

        if (inorder[i] == 0) {
            counter++;
            store.push(i);
        }
    }

    if (counter != 1) {
        return false;
    }

    counter = 0;
    while (!store.empty()) {
        counter++;
        int hold = store.front();
        store.pop();

        // left 
        if (leftChild[hold] != -1) {
            inorder[leftChild[hold]]--;

            if (inorder[leftChild[hold]] == 0) {
                store.push(leftChild[hold]);
            }
        } 


        // right 
        if (rightChild[hold] != -1) {
            inorder[rightChild[hold]]--;
            
            if (inorder[rightChild[hold]] == 0) {
                store.push(rightChild[hold]);
            }
        } 

    }

    if (counter != n) {
        return false;
    }

    return true;
}

int main() {
    return 0;
}