open Shared

let rec range (cur : int) (max : int) (accum : int list) : int list =
  match cur = max with
  | true -> cur :: accum
  | false -> range (cur + 1) max (cur :: accum)
;;

let solve (n : int) : int =
  let rng = range 1 n [] in
  let sum_of_numbers = rng |> List.fold_left ( + ) 0 in
  let sum_of_squares = rng |> List.fold_left (fun acc cur -> acc + (cur * cur)) 0 in
  (sum_of_numbers * sum_of_numbers) - sum_of_squares
;;

let () =
  let input = 100 in
  solver solve input
;;
