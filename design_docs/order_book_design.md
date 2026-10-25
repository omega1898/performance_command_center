# Limit order book — paper design (fill this in BEFORE writing code)

> Start this in Phase 1 and refine it before the Phase 2 build. A paper design you
> can defend aloud is the single highest-leverage habit for every firm in the
> dossier (file 43). Predict behavior first, then make code + tests + measurement agree.

## 1. Requirements (what it must do)
- Operations: add, cancel, replace, trade/match, snapshot, deterministic replay.
- Price-time priority. Define exactly what "priority" means and the tie-break.

## 2. Invariants (must always hold)
- [ ] Total resting quantity at a price = sum of resting orders at that price.
- [ ] No crossed book (best bid < best ask) after any committed event.
- [ ] Every order id is unique and resolvable to its price level in O(1).
- [ ] Replay of the same event stream produces a byte-identical state hash.

## 3. Ownership & data structures
- Who owns an order's memory? (no raw new/delete; state the owner)
- Price level -> orders: which container, and why (intrusive list for O(1) cancel?)
- Order id -> location: hash map? What breaks under adversarial ids?

## 4. Capacity budget
- Target events/sec and ns/event. Allocations per event (goal: zero on the hot path).
- Memory ceiling. What happens at 10x load?

## 5. Failure matrix (what happens on...)
| Event | Behavior |
|---|---|
| duplicate order id | |
| cancel unknown id | |
| out-of-order / gapped sequence | |
| quantity overflow | |
| self-trade | |
| replay divergence | |

## 6. How I will KNOW it is correct
- Property tests: price-time priority, quantity conservation, deterministic replay.
- How I measure latency: P50/P99/P99.9, pinned core, release build, baseline vs optimized.
