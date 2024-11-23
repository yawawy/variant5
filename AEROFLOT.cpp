#include "AEROFLOT.h"

AEROFLOT::AEROFLOT(std::string dest, int num, std::string type)
	: sDestination(dest), nFlightNumber(num), sAircraftType(type) {}

AEROFLOT::AEROFLOT() {
    sDestination = "";
    nFlightNumber = 0;
    sAircraftType = "";
    std::cout << "Конструктор объекта класса \"AEROFLOT\" вызван" << std::endl;
    system("pause");
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Деструктор объекта типа \"AEROFLOT\" вызван" << std::endl;
    system("pause");
}

std::ostream& operator << ( std::ostream& os, const AEROFLOT& aeroflot) {
    os << "Полёт №" << aeroflot.nFlightNumber << " на " << aeroflot.sAircraftType
        << " в " << aeroflot.sDestination << std::endl << std::endl;
    return os;
}

std::istream& operator>> (std::istream& in, AEROFLOT& aeroflot) {
        std::string dest;
        int num;
        std::string type;
        std::cout << "Введите пункт назначения: ";
        in >> dest;
        std::cout << "Введите номер рейса: ";
        in >> num;
        std::cout << "Введите тип самолёта: ";
        in >> type;

        aeroflot.push(dest, num, type);
       
        return in;
}

bool operator<(const AEROFLOT& a, const AEROFLOT& b) {
    return a.sDestination < b.sDestination;
}

bool operator>(const AEROFLOT& a, const AEROFLOT& b) {
    return a.sDestination > b.sDestination;
}


void AEROFLOT::push(std::string dest, int num, std::string type) {
    sDestination = dest;
    nFlightNumber = num;
    sAircraftType = type;
}

std::string AEROFLOT::GetDestination() { 
    return sDestination; 
}

int AEROFLOT::GetFlightNumber() { 
    return nFlightNumber; 
}

std::string AEROFLOT::GetAircraftType() { 
    return sAircraftType; 
}

void AEROFLOT::LoadInFile(std::ofstream& file) {
    file << "Пункт назначения: " << std::endl << sDestination    << std::endl << std::endl
         << "Номер рейса: "      << std::endl << nFlightNumber  << std::endl << std::endl
         << "Тип самолёта: "     << std::endl << sAircraftType  << std::endl
         << "________________________________________________"  << std::endl;
}

void AEROFLOT::LoadFromFile(std::ifstream& file) {
    std::string line = "";
    getline(file, line);
    sDestination = line;
    getline(file, line);
    getline(file, line);
    getline(file, line);
    nFlightNumber = { std::stoi(line) };
    getline(file, line);
    getline(file, line);
    getline(file, line);
    sAircraftType = line;
    getline(file, line);
}

