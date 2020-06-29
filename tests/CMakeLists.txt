add_subdirectory(googletest)
include_directories(googletest/include)

file(GLOB test_srcs 
        TestCalculo.cpp
        TestFibonacci.cpp
        TestPrimos.cpp
)

add_executable(test_demo main.cpp ${test_srcs})
target_link_libraries(test_demo gtest)
