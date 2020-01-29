#include "SelectDataToSQL.h"

SelectDataToSQL::SelectDataToSQL(std::string db, std::string dbserver, std::string uname, std::string pass)
{
	char buff[200];
	std::string tmp = "dbname=" + db + " host=" + dbserver + " port=5432 user=" + uname + " password=" + pass;
	std::strcpy(buff,tmp.c_str());
	dbconn = PQconnectdb(buff);
}

std::map <int,std::vector<std::string>> & SelectDataToSQL::selectData(std::string table)
{
	std::string SQL = "select * from " + table +";";
	std::string tmp = "BEGIN; DECLARE " + table + " CURSOR FOR " + SQL;
	std::vector<std::string> line;

	std::strcpy(buff,tmp.c_str());
	res = PQexec(dbconn, buff);
	PQclear(res);
  
	tmp = "FETCH ALL in " + table;
	std::strcpy(buff,tmp.c_str());
	res = PQexec(dbconn, buff);
  
	int nFields = PQnfields(res);

	for(int i=0; i < PQntuples(res); i++)
	{
		for(int j=0; j < nFields; j++)
			line.push_back(PQgetvalue(res, i, j));

		lines[i] = line;
	}
	return lines;
}

SelectDataToSQL::~SelectDataToSQL(){}
