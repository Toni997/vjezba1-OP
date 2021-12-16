#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"

int main()
{
	const auto total_race_length_in_km = 305;
	
	std::vector<Timer> drivers;
	drivers.reserve(10);
	drivers.emplace_back(Timer(1, 30, 17.345));
	drivers.emplace_back(Timer(1, 30, 19.601));
	drivers.emplace_back(Timer(1, 30, 22.518));
	drivers.emplace_back(Timer(1, 30, 23.037));
	drivers.emplace_back(Timer(1, 30, 23.876));
	drivers.emplace_back(Timer(1, 30, 24.808));
	drivers.emplace_back(Timer(1, 31, 16.545));
	drivers.emplace_back(Timer(1, 31, 19.053));
	drivers.emplace_back(Timer(1, 31, 21.371));
	drivers.emplace_back(Timer(1, 31, 23.402));

	// 2 second penalty
	for (auto& driver : drivers)
	{
		driver += 2;
	}

	Timer average_time;
	
	for(auto& driver : drivers)
	{
		average_time += driver;
	}

	average_time /= drivers.size();

	std::cout << "Average speed: " << total_race_length_in_km / static_cast<double>(average_time) << "km/h" << std::endl;
	std::cout << "Fastest time: " << *std::min_element(drivers.begin(), drivers.end()) << std::endl;
	std::cout << "Time difference between 1st and 3rd driver: " << drivers.at(2) - drivers.at(0) << std::endl;
}
