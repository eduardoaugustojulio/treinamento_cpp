add_subdirectory(benchmark)
include_directories(benchmark/include)

file(GLOB bench_srcs bench.cpp)

add_executable(bench_demo ${bench_srcs})
target_link_libraries(bench_demo benchmark)
