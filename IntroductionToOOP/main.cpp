
#include<iostream>
using namespace std;

/*
  Создавая структуру или класс, мы создаем новый тип(пользовательский) данных.
*/

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors:

	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Method:

	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double distance(double x, double y)
	{
		return sqrt(x * x + y * y);
	}
	double distance(double x, double y, double x2, double y2)
	{
		double a, b;
		if (x < x2)
			a = x2 - x;
		else
			a = x - x2;
		if (y < y2)
			b = y2 - y;
		else
			b = y - y2;
		return sqrt(a * a + b * b);
	}

};

//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;
	A.x = 2, A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	//A.set_x(2);
	//A.set_y(3);
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D;
	cout << "Расстояние до точки: " << D.distance(3, 6) << endl;
	cout << "Расстояние между точками: " << D.distance(2,3,6,5) << endl;


}