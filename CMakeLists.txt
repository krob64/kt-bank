cmake_minimum_required(VERSION 3.20) 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) #fuer vscode(?) und andere editor

project(Bank VERSION 1.0) #projectdefinition

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES src/*.cpp) # einen 'file' erstellen mit all unseren .cpp files
add_executable(Bank ${SOURCES}) # cmake sagen, dass die Bank executable aus der oberen datei besteht

target_include_directories(Bank PUBLIC src/headers) # 'src/headers/' ist unser root-ordner fuer die header
                                                    # #include "headers/kreditkarte.h" wird zu #include "kreditkarte.h"

target_compile_features(Bank PUBLIC cxx_std_11) # compiler optionen
