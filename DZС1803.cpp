#include <iostream>
using namespace std;

class Predator {
protected:
    string name;
    int size;
public:
    Predator() {
        name = "";
        size = 0;
    }
    Predator(string name, int sizee) {
        if (sizee < 0)
            cout << "ошибка размера";
        else {
            this->name = name;
            size = size;
        }
    }
    virtual void print() {
        cout << "название: " << name << endl;
        cout << "размер:  " << size << endl;
    }
    bool operator<(const Predator& l) {
        if (this->size < l.size)
            return true;
        return false;
    }
    bool operator>(const Predator& l) {
        if (this->size > l.size)
            return true;
        return false;
    }
    void operator++() {
        this->size++;
    }
    Predator operator+(Predator& l) {
        this->size += l.size;
        return *this;
    }
};

class Animal :public Predator {
protected:
    string diet;
    int konechnost;
public:
    Animal(string name, int sizee, string diett, int kon) {
        if (sizee < 0 || kon <= 0)
            cout << "ошибка";
        else {
            name = name;
            size = size;
            diet = diett;
            konechnost = kon;
        }
    }
    Animal() {
        name = "";
        size = 0;
        diet = "";
        konechnost = 0;
    }
    virtual void print() {
        cout << "название: " << name << endl;
        cout << "размер:  " << size << endl;
        cout << "кого ест: " << diet << endl;
        cout << "количество конечностей: " << konechnost << endl;
    }
    bool operator<(const Animal& l) {
        if (this->size < l.size && this->konechnost < l.konechnost)
            return true;
        return false;
    }
    bool operator>(const Animal& l) {
        if (this->size > l.size && this->konechnost > l.konechnost)
            return true;
        return false;
    }
    void operator++() {
        this->size++;
        this->konechnost++;
    }
    Predator operator+(Animal& l) {
        this->size += l.size;
        this->konechnost += l.konechnost;
        return *this;
    }

};

class Fish :public Animal {
protected:
    string issalt;
    int ikra;
public:
    Fish(string name, int sizee, string diiet, int kon, string salt, int ikr) {
        if (sizee < 0 || kon < 0 || ikr <= 0) {
            cout << "ошибка";
        }
        else {
            diet = diiet;
            size = sizee;
            konechnost = kon;
            ikra = ikr;
            this->name = name;
            issalt = salt;
        }
    }
    Fish() {
        diet = "";
        size = 0;
        konechnost = 0;
        ikra = 0;
        name = "";
        issalt = "";
    }
    virtual void print() {
        cout << "название: " << name << endl;
        cout << "размер:  " << size << endl;
        cout << "в какой воде плавает: " << issalt << endl;
        cout << "кого ест: " << diet << endl;
        cout << "в какой воде: " << issalt << endl;
        cout << "сколько икры: " << ikra;
    }
    bool operator<(const Fish& l) {
        if (this->size < l.size && this->konechnost < l.konechnost && this->ikra < l.ikra)
            return true;
        return false;
    }
    bool operator>(const Fish& l) {
        if (this->size > l.size && this->konechnost > l.konechnost && this->ikra < l.ikra)
            return true;
        return false;
    }
    void operator++() {
        this->size++;
        this->konechnost++;
        this->ikra++;
    }
    Predator operator+(Fish& l) {
        this->size += l.size;
        this->konechnost += l.konechnost;
        this->ikra += l.ikra;
        return *this;
    }
};

class Reptile :public Animal {
protected:
    string iswater;
    int perep;
public:
    Reptile() {
        name = "";
        size = 0;
        diet = "";
        konechnost = 0;
        perep = 0;
        iswater = "";
    }
    Reptile(string name, int sizee, string diett, int kon, string water, int perepon) {
        if (sizee < 0 || kon <= 0 || perepon <= 0)
            cout << "ошибка";
        else {
            perep = perepon;
            iswater = water;
            name = name;
            size = size;
            diet = diett;
            konechnost = kon;
        }
    }
    void print() {
        cout << "название: " << name << endl;
        cout << "размер:  " << size << endl;
        cout << "кого ест: " << diet << endl;
        cout << "количество конечностей: " << konechnost << endl;
        cout << "живет ли в воде: " << iswater << endl;
        cout << "количество пальцев: " << perep << endl;
    }
    bool operator<(const Reptile& l) {
        if (this->size < l.size && this->konechnost < l.konechnost && this->perep < l.perep)
            return true;
        return false;
    }
    bool operator>(const Reptile& l) {
        if (this->size > l.size && this->konechnost > l.konechnost && this->perep < l.perep)
            return true;
        return false;
    }
    void operator++() {
        this->size++;
        this->konechnost++;
        this->perep++;
    }
    Predator operator+(Reptile& l) {
        this->size += l.size;
        this->konechnost += l.konechnost;
        this->perep += l.perep;
        return *this;
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    Fish sdf{ "salt",10,"ribke",2,"shuka",1 };
    Fish asdf{ "salt",1123,"ribke",3,"shuka",3 };
    if (sdf < asdf)
        cout << "bigger 2" << endl;
    else
        cout << "bigger 1" << endl;

}
