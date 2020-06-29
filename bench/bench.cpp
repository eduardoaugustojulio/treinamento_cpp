#include "benchmark/benchmark.h"

static void CountPrimes(benchmark::State& State)
{

}


BENCHMARK(CountPrimes)
    ->Args({100})
    ->Args({1000})
    ->Args({10000})
    ->Args({100000});

BENCHMARK_MAIN();
