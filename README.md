# performance_command_center

Public evidence repository for a C++ / low-latency / performance-engineering career.
The value of this repo is the **visible progression** from small correct code to a
defensible, measured system — not a pile of unrelated tutorials.

**Target:** C++ roles in performance lanes at big companies — HFT/low-latency first
(Citadel Securities, HRT-Core, Jump, Akuna, Tower, IMC, DRW), Apple a priority
(CoreMedia/DSP, Compiler/LLVM, CPU-GPU perf), NVIDIA second.

**Plan:** executed from `44_180_day_command_plan_v9.md` in the course package;
hiring research in `43_big_company_hiring_dossiers_v9.md`.

## Non-negotiable rules
1. Correctness before speed. A faster wrong program is a regression.
2. No performance claim without a reproducible experiment (CPU, OS, compiler, flags, input, warm-up, sample count, distribution).
3. No benchmark with one timing — report median + P99 tail.
4. No raw pointer without an ownership explanation.
5. No concurrency feature without a stated failure model (shutdown, cancel, queue-full, timeout, crash, partial write).
6. No AI-generated code you cannot explain line by line.
7. Nothing is "done" until a stranger can clone it and reproduce the main result.

## Layout
```
c_foundations/    small C programs, memory, the machine model
cpp_core/         modern C++, ownership, templates, concurrency
linux_systems/    processes, sockets, epoll, mmap, IPC
performance_lab/  benchmark harnesses, cache/branch/SIMD studies
market_engine/    the limit order book + replay (HFT flagship)
realtime_engine/  (optional) ECS / fixed-timestep track
shared_libraries/ reusable pieces (SPSC queue, allocators, logger)
interview_drills/ timed problems, C++-internals reps
benchmark_reports/ written investigations (baseline -> change -> result)
design_docs/      paper designs + invariants, written BEFORE code
```

## Build & test
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
ctest --test-dir build --output-on-failure
# sanitizer pass:
cmake -S . -B build-san -DCMAKE_BUILD_TYPE=Debug -DSANITIZE=ON
cmake --build build-san -j && ctest --test-dir build-san --output-on-failure
```

Start with `WEEK_01_CHECKLIST.md`.
