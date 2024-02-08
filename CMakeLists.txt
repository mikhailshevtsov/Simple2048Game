cmake_minimum_required(VERSION 3.16)
project(Simple2048Game)

set(SOURCES src/ColumnIterator.cpp /
            src/Controller.cpp /
            src/GameTable.cpp /
            src/Game.cpp /
            src/main.cpp /
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE inc)