#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {

	int flag = 0;
	string operation_code;
	int stop_count = 0;
	is >> operation_code;

	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus >> stop_count;

		q.stops.clear();
		for (size_t i = 0; i < stop_count; i++) {
			is >> q.stop;
			q.stops.push_back(q.stop);
		}
	}
	else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	string stop;
	vector<string> buses;
};

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

struct StopsForBusResponse {
	string bus;
	vector<string> stops;
};

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

struct AllBusesResponse {
	vector<string> all_buses;
};

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

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		buses_to_stops[bus] = stops;
		for (string stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse bts;
		bts.stop = stop;
		map<string, vector<string>> loc_bts = stops_to_buses;
		if (loc_bts.count(stop) == 0) {
			bts.buses.push_back("No stop");
		}
		else bts.buses = loc_bts[stop];
		return bts;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {

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

	AllBusesResponse GetAllBuses() const {
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

private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

//int main() {
//	int query_count;
//	Query q;
//
//	cin >> query_count;
//
//	BusManager bm;
//	for (int i = 0; i < query_count; ++i) {
//		cin >> q;
//		switch (q.type) {
//		case QueryType::NEW_BUS:
//			bm.AddBus(q.bus, q.stops);
//			break;
//		case QueryType::BUSES_FOR_STOP:
//			cout << bm.GetBusesForStop(q.stop) << endl;
//			break;
//		case QueryType::STOPS_FOR_BUS:
//			cout << bm.GetStopsForBus(q.bus) << endl;
//			break;
//		case QueryType::ALL_BUSES:
//			cout << bm.GetAllBuses() << endl;
//			break;
//		}
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//// ответ на запрос BUSES_FOR_STOP
//void PrintBusesForStop(map<string, vector<string>>& stops_to_buses,
//	const string& stop) {
//	if (stops_to_buses.count(stop) == 0) {
//		cout << "No stop" << endl;
//	}
//	else {
//		for (const string& bus : stops_to_buses[stop]) {
//			cout << bus << " ";
//		}
//		cout << endl;
//	}
//}
//
//// ответ на запрос STOPS_FOR_BUS
//void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
//	map<string, vector<string>>& stops_to_buses,
//	const string& bus) {
//	if (buses_to_stops.count(bus) == 0) {
//		cout << "No bus" << endl;
//	}
//	else {
//		for (const string& stop : buses_to_stops[bus]) {
//			cout << "Stop " << stop << ": ";
//
//			// если через остановку проходит ровно один автобус,
//			// то это наш автобус bus, следовательно, пересадки тут нет
//			if (stops_to_buses[stop].size() == 1) {
//				cout << "no interchange";
//			}
//			else {
//				for (const string& other_bus : stops_to_buses[stop]) {
//					if (bus != other_bus) {
//						cout << other_bus << " ";
//					}
//				}
//			}
//			cout << endl;
//		}
//	}
//}
//
//// ответ на запрос ALL_BUSES
//void PrintAllBuses(const map<string, vector<string>>& buses_to_stops) {
//	if (buses_to_stops.empty()) {
//		cout << "No buses" << endl;
//	}
//	else {
//		for (const auto& bus_item : buses_to_stops) {
//			cout << "Bus " << bus_item.first << ": ";
//			for (const string& stop : bus_item.second) {
//				cout << stop << " ";
//			}
//			cout << endl;
//		}
//	}
//}
//
//int main() {
//	int q;
//	cin >> q;
//
//	map<string, vector<string>> buses_to_stops, stops_to_buses;
//
//	for (int i = 0; i < q; ++i) {
//		string operation_code;
//		cin >> operation_code;
//
//		if (operation_code == "NEW_BUS") {
//
//			string bus;
//			cin >> bus;
//			int stop_count;
//			cin >> stop_count;
//
//			// с помощью ссылки дадим короткое название вектору
//			// со списком остановок данного автобуса;
//			// ключ bus изначально отсутствовал в словаре, поэтому он автоматически
//			// добавится туда с пустым вектором в качестве значения
//			vector<string>& stops = buses_to_stops[bus];
//			stops.resize(stop_count);
//
//			for (string& stop : stops) {
//				cin >> stop;
//				// не забудем обновить словарь stops_to_buses
//				stops_to_buses[stop].push_back(bus);
//			}
//
//		}
//		else if (operation_code == "BUSES_FOR_STOP") {
//
//			string stop;
//			cin >> stop;
//			PrintBusesForStop(stops_to_buses, stop);
//
//		}
//		else if (operation_code == "STOPS_FOR_BUS") {
//
//			string bus;
//			cin >> bus;
//			PrintStopsForBus(buses_to_stops, stops_to_buses, bus);
//
//		}
//		else if (operation_code == "ALL_BUSES") {
//
//			PrintAllBuses(buses_to_stops);
//
//		}
//	}
//
//	return 0;
//}