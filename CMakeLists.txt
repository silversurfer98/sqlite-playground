cmake_minimum_required(VERSION 3.2)
set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)

# change the path to compiler here
set(CMAKE_C_COMPILER_FORCED "C://a//bin//gcc.exe")
set(CMAKE_CXX_COMPILER_FORCED "C://a//bin//g++.exe")

# IN MY HOME USE THESE --------------------------------------------
#set(CMAKE_C_COMPILER "D://C_Compilers//mingw64//bin//gcc.exe")
#set(CMAKE_CXX_COMPILER "D://C_Compilers//mingw64//bin//g++.exe")
# -------------------------------------------------------------------

# include_directories("${PROJECT_SOURCE_DIR}/dlls")
# add_subdirectory(dlls)

project(dbtest VERSION 0.1)
add_executable(output sqlite.h test.cpp)
# target_link_libraries(output SQLITE)