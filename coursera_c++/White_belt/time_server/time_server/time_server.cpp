// time_server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <ctime>
#include <time.h>

using namespace std;

string AskTimeServer() {
	char buffer[80];
	
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	
	const char* format = "%H:%M:%S";
	strftime(buffer, 80, format, &newtime);
	string str = buffer;
	return str;
}

class TimeServer {
public:
	string GetCurrentTime();
private:
	string last_fetched_time = "00:00:00";
};

string TimeServer::GetCurrentTime() {
	try {
		string get_time = AskTimeServer();
		last_fetched_time = get_time;
		return last_fetched_time;
	}
	catch (system_error& e) {
		return last_fetched_time;
	}
}

int main()
{
	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	}
	catch (exception& e) {
		cout << "Получено исключение:" << e.what() << endl;
	}
}

