open Shared

let rec floodfill cur stepsize max list : bool array =
  if cur > max
  then list
  else (
    list.(cur) <- false;
    floodfill (cur + stepsize) stepsize max list)
;;

let rec sieve factor max list =
  if factor > max
  then list
  else (
    match list.(factor) with
    | true -> floodfill (factor + factor) factor max list |> sieve (factor + 1) max
    | false -> sieve (factor + 1) max list)
;;

let generate_primes max =
  let primes = Array.make (max + 1) true in
  primes.(0) <- false;
  primes.(1) <- false;
  sieve 2 max primes |> Array.mapi (fun i e -> i, e) |> Array.to_list
;;

let solve n =
  n
  |> generate_primes
  |> List.filter (fun (i, e) -> e)
  |> List.fold_left (fun acc (number, _) -> acc + number) 0
;;

let () =
  let input = 2000000 in
  solver solve input
;;
