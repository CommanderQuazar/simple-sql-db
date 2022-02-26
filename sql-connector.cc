//
// Created by Tobey Ragain on 2/25/22.
//

#include <mysql/mysql.h>

#include <iostream>
#include <cstdio>


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

void sql_manager(MYSQL mysql)
{
    while(true)
    {
        const char choices[] = {'1', '2', '3', 'q'};
        char MMUserChoice;
        size_t size = sizeof(choices)/sizeof(choices[0]);


        printf("+----------------------------------------------------------------+\n");
        printf("|                            Main Menu                           |\n");
        printf("+----------------------------------------------------------------+\n");
        printf("1. Add Entry\n2. Remove Entry\n3. View Table\nPress q at any time to quit"
               "\n\n");

        MMUserChoice = selector(choices, size);

        switch (MMUserChoice)
        {
            case '1':

                break;
            case '2':

                break;
            case '3':

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

    //mysql_query(&mysql, "INSERT INTO Address (street, City, area_code, state) "
    //                     "VALUES ('9843 56th SW', 'Seattle', 58934, 'WA')");
    return 0;
}