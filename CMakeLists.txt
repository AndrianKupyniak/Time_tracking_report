CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

PROJECT(main)

SET(sources
  Logger/Logger.cpp
  Logger/Log.cpp
  Date.cpp
  Employee.cpp   
  Parser.cpp 
  Timer.cpp

  main.cpp
)

add_executable(main ${sources})	