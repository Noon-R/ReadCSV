#pragma once

#include <string> 
#include <vector>
#include <sstream>
#include <fstream>

void ReadCSV(std::vector<std::string> &list, std::string& fileName, char delim);


typedef struct sampleDataT {

	//�s���{���R�[�h	�s���{����	����	�a��i�N�j	����i�N�j	�l���i�����j	�l���i�j�j	�l���i���j
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