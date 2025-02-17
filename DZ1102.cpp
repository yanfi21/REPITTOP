#include <iostream>
#include<string>
using namespace std;

class Cone {
private:
	int x;
	int y;
	int radius;
	int height;
	int l;
public:
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getRadius() {
		return radius;
	}
	int getHeight() {
		return height;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setRadius(int radius) {
		this->radius = radius;
	}
	void setHeight(int height) {
		this->height = height;
	}
	int getL() {
		return l;
	}
	void setL(int l) {
		this->l = l;
	}
	Cone() {
		this->x = 0;
		this->y = 0;
		this->radius = 0;
		this->height = 0;
		int l = 0;
	}
	Cone(int x,int y,int radius,int height,int l) {
		this->x = x;
		this->y = y;
		this->radius = radius;
		this->height = height;
		this->l = l;
	}
	double findS() {
		const double pi = 3.14;
		double m = pi * this->radius * this->l;
		return m;
	}
	double findOb() {
		const double pi = 3.14;
		double m = (pi * this->radius * this->radius * this->height) / 3;
		return m; 
	}
	friend ostream& operator<<(ostream& ostream, Cone& cur) {
		ostream << "x - " << cur.x << "y - " << cur.y << "radius - " << cur.radius << "height  - " << cur.height<<cur.l;
		return ostream;
	}
	friend istream& operator>>(istream& istream, Cone& cur) {
		istream >> cur.x >> cur.y >> cur.radius >> cur.height;\
			return istream;
	}

};

class UsCone : Cone
{
private:
	int r2;
public:
	int getR2() {
		return r2;
	}
	void setR2(int r2) {
		this->r2 = r2;
	}
	UsCone(int x, int y, int radius, int height,int l, int r2) :Cone(x, y, radius, height,l) {
		this->r2 = r2;
	}
	UsCone() :Cone() {
		this->r2 = 0;
	}
	virtual double findS() {
		const double pi = 3.14;
		double s = pi * this->getL() * (this->getRadius() + this->r2);
		return s;
	}
	virtual double findOb() {
		const double pi = 3.14;
		double v = (pi / 3) * this->getHeight() * (this->getRadius() * this->getRadius() + this->getRadius() * this->r2 + this->r2 * this->r2);
		return v;
	}
	friend ostream& operator<<(ostream& ostream, UsCone& cur) {
		ostream << "x - " << cur.getX() << "y - " << cur.getY() << "radius - " << cur.getRadius() << "height  - " << cur.getHeight() << cur.getL()<<"r2 - "<<cur.getR2();
		return ostream;
	}
	bool operator==(Cone& cone) {
		if (findOb() == cone.findOb())
			return true;
		return false;
	}
	bool operator>(Cone& cone) {
		if (findOb() > cone.findOb())
			return true;
		return false;
	}
	bool operator<(Cone& cone) {
		if (findOb() < cone.findOb())
			return true;
		return false;
	}
};



int main() {
	
	Cone cone = Cone(10,10,13,10,10);
	cout << cone.findOb()<<" ";
	cout << cone.findS() << endl;
	UsCone usCone = UsCone(10, 10, 13, 20, 10, 12);
	cout<<usCone.findOb();

}
