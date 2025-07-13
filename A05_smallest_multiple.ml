open Shared

let primes_to_20 = [ 2; 3; 5; 7; 11; 13; 17; 19 ]

let rec range (cur : int) (max : int) (accum : int list) : int list =
  match cur = max with
  | true -> cur :: accum
  | false -> range (cur + 1) max (cur :: accum)
;;

let rec prime_factorise (candidates : int list) (accum : int list) (n : int) : int list =
  if n = 1
  then accum
  else (
    match candidates with
    | [] -> accum
    | head :: rst ->
      if n mod head = 0
      then prime_factorise candidates (head :: accum) (n / head)
      else prime_factorise rst accum n)
;;

let to_hashtable (list : int list) : (int, int) Hashtbl.t =
  let tbl = Hashtbl.create 11 in
  list
  |> List.iter (fun e ->
    let curval = Option.value (Hashtbl.find_opt tbl e) ~default:0 in
    Hashtbl.replace tbl e (1 + curval));
  tbl
;;

(* n is small, no need for fancy tricks here *)
let rec pow (base : int) (exponent : int) : int =
  if exponent == 0 then 1 else base * pow base (exponent - 1)
;;

let solve (n : int) : int =
  let tbl = Hashtbl.create 11 in
  range 1 n []
  |> List.map (prime_factorise primes_to_20 [])
  |> List.map to_hashtable
  |> List.iteri (fun i e ->
    Hashtbl.iter
      (fun key value ->
         let curval = Option.value (Hashtbl.find_opt tbl key) ~default:0 in
         Hashtbl.replace tbl key (max curval value))
      e);
  Hashtbl.fold (fun key value accum -> accum * pow key value) tbl 1
;;

let () =
  let input = 20 in
  solver solve input
;;
