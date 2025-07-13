open Shared

let rec is_prime (n : int) (list : int list) : bool =
  match list with
  | [] -> true
  | p :: [] -> if p * p > n then true else n mod p <> 0
  | p :: ps -> if n mod p = 0 then false else is_prime n ps
;;

let rec get_nth (n : int) (count : int) (list : int list) (curnum : int) (lastprime : int)
  : int
  =
  if n == count
  then lastprime
  else if is_prime curnum list
  then get_nth (n + 1) count (list @ [ curnum ]) (curnum + 1) curnum
  else get_nth n count list (curnum + 1) lastprime
;;

let solve (n : int) : int = get_nth 0 n [] 2 2

let () =
  let input = 10001 in
  solver solve input
;;
