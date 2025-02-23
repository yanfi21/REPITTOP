#include <iostream>
#include<string>
using namespace std;

class Employee {
private:
    string name;
    int salary;
public:
    Employee(string name, int salary) {
        this->name = name;
        this->salary = salary;
    }
    Employee() {
        this->name = " ";
        this->salary = 0;
    }
    string getName() {
        return name;
    }
    int getSalary() {
        return salary;
    }
    void setName(string name) {
        this->name = name;
    }
    void setSalary(int salary) {
        this->salary = salary;
    }
    virtual int calculateBonus() {
        int bonus = 10;
        return bonus;
    }
};

class Manager :Employee {
private:
    int numberOfSubordinates;
public:
    Manager(string name, int salary, int numberOfSubordinates) :Employee(name, salary) {
        this->numberOfSubordinates = numberOfSubordinates;
    }
    int getNumberOfSubordinates() {
        return numberOfSubordinates;
    }
    void setNumberOfSubordinates(int setNumberOfSubordinates) {
        this->numberOfSubordinates = numberOfSubordinates;
    }
    int calculateBonus() {
        int bonus = 10;
        if (numberOfSubordinates >= 10 && getSalary() >= 1000)
            return bonus;
        else
            return bonus - 5;
    }
};
class Developer:Employee {
private:
    int numberOfProjects;
public:
    Developer(string name, int salary, int numberOfProjects) :Employee(name, salary) {
        this->numberOfProjects = numberOfProjects;
    }
    int getNumberOfProjects() {
        return numberOfProjects;
    }
    void setNumberOfProjects(int numberOfProjects) {
        this->numberOfProjects = numberOfProjects;
    }
    int calculateBonus() {
        int bonus = 10;
        if (getSalary() > 1000 && numberOfProjects > 2) 
            return bonus;
        
        else
            return bonus - 5;
    }
};
class Intern:Employee {
private:
    int internshipDuration;
public:
    Intern(string name, int salary, int internshipDuration) :Employee(name, salary) {
        this->internshipDuration = internshipDuration;

    }
    int getInternshipDuration() {
        return internshipDuration;
    }
    void setInternshipDuration(int internshipDuration) {
        this->internshipDuration = internshipDuration;
    }
    int calculateBonus() {
        int bonus = 10;
        if (internshipDuration > 3)
            return bonus;
        return 0;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Employee n = Employee();
    Manager manager = Manager("gosha", 10000, 9);
    Developer developer = Developer("koshka", 20000, 3);
    Intern intern = Intern("f", 500, 3);
    cout << "бонус = "<< manager.calculateBonus() << endl;
    cout << "бонус = " << developer.calculateBonus() << endl;
    cout << "бонус = " << intern.calculateBonus() << endl;
}
