/*
logmgr.h contains the class for the mxlog class.

This class uses both SQLite and standard Linux systems to log all events that 
MatrixSSH covers.
*/

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "../../DataTypes.h"
#pragma once

class mxlog{

    private:

    // Database connection object
    sqlite3 *LogDatabase;

    // SQLite3 databse number that it needs
    int LogSQLNumberStatment;

    // Database location
    std::string LogDatabaseLocation;

    public:

    // Constuctors and copy constructors
    mxlog();
    mxlog(const mxlog& copydt);

    /*
    ConfigLogDB() : is what set the databse for recording log data
    This takes in general data to config the database connection and
    returns a message data for the result
    */
    MessageData ConfigLogDB(GeneralData DBConfig);

    /*
    StartLog() : starts the logging data, that is once activated all data sent to
    it is now recorced to the databas log and to other soruces where recorded at.

    This takes no paramiter and returns a message data as the activation result
    */
    MessageData StartLog();

    /*
    RecordData() : takes data and writes it to the database. 
    
    This takes a General data as input and returns message data as a 
    result from the record.
    */
    MessageData RecordData(GeneralData Record);
    

};