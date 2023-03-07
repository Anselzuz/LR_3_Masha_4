#include <iostream>
#include <list>
#include <cstdarg>
#include <math.h>
using namespace std;

//Task 1
int *PositiveArray(int, ...);
int *PositiveArray(int count, int *sizeMass,  ...)
{
    if (count < 1)
    {
        cout << "Количество чисел не может быть < 1" << endl;
        exit(0);
    }

    list<int> positiveList;
    int numBuff;
    va_list param;
    va_start(param, count);

    //Просматриваем все числа, если число +, то добавляем в список
    numBuff = va_arg(param, int);   //Пропускаем 1 элемент, поскольку он является sizeMass
    for (int i = 0; i < count; ++i)
    {
        numBuff = va_arg(param, int);
        if (numBuff > 0)
            positiveList.push_back(numBuff);
    }
    va_end(param);

    //Создаем массив и заполняем его элементами из списка
    *sizeMass = positiveList.size();
    int *positiveMass = new int[*sizeMass];
    int i = 0;
    for (int el : positiveList)
    {
        *(positiveMass + i) = el;
        ++i;
    }

    return positiveMass;
}

//Task 2
float InscribedCircleRadius(float side, int numOfSides = 3);
float InscribedCircleRadius(float side, int numOfSides)
{
    float r = side / (2 * tan((180 / numOfSides) * 3.1415 / 180));
    cout << "Радиус окружности вписанной в правильный многоугольник с "
         << numOfSides << " сторонами = " << side << " равняется " << r << endl;
    return r;
}

int main()
{
    setlocale (LC_ALL, "Rus");

    //Task 1
    cout << "Task 1" << endl << endl;
    int* mass;
    int* sizeMass = new int;
    mass = PositiveArray(7, sizeMass, 1, 2, 3, -1, -2, 2000000000, 10);
    for (int i = 0; i < *sizeMass; i++)
        cout << mass[i] << endl;
    delete sizeMass;
    delete[] mass;

    //Task 2
    cout << endl << endl << "Task 2" << endl << endl;
    InscribedCircleRadius(5);
    InscribedCircleRadius(5, 10);
}