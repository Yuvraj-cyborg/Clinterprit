# Review context: Clinterprit

Read this before reviewing. It tells you what this project is and what to weigh
most heavily. It is injected as extra context into the PR review prompt.

## What this is

Clinterprit is a small **C interpreter / REPL** written in C. It reads a line of
input from stdin, runs it through a **lexer** (tokenizer), a **parser**, and an
**evaluator** for arithmetic expressions. Token kinds so far are `NUMBER`, `ADD`,
`SUBTRACT`, `MULTIPLY`, `DIVIDE`, and end-of-input. The code lives in `main.c`
today and is expected to grow into separate lexer / parser / evaluator units.

This is an **early-stage work in progress**. Prioritize correctness, crashes, and
memory safety over polish or architecture debates.

## Build & run

```bash
make            # gcc -Wall -Wextra main.c -o main && ./main
```

There is **no automated test suite yet**. You have a full VM — manual REPL testing
is encouraged (e.g. `printf '1 + 2\n' | ./main`, then try malformed and edge-case
input). The binary is an interactive REPL, so feed it via a pipe or heredoc so it
doesn't hang waiting on stdin.

## What to focus on (C-specific)

Weight your attention here, roughly in priority order:

1. **Memory safety.** Buffer overflows, out-of-bounds reads/writes, use-after-free,
   double-free, uninitialized reads. Watch fixed-size buffers (`fgets` into
   `char buff[INPUT_LEN]`) and any pointer-walking over the input string.
2. **Undefined behavior.** Signed integer overflow in arithmetic evaluation,
   **division / modulo by zero**, dereferencing `NULL` or invalid pointers, reading
   past the NUL terminator, and shift/overflow UB.
3. **EOF / input handling.** `fgets` returns `NULL` on EOF (Ctrl-D) or error — if
   that isn't checked, the REPL can spin forever or operate on stale buffer
   contents. Also handle empty lines and input longer than the buffer (truncation).
4. **Lexer / parser robustness.** Unexpected characters, malformed expressions,
   unbalanced tokens, and leading/trailing whitespace should produce a clear error,
   not a crash or silent wrong answer.
5. **Standard-library name collisions.** C has no namespaces. Flag identifiers that
   collide with or shadow standard names — e.g. an `EOF` token enum vs. the `<stdio.h>`
   `EOF` macro, or a local variable that shadows a function parameter.
6. **Resource handling.** Every `malloc`/`fopen` freed/closed on all paths,
   including error paths; no leaks accumulating across REPL iterations.
7. **Clean compile.** Code should build warning-free under `-Wall -Wextra`. Flag
   anything that would trip those warnings (unused vars, implicit conversions,
   missing returns, uninitialized use).
8. **Error UX.** Malformed input should yield a readable message and keep the REPL
   alive, not segfault or exit.

## Scope / what to skip

- Don't comment on formatting, style, or lint — CI and the babysit bot handle those.
- Don't run a test suite (there isn't one). Prefer targeted manual runs instead.
- Don't over-index on architecture for a file this small; suggest structure only
  when it directly prevents a class of bugs above.

Be constructive and concrete. Point to the specific line and describe the failing
input or scenario, not just the abstract concern.
