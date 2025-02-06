
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
#include <io.h>
#include <vector>
#include <fstream>
#include <cassert>
#include<conio.h>
#include <cstdlib>



using namespace std;


class Equation 
{

public:

    virtual void findRoots() const = 0; 


    virtual ~Equation() = default;       

};



class Line_equation : public Equation 
{

private:

    double a;

    double b;



public:

    Line_equation(double a, double b) : a(a), b(b) {}



    void findRoots() const override 
    {

        if (a == 0) 
        {

            if (b == 0) 
            {

                cout << "Уравнение имеет бесконечно много решений." << endl;

            }
            else {

                cout << "Уравнение не имеет решений." << endl;

            }

        }
        else 
        {

            double root = -b / a;

            cout << "Корень линейного уравнения: x = " << root <<endl;

        }

    }

};



class Quadrat_equation : public Equation 
{

private:

    double a, b,c;
    
public:

    Quadrat_equation(double a, double b, double c) : a(a), b(b), c(c) {}



    void findRoots() const override 
    {

        if (a == 0) 
        {

            Line_equation(b, c).findRoots(); // Преобразуем в линейное

            return;

        }



        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) 
        {

            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);

            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);

            cout << "Корни квадратного уравнения: x1 = " << root1 << ", x2 = " << root2 << endl;

        }
        else if (discriminant == 0) 
        {

            double root = -b / (2 * a);

            cout << "Уравнение имеет один корень: x = " << root << endl;

        }
        else 
        {

            cout << "Уравнение не имеет действительных корней." << endl;

        }

    }

};



int main() {

    system("chcp 1251 > nul");
    setlocale(LC_ALL, "Rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<unique_ptr<Equation>> equations;



    // Пример линейного уравнения: 6x + 15 = 0

    equations.push_back(make_unique<Line_equation>(6, 15));



    // Пример квадратного уравнения: x^2 - 5x + 6 = 0

    equations.push_back(make_unique<Quadrat_equation>(1, -5, 6));



    // Вычисление корней

    for (const auto& equation : equations)
    {

        equation->findRoots();

    }



    return 0;

}