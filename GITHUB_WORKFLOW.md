# GitHub workflow for weekly practice

Your repo: https://github.com/omega1898/performance_command_center

Everything you build goes here. Recruiters can see it, and the Saturday check-in reads it. Work that is not committed and pushed does not count, so save and push after every study session.

## One-time setup (already done on this computer)

For reference, in case you set up a second machine:

```bash
sudo apt install -y gh git
gh auth login                      # GitHub.com → HTTPS → Yes → Login with a web browser
git config --global user.name "mo"
git config --global user.email "you@example.com"
git clone https://github.com/omega1898/performance_command_center.git
```

**Still to do once: let the check-in upload its reports.**
1. Open https://github.com/apps/claude/installations/select_target
2. Choose **omega1898**.
3. Pick **Only select repositories**, then choose **performance_command_center**.
4. Click **Install**.

Optional: to hide your personal email on public commits, turn on GitHub → Settings → Emails → "Keep my email addresses private". Then run `git config --global user.email "<the noreply address GitHub shows you>"`.

## After every study session (2 minutes)

```bash
cd ~/Desktop/Cpp/performance_command_center
git status                      # see what changed
git add -A                      # stage everything (build/ is ignored automatically)
git commit -m "week 1: numbers tool parses and rejects bad input"
git push
```

Write commit messages that say what works now, not "update" or "stuff". A good history reads like a progress log:
- `week 3: dynamic byte vector grows; failed realloc keeps old data`
- `week 4: frame decoder rejects every truncated prefix (tests added)`
- `algorithms: two-sum and group-anagrams (arrays & hashing)`

Commit small and often. Several commits per session is normal, and it is better than one huge commit on Sunday.

## Where things go

| Work | Folder |
|---|---|
| C programs (Weeks 1–5) | `c_foundations/` |
| Modern C++ (Weeks 6–11) | `cpp_core/` |
| Linux, sockets, threads (Weeks 9–14) | `linux_systems/` |
| Benchmarks and performance experiments | `performance_lab/` + reports in `benchmark_reports/` |
| Order book, ITCH parser, pipeline (Weeks 15–22) | `market_engine/` |
| Reusable pieces (SPSC queue, allocators) | `shared_libraries/` |
| Flight/embedded thread (file 57) | `flight_embedded/` (create it in Week 3) |
| Games thread (file 58) | `realtime_engine/` |
| Algorithm problems (NeetCode, Codeforces) | `interview_drills/` |
| Paper designs and STAR stories | `design_docs/` |
| Weekly logs | `logs/` |

Each new program gets its own folder with a `CMakeLists.txt`, and a line in the top-level `CMakeLists.txt` (`add_subdirectory(...)`) so it builds and its tests run with everything else.

## Every Sunday: the weekly log

```bash
cp logs/TEMPLATE.md logs/week-01.md     # use the real week number, two digits
# fill it in: hours per block (max 20), what you built, what failed, what you cut
git add logs/week-01.md && git commit -m "week 1 log" && git push
```

The check-in uses your newest log to work out which plan week you are on, and checks your hours against the 20-hour cap.

## Every Saturday: read your check-in

A cloud check-in runs every Saturday morning (about 9–10am Eastern). It looks at the past week's commits, builds and tests the repo, compares your progress with `PLAN.md`, and writes a short report.

Read it in either place:
- **On GitHub:** switch the branch dropdown from `main` to `claude/checkins`, then open the `checkins/` folder.
- **In the terminal:**
  ```bash
  git fetch origin
  git show origin/claude/checkins:checkins/2026-10-31.md     # use that Saturday's date
  ```

GitHub may show a yellow "Compare & pull request" banner for `claude/checkins`. **Ignore it; never merge it.** That branch only holds reports, and your work stays on `main`.

To manage the check-in (pause, run now, see past runs): https://claude.ai/code/routines/trig_015DK1BCDhwHu53GfERxCDTD

## When something goes wrong

| Problem | Fix |
|---|---|
| `git push` rejected ("fetch first") | `git pull --rebase` then `git push` |
| Committed something by mistake (not pushed yet) | `git reset --soft HEAD~1`, fix it, commit again |
| Want to throw away uncommitted changes to one file | `git restore path/to/file` |
| A big file or build output got staged | `git restore --staged <file>` and add the pattern to `.gitignore` |
| `gh` or `git` asks you to log in again | `gh auth login` |
| Not sure what state you are in | `git status` and `git log --oneline -5` |

Never commit passwords, API keys or personal data. Before pushing, check `git status` for anything unexpected.
