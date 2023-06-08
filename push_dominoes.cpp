#include <iostream>
using namespace std;

string pushDominoes(string dominoes){
    // 0 = none
    // 1 = r
    // 2 = l
    int check = 0;
    int front = 0;
    int back  = 0;
    int middle = 0;
    while (front < dominoes.size()){
        if (check == 0){
            if (dominoes[front] == '.'){
                front++;
                middle++;
            }else if(dominoes[front] == 'L'){
                for (int i = back; i < front; i++){
                    dominoes[i] = 'L';
                }
                back = (++front);
                middle = 0;
            }else{
                back = (++front);
                middle = 0;
                check = 1;
            }
        }else if(check == 1){
            if (dominoes[front] == '.'){
                front++;
                middle++;
            }else if(dominoes[front] == 'L'){
                check = 0;
                if (middle % 2 == 0){
                    for (int i = back; i < back + middle/2; i++){
                        dominoes[i] = 'R';
                    }

                    for (int i = back + middle/2; i < back + middle; i++){
                        dominoes[i] = 'L';
                    }
                }else{
                    for (int i = back; i < back + middle/2; i++){
                        dominoes[i] = 'R';
                    }

                    for (int i = back + middle/2; i < back + middle; i++){
                        dominoes[i] = 'L';
                    }

                    dominoes[back + middle/2] = '.';
                }

                back = (++front);
            }else{
                for (int i = back; i < front; i++){
                    dominoes[i] = 'R';
                }
                middle = 0;

                back = (++front);
            }
        }
    }

    if (check == 1){
        for (int i = back; i < front; i++){
            dominoes[i] = 'R';
        }
    } 
    return dominoes;
}

int main(){
    cout << pushDominoes("R.R.L") << endl;
    return 0;
}