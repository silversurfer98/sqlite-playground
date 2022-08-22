#include<iostream>
#include<sqlite3.h>
#include<string>
#include<vector>

#include"charOperations.h"

void i_came_here()
{
    static unsigned int call_count = 0;
    call_count++;
    std::cout<<"\n I came here for the "<<call_count<<"th time \n";
}

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

void run_command(sqlite3 *db, char* entry)
{
   int rc;
   char* zErrMsg = 0;
   rc = sqlite3_exec(db, entry, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK)
   {
      //fprintf(stderr, "SQL error: %s\n", zErrMsg);
      std::cout<<"SQL error: "<<zErrMsg<<"\n";
      sqlite3_free(zErrMsg);
   }
   else
   {
     std::cout<<"success \n";
      //fprintf(stdout, "changes successfully\n");
   }
}

int main()
{
    std::string r;
    std::cin>>r;
    std::cout<<r;
    std::cout<<"\n *************** c++ interface for sqlite3 ********** \n ";
    std::cout<<"enter the filename : ";
    char* filename = new char[200];
    //char* folder = "../Databses/";
    std::cin>>filename;
    //char *topass = append(folder,filename);
    // const char* filename = "testdb1.db";
    sqlite3* db = opendb(filename);

    while(true)
    {
        char* command = new char[200];
        std::cout<<"\nsqlite> ";
        //std::cin>>command;
        scanf(" %[^\n]s",command);

        // break for quit
        if(quit_compare(command))
        {
            std::cout<<"\nbye\n";
            break;
        }

        // check command to dbms
        std::cout<<"ur command to db is : ";
        charprint(command);

        // run the command
        run_command(db, command);

        delete[] command;
    }

    sqlite3_close(db);
    return 0;
}