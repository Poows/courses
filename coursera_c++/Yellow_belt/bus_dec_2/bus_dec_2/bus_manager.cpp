#pragma once

#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	buses_to_stops[bus] = stops;
	for (string stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	BusesForStopResponse bts;
	bts.stop = stop;
	map<string, vector<string>> loc_bts = stops_to_buses;
	if (loc_bts.count(stop) == 0) {
		bts.buses.push_back("No stop");
	}
	else bts.buses = loc_bts[stop];
	return bts;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {

	StopsForBusResponse stb;
	map<string, vector<string>> loc_btb = buses_to_stops;
	map<string, vector<string>> loc_stb = stops_to_buses;
	string s;
	if (buses_to_stops.count(bus) == 0) {
		stb.stops.push_back("No bus");
	}
	else {
		for (const string& stop : loc_btb[bus]) {
			s = "Stop " + stop + ": ";
			if (loc_stb[stop].size() == 1) {
				s += "no interchange";
				stb.stops.push_back(s);
			}
			else {
				for (const string& other_bus : loc_stb[stop]) {
					if (bus != other_bus) {
						s += other_bus + " ";
					}
				}
				stb.stops.push_back(s);
			}
		}
	}
	return stb;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse abr;
	string bus_info = "";

	if (buses_to_stops.empty()) {
		abr.all_buses.push_back("No buses");
	}
	else {
		for (const auto& bus_item : buses_to_stops) {
			bus_info += "Bus " + bus_item.first + ": ";
			for (const string& stop : bus_item.second) {
				bus_info += stop + " ";
			}
			abr.all_buses.push_back(bus_info);
			bus_info.clear();
		}
	}
	return abr;
}