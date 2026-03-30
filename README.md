## PunkShell

This project is intentionally minimal and experimental.

Instead of aiming for full feature parity with traditional Unix shells, the focus is on:

* understanding core mechanisms
* keeping the codebase small and readable
* evolving the shell incrementally

The implementation favors clarity over completeness.

## Current Architecture

The current implementation follows a simple execution model:

input → argument splitting → execution

At this stage:

* Commands are split using basic tokenization (`strtok`)
* No advanced parsing is implemented yet
* Execution is handled through `fork` + `execvp`

This design is expected to evolve into a more structured pipeline:
input → tokenizer → parser → executor


quero implementar X
 → vejo documentação
 → implemento
 → erro
 → debug
 → aprendo de verdade


✅ fork + execvp (comando simples)
✅ tokenizer básico
✅ built-ins (cd, exit)
✅ pipes
✅ redirection
✅ signals decentes