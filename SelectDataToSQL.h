#pragma once

#include <stdio.h>
#include <postgresql/libpq-fe.h>
#include <cstring>
#include <map>
#include <vector>

class SelectDataToSQL {
	std::map <int,std::vector<std::string>> lines;
	char     buff[200];
	PGconn   *dbconn;
	PGresult *res;

	SelectDataToSQL & operator =(SelectDataToSQL const &) = delete;
	SelectDataToSQL( SelectDataToSQL const &) = delete;

public:
	SelectDataToSQL(std::string, std::string, std::string, std::string);

	std::map <int,std::vector<std::string>> & selectData(std::string);

	~SelectDataToSQL();
};
