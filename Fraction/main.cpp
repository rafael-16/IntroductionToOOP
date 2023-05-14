#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Fraction;
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

#define delimiter "\n--------------------------------\n"

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	//		Getters:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	//		Setters:
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructors:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructors:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructors:\t\t" << this << endl;
	}

	Fraction(double decimal_fraction)
	{
		int multiplier = 10000;
		this->integer = (int)decimal_fraction;
		this->numerator = (decimal_fraction - integer) * multiplier;
		this->denominator = multiplier;
		Fraction::reduce();
		cout << "Constructors:\t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//		Operators:

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}

	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//		Increment/Decrement:

	Fraction& operator++()  // Prefix increment
	{
		to_proper();
		integer++;
		return *this;
	}

	Fraction operator++(int)  //Postfix increment
		//Всегда принимает один и только один параметр типа 'int', и только 'int'
		//Это позволяет компилятору на уровне перегрузки функций отличить постфиксный инкремент от префиксного
	{
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}

	Fraction& operator--()  //Prefix decrement
	{
		to_proper();
		integer--;
		return *this;
	}

	Fraction operator--(int)  //Postix decrement
	{
		to_proper();
		Fraction old = *this;
		integer--;
		return old;
	}

	//		Type-cast operators:

	explicit operator int()
	{
		to_proper();
		return integer;
	}

	operator double()
	{
		return integer + (double)numerator / denominator;
	}

	//		Methods:

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	Fraction& positive_denominator()
	{
		if (denominator < 0)
			denominator = denominator * (-1);
		return *this;
	}

	void print()const
	{
		if (integer)
			cout << integer;
		if (numerator)
		{
			if (integer)
				cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)
				cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator()
		+
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator()
		-
		right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce().positive_denominator();
	cout << 2 << endl;
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{

#ifdef SIMPLE_INPUT
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj(integer, numerator, denominator);
#endif // SIMPLE_INPUT

	const int SIZE = 256;
	char buffer[SIZE]{};
	is.getline(buffer, SIZE);

	int number[3]{};
	int n = 0;
	char delimeters[] = "() /";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
	{
		number[n++] = atoi(pch);
	}
	obj = Fraction();
	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3:obj(number[0], number[1], number[2]); break;
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

//#define ARITHMETICAL_OPERATORS_CHECK
//#define ASSIGNEMENT_OPERATORS_CHECK
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS_CHECK
//#define ISTREAM_OPERATOR
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
#define HOME_WORK_1

void main()
{
	setlocale(LC_ALL, "");

#ifdef INCREMENT_DECREMENT

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}

	for (Fraction i(10, 1, 2); i.get_integer() >= 0; i--)
	{
		i.print();
}
#endif // INCREMENT_DECREMENT

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	Fraction C = A - B;
	A.print();
	B.print();
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef ASSIGNEMENT_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);
	A.print();
	B.print();
	A -= B;
	A.print();

#endif // ASSIGNEMENT_OPERATORS_CHECK

#ifdef ISTREAM_OPERATOR
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	Fraction B(3, 4, 5);

	if (A == B)
		cout << A << " = " << B << endl;
	if (A != B)
		cout << A << " != " << B << endl;
	if (A < B)
		cout << A << " < " << B << endl;
	if (A > B)
		cout << A << " > " << B << endl;
	if (A <= B)
		cout << A << " <= " << B << endl;
	if (A >= B)
		cout << A << " >= " << B << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << delimiter;
	Fraction B;
	B = Fraction(8);
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = int(A);
	cout << a << endl;

	double b = A;
	cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER


#ifdef HOME_WORK_1
	Fraction A = 2.75;
	cout << A << endl;
#endif // HOME_WORK_1



}