#include <iostream>
using namespace std;

class Shop {
private:
    Shop* shop;
public:
    Shop* getShop() {
        return shop;
    }
};

class Socks {
private:

    string color;
    int size;
public:
    string getColor() {return color;}
    int getSize() { return size; }
    void setColor(string color) {
        this->color = color;
    }
    void setSize(int size) {
        this->size = size;
    }

};

class Shoes {
private:
    int size;
    int fullness;
    string color;
public:
    int getSize() {return size;}
    int getFullness() { return fullness;}
    string getColor() { return color; }
    void setSize(int size) {
        this->size = size;
    }
    void setColor(string color) {
        this->color = color;
    }
    void setFullness(int fullness) {
        this->fullness = fullness;
    }

}
