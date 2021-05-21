#pragma once

#include <string> 
#include <vector>
#include <sstream>
#include <fstream>

void ReadCSV(std::vector<std::string> &list, std::string& fileName, char delim);


typedef struct sampleDataT {

	//都道府県コード	都道府県名	元号	和暦（年）	西暦（年）	人口（総数）	人口（男）	人口（女）
	int code;
	std::string pref;
	std::string age;
	int year_jp;
	int year;
	int total;
	int manCount;
	int womanCount;

};
void MakeData(std::vector<sampleDataT> &datas, int itemCount, std::string fileName);