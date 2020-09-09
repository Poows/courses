// temperature.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
	unsigned int N = 0;
	int tp = 0;
	unsigned int count = 0;
	vector<int> temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tp;
		temp.push_back(tp);
	}

	int64_t sum = 0;

	for (auto x : temp) {
		sum += x;
	}

	int avg = sum / static_cast<int>(temp.size());

	for (int i = 0; i < static_cast<int>(temp.size()); i++) {
		if (temp[i] > avg) {
			count++;
		}
	}

	cout << count << endl;

	for (int i = 0; i < static_cast<int>(temp.size()); i++) {
		if (temp[i] > avg) {
			cout << i << " ";
		}
	}

	return 0;
}


