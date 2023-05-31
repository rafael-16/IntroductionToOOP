#include<iostream>

using namespace std;

class Matrix
{
	int rows;
	int cols;
	int** arr;
public:
	//			Getters:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	//			Constructors:
	Matrix()
	{
		this->rows = 0;
		this->cols = 0;
		this->arr = nullptr;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
			delete[] arr[i];
		delete[] arr;
		cout << "Destructor:\t\t" << this << endl;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		this->arr = new int* [rows];
		for (int i = 0; i < rows; i++)
			this->arr[i] = new int[cols] {};
		for (int i = 0, k=0; i < rows; i++, k+=(cols-1))
		{
			for (int j = 0; j < cols; j++)
				arr[i][j] = i + j+k;
		}
		cout << "TwoArgConstructor:\t" << this << endl;
	}
	//			Methods:
	void print()const
	{
		cout << "ROWS:\t" << rows << endl;
		cout << "COLS:\t" << cols << endl;
		if (rows > 0 && cols > 0)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
					cout << arr[i][j] << '\t';
				cout << endl;
			}
		}
		else
		{
			cout << "MATRIX:\t" << 0 << endl;
		}
	}
};

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
	return (os);
}


void main()
{
	setlocale(LC_ALL, "");

	Matrix A(4,7);
	A.print();

}
