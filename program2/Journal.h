#pragma once
#include <iostream>
using namespace std;
class Journal
{private:
	string name;
	float srMath = 0;
	float srRus = 0;
	float srPhys = 0;
public:
	Journal() {}
	Journal(string name) {
		this->name = name;
	}
	Journal(string name, float srMath, float srRus, float srPhys):Journal(name) {
		this->srMath = srMath;
		this->srRus = srRus;
		this->srPhys = srPhys;
	}
	string getName() {
		return name;
	}
	float getSrmath() {
		return srMath;
	}
	float getSrrus() {
		return srRus;
	}
	float getSrphys() {
		return srPhys;
	}
	void showInfo() {
		cout << name << " " << srMath << " : " << srRus << " : " << srPhys << endl;
	}
};


