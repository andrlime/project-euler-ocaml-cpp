open Shared

let rec floodfill (cur : int) (stepsize : int) (max : int) (list : bool array)
  : bool array
  =
  if cur > max
  then list
  else (
    list.(cur) <- false;
    floodfill (cur + stepsize) stepsize max list)
;;

let rec sieve (factor : int) (max : int) (list : bool array) : bool array =
  if factor > max
  then list
  else (
    match list.(factor) with
    | true -> floodfill (factor + factor) factor max list |> sieve (factor + 1) max
    | false -> sieve (factor + 1) max list)
;;

let generate_primes (max : int) : (int * bool) list =
  let primes = Array.make (max + 1) true in
  primes.(0) <- false;
  primes.(1) <- false;
  sieve 2 max primes |> Array.mapi (fun i e -> i, e) |> Array.to_list
;;

let solve (n : int) : int =
  n
  |> generate_primes
  |> List.filter (fun (i, e) -> e)
  |> List.fold_left (fun acc (number, _) -> acc + number) 0
;;

let () =
  let input = 2000000 in
  solver solve input
;;
