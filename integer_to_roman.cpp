#include <iostream>
using namespace std;

string getroman(int x){
    if (x >= 1 && x <= 4){
        return "I";
    }else if(x >= 5 && x <= 9){
        return "V";
    }else if(x >= 10 && x <= 49){
        return "X";
    }else if(x >= 50 && x <= 99){
        return "L";
    }else if(x >= 100 && x <= 499){
        return "C";
    }else if(x >= 500 && x <= 999){
        return "D";
    }else{
        return "M";
    }
}

int value_equi(string x){
    if (x == "I"){
        return 1;
    }else if (x == "V"){
        return 5;
    }else if (x == "X"){
        return 10;
    }else if (x == "L"){
        return 50;
    }else if (x == "C"){
        return 100;
    }else if (x == "D"){
        return 500;
    }else if (x == "M"){
        return 1000;
    }else{
        return 0;
    }
} 

string intToRoman(int num){
    static string s;
    static string temp;
    temp.clear();
    if (num == 0){
        cout << "hi" << endl;
        temp.assign(s);
        s.clear();
    }else if (num == 4 || num == 9){
        if (num == 4){
            s.append("IV");
            temp.assign(s);
            s.clear();
        }else{
            s.append("IX");
            temp.assign(s);
            s.clear();
        }
    }else if(num >= 40 && num < 50 || num >= 90 && num < 100){
        if (num >= 40 && num < 50){
            s.append("XL");
            intToRoman(num - 40);
        }else{
            s.append("XC");
            intToRoman(num - 90);
        }
    }else if(num >= 400 && num < 500 || num >= 900 && num < 1000){
        if (num >= 400 && num < 500){
            s.append("CD");
            intToRoman(num - 400);

        }else{
            s.append("CM");
            intToRoman(num - 900);

        }
    }else{
        string t = getroman(num);
        s.append(t);
        intToRoman(num - value_equi(t));
    }
    return temp;
}


int main(){
    cout << intToRoman(3) << endl;
    cout << intToRoman(58) << endl;
    return 0;
}