cmake_minimum_required(VERSION 2.8)
project(treinamento-cpp)

message(STATUS "To disable compilation of the unit test use: cmake -DWITH_UNIT=OFF ..")
option(WITH_UNIT "Compilation using unit test" ON)

# Compile options
add_compile_options(-std=c++11 -pthread)
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Project source files
set(SRCS_PATH   "${PROJECT_PATH}/src")
file(GLOB SRCS_FILES 
    "${SRCS_PATH}/*.cpp"
)

# Unit tests files
set(TESTS_PATH   "${PROJECT_PATH}/test")
file(GLOB TESTS_FILES 
    "${TESTS_PATH}/*.cpp"
)

# Externals directories
set(EXTRNL_PATH "${PROJECT_PATH}/ext")
set(EXTRNL_INCD_PATH "${EXTRNL_PATH}/include")
set(EXTRNL_LIBS_PATH "${EXTRNL_PATH}/lib/Linux") 

# HippoMocks and Google Test Headers
set(GTEST_INCD "${EXTRNL_INCD_PATH}/gtest")
set(HIPPO_INCD "${EXTRNL_INCD_PATH}/HippoMocks") 

# Find dependencies
find_package(Threads REQUIRED)
find_library(UNIT_TEST_LIBS gtest gtest_main ${EXTRNL_LIBS_PATH})

include_directories(
    ${SRCS_PATH} 
    ${GTEST_INCD}
    ${HIPPO_INCD}
    ${EXTRNL_INCD_PATH} 
)

add_custom_target(
    cppcheck
    COMMAND /usr/bin/cppcheck
    --enable=performance,portability,style
    --std=c++03
    --template=gcc
    ${SRCS_FILES} 2> cppcheck.txt 
)

if(WITH_UNIT)
    add_definitions(-DWITH_UNIT_TEST)
    
    # Compile unit test
    add_executable(unit_test  ${TESTS_FILES} ${SRCS_FILES})  
    target_link_libraries(unit_test ${UNIT_TEST_LIBS} ${CMAKE_THREAD_LIBS_INIT})
    
    # Only be able to run kcov if tests are available

else()
    add_definitions(-DNO_UNIT_TEST)
    
    # Compile Application
    add_executable(calculo ${SRCS_FILES})
    target_link_libraries(calculo ${CMAKE_THREAD_LIBS_INIT})
endif()
