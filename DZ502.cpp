#include<iostream>
using namespace std;
class Distance {
private:
    int km;
    int m;
public:
    Distance(int km, int m) {
        this->km = km;
        this->m = m;
    }
    Distance() {
        this->km = 0;
        this->m = 0;
    }
    int getKm() {
        return km;
    }
    int getM() {
        return m;
    }
    void setkm(int km) {
        this->km = km;
    }
    void setM(int m) {
        this->m = m;
    }
    Distance operator+(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 + s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator+(int& n) {
        return Distance(km + n, m);
    }
    Distance operator-(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 - s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator*(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 * s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance operator/(Distance& second) {
        int s1, s2, s3;
        Distance answer;
        s1 = (km * 100) + m;
        s2 = (second.km * 100) + second.m;
        s3 = s1 / s2;
        km = s3 / 100;
        m = s3 % 100;
        answer.setkm(km);
        answer.setM(m);
        return answer;
    }
    Distance& operator++ () {
        km++;
        return *this;
    }
    Distance& operator++ (int)
    {
        Distance copy{ *this };
        ++(*this);
        return copy;
    }
    friend ostream& operator<<(ostream& stream, Distance& curr)
    {
        stream << "Киллометры: " << curr.km << " метры: " << curr.m << endl;
        return stream;
    }
    friend istream& operator>>(istream& stream, Distance& curr) {
        stream >> curr.km;stream >> curr.m;
        return stream;
    }
    bool operator==(Distance& second) {
        if (km == second.km && m == second.m)
            return true;
        return false;
    }
    bool operator!=(Distance& second) {
        if (km != second.km || m != second.m)
            return true;
        return false;
    }


};
int main()
{
    setlocale(LC_ALL, "rus");

}

    //l.printCyrrency();
