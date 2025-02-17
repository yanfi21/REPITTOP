#include <iostream>
#include <string>
using namespace std;
class Wheels {
private:
    int radius;
    string pr;
public:
    Wheels() {
        this->radius = 0;
        this->pr = "";
    }
    Wheels(int radius, string pr) {
        this->radius = radius;
        this->pr = pr;
    }
    int getRadius() {
        return radius;
    }
    void setRadius(int radius) {
        this->radius = radius;
    }
    string getPr() {
        return pr;
    }
    void setPr(string pr) {
        this->pr = pr;
    }
    ~Wheels() {}

};
class Engine {
private:
    int power;
    int ob;
public:
    Engine() {
        this->power = 0;
        this->ob = 0;
    }
    Engine(int power, int ob) {
        this->power = power;
        this->ob = power;
    }
    int getPower() {
        return power;
    }
    int getOb() {
        return ob;
    }
    void setPower(int power) {
        this->power = power;
    }
    void setOb(int ob) {
        this->ob = ob;
    }
    ~Engine() {}

};
class Transmission {
private:
    string type;
public:
    string getType() {
        return type;
    }
    void setType(string type) {
        this->type = type;
    }
    Transmission() {
        this->type = "";
    }
    Transmission(string type) {
        this->type = type;
    }
    ~Transmission(){ }
};
class Body {
private:
    string material;
    string color;
public:
    Body() {
        this->material = "металл";
        this->color = "белый";
    }
    Body(string material, string color) {
        this->material = material;
        this->color = color;
    }
    ~Body() {}
    string getMaterial() {
        return material;
    }
    string getColor() {
        return color;
    }
    void setMaterial(string material) {
        this->material = material;
    }
    void setColor(string color) {
        this->color = color;
    }
};
class Car :Wheels, Engine, Body, Transmission
{
private:
    string model;
    string date;
    string country;
public:

    Car() :Wheels(), Engine(), Body(),Transmission()
    {
        this->model = "";
        this->date = "";
        this->country = "";

    }
    Car(string model, string date, string country, string material, string color, int power, int ob, int radius, string pr,string type) :
        Wheels(radius, pr),
        Engine(power, ob),
        Body(material, color),
        Transmission(type)
    {
        this->model = model;
        this->date = date;
        this->country = country;

    }

    string getModel() {
        return model;
    }
    string getDate() {
        return date;
    }
    string getCountry() {
        return country;
    }
    void setModel(string model) {
        this->model = model;
    }
    void setDate(string date) {
        this->date = date;
    }
    void setCountry(string country) {
        this->country = country;
    }
    friend ostream& operator<<(ostream& ostream, Car& cur) {
        ostream << "model - " << cur.model << "\n" << "date - " << cur.date << "\n" << "country - " << cur.country << endl;
        ostream << "material - " << cur.getMaterial() << "\n" << "color" << cur.getColor() << endl;
        ostream << "power - " << cur.getPower() << "\n" << "ob - " << cur.getOb() << endl;
        ostream << "radius - " << cur.getRadius() << "\n" << "pr - " << cur.getPr();
        return ostream;
    }

};
int main()
{
    Car car = Car("Bmw x3", "2024", "Germany", "Carbon", "RED", 550, 5, 21, "michlen","механика");
    cout << car;
}
