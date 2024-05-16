#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;

    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }

    Point get() {
        return Point(this->x, this->y);
    }

    Point() :x(0), y(0) {}

    Point(double x, double y) : x(x), y(y) {}

    Point(const Point& a) : x(a.x), y(a.y) {}

    ~Point() {}
};
class Square {
public:
    Point a, b;

    void set(Point a, Point b) {
        this->a = a;
        this->b = b;
    }
    Square get() {
        return Square(this->a,this->b);

    }

    double Leg() {
        return abs(b.x - a.x);
    }

    double Diagonal() {
        return Leg() * sqrt(2);
    }

    double Perimeter() {
        return 4 * Leg();
    }

    double Area() {
        return pow(Leg(), 2);
    }

    double Radius() {
        return Diagonal() / 2;
    }

    double radius() {
        return Leg() / 2;
    }
    string Tangent() {
        double k = (b.y - a.y) / (b.x - a.x);
        double b = a.y - k * a.x;

        return "y = " + to_string(k) + "x + " + to_string(b);
    }
    void Turn(double x, double y, double alpha) {
        a.x -= x;
        a.y -= y;
        b.x -= x;
        b.y -= y;

        double newX, newY;

        newX = a.x * cos(alpha) - a.y * sin(alpha);
        newY = a.x * sin(alpha) + a.y * cos(alpha);
        a.x = newX;
        a.y = newY;

        newX = b.x * cos(alpha) - b.y * sin(alpha);
        newY = b.x * sin(alpha) + b.y * cos(alpha);
        b.x = newX;
        b.y = newY;

        a.x += x;
        a.y += y;
        b.x += x;
        b.y += y;
    }
   
    bool operator <(const Square& ab) {
        return Square(a,b).Area() < Square(ab.a, ab.b).Area();
    }
    bool operator >(const Square& ab) {
        return Square(a, b).Area() > Square(ab.a, ab.b).Area();
    }
    bool operator =(const Square& ab) {
        return Square(a, b).Area() == Square(ab.a, ab.b).Area();
    }
    Square operator *(const int N) {

        return Square(Point(a.x*N,b.x*N), Point(a.y* N,b.y* N));
    }
    int operator +(const Square& ab) {
        return Square(a, b).Area() + Square(ab.a, ab.b).Area();
    }
    int operator -(const Square& ab) {
        return abs(Square(a, b).Area() - Square(ab.a, ab.b).Area());
    }

    Square() = default;
    Square(Point a, Point b) : a(a), b(b) {}
    Square(const Square& ab) : a(ab.a), b(ab.b) {}
    ~Square() {}

};





int main()
{
    setlocale(LC_ALL, "Rus");
    
    Square square;
    Point Vershina_A, Vershina_B;
    Square square2;
    square2.set(Point(5, 5), Point(-2, -2));

    cout << "Задайте координаты первой вершины квадрата:" << endl;
    cin >> Vershina_A.x>> Vershina_A.y;
    cout << "Задайте координаты второй вершины квадрата:" << endl;
    cin >> Vershina_B.x >> Vershina_B.y;
    square.set(Vershina_A, Vershina_B);
    cout << "Вы успешно создали квадрат с вершинами в следующих точках: " << "А(" << Vershina_A.x << ',' << Vershina_A.y << ')' << ' ' << "B(" << Vershina_B.x << ',' << Vershina_B.y <<')' << endl;
    
    cout << "Сторона квадрата: " << square.Leg() << endl;
    cout << "Длина диагонали: " << square.Diagonal() << endl;
    cout << "Периметр квадрата: " << square.Perimeter() << endl;
    cout << "Площадь квадрата: " << square.Area() << endl;
    cout << "Радиус описанной окружности: " << square.Radius() << endl;
    cout << "Радиус вписанной окружности: " << square.radius() << endl;
    cout << "Уравнение прямой: " << square.Tangent()<<endl;
    square.Turn(0, 0, 60);
    cout << "Уравнение прямойпосле поворота квадрата: " << square.Tangent()<<endl;
    cout << "Операторы:"<< endl;
    cout << "возвращает 1, если площадь квадрата слева меньше площади квадрата справа, возвращает: " << (square < square2) << endl;
    //cout << "square*5=" << (square*5)<<endl;
    cout << "square+square2=" << square + square2 << endl;
    cout << "square-square2=" << square - square2 << endl;


    return 0;
}
/* УСЛОВИЕ
Лабораторная работа №№ 1-3.
Классы. Конструкторы и деструкторы класса.
Компоненты класса. Перегрузка операций.

Разработать классы для описанных ниже объектов. Определить конструктор по умолчанию (без параметров), конструкторы с параметрами, конструктор копирования, деструктор. 
Определить методы класса set(…) для инициализации полей (данных) класса, get(…) для получения значений полей (данных) класса, show() для вывода данных на экран, другие 
методы согласно заданию. Обеспечить выбор методов и операций класса пользователю для демонстрации работы объектов класса.
В том случае, когда в качестве данных класса фигурирует точка на декартовой плоскости, использовать дополнительный класс Point {double x,y;}, определив для него 
конструкторы и методы get() и set().

Вариант 3.

Объект: Square(квадрат):
Данные:  2 точки с координатами противолежащих вершин (double x,y).
Методы: 
координаты вершин квадрата (double[4][2] Apex(void));
сторона квадрата (double Leg(void));
длина диагонали (double Diagonal(void));
периметр квадрата (double Perimeter(void));
площадь квадрата (double Area(void));
радиус описанной окружности (double Radius (void)); 
радиус вписанной окружности (double radius (void));
метод, который совершает поворот квадрата относительно точки с координатами (x,y) на угол α (Square Turn (double x,double y,double alfa);
метод, который возвращает строку с уравнением прямой, на которой лежит диагональ (string Tangent(void)).
Операторы: 
< (возвращает 1, если площадь квадрата слева меньше площади квадрата справа, 0 - в остальных случаях),
> (возвращает 1, если площадь квадрата слева больше площади квадрата справа, 0 - в остальных случаях),
= (возвращает 1, если площади соответствующих квадратов равны);
* («растягивает» квадрат в N раз, относительно центра);
|| (совершает параллельный перенос квадрата на вектор (x,y))
+ (возвращает сумму площадей соответствующих квадратов);
- (возвращает модуль разности площадей соответствующих квадратов).
*/

