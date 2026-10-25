# 50 — v10 Master Plan: 26 weeks, 20 hours a week maximum

> Copy of `C_CPP_Performance_Command_Course_6_Months/50_v10_master_plan_20h.md` (v10). Links to other course files point into that local course folder, not this repo.

This file is the single schedule for the course. When any other file disagrees about hours, order or targets, this file wins. Older plans (files 29, 42, 44 and 45, the README's 45–55 hour figure, and the archive) are kept for reference only.

## 1. The one rule: 20 hours a week is a ceiling

You study **at most 20 focused hours per week**. That is 520 hours over 26 weeks. Everything counts toward the 20: reading, coding, algorithms, mock interviews, applications and reviewing old material. Breaks and commuting do not count, and neither do they earn you extra study time.

If you fall behind, you **cut scope, never add hours**. Cut in this order, and write down what you cut so you can come back to it later:

1. "Go deeper" items and optional demos inside a lesson.
2. The backup domain thread for that week (embedded or games). It returns next cycle.
3. Extra algorithm problems beyond the weekly minimum.
4. Repeat runs of benchmarks you have already reported.

Never cut: the weekly build, the exercises, the closed-book gate, or the 7-day retest. Those are where the learning actually happens.

Keep one full rest day a week. Sleep consolidates what you studied; an exhausted hour is worth less than a rested one.

## 2. What you are aiming at

**Primary target: high-finance C++.** Market makers and proprietary trading firms (Citadel Securities, Hudson River Trading, Jump, Optiver, IMC, Tower, DRW, Akuna), multi-strategy funds (Citadel), and Jane Street.

Two honest notes:

- **Jane Street** writes almost everything in OCaml. Its software-engineering interviews let you use any language, so C++ is fine in the room, and the interviews reward clean code that you extend as the problem grows. If Jane Street is a top target, spend the optional OCaml hour in Weeks 21–26 (see §6). Citadel Securities, HRT Core, Jump and Optiver are the firms where C++ depth is the interview itself.
- **These are among the hardest software offers to get.** Plan the stepping stones too: bank electronic-trading and market-access teams, exchanges (CME, Nasdaq, ICE, Cboe), market-data and trading-infrastructure vendors, and smaller prop shops. One to two years in one of those makes the top firms far more reachable.

**Backups: flight software, embedded systems, and game engines.** These are not separate courses. They reuse the same core work: a binary packet parser becomes a market-data decoder, a telemetry decoder and a network-message decoder; a ring buffer moves market data, UART bytes and render commands; replay testing checks an order book, a flight state machine and a deterministic simulation. You build skill organically in all four domains from one foundation.

## 3. The weekly budget

| Block | Hours | Source |
|---|---:|---|
| Core lesson + build | 10 | The core file(s) for that week (table in §5) |
| Algorithms and data structures (in C++) | 4 | NeetCode 150, then Codeforces (§7) |
| Domain thread | 3 | Finance (55), flight/embedded (57) or games (58), rotating |
| Probability and mental math | 1.5 | File 56: five-minute daily drills plus one 60-minute session |
| Interview practice and career | 1.5 | Explaining answers aloud, STAR stories, resume, outreach, mocks |
| **Total** | **20** | |

A typical week (each day except the rest day also has a 5-minute mental-math drill; six drills = 30 minutes, part of the probability block):

| Day | Hours | Plan |
|---|---:|---|
| Mon | 2 | Core: read the lesson; type and run the examples |
| Tue | 2 | Core: build |
| Wed | 2 | Algorithms: two or three problems |
| Thu | 2 | Core: build and tests |
| Fri | 2 | Algorithms 1.5 h (one problem + a 7-day retest) · explain one answer aloud, recorded, 0.5 h |
| Sat | 6 | Core build 3 h · domain thread 3 h |
| Sun | 3.5 | Core exercises and gate 1 h · algorithms 0.5 h · probability session 1 h · career 1 h |
| Rest | — | One full day off; move the plan so the rest day falls where it suits you |

Totals: core 10 · algorithms 4 · domain 3 · probability 1.5 (1 h session + 30 min of drills) · interview/career 1.5 = **20**.

## 4. Which files you use

**Primary teaching files (v10):**

| File | What it teaches | Weeks |
|---|---|---|
| [51](51_lessons_c_and_machine_model.md) | C and the machine model | 1–5 |
| [54](54_lessons_modern_cpp_depth.md) | Modern C++ in depth | 6–11 |
| [52](52_lessons_linux_networking_concurrency.md) | Linux, networking, concurrency, the memory model | 9–14 |
| [53](53_lessons_performance_and_low_latency.md) | Performance engineering and low latency | 13–18 |
| [55](55_lessons_markets_order_book_market_data.md) | Markets, order books, market data; the flagship build | thread all year; core build 15–22 |
| [56](56_lessons_probability_and_mental_math.md) | Probability and mental math | every week |
| [57](57_lessons_flight_software_and_embedded.md) | Flight software and embedded (backup thread) | 3, 7, 11, 15, 19, 23 |
| [58](58_lessons_game_engine_systems.md) | Game engine systems (backup thread) | 4, 8, 12, 16, 20, 24 |

**Runnable labs:** `foundation_labs/`, `teaching_labs/` (including the new `order_book.hpp`/`order_book.cpp` and `spsc_queue.cpp`), `interview_labs/` (broken programs to debug, with solutions), `work_samples/`.

**Kept as supporting material:**

- Exercises and answer keys: 19.
- Mastery gates: 31 (its gates apply on the timing in §8 below).
- Paper design: 27 and 40.
- Options accounting: 41.
- The unfamiliar-repository exercise: 33.
- Mock interviews: 34 (blind full loops), 26 (company-style loops; choose finance ones) and 13 (broken-code labs).
- Hiring research: 43, finance sections. Verify every detail with the recruiter.

**Reference only (do not schedule from these):** 00–12, 14–18, 20–30, 32, 35–39, 42, 44, 45 and `archive/`. Files 36–39 are the compact originals of 51–54. Use them for a second explanation if a v10 lesson does not land.

**The 1,000-question dataset** (`../C_CPP_Interview_Dataset_1000/`) is not part of the schedule. If you want extra recall practice, use only questions CPP-0001 to CPP-0100 and its `labs/solutions.cpp`.

## 5. The 26 weeks

Domain thread key: **F** = finance module in file 55, **E** = flight/embedded module in file 57, **G** = games module in file 58. "P-n" = probability unit n in file 56.

| Wk | Core (10 h) | Build you finish this week | Domain (3 h) | Algorithms (4 h) | Prob. | Gate |
|---:|---|---|---|---|---|---|
| 1 | 51 Week 1: source to running process | numbers tool (`01_numbers.c` contract) | F1 | Arrays & hashing | P-1 | |
| 2 | 51 Week 2: integers and floating point | text statistics (`02_text_stats.c`) | F2 | Arrays & hashing, two pointers | P-1 | |
| 3 | 51 Week 3: pointers, memory layout, gdb | dynamic byte vector (`03_dynamic_array.c`) | E1 | Two pointers | P-2 | |
| 4 | 51 Week 4: structs, endianness, allocators | packet codec, rebuilt frame codec | G1 | Sliding window | P-2 | |
| 5 | 51 Week 5: UB, sanitizers, assembly, CMake | frame decoder capstone with tests | F3 | Stack | P-3 | **G1** |
| 6 | 54 Lesson 1: lifetime, RAII, rule of 0/3/5 | lifetime tracer, rule-of-five buffer | F4 | Binary search | P-3 | |
| 7 | 54 Lesson 2: value categories, move, forwarding | elision lab, `noexcept` growth lab | E2 | Linked list | P-4 | |
| 8 | 54 Lesson 3: smart pointers, allocators | your `UniquePtr`, `SharedPtr`, arena, pool | G2 | Trees | P-4 | |
| 9 | 54 L4 (vector from scratch) 5 h · 52 L1–2 (processes, syscalls, pipes) 5 h | `Vec<T>` with strong guarantee; `write_all` + pipe capture | F5 | Trees | P-5 | |
| 10 | 54 L5 (polymorphism, templates, lambdas) 5 h · 52 L3 (virtual memory, mmap) 5 h | CRTP/concepts/`variant` handler; page-fault counter | F6 | Tries, heap | P-5 | |
| 11 | 54 L6 (STL internals, UB, the drill) 5 h · 52 L4 (sockets, TCP, UDP multicast) 5 h | the 16-snippet drill closed-book; framed loopback client/server | E3 | Heap / priority queue | P-6 | **G2** |
| 12 | 52 L5–6: epoll, threads, locks, condition variables | epoll echo server; thread pool with clean shutdown (TSan clean) | G3 | Backtracking | P-6 | |
| 13 | 52 L7 (memory model) 5 h · 53 L1–2 (latency numbers, pipeline, branches) 5 h | litmus tests; `branch_demo` and its assembly | F7 | Graphs | P-7 | |
| 14 | 52 L8 (SPSC, seqlock, false sharing) 5 h · 53 L3 (caches, layout, TLB) 5 h | your own SPSC vs `teaching_labs/spsc_queue.cpp`; `traversal` + `false_sharing` | F8 | Graphs | P-7 | |
| 15 | 53 L4 (allocation, hot path) 5 h · 55 B1 (book design) 5 h | `alloc_demo`; order-book paper design + invariants | E4 | Advanced graphs | P-8 | |
| 16 | 53 L5 + L7 first half (compiler, timers, percentiles) 5 h · 55 B2 (matching, cancel, modify) 5 h | aliasing/PGO lab; order book add/cancel/match with tests | G4 | 1-D dynamic programming | P-8 | **G3** |
| 17 | 53 L7 second half (Google Benchmark, coordinated omission, perf) 5 h · 55 B3 (testing the book) 5 h | `bm_demo`; order book passes a differential test vs a naive book | F9 | 1-D DP | P-9 | |
| 18 | 53 L8–9 (NIC-to-strategy, benchmark campaign) 5 h · 55 B4 (ITCH parser, synthetic feed) 5 h | written SPSC campaign report; ITCH decoder with tests | F10 | 2-D DP | P-9 | |
| 19 | 55 B5: the book builder | market-by-order replica books from ITCH (synthetic feed; a real Nasdaq sample file if you download one) | E5 | Intervals, greedy | P-10 | |
| 20 | 55 B6: the benchmark campaign | p50/p99/p99.9 per message; zero allocation on the hot path | G5 | Mixed review | P-10 | **G4** |
| 21 | 55 B7: the optimization pass (+ file 41 options accounting if time) | one measured optimization, one rejected, before/after report | F11 | Codeforces Div 2 set | P-11 | |
| 22 | 55 B8: putting it together | feed → book → strategy → pre-trade risk → gateway, two threads joined by the SPSC queue | F12 | Codeforces Div 2 set | P-11 | |
| 23 | Capstone hardening | fuzzing, fault injection, README a stranger can reproduce, cold demo | E6 | Codeforces + company tags | P-12 | **G5** |
| 24 | Unfamiliar codebase (file 33) | one small tested patch to a real open-source C++ project | G6 | Company tags | P-12 | |
| 25 | Interview gauntlet (files 34, 26, 13) | two blind full loops; C++ internals and concurrency drills; fix what failed | F13 | Timed mixed sets | P-13 | |
| 26 | Final loops and applications | fresh variants; applications and referrals sent | F14 | Timed mixed sets | P-13 | **G6** |

**Where the domain threads land.** Finance gets 14 sessions (42 hours) plus the eight-week core build. Flight/embedded and games each get 6 sessions (18 hours). That is enough for informed, project-backed interviews in the backup domains, while the depth goes into finance. After Week 26, see §10 for how to deepen a backup if one of those doors opens first.

**Weeks with two core files** (9–11, 13–18) split the 10 core hours roughly 5 and 5. Several of those lessons were written assuming a full 10 hours. Do the idea, the worked examples, the build and the exercises. Treat the extra demos and "Go deeper" lists as optional, following the cut order in §1. In file 53, Lesson 6 (SIMD) is optional on this schedule. Skim it, and come back to it after Week 26 or if a role asks for it.

## 6. Optional swaps (still inside 20 hours)

- **Jane Street focus.** In Weeks 21–26, replace one hour of algorithms with OCaml (*Real World OCaml*, free online). Re-solve problems you already know in OCaml. The goal is to read and write it comfortably, not to master it.
- **Optiver / trader-adjacent focus.** From Week 13, move 30 minutes from the domain thread to timed arithmetic (file 56 drill protocol).
- **Embedded or flight software turns into the most promising door.** Swap a finance thread week for the next 57 module, and keep the order-book build.

## 7. Algorithms (4 hours a week, always in C++)

- **Weeks 1–18: NeetCode 150, pattern by pattern**, as listed in the table. That is about 8–10 problems a week. Implement each one without looking. Name the pattern. Write the complexity. Retest it 7 days later.
- **Weeks 19–22:** redo NeetCode problems in random order, plus one timed Codeforces Div 2 set a week (problems B–D). HRT and Jump online assessments feel closer to Codeforces than to LeetCode.
- **Weeks 23–26:** company-tagged lists for the firms you are actually interviewing with, and timed mixed sets.
- Readiness means **solving an unseen medium in 20–30 minutes while explaining aloud**, not a problem count.

## 8. Gates (pass before moving on; details in file 31 and in each lesson's self-check)

| Gate | Week | You must, closed book |
|---|---:|---|
| G1 C foundations | 5 | Write and debug small C programs from an empty file. Explain source→process, two's complement, struct padding and endianness. Ship the frame decoder with tests, clean under the sanitizers. |
| G2 C++ and OS basics | 11 | Implement `Vec<T>` and a `UniquePtr` from memory. Answer the 16-snippet drill. Explain fork/COW, mmap and TCP framing. |
| G3 Concurrency and performance | 16 | Build a correct mutex queue and an SPSC ring. Defend every `memory_order`. Demonstrate false sharing with numbers. Report a benchmark with p50/p99 and equal work. |
| G4 Domain correctness | 20 | Order book passes a differential test vs a naive book. ITCH replay into the book works. Latency report is honest about scope (simulated vs real). |
| G5 Assurance | 23 | Fuzzed parser, fault-injection tests, a README a stranger can reproduce, and a cold demo with no notes. |
| G6 Employability | 26 | Two blind full loops with no critical failure in coding, C++ depth, concurrency or communication; applications out. |

If you fail a gate, spend the next week's core hours repairing exactly what failed. Push later weeks back by one and record that you did. Do not start lock-free work on a shaky C foundation.

## 9. Applications timeline

- **Weeks 4–10:** read 10–12 real job postings across the four domains. List the skills they ask for and keep the list in your repo.
- **Weeks 14–18:** apply to stepping-stone and backup roles where your evidence already fits: embedded, flight software, bank technology and exchanges. Three to five well-targeted applications a week.
- **Week 18 onward:** apply to trading firms once the order book and the SPSC benchmark report are public and reproducible. Use the experienced-hire route if you have work history.
- **Throughout:** student competitions and programs that skip the resume screen (for example IMC Prosperity), if you are eligible.
- **Track replies, screens, technical passes and offers separately.**
  - No replies after a meaningful number of applications: fix your resume and targeting.
  - Failing coding screens: shift two hours into algorithms for four weeks.
  - Failing the C++ depth rounds: repeat file 54's drill and file 52's Lesson 7.

## 10. After Week 26

Keep 20 hours a week and keep applying. The application campaign usually runs several more months. Deepen whichever domain is producing interviews. For flight or embedded, port the telemetry service from file 57 to a real microcontroller board. For games, add the SDL3 window and rendering from file 58. For finance, add multicast feed handling, a binary order-entry protocol and file 53's SIMD and kernel-bypass topics.

## 11. Your weekly log (copy into your repo each week)

```text
Week N — hours: core _/10, algorithms _/4, domain _/3, probability _/1.5, career _/1.5 = _/20
Built (commit links):
Failed and how I proved the cause:
Measured (numbers + machine + flags):
Gate / retest results:
Cut this week (to return to):
Next week's first task (file, function, first test):
```
