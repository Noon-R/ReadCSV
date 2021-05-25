#include "CSV_util.h"

#include <stdarg.h>

char rootPath[] = "data/";

void ReadCSV_item(std::vector<std::string> &list, const char* fileName, const char delim) {

	std::vector<std::string> lines;
	ReadCSV_line(lines,fileName);

	for (int i = 0; i < lines.size(); ++i) {
		std::istringstream i_stream(lines[i]);
		std::string elm;
		while (std::getline(i_stream, elm, delim)) {
			list.push_back(elm);
		}
	}
	list.shrink_to_fit();

}

void ReadCSV_line(std::vector<std::string> &list, const char* fileName) {

	std::string path = rootPath + std::string(fileName);
	std::ifstream ifs_csv_file(path);

	list.clear();

	std::string line;

	//1行目は基本不必要なデータなのです。　の処理
	//ラベルとして使われてるし......
	std::getline(ifs_csv_file, line);

	while (std::getline(ifs_csv_file, line)) {

		list.push_back(line);
	}

	list.shrink_to_fit();

}

void SetData(char const *fileArc, std::string line,char const delim, ...) {
	
	va_list vl;

	va_start(vl, delim);

	std::istringstream i_stream (line);
	std::string item;

	int count = 0;

	while ( std::getline (i_stream, item, delim) ) {

		std::istringstream ss (item);

		switch ( fileArc[count] ) {
			case 'd':
				ss >> *va_arg (vl, int*);
				break;
			case 'f':
				ss >> *va_arg (vl, float*);
				break;
			case 's':
				ss >> *va_arg (vl, std::string*);
				break;
			default:
				break;
		}

		count++;
		

	}



}


void MakeData(std::vector<sampleDataT> &datas, int itemCount, char const * fileName) {

	std::vector<std::string> stringData;

	ReadCSV_item (stringData, fileName, ',');


	sampleDataT data;
	for (int i = 0; i < stringData.size(); ++i) {

		std::istringstream ss(stringData[i]);

		switch (i%itemCount)
		{
		case 0:
			ss >> data.code;
			break;

		case 1:
			ss >> data.pref;
			break;

		case 2:
			ss >> data.age;
			break;

		case 3:
			ss >> data.year_jp;
			break;

		case 4:
			ss >> data.year;
			break;

		case 5:
			ss >> data.total;
			break;

		case 6:
			ss >> data.manCount;
			break;

		case 7:
			ss >> data.womanCount;

			break;

		default:
			break;
		}


		if (i%itemCount == itemCount - 1)datas.push_back(data);
	}

}
