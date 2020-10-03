// merge_sort_div2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) 
{

	if (range_end - range_begin < 2)
	{
		return;
	}

	MergeSort(range_begin, range_begin + (range_end - range_begin) / 2);
	MergeSort(range_begin + (range_end - range_begin) / 2, range_end);

	vector<typename RandomIt::value_type> elements;
	merge(range_begin, range_begin + (range_end - range_begin) / 2, range_begin + (range_end - range_begin) / 2, range_end, back_inserter(elements));

	for (auto it = elements.begin(); it != elements.end(); it++) {
		*range_begin++ = *it;
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}	

