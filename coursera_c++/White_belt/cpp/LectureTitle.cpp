// LectureTitle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Specialization {
	string specialization;
	explicit Specialization(string value) {
		specialization = value;
	}
};
struct Course
{
	string course;
	explicit Course(string value) {
		course = value;
	}
}; 
struct Week
{
	string week;
	explicit  Week(string value) {
		week = value;
	}
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;
	LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
		specialization = new_specialization.specialization;
		course = new_course.course;
		week = new_week.week;
	}
};

//int main()
//{
//	LectureTitle title(Specialization("C++"), Course("While belt"), Week("4th")); 
//
//	return 0;
//}

