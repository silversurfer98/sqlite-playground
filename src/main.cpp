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
    std::cout<<"\n *************** c++ interface for sqlite3 ********** \n ";
    std::cout<<"enter the filename : ";
    
    std::string folder = "../Databases/";
    std::string file;
    std::cin>>file;
    
    std::string res = folder + file + ".db";
    //const char* filename = res.c_str();
    //const char* work = "../Databases/mydb.db";

    sqlite3* db = opendb(res.c_str());

if(db!=nullptr)
{    
    std::cout<<"\n  The opened database is --> "<<res<<"\n";
    std::cout<<"establish commands here --> loop starts / issue quit to quit \n";
    while(true)
    {
        char* command = new char[300];
        std::cout<<"\nsqlite> ";
        //std::cin>>command;
        scanf(" %[^\n]s",command);

        // break for quit
        if(quit_compare(command))
        {
            std::cout<<"\n ********** bye ! *********\n\n";
            delete[] command;
            break;
        }

        // check command to dbms
        std::cout<<" ---- ur command to dbms is : ";
        charprint(command);
        std::cout<<" ---- ";
        // run the command
        run_command(db, command);

        delete[] command;
    }
    sqlite3_close(db);
    return 0;
}
    else
        return 0;

}