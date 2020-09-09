// matrix_sum.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Matrix {
public:
	Matrix() {
	}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int num_rows, int num_cols);
	int At(const int num_rows, const int num_cols) const;
	int& At(int num_rows, int num_cols);
	const int GetNumRows() const;
	const int GetNumColums() const;
	void set(int i, int j, int value);

private:
	map<int, vector<int>> my_matrix;
	vector<int> my_int_string;
};

int Matrix::At(const int num_rows, const int num_cols) const {
	
	auto elm = my_matrix.at(num_rows).at(num_cols);

	return elm;
}

int& Matrix::At(int num_rows, int num_cols) {

	int& elm = my_matrix.at(num_rows).at(num_cols);

	return elm;
}

Matrix operator+ (Matrix& matrix_1, Matrix& matrix_2) {
	if (matrix_1.GetNumRows() != matrix_2.GetNumRows()) {
		throw invalid_argument("invalid_argument");
	}

	if (matrix_1.GetNumColums() != matrix_2.GetNumColums()) {
		throw invalid_argument("invalid_argument");
	}

}

istream& operator>> (istream& stream, Matrix& matrix) {
	int num_rows, num_cols;
	stream >> num_rows >> num_cols;

	if (num_rows <= 0 || num_cols <= 0) {
		throw out_of_range("out_of_range");
	}

	matrix.Reset(num_rows, num_cols);

	int value;

	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			stream >> value;
			matrix.set(i, j, value);
		}
	}

	return stream;
}

Matrix operator+(const Matrix& one, const Matrix& two) {

	if (one.GetNumColums() != two.GetNumColums()) {
		throw
	}
}

void Matrix::set(int i, int j, int value) {
	my_matrix.at(i).at(j) = value;
}

void Matrix::Reset(int num_rows, int num_cols) {
	
	if (num_rows <= 0 || num_cols <= 0) {
		throw out_of_range("out_of_range");
	}

	my_matrix.clear();
	vector<int> loc_vec;
	for (int i = 0; i < num_cols; i++) {
		loc_vec.push_back(0);
	}

	for (int j = 0; j < num_rows; j++) {
		my_matrix[j] = loc_vec;
	}
}

const int Matrix::GetNumRows() const {

	return my_matrix.size();
}

const int Matrix::GetNumColums() const {
	if (my_matrix.size() > 0) {
		int max = my_matrix[0].size();
		for (int i = 1; i < my_matrix.size(); i++) {
			if (my_matrix[i].size() > max) {
				max = my_matrix[i].size();
			}
		}
		return max;
	}

	return 0;
}

int main()
{
	Matrix one;
	Matrix two;
	try {
		cin >> one >> two;
	}
	catch (out_of_range ex) {
		cout << ex.what() << endl;
	}
	catch (invalid_argument ex) {
		cout << ex.what() << endl;
	}
	//cout << one + two << endl;
}

