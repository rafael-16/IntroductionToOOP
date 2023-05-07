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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructors:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
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

	//Fraction& common_denominator(Fraction& other)
	//{
	//	this->numerator = this->numerator * other.denominator;
	//	this->denominator = this->denominator * other.denominator;
	//	return *this;
	//}

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

bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		!=
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		<
		right.get_numerator() * left.get_denominator();
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		>
		right.get_numerator() * left.get_denominator();
}

bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		<=
		right.get_numerator() * left.get_denominator();
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator()
		>=
		right.get_numerator() * left.get_denominator();
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{

	int integer, numerator, denominator;
	cout << "Введите целую часть дроби:\t";
	is >> integer;
	cout << "Введите числитель дроби:\t";
	is >> numerator;
	cout << "Введите знаменатель дроби:\t";
	is >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	obj.to_improper().reduce().to_proper();
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
#define COMPARISON_OPERATORS_CHECK
//#define INPUT_OPERATOR_CHECK

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

#ifdef INPUT_OPERATOR_CHECK
	Fraction A;
	cin >> A;
	cout << A << endl;
#endif // INPUT_OPERATOR_CHECK

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
}