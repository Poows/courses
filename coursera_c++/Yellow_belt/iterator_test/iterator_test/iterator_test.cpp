#include <iostream>
#include <iterator>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;
using LangIt = vector<int>::iterator;

int f(int x) {
	return x > 2;
}

void PrintRange(LangIt begin_range, LangIt end_range) {
	for (auto it = begin_range; it != end_range; it++) {
		cout << *it << ", ";
	}
	cout << endl;
}	

int main()
{
	/*vector<string> langs = {
		"Python", "C", "C++", "Java" , "C#"
	};

	set<int> s = { 1,2,3,4 };
	vector<int> v;

	v.assign(begin(s), end(s));
	auto it = remove_if(begin(v), end(v),
		[](int x) { return !f(x); });
	v.erase(it, end(v));


	PrintRange(v.begin(), v.end());
*/
	//set<string> m_langs = {
	//	"Python", "C", "C++", "Java" , "C#"
	//};

	vector<int> vec = { 4, 3, 2, 6, 7, 8 };
	auto vector_begin = begin(vec);
	auto vector_end = end(vec);

	string str = "C++KAEF";
	auto string_begin = begin(str);
	auto string_end = end(str);

	set<int> s = { 1, 2, 3, 4 };
	auto set_begin = begin(s);
	auto set_end = end(s);

	auto res = next_permutation(set_begin, set_end);

	//auto it = is_sorted_until(rbegin(vec), rend(vec),
	//	[](auto lhs, auto rhs) { return rhs < lhs; });
	//	//auto res = accumulate(set_begin, set_end, 0);
	//	//auto res = is_permutation(set_begin, set_end, vector_begin);
	//cout << *it << endl;
	//PrintRange(it, rend(vec));
	// Методы для вектора (erase, insert): 
	//auto it = find(langs.begin(), langs.end(), "C++");
	//langs.insert(it, 5, "SPSS"); // Добавление SPSS 5 раз

	//it = find(langs.begin(), langs.end(), "C++"); // Обновление позиции итератора

	//langs.insert(it, {"1"}); // Добавление 1

	//PrintRange(langs.begin(), langs.end());	

	/*auto it_remove_if = remove_if(langs.begin(), langs.end(), [](const string& lang) {
		return lang[0] == 'C'; 
	}); */// Удаление элементов вектора, которые начинаются на 'C'. Данная функция возвращает итератор на конец нового интервала.	
	
	//auto it_find_if = find_if(begin(langs), end(langs), [](const string& s) {return s[0] == 'C'; });
	//cout << *it_find_if << endl;
	//PrintRange(it_find_if, end(langs));
	//langs.erase(it_find_if, end(langs));
	//PrintRange(begin(langs), end(langs));

	//unique(langs.begin(), langs.end()); // Удаляет подрят идущие одинаковые эелементы

	//auto it_partition = partition(begin(langs), end(langs), [](const string& lang) {return lang[0] == 'C'; }); // Перемещает все елементы, которые удовлетворяют условию, в начало диапозона. Также возвращает итератор на конец интервала.
	//vector<string> c_langs(langs.size());
	//auto it_copy_if = copy_if(begin(langs), end(langs), begin(c_langs), [](const string& lang) {return lang[0] == 'C'; });
	//PrintRange(begin(c_langs), it_copy_if);

	////PrintRange(rbegin(langs), rend(langs));
	////

	//// Функции для контейнера set

	//all_of(begin(m_langs), end(m_langs), [](const string& lang) {
	//	return lang[0] >= 'A' && lang[0] <= 'Z';
	//});


}

