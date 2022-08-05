#include <iostream>
#include<string.h>
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

// bool opendb(sqlite3 *db, const char* filename)
// {
//     int rc;
//     rc = sqlite3_open(filename, &db);

//     if(rc) 
//     {
//        std::cout<<"Can't open database: %s\n"<<sqlite3_errmsg(db);
//        return false;
//     } 
//     else 
//     {
//        std::cout<<"Opened database successfully\n";
//        return true;
//     }
// }
// int main()
// {
//     //std::cout<<"skeleton baby\n";
//     sqlite3 *db;
//     if(opendb(db,"test.db"))
//     {
//         std::cout<<"\n\nomale\n\n";
//         // --------------------------------
//         /* Create SQL statement */
//    const char* sql = "CREATE TABLE MYVALS(" \
"ID INT PRIMARY KEY     NOT NULL," \
"MYVAL            INT);";

// char *zErrMsg = 0;
// int rc;
// rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
//    if( rc != SQLITE_OK ){
//       fprintf(stderr, "SQL error: %s\n", zErrMsg);
//       sqlite3_free(zErrMsg);
//    } else {
//       fprintf(stdout, "Table created successfully\n");
//    }
//         // ---------------------------------
//         sqlite3_close(db);
//     }
//     return 0;
    
//}


int main(int argc, char* argv[]) 
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   //char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test2.db", &db);
   
   if(rc) 
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } 
   else 
      fprintf(stderr, "Opened database successfully\n");

   /* Create SQL statement */
    const char* sql = "CREATE TABLE MYVALS(" \
"ID INT PRIMARY KEY     NOT NULL," \
"MYVAL            INT);";

 rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK )
    {
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
   } 
   else 
      fprintf(stdout, "Table created successfully\n");

int myvalues = 0;
   for(int i=0;i<100;i++)
   {
      
      std::string last = "INSERT INTO MYVALS (ID,MYVAL) " \
      "VALUES (";
      char c = '0'+ i;
      char d = '0'+ myvalues;
      std::string last1 = last + c + ", " + d + "); ";
      sql = &last1[0];
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
      if(rc != SQLITE_OK)
         {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
         } 
      else
         fprintf(stdout, "Records created successfully\n");
   
      myvalues = myvalues + 1;
   }






   // /* Create SQL statement */
   // sql = "SELECT * from COMPANY";

   // /* Execute SQL statement */
   // rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   // if( rc != SQLITE_OK ) {
   //    fprintf(stderr, "SQL error: %s\n", zErrMsg);
   //    sqlite3_free(zErrMsg);
   // } else {
   //    fprintf(stdout, "Operation done successfully\n");
   // }
   sqlite3_close(db);
   return 0;
}