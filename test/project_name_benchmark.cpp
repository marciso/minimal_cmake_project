#include <benchmark/benchmark.h>

static void project_name_benchmark1(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(project_name_benchmark1);

// Define another benchmark
static void project_name_benchmark2(benchmark::State& state) {
    std::set<int> data;
    for (auto _ : state) {
        state.PauseTiming();
        data = std::set<int>{(int)state.range(0)};
        state.ResumeTiming();
        for (int j = 0; j < state.range(1); ++j)
            data.insert(j);
    }
}
BENCHMARK(project_name_benchmark2)
    ->Args({1<<10, 10})
    ->Args({2<<10, 20});

BENCHMARK_MAIN();
