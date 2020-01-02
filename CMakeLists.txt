cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Lexer.cpp Lexer.h Command.h OpenServerCommand.cpp OpenServerCommand.h
        PrintCommand.cpp PrintCommand.h ex1.cpp ex1.h Expression.h Interpreter.cpp Interpreter.h Data.cpp Data.h
        SleepCommand.cpp SleepCommand.h)