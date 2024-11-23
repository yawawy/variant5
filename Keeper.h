#pragma once
#include "AEROFLOT.h"

class Keeper {
public:
    struct container {
        AEROFLOT obj;
        container* next;
    };
    int counter = 0;
    container* first;
    container* last;

    Keeper();
    ~Keeper();

    bool    IsEmpty() const;// Проверка на пустоту
    void    Push(AEROFLOT obj); // Добавление объекта в контейнер
    void    LoadInFile(const std::string& filename) ; // Сохранение данных в файл
    Keeper  LoadFromFile(const std::string& filename); // Загрузка данных из файла
    void    DisplayAll() const; // Вывод всех объектов, отсортированных по номеру рейса 
    void    Search() const;   //функция поиска
    void    Remove();   // Удаление элемента по его индексу
    void    Edit();//редактирование элемента
};


