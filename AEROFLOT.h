#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>

class AEROFLOT {
private:
	std::string sDestination;
	int nFlightNumber;
	std::string sAircraftType;
public:
	AEROFLOT(std::string dest, int num, std::string type);
	AEROFLOT();

	~AEROFLOT();

	friend std::ostream& operator << (std::ostream& os, const AEROFLOT& aeroflot);
	friend std::istream& operator >> (std::istream& in, AEROFLOT& aeroflot);

	friend bool operator<(const AEROFLOT& a, const AEROFLOT& b);
	friend bool operator>(const AEROFLOT& a, const AEROFLOT& b);

	void push(std::string dest, int num, std::string type);
	
	std::string GetDestination();
	int GetFlightNumber();
	std::string GetAircraftType();

	void LoadInFile(std::ofstream& file) ;

	void LoadFromFile(std::ifstream& file);
};

