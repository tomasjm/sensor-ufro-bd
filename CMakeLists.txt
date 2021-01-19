cmake_minimum_required(VERSION 2.8.3)
project(database_sensor)

include_directories(
        "${PROJECT_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} src/database.cpp)
add_library(SQlite3Lib src/shell.c src/sqlite3.c)
target_link_libraries(${PROJECT_NAME} SQlite3Lib)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")