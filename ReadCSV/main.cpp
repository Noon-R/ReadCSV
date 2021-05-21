
#include <iostream>

#include "CSV_util.h"

int main() {

	std::vector<sampleDataT> data;
	
	MakeData(data, 8, std::string("c01.csv"));

	for (int i = 0; i < data.size(); ++i) {

		std::cout << data[i].code << ',' << data[i].pref << ',' << data[i].age << ',' << data[i].year_jp << ',' << data[i].year << ',' << data[i].total << ',' << data[i].manCount << ',' << data[i].womanCount;

		std::cout << std::endl;
		
	}

	return 0;
}