#include <iostream>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
{
   int i;
   for(i = 0; i<argc; i++) 
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
   printf("\n");
   return 0;
}

bool opendb(sqlite3 *db, const char* filename)
{
    int rc;
    rc = sqlite3_open(filename, &db);

    if(rc) 
    {
       std::cout<<"Can't open database: %s\n"<<sqlite3_errmsg(db);
       return false;
    } 
    else 
    {
       std::cout<<"Opened database successfully\n";
       return true;
    }
}
int main()
{
    //std::cout<<"skeleton baby\n";
    sqlite3 *db;
    if(opendb(db,"test.db"))
    {
        std::cout<<"\n\nomale\n\n";
        // --------------------------------
        /* Create SQL statement */
   const char* sql = "CREATE TABLE mynumbers("  \
      "ID INT PRIMARY KEY   NOT NULL," \
      "value    INT );";

char *zErrMsg = 0;
int rc;
rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
        // ---------------------------------
        sqlite3_close(db);
    }
    return 0;
    
}