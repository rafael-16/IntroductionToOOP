#include<iostream>
using namespace std;
#define delimiter "\n--------------------------------\n"

class Fraction
{
	int numerator;
	int denominator;
public:
	// Getters:
	int get_n()const
	{
		return numerator;
	}
	int get_d()const
	{
		return denominator;
	}
	// Setters:
	void set_n(int n)
	{
		this->numerator = n;
	}
	void set_d(int d)
	{
		this->denominator = d;
	}

	// Constructions:
	Fraction()
	{
		numerator = denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int n, int d)
	{
		this->numerator = n;
		this->denominator = d;
		cout << "Constructor:\t\t" << this << endl;
	}
	// Destructor:
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	// Operators:
	Fraction& operator+(const Fraction& other)
	{
		Fraction buffer;
		if (this->denominator == other.denominator)
		{
			buffer.numerator = this->numerator + other.numerator;
			buffer.denominator = this->denominator;
			cout << "Сложение:\t\t" << this << endl;
		}
		else
		{
			int i = 1;
			int j;
			while ((this->denominator * i) % other.denominator)
			{
				i++;
			}
			j = this->denominator * i/other.denominator;
			buffer.numerator = this->numerator*i + other.numerator*j;
			buffer.denominator = this->denominator*i;
			cout << "Сложение:\t\t" << this << endl;
		}
		return buffer;
	}
	Fraction& operator*(const Fraction& other)
	{
		Fraction buffer;
		buffer.numerator = this->numerator * other.numerator;
		buffer.denominator = this->denominator * other.denominator;
		cout << "Умножение:\t\t" << this << endl;
		return buffer;
	}
	Fraction& operator/(const Fraction& other)
	{
		Fraction buffer;
		buffer.numerator = this->numerator * other.denominator;
		buffer.denominator = this->denominator * other.numerator;
		cout << "Деление:\t\t" << this << endl;
		return buffer;
	}

	// Metod:

	void print()
	{
		if (numerator != denominator && denominator != 1 && numerator < denominator)
			cout << "Простая дробь: " << numerator << "/" << denominator << endl;
		else if (numerator > denominator && denominator != 1)
			cout << "Неправильная дробь: " << numerator << "/" << denominator << endl;
		else if (numerator == denominator)
			cout << "Неправильная дробь: " << 1 << endl;
		else if (denominator == 1)
			cout << "Неправильная дробь: " << numerator << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(2, 7);
	Fraction B(4, 5);
	cout << delimiter<<endl;
	A.print();
	cout << delimiter << endl;
	B.print();
	cout << delimiter << endl;
	Fraction C = A + B;
	C.print();
	cout << delimiter << endl;
	Fraction D = A * B;
	D.print();
	cout << delimiter << endl;
	Fraction E = A / B;
	E.print();
	cout << delimiter << endl;
}