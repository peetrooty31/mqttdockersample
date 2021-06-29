#include <sqlite3.h>
#include <stdio.h>
#include<time.h>

int callback(void *, int, char **, char **);

int main(void) {

    time_t utcT;
    time(&utcT);
	char* hrT;
	hrT=ctime(&utcT);
    sqlite3 *db;
    char *err_msg = 0;
	printf("hrt: %s \nutcT: %ld",hrT,utcT);

    int rc = sqlite3_open("sensordb.db", &db);

    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }

char sqlQ[500];

char SensorRead[10]="Temp 300K";
int logm;
logm=122;
sprintf(sqlQ, "INSERT INTO sensors(UTCtime,HRtime,SensorMsg,log)VALUES(%ld,'%s','%s',%d);",utcT,hrT,SensorRead,logm);

    rc = sqlite3_exec(db, sqlQ, 0, 0, &err_msg);

    if (rc != SQLITE_OK ) {

        fprintf(stderr, "SQL error: %s\n", err_msg);

         sqlite3_free(err_msg);
        sqlite3_close(db);

        return 1;
    }

 char *sql = "SELECT * FROM sensors";
        
    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);
        
        return 1;
    } 

    sqlite3_close(db);

    return 0;
}


int callback(void *NotUsed, int argc, char **argv, 
                    char **azColName) {
    
    NotUsed = 0;
    
    for (int i = 0; i < argc; i++) {

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    
    return 0;
}
