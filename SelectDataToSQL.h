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

public:
	SelectDataToSQL(std::string, std::string, std::string, std::string);
	SelectDataToSQL( SelectDataToSQL const &) = delete;	
	SelectDataToSQL & operator = (SelectDataToSQL const &) = delete;

	std::map <int,std::vector<std::string>> & selectData(std::string);

	~SelectDataToSQL();
};
