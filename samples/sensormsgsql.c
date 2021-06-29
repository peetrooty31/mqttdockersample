#include <sqlite3.h>
#include <stdio.h>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("sensordb.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    long int utcT;
utcT=1624652495;
char sqlQ[500];
char hrT[25]="12:34:32PM 28 Jun 2021";
char SensorRead[10]="Temp 300K";
int logm;
logm=122;
int last_id = sqlite3_last_insert_rowid(db);
sprintf(sqlQ, "INSERT INTO sensors(Id,UTCtime,HRtime,SensorMsg,log)VALUES(%d,%ld,'%s','%s',%d);",last_id,utcT,hrT,SensorRead,logm);

    char *sql =sqlQ;
 
    rc = sqlite3_exec(db, sqlQ, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}
