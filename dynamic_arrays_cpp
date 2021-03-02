#include <Windows.h>
#include <iostream>

using namespace std;

void Show(int* mass_of_age, int& size_of_age, float* mass_of_weith, double* mass_of_high)
{
    cout << "Возраст\tВес\tРост\t\n";
    for (int i = 0; i < size_of_age; i++)
    {
        cout << mass_of_age[i] << "\t";
        cout << mass_of_weith[i] << "\t";
        cout << mass_of_high[i] << "\n";
    }
}

void Find(int*& mass, int& size)
{   
    int val, temp;
    cout << "Индекс какого значения вы хотите найти? "; cin >> val;
    for (int i = 0; i < size; i++)
    {
        if (val == mass[i])
            temp = i;
    }
    cout << "Индекс Вашего элемента " << temp+1 << "\n";      
}

void FindW(float*& mass, int& size)
{
    float val;
    int temp;
    cout << "Индекс какого значения вы хотите найти? "; cin >> val;
    for (int i = 0; i < size; i++)
    {
        if (val == mass[i])
            temp = i;
    }
    cout << "Индекс Вашего элемента " << temp+1 << "\n";
}

void FindH(double*& mass, int& size)
{
    double val;
    int temp;
    cout << "Индекс какого значения вы хотите найти? "; cin >> val;
    for (int i = 0; i < size; i++)
    {
        if (val == mass[i])
            temp = i;
    }
    cout << "Индекс Вашего элемента " << temp + 1 << "\n";
}

void Add(int*& mass, int& size)
{
    if (size == 0)
        mass = new int[size + 1];
    else
    {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = mass[i];
        }
        delete[] mass;
        mass = temp;
    }
    cout << "Введите возраст "; cin >> mass[size];
    size++;
}

void AddWeith(float*& mass, int& size)
{
    if (size == 0)
        mass = new float[size + 1];
    else
    {
        float* temp = new float[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = mass[i];
        }
        delete[] mass;
        mass = temp;
    }
    cout << "Введите вес "; cin >> mass[size];
    size++;
}


void AddHigh(double*& mass, int& size)
{
    if (size == 0)
        mass = new double[size + 1];
    else
    {
        double* temp = new double[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = mass[i];
        }
        delete[] mass;
        mass = temp;
    }
    cout << "Введите рост "; cin >> mass[size];
    size++;
}

void Sort(int*& mass, int& size, float*& mass2, double*& mass3)
{
    int i, j, zero = 0;
    for (i = 1; i < size; i++)
    {
        zero = mass[i];
        for (j = i - 1; j >= 0 && mass[j] > zero; j--)
        {
            mass[j + 1] = mass[j];
        }
        mass[j + 1] = zero;
    }
    int i1, j1, zero1 = 0;
    for (i1 = 1; i1 < size; i1++)
    {
        zero1 = mass2[i1];
        for (j1 = i1 - 1; j1 >= 0 && mass2[j1] > zero1; j1--)
        {
            mass2[j1 + 1] = mass2[j1];
        }
        mass2[j1 + 1] = zero1;
    }
    int i2, j2, zero2 = 0;
    for (i2 = 1; i2 < size; i2++)
    {
        zero2 = mass3[i2];
        for (j2 = i2 - 1; j2 >= 0 && mass3[j2] > zero2; j2--)
        {
            mass3[j2 + 1] = mass3[j2];
        }
        mass3[j2 + 1] = zero2;
    }
}

void EditArray(int* mass, int& size, float* massw, double* massh)
{
    int mass_of_change;
    int index_of_change;
    do {
        cout << "Выберите таблицу, которую хотите исправить\n";
        cin >> mass_of_change;
        if (mass_of_change > 3 || mass_of_change < 1) {
            cout << "Не верный индекс." ;
        }
    } while (mass_of_change > 3 || mass_of_change < 1);
    do {
        cout << "Выберите элемент, который хотите изменить (введите его индекс) ";
        cin >> index_of_change;
        index_of_change -= 1;
        if (index_of_change > size || index_of_change < 0) {
            cout << "Не верный индекс.";
        }
    } while (index_of_change > size || index_of_change < 0);
    cout << "Введите новое значение ";
    if (mass_of_change == 1) {
        cin >> mass[index_of_change];
    }
    else {
        if (mass_of_change == 2) {
            cin >> massw[index_of_change];
        }
        else {
            cin >> massh[index_of_change];
        }
    }
}

int main() {
    setlocale(LC_ALL, "russian");
    int size_of_age = 0, size_of_weith = 0, size_of_high = 0, choice;
    int* mass_of_age = 0;
    float* mass_of_weith = 0;
    double* mass_of_high = 0;
    bool job = 1;
      

    while (job)
    {
        if (size_of_age == 0 && size_of_weith == 0 && size_of_high == 0)
        {
            system("cls");
            Add(mass_of_age, size_of_age);//функция добавления в массив int возраст
            system("cls");
            AddWeith(mass_of_weith, size_of_weith);//функция добавления в массив float вес
            system("cls");
            AddHigh(mass_of_high, size_of_high);//функция добавления в массив double рост
        }
        else
        {
            cout << "1 - добавить значение в таблицу\n2 - редактировать значение в таблице\n3 - найти значение\n4 - сортировать таблицу\n5 - показать таблицу\n6 - выйти\n"; cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
                system("cls");
                Add(mass_of_age, size_of_age);//функция добавления в массив int возраст
                system("cls");
                AddWeith(mass_of_weith, size_of_weith);//функция добавления в массив float вес
                system("cls");
                AddHigh(mass_of_high, size_of_high);//функция добавления в массив double рост
                break;
            case 2:                    
                system("cls"); 
                Show(mass_of_age, size_of_age, mass_of_weith, mass_of_high);//показать все массивы
                EditArray(mass_of_age, size_of_age, mass_of_weith, mass_of_high); //редактирование таблицы                 
                break;
            case 3:
                //функция поиска по массивам
                int find_choice;
                Show(mass_of_age, size_of_age, mass_of_weith, mass_of_high);
                cout << "Что хотите найти?\n 1 - возраст\n 2 - вес\n 3 - рост\n 4 - выйти в главное меню\n"; cin >> find_choice;
                switch (find_choice)
                {
                case 1:
                    Find(mass_of_age, size_of_age);
                    break;
                case 2:
                    FindW(mass_of_weith, size_of_weith);
                    break;
                case 3:
                    FindH(mass_of_high, size_of_high);
                    break;
                default:
                    break;
                }
                break;
            case 4:
                Sort(mass_of_age, size_of_age, mass_of_weith, mass_of_high);
                Show(mass_of_age, size_of_age, mass_of_weith, mass_of_high);
                cout << "Введите:\n1 - продолжить\n2 - выйти из программы\n"; cin >> job; //сортировка всех массивов
                break;
            case 5:
                Show(mass_of_age, size_of_age, mass_of_weith, mass_of_high);//вывод всех массивов таблицей
                cout << "Введите:\n1 - продолжить\n2 - выйти из программы\n"; cin >> job;
                break;
            case 6:
                job = 0;
                break;
            default:
                break;
            }        
        }
    }
}
