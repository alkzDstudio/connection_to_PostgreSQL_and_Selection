#include <iostream>
#include <cstring>
#include "SelectDataToSQL.h"

int main() {
  std::string db 			  = "LanitTercom";
  std::string dbserver	= "127.0.0.1";
  std::string uname    	= "LanitTercom";
  std::string pass     	= "1111";
  std::string table     = "playground";

	SelectDataToSQL con (db, dbserver, uname, pass);

	std::cout << con.selectData(table)[1][2] << std::endl;


	return 0;
}
