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

	// [1:9/3)[4:7)[7:10

	MergeSort(range_begin, range_begin + (range_end - range_begin) / 3);
	MergeSort(range_begin + (range_end - range_begin) / 3, range_end - (range_end - range_begin) / 3);
	MergeSort(range_end - (range_end - range_begin) / 3, range_end);

	auto third_vec = (range_end - range_begin) / 3;

	vector<typename RandomIt::value_type> elements;
	
	merge(range_begin, range_begin + third_vec,
		  range_begin + third_vec,
		  range_end - third_vec, back_inserter(elements));
	
	vector<typename RandomIt::value_type> elements2;
	merge(begin(elements), end(elements), range_end - third_vec, range_end, back_inserter(elements2));

	for (auto it = elements2.begin(); it != elements2.end(); it++) {
		*range_begin++ = *it;
	}
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

