#include <iostream>
#include <string>

using namespace std;

class IActivity {
public:
    virtual void doActivity() const = 0;
    virtual ~IActivity() = default;
};

class Hobby : public IActivity {
protected:
    string name;
    int hoursPerWeek;
public:
    Hobby(const string& name, int hours) : name(name), hoursPerWeek(hours) {}
    virtual ~Hobby() = default;
    
    friend ostream& operator<<(ostream& os, const Hobby& hobby) {
        os << "Hobby: " << hobby.name << ", hours per week: " << hobby.hoursPerWeek;
        return os;
    }
};

class Sport : public Hobby {
protected:
    string equipment;
public:
    Sport(const string& name, int hours, const string& equip) 
        : Hobby(name, hours), equipment(equip) {}
    
    void doActivity() const override {
        cout << "Doing sport: " << name << " with " << equipment << endl;
    }
    
    friend ostream& operator<<(ostream& os, const Sport& sport) {
        os << static_cast<const Hobby&>(sport) << ", equipment: " << sport.equipment;
        return os;
    }
};

class Football : public Sport {
    int teamSize;
public:
    Football(int hours, int teamSize) 
        : Sport("Football", hours, "ball"), teamSize(teamSize) {}
    
    void doActivity() const override {
        cout << "Playing football with " << teamSize << " players in team" << endl;
    }
    
    friend ostream& operator<<(ostream& os, const Football& football) {
        os << static_cast<const Sport&>(football) << ", team size: " << football.teamSize;
        return os;
    }
};
class Music : public Hobby {
    string instrument;
public:
    Music(const string& instrument, int hours) 
        : Hobby("Music", hours), instrument(instrument) {}
    
    void doActivity() const override {
        cout << "Playing " << instrument << " for " << hoursPerWeek << " hours per week" << endl;
    }
    
    friend ostream& operator<<(ostream& os, const Music& music) {
        os << static_cast<const Hobby&>(music) << ", instrument: " << music.instrument;
        return os;
    }
};

int main() {
    Hobby* activities[] = {
        new Football(5, 11),
        new Music("Guitar", 10),
        new Sport("Tennis", 3, "racket")
    };
    
    for (const auto& activity : activities) {
        activity->doActivity();
        cout << *activity << endl << endl;
    }
    
    for (const auto& activity : activities) {
        delete activity;
    }
    
    return 0;
}
