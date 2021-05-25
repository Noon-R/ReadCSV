#pragma once

#include <string> 
#include <vector>
#include <sstream>
#include <fstream>

void ReadCSV_item (std::vector<std::string> &list, const char* fileName, const char delim);
void ReadCSV_line (std::vector<std::string> &list, const char* fileName);

void SetData (char const *fileArc, std::string line, char const delim, ...);


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
void MakeData(std::vector<sampleDataT> &datas, int itemCount, char const * fileName);

/*
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
*/

