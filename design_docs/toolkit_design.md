# Shared performance toolkit — paper design ("general tooling")

> The reusable substrate under BOTH flagships (engine + order book). Build in Phase 1.
> Each piece must stand alone: small, tested, benchmarked, defensible in an interview.

## Pieces
- [ ] **Lock-free SPSC queue** — `alignas(64)` to kill false sharing; acquire/release ordering.
      Gate: proven correct on x86 AND on ARM64 (the Mac). Benchmark round-trip latency vs a mutex baseline.
- [ ] **MPMC queue** (stretch) — bounded, Vyukov-style; compare against the SPSC and a mutex queue.
- [ ] **Job system** — task scheduler on top of the queue; used by the engine for parallel system updates.
      State the failure model: shutdown, cancellation, queue-full, worker death.
- [ ] **Pool / arena allocator** — fixed-size pool + bump arena; zero-allocation hot paths.
      Benchmark alloc/free throughput vs `malloc`; show the memory-retention tradeoff.
- [ ] **Benchmark harness** — thin wrapper over Google Benchmark / nanobench + `perf stat`.
      Enforces: Release build, pinned core (`taskset`), `DoNotOptimize`, inputs out of the timed loop,
      report P50/P99/P99.9, record CPU/compiler/flags. Every perf claim in the repo goes through this.
- [ ] **Deterministic event log** — append-only, replayable; shared by engine replay and order-book replay.

## Interview framing (one line each)
For each piece: what problem it solves, the key correctness argument (memory ordering / ownership / invariants),
and a measured number vs a baseline. "It's fast enough" is never the answer — name the mechanism and show the number.
