# Real-time engine + iOS game — paper design (the lead Apple artifact)

> Fill this in during pre-season / Phase 1, before writing engine code. The portfolio
> artifact is a MEASURED engine subsystem + a SMALL shipped game — not a big game.
> See course file 45 for how this maps to the 180-day plan and target companies.

## 1. The game (keep it tiny + deterministic + entity-heavy)
- Pick one small concept whose fun comes from MANY entities: swarm / bullet-hell / 2D-physics sandbox.
- Why entity-heavy: it forces the ECS, job system, and cache-friendly layout to matter, and produces real frame-budget numbers to optimize.
- Determinism requirement: same inputs -> same state -> reproducible hash (enables replay + testing).

## 2. Modules
- [ ] **ECS** — sparse-set or archetype storage; entity handles (generation + index) that detect stale references.
- [ ] **Component layout** — Structure-of-Arrays (data-oriented), cache-line aware.
- [ ] **Fixed-timestep loop** — fixed update dt + render interpolation; deterministic system order.
- [ ] **Job system** — reuse `shared_libraries` lock-free queue; parallel system updates; explicit ownership transfer.
- [ ] **Allocators** — pool/arena for components; zero per-frame heap allocation on the hot path.
- [ ] **Render-backend interface** — one `Renderer` abstraction, two implementations:
      - backend 1: SDL3 / SDL_GPU or Vulkan (Linux dev on the i9)
      - backend 2: Metal via metal-cpp (iOS/macOS ship on the Mac)
- [ ] **Profiler overlay** — on-screen frame-time + per-system timings; frame-time histogram export.
- [ ] **Headless mode** — run the sim with no graphics; emit a reproducible state hash (the correctness gate).
- [ ] **iOS shell** — thin Swift/Obj-C app over a C interface to the C++ engine; touch input; TestFlight -> App Store.

## 3. Invariants
- [ ] A stale entity handle never reads a live component (generation check).
- [ ] Headless replay of an input log is byte-identical across runs and machines.
- [ ] No heap allocation inside the per-frame update once steady-state.

## 4. Budgets & how I'll measure
- Targets: 60 fps (16.67 ms) and 120 fps (8.33 ms) frames; report P95/P99 frame time, not mean.
- Counters: cache misses, branch misses, job-system utilization (Instruments on Apple Silicon; perf on Linux).
- The headline campaign: baseline -> cache-friendly SoA -> job-parallel -> (one optimization rejected by the data), with before/after traces and one deliberately retained bottleneck I can explain.

## 5. Cross-platform / ship plan
- Build + iterate everything possible on Linux behind the render interface.
- Mac needed only for: Metal backend, Instruments profiling, iOS build, App Store submission.
- Submit for App Store review EARLY in Phase 4 (review latency is days-to-weeks).
