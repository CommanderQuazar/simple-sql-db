//
// Created by Tobey Ragain on 2/25/22.
//

#include <mysql/mysql.h>

#include <iostream>
#include <cstdio>

#include "SqlManager.h"


char selector(const char * options, size_t numberOfOptions)
{
    char userChoice;
    while(true)
    {
        std::cout << "Entry: ";
        std::cin.get(userChoice);
        std::cout << userChoice;

        for(int i = 0; i < numberOfOptions; ++i)
        {
            if(options[i] == userChoice)
            {
                return userChoice;
            }
            else
            {
                continue;
            }
        }
        std::cout << "Invalid entry... try again!"
                  << std::endl;
    }
}

void sql_manager(SqlManager * mgr_obj,
                 std::string * host,
                 std::string * usern,
                 std::string * passwd,
                 std::string * database,
                 unsigned int port_num)
{

    mgr_obj->connect(host,
                        usern,
                        passwd,
                        database,
                        port_num,
                        nullptr,
                        0);
    while(true)
    {
        const char choices[] = {'1', '2', '3', 'q'};
        char MMUserChoice;
        size_t size = sizeof(choices)/sizeof(choices[0]);

        printf("+----------------------------------+\n");
        printf("|             Main Menu            |\n");
        printf("+----------------------------------+\n");
        printf("1. Add Entry\n2. Remove Entry\n3. View Table\nPress q at any time to quit"
               "\n\n");

        MMUserChoice = selector(choices, size);

        switch (MMUserChoice)
        {
            case '1':
                std::string street, city, area_code, state;
                std::cout << "Enter a 'street' 'city' 'area code' 'state' (in that order)"
                          << std::endl;
                std::cin >> street >> city >> area_code >> state;
                mgr_obj->add_item(street, city, area_code, state);
                break;
            case '2':

                break;
            case '3':
                mgr_obj->display_table();
                break;
            case 'q':
                printf("Quitting...\n");
                return;
            default:
                EXIT_FAILURE;
                return;
        }
    }
}

int main(int argc, char **argv)
{
    // Read in all program / database info
    std::string host        = argv[0];
    std::string username    = argv[1];
    std::string passwrd     = argv[2];
    std::string db          = argv[3];
    std::string port        = argv[4];
    std::string log_file    = argv[5];

    SqlManager sql_mgr(log_file);
    sql_manager(&sql_mgr,
                &host,
                &username,
                &passwrd,
                &db,
                std::stoi(port));

    return 0;
}