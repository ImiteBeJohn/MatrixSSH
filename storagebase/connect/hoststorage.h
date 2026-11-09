/*
hoststrage.h : contains a class that uses sqlite3 as the backend as a means to 
manage an track connections that MatrixSSH uses to manage what host
MatrixSSH will connect to.

The class it contains is "connectiondb"
*/

#include <iostream>
#include <string>
#include <sqlite3.h>
#include <vector>
#include "../../DataTypes.h"
#pragma once

class connectiondb{

    private:

    // SQLite connection entity
    sqlite3* ConnectStorage;

    // int that SQLie is dependent on
    int connect_SQLiteNumber;

    // Path to database
    std::string PathToDataBaseConnect;

    public:

    // Construtor and copy construtctor
    connectiondb();

    connectiondb(const connectiondb& cpy);

    // Deconstrutor
    ~connectiondb();

    /*
    ConfigDB() : is used to point the datbase to the proper file. 
    As per Linux standard the usuall directory is 

    /var/matrixssh/connection/<database>

    This takes GeneralData as input with StringDataInfo containing
    the path to the database at the moment (unless SQLite needs more data to work)
    Otherwise the defuault :
    /var/matrixssh/connection/connection.db
    is used at the connection storage
    **it should be noted that the database dose contain the PASSWORDS to host**
    to proper security on this file shoudl be monitored. 

    This returns MessageData as a result for processing by the program
    */
    MessageData ConfigDB(GeneralData SetDB);

    /*
    ActivateDB() : will then make the connection to the database for reading
    and writing data to the database. 

    This takes no paramiters, and returns MessageData for results
    */
    MessageData ActivateDB();

    /*
    FetchConnection() : Will return a list of connections from the database

    This contains two paramiters to use: type and param as strings
    type is things like groups, or usernames 
    param is the name of the group and so on

    This returns a list (vector) of ConnectionBlob types for processing
    */
    std::vector<ConnectionBlob> FetchConncetion(std::string type, std::string param);

    /*
    CreateConnection() : will add a new connection to the database
    Takes a connection blob as a paramiter and returns message data
    */
    MessageData CreateConnection(ConnectionBlob NewConnection);

    /*
    AlterConnection() : changes the current exsting connection of the 
    database

    This takes a  connecton blob as input that holds the updated info.
    Oper is used to decide what is done, delete (delete connection)
        or update (change the connection)
    returns a message data for the results
    */
    MessageData AlterConnection(ConnectionBlob AlterConn, std::string Oper);
    
};