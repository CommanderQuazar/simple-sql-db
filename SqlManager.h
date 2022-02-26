//
// Created by Tobey Ragain on 2/25/22.
//
// This class only operated on the Address
// table in the 'SIMPLE_SCHEMA' MySql database.
//


#ifndef SIMPLE_SQL_DB__SQLMANAGER_H_
#define SIMPLE_SQL_DB__SQLMANAGER_H_

#include "mysql/mysql.h"

#include <iostream>
#include <fstream>
#include <utility>

class SqlManager
{
    public:
    explicit SqlManager(std::string log_file) :
        _log_file(std::move(log_file))
    { };
    SqlManager(SqlManager& copy)    = delete;
    SqlManager(SqlManager&& move)   = delete;

    SqlManager& connect(std::string *   host,
                        std::string *   user,
                        std::string *   passwd,
                        std::string *   db,
                        unsigned int    port,
                        std::string *   unix_socket,
                        unsigned long   client_flag);

    SqlManager& display_table();
    SqlManager& add_item();
    SqlManager& remove_item();
    SqlManager& clear_table();

    inline void log(std::string& logMsg);

    private:
    MYSQL _mysql {};
    std::string _log_file;
    static inline std::string get_curr_time_date(const std::string& s);
};

#endif //SIMPLE_SQL_DB__SQLMANAGER_H_
