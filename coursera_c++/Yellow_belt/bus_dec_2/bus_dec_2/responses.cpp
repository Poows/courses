#pragma once

#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.buses[0] == "No stop") {
		os << "No stop";
	}
	else {
		for (size_t i = 0; i < r.buses.size(); i++) {
			os << r.buses[i] << " ";
		}
	}
	return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	int count = r.stops.size() - 1;
	for (size_t i = 0; i < r.stops.size(); i++) {
		if (i != count) {
			os << r.stops[i] << endl;
		}
		else {
			os << r.stops[i];
		}
	}
	return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {

	int count = r.all_buses.size() - 1;
	for (size_t i = 0; i < r.all_buses.size(); i++) {
		if (i != count) {
			os << r.all_buses[i] << endl;
		}
		else {
			os << r.all_buses[i];
		}
	}
	return os;
}