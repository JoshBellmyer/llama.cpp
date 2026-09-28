#include <cstdio>
#include <cstdlib>

int llama_bench(int argc, char ** argv);

int main(int argc, char ** argv) {
    // redirect output to a file when running under profilers that swallow console output (e.g. nsys on Windows)
    if (const char * log_file = std::getenv("LLAMA_BENCH_LOG_FILE")) {
        if (freopen(log_file, "w", stdout) != nullptr) {
            freopen(log_file, "a", stderr);
        }
    }
    return llama_bench(argc, argv);
}
