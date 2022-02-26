cmake_minimum_required(VERSION 3.21)
project(simple_sql_db)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/Cellar/mysql/8.0.28/include)
include_directories(/usr/local/Cellar/mysql/8.0.28/lib)
add_link_options(/usr/local/Cellar/mysql/8.0.28/lib/libmysqlclient.21.dylib)

add_executable(simple_sql_db SqlManager.cc SqlManager.h sql-connector.cc)