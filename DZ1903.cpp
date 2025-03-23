#include <iostream>

using namespace std;

class SmartHome;
class SmartDevice {
	friend SmartHome;
protected:
	bool IsOn;
public:
	SmartDevice() {
		IsOn = false;
	}
	SmartDevice(bool ison) {
		IsOn = ison;
	}
	void On() {
		if (!IsOn)
			IsOn = true;
		else
			cout << "Устройство уже включено";
	}
	void Off() {
		if (IsOn)
			IsOn = false;
		else
			cout << "Устройство уже выключено";
	}
	void Check() {
		if (IsOn) 
			cout << "Устройство включено";
		else
			cout << "Устройство выключено";
		}
};
class Socket : public SmartDevice {
public :
	Socket() {
		IsOn = false;
	}
	Socket(bool ison) {
		IsOn = ison;
	}
};
class Lamp : public SmartDevice {
public:
	Lamp() {
		IsOn = false;
	}
	Lamp(bool ison) {
		IsOn = ison;
	}
};
class Speaker : public SmartDevice {
public:
	Speaker() {
		IsOn = false;
	}
	Speaker(bool ison) {
		IsOn = ison;
	}
};
class SmartHome {
private:
	Socket socket;
	Lamp lamp;
	Speaker speaker;
public:
	void OnAll() {
		socket.On();
		lamp.On();
		speaker.On();
	}
	SmartHome() {
		socket.IsOn=false;
		lamp = false;
		speaker = false;
	}
	SmartHome(bool isonlamp, bool isonspeak, bool isonsocket) {
		socket.IsOn = isonlamp;
		lamp = isonlamp;
		speaker = isonspeak;
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

}
