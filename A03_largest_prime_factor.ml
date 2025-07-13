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

let find_max_prime (n : int) (max : int) (list : (int * bool) list) =
  List.fold_left
    (fun acc (index, _) ->
       match n mod index with
       | 0 -> index
       | _ -> acc)
    0
    list
;;

let solve (n : int) : int =
  n
  |> Float.of_int
  |> Float.sqrt
  |> Float.floor
  |> Float.to_int
  |> generate_primes
  |> List.filter (fun (i, e) -> e)
  |> find_max_prime n 0
;;

let () =
  let input = 600851475143 in
  solver solve input
;;
