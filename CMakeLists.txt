cmake_minimum_required(VERSION 2.8)
project(treinamento-cpp)

add_compile_options(-std=c++11 -pthread)
set(PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

set(SRCS_PATH   "${PROJECT_PATH}/src")
set(SRCS_HEADERS "${SRCS_PATH}")
file(GLOB SRCS_FILES 
    "${SRCS_PATH}/*.cpp"
)

set(TESTS_PATH   "${PROJECT_PATH}/test")
file(GLOB TESTS_FILES 
    "${TESTS_PATH}/*.cpp"
)

set(EXTRNL_PATH "${PROJECT_PATH}/ext")
set(EXTRNL_INCD_PATH "${EXTRNL_PATH}/include")
set(EXTRNL_LIBS_PATH "${EXTRNL_PATH}/lib/Linux") 

set(GTEST_INCD "${EXTRNL_INCD_PATH}/gtest")
set(HIPPO_INCD "${EXTRNL_INCD_PATH}/HippoMocks") 

find_package(Threads REQUIRED)
find_library(LIBS gtest gtest_main ${EXTRNL_LIBS_PATH})

include_directories(
    ${SRCS_HEADERS} 
    ${GTEST_INCD}
    ${HIPPO_INCD}
    ${EXTRNL_INCD_PATH} 
)

add_executable(component ${SRCS_FILES})
target_link_libraries(component ${LIBS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(unit_test ${TESTS_FILES})
target_link_libraries(unit_test ${LIBS} ${CMAKE_THREAD_LIBS_INIT})

