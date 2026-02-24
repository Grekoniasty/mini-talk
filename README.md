# minitalk

A 42 School project demonstrating UNIX signal-based inter-process communication. A client sends a string to a server using only `SIGUSR1` and `SIGUSR2` — one bit at a time.

---

## How it works

The server starts and prints its PID. The client takes that PID and a string, then encodes each character bit by bit:

- `SIGUSR1` represents a `0` bit
- `SIGUSR2` represents a `1` bit

The server reconstructs each character by collecting 8 bits, then prints it. `sigaction` is used instead of `signal` for reliable, portable handling.

---

## Bonus

The bonus adds **acknowledgement signals** — after receiving each character, the server sends a signal back to the client confirming receipt. This prevents signal loss on fast transmissions and allows the client to know when the full message has been delivered.

Unicode support is also included, handling multi-byte characters correctly by extending the bit-collection logic beyond 8 bits where needed.
