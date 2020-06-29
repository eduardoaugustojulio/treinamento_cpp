include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB srcs
            Calculo.cpp
)

add_executable(Calculo main.cpp ${srcs})
