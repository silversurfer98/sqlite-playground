#include <iostream>
#include <sqlite3.h>
#include"charOperations.h"

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

sqlite3 * opendb(const char* filename)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open(filename, &db);

    if(rc) 
    {
       std::cout<<"Can't open database: %s\n"<<sqlite3_errmsg(db);
       return NULL;
    } 
    else 
    {
       std::cout<<"Opened database successfully\n";
       return db;
    }
}

void create_table(sqlite3 *db, char* command)
{
   if(command==NULL)
   {
         const char* sql = "CREATE TABLE MYVALS(" \
"ID INT PRIMARY KEY     NOT NULL," \
"MYVAL            FLOAT);";
      int rc;
      char *zErrMsg = 0;
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK )
      {
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      } 
      else 
         fprintf(stdout, "Table created successfully\n");
   }
   else
   {
      int rc;
      char *zErrMsg = 0;
      rc = sqlite3_exec(db, command, callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK )
      {
         fprintf(stderr, "SQL error: %s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      } 
      else 
         fprintf(stdout, "Table created successfully\n");

   }
}

void insert_data(sqlite3 *db, char* entry)
{
   int rc;
   char* zErrMsg = 0;
   rc = sqlite3_exec(db, entry, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK)
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      fprintf(stdout, "Records created successfully\n");
   }
}

int main() 
{
   std::cout<<"enter the filename : ";
   char filename[200];
   std::cin>>filename;
   // const char* filename = "testdb1.db";
   sqlite3* db = opendb(filename);
   char* command = NULL;
   create_table(db,command);

///---------------------
   char* c;
   char* d;
   float myvalues = 0.1245;
   for(int i=1;i<100;i++)
      {
         const char* first = "INSERT INTO MYVALS (ID,MYVAL) VALUES (";
         const char* mid = ", ";
         const char* last = ");";
         c = intTochar(i);
         d = floatTochar(myvalues);
         char *res = new char[200];
         strcpy(res,first);
         strcat(res,c);
         strcat(res, mid);
         strcat(res,d);
         strcat(res,last);
         charprint(res);

         insert_data(db,res);

         delete[] res;
         myvalues = myvalues + 0.5;
      }
//----------------extensive test

   sqlite3_close(db);
   return 0;
}