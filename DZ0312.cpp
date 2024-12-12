#include <iostream>
#include "string"
using namespace std;

//Задача 1
string strq(string txt, string use) {
    string qq = "aeiouy";
    int i = 0;
    while (qq[i] != NULL) {
        int z = 0;
        while (txt[z] != NULL)
        {
            if (qq[i] == txt[z]) {
                txt[z] = use[0];
            }
            z++;
        }
        i++;
    }
    return txt;
}

//Задача 2
void numword(string txt) {
    string qq = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int size = qq.size();
    int* array = new int[size] + 1;
    while (qq[i] != NULL)
    {
        array[i] = i;
        i++;
    }

   int z = 0;
    while (txt[z] != NULL)
    {
        int count = int(txt[z]) - 97;

        cout  << array[count]+1 << " " ;
        z++;
    }
    cout << endl;
    // 97 98 99 90
    //122 121 120 119

}

int Num(char word) {
    int num = word;
    int plus = 0;
    // 97(0) = 122 98(2) = 121
    while (num > 97) {
        num--;
        plus = plus + 2;
    }
    return plus;

}

//Задача 3
string up(string txt) {
    int z = 0;

    while (txt[z] != NULL)
    {
        if (int(txt[z]) >= 97 || int(txt[z]) >= 122) {
            txt[z] = int(txt[z]) - 32;
        }
        z++;
    }

    return txt;
}



//Задача 4
void polinom(string test) {
    int z = 0;
    while (test[z] != NULL)
    {
        z++;
    }
    int y = 0;
    string tset = test + " ";

    while (z > -1)
    {
        tset[y] = test[z];
        z--;
        y++;
    }
    cout << test;
    cout << " " << tset << endl;
    if (tset == test) {
        cout << "polinom" << endl;
    }
    else
        cout << "nixya ne polinom" << endl;
}




