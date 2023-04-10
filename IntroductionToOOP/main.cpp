
#include<iostream>
using namespace std;

/*
  Создавая структуру или класс, мы создаем новый тип(пользовательский) данных.
*/

class Point
{
	double x, x2;
	double y, y2;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	double get_x2()const
	{
		return x2;
	}
	double get_y2()const
	{
		return y2;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	void set_x2(double x2)
	{
		this->x2 = x2;
	}
	void set_y2(double y2)
	{
		this->y2 = y2;
	}

	// Constructors:

	Point()
	{
		x = y = 0;
		x2 = y2 = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		this->x2 = 0;
		this->y2 = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->x2 = 0;
		this->y2 = 0;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(double x, double y, double x2, double y2)
	{
		this->x = x;
		this->y = y;
		this->x2 = x2;
		this->y2 = y2;
		cout << "Constructor of two points:\t\t" << this << endl;
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