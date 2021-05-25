
#include <iostream>

#include "CSV_util.h"

int main() {

	std::vector<sampleDataT> data;
	
	std::vector<std::string> line;
	ReadCSV_line (line,"c01.csv");

	for ( int i = 0; i < line.size (); ++i) {
		sampleDataT lineData;
		SetData ("dssddddd", line[i], ',', 
			&lineData.code, 
			&lineData.pref, 
			&lineData.age, 
			&lineData.year_jp, 
			&lineData.year, 
			&lineData.total, 
			&lineData.manCount, 
			&lineData.womanCount);
		data.push_back (lineData);
	}
	

	for (int i = 0; i < data.size(); ++i) {

		std::cout << data[i].code << ',' << data[i].pref << ',' << data[i].age << ',' << data[i].year_jp << ',' << data[i].year << ',' << data[i].total << ',' << data[i].manCount << ',' << data[i].womanCount;

		std::cout << std::endl;
		
	}

	return 0;
}