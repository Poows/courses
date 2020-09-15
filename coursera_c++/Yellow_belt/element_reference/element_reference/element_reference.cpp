// element_reference.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>

using namespace std;

template<class key, class value> value& GetRefStrict(map<key, value>& m, key k);

template<class key, class value>
value& GetRefStrict(map<key, value>& m, key k) {
	if (m.find(k) == m.end()) {
		throw runtime_error("runtime_error");
	}
	else {
		value& r = m[k];
		return r;
	}
}

//int main()
//{
//	try {
//		map<int, string> m = { {0, "value"} };
//		string& item = GetRefStrict(m, 0);
//		item = "newvalue";
//		cout << m[0] << endl; // выведет newvalue
//	}
//	catch (exception ex) {
//		cout << ex.what() << endl;
//	}
//}


