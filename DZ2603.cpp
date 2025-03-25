#include <iostream>
using namespace std;
class Shipher {
public:
    virtual string Crypt() = 0;
};
class Caesar : Shipher {
private:
    string old;
    int pass;
public:
    string Crypt() {
        
        if (pass<0)
            throw "Paasword<0";

        for (int i = 0; i < old.length(); i++)
            old[i] += pass;
        return old;
        
    }
    Caesar() {
        old = "";
        pass = 0;
    }
    Caesar(string old, int pass) {
        Crypt();
        this->old = old;
        this->pass = pass;
    }
    void print() {
        cout << old << endl ;
    }
};
class Atbash : Shipher {
private:
    string old;
public:
    Atbash() {
        old = "";
    }
    Atbash(string old) {
        this->old = old;
    }
    string Crypt() {

        int a;
        for (int i = 0; i < old.length(); ++i) {
            char ch = old[i];
            if ('А' <= ch && ch <= 'Я') { 
                old[i] = 'Я' - (ch - 'А');
            }
            else if ('а' <= ch && ch <= 'я') {
                old[i] = 'я' - (ch - 'а');
            }
        }

        return old;
    }
    void print() {
        cout << old << endl ;
    }
};
class MyShipher :Shipher{
private:
    string old;
public:
    MyShipher() {
        old = "";
    }
    MyShipher(string old) {
        this->old = old;
    }
    string Crypt() {
        for (int i = 0; i < old.length();i++) {
            old[i] += char(i);
        }
        return old;
    }
    void print() {
        cout << old << endl ;
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    Atbash b{ "абв" };
    b.Crypt();
    b.print();
    MyShipher c{ "абв" };
    b.Crypt();
    b.print();
    try {
        Caesar a{ "абвul",-1 };
        a.Crypt();
        a.print();
    }
    catch (const char* message) {
        cout << message;
    }
}
