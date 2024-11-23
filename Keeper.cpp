#include "Keeper.h"

Keeper::Keeper() {
	first = nullptr;
	last = nullptr;
	std::cout << "Конструктор объекта класса \"Keeper\" вызван" << std::endl;
	system("pause");
}
Keeper::~Keeper() {
	std::cout << "Деструктор объекта типа \"Keeper\" вызван" << std::endl;
	system("pause");
}

bool Keeper::IsEmpty() const{
	return  first == nullptr;;
}

void Keeper::Push(AEROFLOT obj){
container* buffer = new container;
	buffer->obj = obj;
	if (IsEmpty()) {
		first = last = buffer;
		buffer->next = nullptr;
		counter++;
		return;
	}
	if (buffer->obj < first->obj) {
		buffer->next = first;
		first = buffer;
		counter++;
		return;
	}
	if (first == last) {
		if(buffer->obj > first->obj){
			buffer->next = nullptr;
			last = buffer;
			first->next = last;
		}
		else {
			buffer->next = first;
			first = buffer;
		}
		counter++;
		return;
	}
	container* buffer_sort = first;
	while (buffer_sort->next != nullptr) {
		if (buffer->obj > buffer_sort->next->obj) {
			buffer_sort = buffer_sort->next;
		}
		else if (buffer->obj < buffer_sort->next->obj) {
			buffer->next = buffer_sort->next;
			buffer_sort->next = buffer;
			counter++;
			return;
		}
		else {
			buffer->next = buffer_sort->next;
			buffer_sort->next = buffer;
			counter++;
			return;
		}
	}
	buffer->next = nullptr;
	last->next = buffer;
	last = buffer;
	counter++;
}

void Keeper::LoadInFile(const std::string& filename) {
	if (IsEmpty()) {
		std::cout << "Контейнер пуст" << std::endl;
		system("pause");
		return;
	}
	std::ofstream file(filename);
	if (file.is_open()) {
		container* buffer = first;
		while (buffer->next != nullptr) {
			buffer->obj.LoadInFile(file);
			buffer = buffer->next;
		}
		buffer->obj.LoadInFile(file);
		first = last = nullptr;
		counter = 0;
		file.close();
	}
	else {
		throw std::runtime_error("Невозможно открыть файл для записи");
		std::cout << std::endl;
		system("pause");
	}
}

Keeper Keeper::LoadFromFile(const std::string& filename){

	Keeper keeper;
	std::ifstream file(filename);
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			AEROFLOT obj;
			obj.LoadFromFile(file);
			keeper.Push(obj);
			counter++;
		}
		file.close();
		return keeper;
	}
	else {
		throw std::runtime_error("Файл не читается");
		std::cout << std::endl;
		system("pause");
	}
}

void Keeper::DisplayAll() const{
	if (IsEmpty()) {
		std::cout << "Контейнер пуст" << std::endl;
		return;
	}
	if (first == last) {
		std::cout << "1 " << first->obj;
		return;

	}
	container* buffer = first;
	int i = 1;
	while (buffer != last) {
		std::cout << i++ << " " << buffer->obj;
		buffer = buffer->next;
	}
	std::cout << i << " " << buffer->obj;
}

void Keeper::Search() const{
	int counter = 0;
	if (!first) {
		std::cout << "Контейнер пуст " << std::endl;
		return;
	}
	std::string key_word;
	std::cout << "Введи название самолета для поиска: ";
	std::cin >> key_word;
	std::cout << std::endl;
	container* buffer = first;
	std::cout << "Вот что нашлось: " << std::endl << std::endl ;
	while (buffer->next != nullptr) {
		if (buffer->obj.GetAircraftType() == key_word) {
			std::cout << buffer->obj << std::endl;
			counter++;
		}
		buffer = buffer->next;
	}
	if (buffer->obj.GetAircraftType() == key_word) {
		std::cout << buffer->obj << std::endl;
		counter++;
	}
	if (counter == 0) {
		std::cout << "Ничего не найдено" << std::endl;
	}

}

void Keeper::Remove(){
	int index;
	if (IsEmpty()) {
		std::cout << "Контейнер пуст" << std::endl;
		system("pause");
		return;
	};
A:
	system("cls");
	container* buffer = first;
	DisplayAll();
	std::cout << "Введите полета в списке, который нужно удалить: ";
	std::cin >> index;
	if (index > counter || index <= 0) {
		std::cout << "Введите цифру из списка пожалуйста";
		goto A;
	}
	if (index == 1) {
		buffer = first;
		first = first->next;
		counter--;
		return;
	}
	if (index == counter) {
		buffer = first;
		while (buffer->next != last) buffer = buffer->next;
		buffer->next = nullptr;
		delete last;
		last = buffer;
		counter--;
		return;
	}
	buffer = first;
	container* buffer_prev = first;
	for (int i = 1; i < index; i++) {
		buffer_prev = buffer;
		buffer = buffer->next;
	}
	buffer_prev->next = buffer->next;
	counter--;

}

void Keeper::Edit(){
	int index;
	if (IsEmpty()) {
		std::cout << "Контейнер пуст" << std::endl;
		system("pause");
		return;
	};
A:
	system("cls");
	container* buffer = first;
	for (int i = 0; i < counter; i++) {
		std::cout << i + 1 << ". " << buffer->obj.GetFlightNumber() << std::endl;
		buffer = buffer->next;
	}
	std::cout << "Введите номер человека в списке, данные которого нужно отредактировать: ";
	std::cin >> index;
	if (index > counter || index <= 0) {
		std::cout << "Введите цифру из списка пожалуйста"; 
		goto A;
	}
	if (index == 1) {
		std::cout << "Введите новые значения: " << std::endl;
		std::cin >> first->obj;
		return;
	}
	if (index == counter) {
		std::cout << "Введите новые значения: ";
		std::cin >> last->obj;
		return;
	}
	buffer = first;
	for (int i = 1; i < index; i++) {
		buffer = buffer->next;
	}
	std::cout << "Введите новые значения: ";
	std::cin >> buffer->obj;
	counter--;
}
