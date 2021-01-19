
#include <iostream>
#include <fstream>
#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main() {
    sqlite3 *db_handle;
    char *sql;
    char * errorMsg = 0;

    sqlite3_open("basedatos.db", &db_handle);
    std::cout<< "Se abrió el archivo" << std::endl;
    sql = "CREATE TABLE DATOS("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "VALOR           TEXT    NOT NULL," \
      "FECHA           TEXT     NOT NULL);";

    int exec = sqlite3_exec(db_handle, sql, callback, 0, &errorMsg);
    if( exec != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", errorMsg);
      sqlite3_free(errorMsg);
   } else {
      fprintf(stdout, "Tabla creada correctamente\n");
   }
   sqlite3_close(db_handle);
    return 0;
}