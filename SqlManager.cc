//
// Created by Tobey Ragain on 2/25/22.
//

#include "SqlManager.h"

SqlManager& SqlManager::connect(std::string * host,
                         std::string * user,
                         std::string * passwd,
                         std::string * db,
                         unsigned int  port,
                         std::string * unix_socket,
                         unsigned long client_flag)
{
    mysql_init(&_mysql);
    if (!mysql_real_connect(&_mysql,
                            host    ->c_str(),
                            user    ->c_str(),
                            passwd  ->c_str(),
                            db      ->c_str(),
                            port,
                            unix_socket == nullptr ? nullptr : unix_socket->c_str(),
                            client_flag))
    {
        log(mysql_error(&_mysql));
        return *this;
    }
    log("Connect to MySql database: " + *db);
    return *this;
}

/*
 * Displays all info stored in the table
 */
SqlManager &SqlManager::display_table()
{
    MYSQL_ROW       row ;
    MYSQL_RES *     result {};
    unsigned int    num_fields;
    unsigned int    i;

    if(mysql_query(&_mysql, "SELECT * FROM Address"))
    {
        fprintf(stderr, "Error: %s\n", mysql_error(&_mysql));
    }
    else
    {
        result = mysql_store_result(&_mysql);
        num_fields = mysql_num_fields(result);
        if(num_fields == 0)
        {
            std::cout << "No Entries!" << std::endl;
            return *this;
        }

        while ((row = mysql_fetch_row(result)))
        {
            unsigned long *lengths;
            lengths = mysql_fetch_lengths(result);
            for(i = 0; i < num_fields; i++)
            {
                printf("[%.*s] \t", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
            printf("\n");
        }
    }
    std::cout << std::endl;
    log("Table content displayed");
    return *this;
}

/*
 * Adds a row to the table
 */
SqlManager &SqlManager::add_item(const std::string& street,
                                 const std::string& city,
                                 const std::string& area_code,
                                 const std::string& state)
{
    std::string query = "INSERT INTO Address (street, city, area_code, state) "
                        "VALUES ('" + street + "', '" + city + "', '" + area_code
                        + "', '" + state + "')";

    mysql_query(&_mysql, query.c_str());
    log("Row added to the table");
    return *this;
}

SqlManager &SqlManager::add_contact(const std::string &phone_n, const std::string &address)
{

}

/*
 * Removes a row from the table
 */
SqlManager &SqlManager::remove_item(const std::string& id)
{
    std::string query = "DELETE FROM Address WHERE id=" + id;

    mysql_query(&_mysql, query.c_str());
    log("Row removed from table: " + id);
    return *this;
}

/*
 * Destroys all data stored in the table
 */
SqlManager &SqlManager::clear_table()
{
    mysql_query(&_mysql, "DELETE FROM Address");
    log("Table cleared");
    return *this;
}

std::string SqlManager::get_curr_time_date(const std::string& s)
{
    time_t now = time(nullptr);
    struct tm  TimeStruct {};
    char  buf[80];
    TimeStruct = *localtime(&now);
    if(s=="now")
    {
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &TimeStruct);
    }
    else if(s=="date")
    {
        strftime(buf, sizeof(buf), "%Y-%m-%d", &TimeStruct);
    }
    return {buf};
}

/*
 * Logs a message to a user specified log file
 */
void SqlManager::log(const std::string& logMsg)
{
    std::string filePath = _log_file;
    std::string now = get_curr_time_date("now");
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << '\t' << logMsg << '\n';
    ofs.close();
}

inline unsigned int SqlManager::total_rows()
{
    MYSQL_RES * result = mysql_store_result(&_mysql);
    return mysql_num_fields(result);
}
SqlManager &SqlManager::add_user(const std::string &usern, const std::string &passph)
{
    return <#initializer#>;
}


