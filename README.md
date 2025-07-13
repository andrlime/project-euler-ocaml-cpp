# OCaml Project Euler 1-100

Solutions to Project Euler problems 1 through 100 (eventually will get there) in OCaml. Per the terms of the website, solutions for problems beyond 100 should not be posted on the public internet. Axx means 000-099, Bxx means 100-199, etc.

## Running
Dune is not used for this project as there are no dependencies. A `Shared` module contains a runner with a timer. Pass it a `'a -> int` function that takes the single input along with the input, and it will print the result. Compilation script is provided in `run.sh`. The `-O3` optimisation flag is used.
