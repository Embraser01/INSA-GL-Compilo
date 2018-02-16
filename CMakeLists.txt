# cmake_minimum_required(VERSION <specify CMake version here>)
project(Lexer)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Lexer
        lexer.cpp
        lexer.h
        main.cpp
        symbole.cpp
        symbole.h Etat.cpp Etat.h Automate.cpp Automate.h)
