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

    bool    IsEmpty() const;// �������� �� �������
    void    Push(AEROFLOT obj); // ���������� ������� � ���������
    void    LoadInFile(const std::string& filename) ; // ���������� ������ � ����
    Keeper  LoadFromFile(const std::string& filename); // �������� ������ �� �����
    void    DisplayAll() const; // ����� ���� ��������, ��������������� �� ������ ����� 
    void    Search() const;   //������� ������
    void    Remove();   // �������� �������� �� ��� �������
    void    Edit();//�������������� ��������
};


