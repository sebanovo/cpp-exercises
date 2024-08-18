cmake_minimum_required(VERSION 3.10)
#cmake -G "MinGW Makefiles" ..
project(script)

include_directories(src/api)
include_directories(src/class)

set(CMAKE_CXX_STANDARD 17)  # O la versión que necesites
set(
    SOURCES src/main.cpp
            src/class/numero.cpp
            src/class/cadena.cpp
            src/api/archivo.cpp
)

add_executable(script ${SOURCES})
