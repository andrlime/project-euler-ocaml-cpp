open Shared

let rec helper (n : int) (accum : int) : int =
  if n == 0
  then accum
  else (
    match n mod 3, n mod 5 with
    | 0, _ | _, 0 -> helper (n - 1) (accum + n)
    | _ -> helper (n - 1) accum)
;;

let rec solve (n : int) : int = helper n 0

let () =
  let input = 1000 in
  solver solve (input - 1)
;;
