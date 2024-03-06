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

target_compile_features(Bank PUBLIC cxx_std_14) # compiler optionen


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  bank_test
  ${CMAKE_CURRENT_SOURCE_DIR}/test/Kreditkarte_test.cpp

 "src/Karte.cpp")
target_link_libraries(
  bank_test
  GTest::gtest_main
)
target_include_directories(bank_test PUBLIC src/headers)


include(GoogleTest)
gtest_discover_tests(bank_test)