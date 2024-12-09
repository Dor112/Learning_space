#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <windows.h>
using namespace std;

class Light {
private:
	bool isOn;
public:
	void turnOn() {
		isOn = true;
	};
	void turnOff() {
		isOn = false;
	};
	string getStatus() const {
		if (isOn) {
			return "On";
		}
		else {
			return "Off";
		}
	};
	bool getState() const {
		return isOn;
	};
	void setState(bool state) {
		isOn = state;
	};
};
class Thermostat {
private:
	int temperature;
public:
	Thermostat() : temperature(20) {}
	void setTemperature(int temp) {
		temperature = temp;
	};
	int getTemperature() const {
		return temperature;
	};
};
	class SecuritySystem {
	private:
		bool isArmed;
	public:
		SecuritySystem() : isArmed(false) {};
		void arm() {
			isArmed = true;
		};
		void disarm() {
			isArmed = false;
		};
		string getStatus() const {
			if (isArmed) {
				return "Armed";
			}
			else {
				return "Disarmed";
			};
		};
		bool getState() const {
			return isArmed;
		};
		void setState(bool state) {
			isArmed = state;
		};
	};
	class Curtains {
	private:
		bool isUp;
	public:
		Curtains() : isUp(false) {}
		void raise() {
			isUp = true;
		};
		void lower() {
			isUp = false;
		};
		string getStatus() const {
			if (isUp) {
				return "Raised";
			}
			else {
				return "Lowered";
			};
		};
		bool getState() const {
			return isUp;
		};
		void setState(bool state) {
			isUp = state;
		};
	};
	class AirConditioner {
	private:
		bool isOn;
	public:
		AirConditioner() : isOn(false) {}
		void turnOn() {
			isOn = true;
		};
		void turnOff() {
			isOn = false;
		};
		std::string getStatus() const {
			if (isOn) {
				return "On";
			}
			else {
				return "Off";
			};
		};
		bool getState() const {
			return isOn;
		};
		void setState(bool state) {
			isOn = state;
		};
	};
	class SmartHome {
private:
    Light light;
	Thermostat thermostat;
    SecuritySystem securitySystem;
    Curtains curtains;
    AirConditioner airConditioner;
    const string stateFile = "home_state.txt";

    void saveState() {
        std::ofstream file(stateFile);
        if (file.is_open()) {
            file << light.getState() << "\n"
                 << thermostat.getTemperature() << "\n"
                 << securitySystem.getState() << "\n"
                 << curtains.getState() << "\n"
                 << airConditioner.getState() << "\n";
            file.close();
            cout << "State saved to " << stateFile << ".\n";
        }
    }

    void loadState() {
        std::ifstream file(stateFile);
        if (file.is_open()) {
            bool lightState, securityState, curtainsState, acState;
            int temp;

            file >> lightState >> temp >> securityState >> curtainsState >> acState;

            light.setState(lightState);
            thermostat.setTemperature(temp);
            securitySystem.setState(securityState);
            curtains.setState(curtainsState);
            airConditioner.setState(acState);

            file.close();
            cout << "State loaded from file.\n";
        } else {
            cout << "No previous state file found. Using default settings.\n";
        }
    }

public:
    SmartHome() { loadState(); }

    ~SmartHome() { saveState(); }

    void displayStatus() {
        cout << "Current State:\n";
        cout << "Light: " << light.getStatus() << "\n";
        cout << "Temperature: " << thermostat.getTemperature() << "°C\n";
        cout << "Security System: " << securitySystem.getStatus() << "\n";
        cout << "Curtains: " << curtains.getStatus() << "\n";
        cout << "Air Conditioner: " << airConditioner.getStatus() << "\n";
    }

    void controlLight(bool state) {
        
		if (state) {
			light.turnOn();
		}
		else {
			light.turnOff();
		};
    }

    void setTemperature(int temp) {
        thermostat.setTemperature(temp);
    }

    void controlSecurity(bool state) {
		if (state) {
			securitySystem.arm();
		}
		else {
			securitySystem.disarm();
		};
    }

    void controlCurtains(bool state) {
		if (state) {
			curtains.raise();
		}
		else {
			curtains.lower();
		};
    }

    void controlAirConditioner(bool state) {
		if (state) {
			airConditioner.turnOn();
		}
		else {
			airConditioner.turnOff();
		};
    }
};

void menu(SmartHome &home) {
    int choice, temp;
    do {
        home.displayStatus();
        std::cout << "\nChoose an action:\n";
        std::cout << "1. Turn on light\n";
        std::cout << "2. Turn off light\n";
        std::cout << "3. Set temperature\n";
        std::cout << "4. Arm security system\n";
        std::cout << "5. Disarm security system\n";
        std::cout << "6. Raise curtains\n";
        std::cout << "7. Lower curtains\n";
        std::cout << "8. Turn on air conditioner\n";
        std::cout << "9. Turn off air conditioner\n";
        std::cout << "10. Exit\n";

        std::cin >> choice;

        switch (choice) {
        case 1: home.controlLight(true); break;
        case 2: home.controlLight(false); break;
        case 3:
            cout << "Enter temperature: ";
            cin >> temp;
            home.setTemperature(temp);
            break;
        case 4: home.controlSecurity(true); break;
        case 5: home.controlSecurity(false); break;
        case 6: home.controlCurtains(true); break;
        case 7: home.controlCurtains(false); break;
        case 8: home.controlAirConditioner(true); break;
        case 9: home.controlAirConditioner(false); break;
        case 10: break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 10);
}

int main() {
	SmartHome home;
	menu(home);
	return 0;
};
