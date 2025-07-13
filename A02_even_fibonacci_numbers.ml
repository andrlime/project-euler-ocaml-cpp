open Shared

let rec helper (prev : int) (cur : int) (accum : int) (max : int) : int =
  let next = prev + cur in
  if next > max
  then accum
  else (
    match next mod 2 with
    | 0 -> helper cur next (accum + next) max
    | _ -> helper cur next accum max)
;;

let solve (n : int) : int = n |> helper 1 1 0

let () =
  let input = 4000000 in
  solver solve (input - 1)
;;
