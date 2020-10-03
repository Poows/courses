#pragma once
#include <string>
#include <iostream>
using namespace std;

class TestRunner { 
	~TestRunner();
	int fail_count = 0;
};