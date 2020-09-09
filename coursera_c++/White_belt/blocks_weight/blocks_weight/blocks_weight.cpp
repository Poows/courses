// blocks_weight.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	uint64_t N;
	uint64_t R;
	uint64_t W, H, D;
	vector<uint64_t> block;

	cin >> N >> R;

	for (int i = 0; i < N; i++) {
		cin >> W >> H >> D;
		uint64_t loc_sum = static_cast<uint64_t>(W * H * D * R);
		block.push_back(loc_sum);
	}

	uint64_t sum = 0;

	for (auto& x : block) {
		sum += x;
	}

	cout << sum;
}


