open Shared

type hundreds =
  | OneThousand
  | Hundred of int
  | Zero

type units =
  | Onety of int
  | Multy of int * int
  | Zero

type number = hundreds * units

let rec range (cur : int) (min : int) (accum : int list) : int list =
  match cur = min with
  | true -> cur :: accum
  | false -> range (cur - 1) min (cur :: accum)
;;

let create_hundreds (n : int) : hundreds =
  if n = 0 then Zero else if n = 10 then OneThousand else Hundred n
;;

let create_units (n : int) : units =
  if n = 0 then Zero else if n < 20 then Onety n else Multy (n / 10, n mod 10)
;;

let rec count_letters_in_number (n : int) : int =
  let hundreds = create_hundreds @@ (n / 100) in
  let ones = create_units @@ (n mod 100) in
  match hundreds, ones with
  | OneThousand, Onety o -> 11 + 3 + count_letters_in_number o
  | OneThousand, Multy (t, o) -> 11 + 3 + (count_letters_in_number t * 10) + o
  | OneThousand, Zero -> 11
  | Hundred h, Onety o -> count_letters_in_number h + 7 + 3 + count_letters_in_number o
  | Hundred h, Multy (t, o) ->
    count_letters_in_number h + 7 + 3 + count_letters_in_number ((t * 10) + o)
  | Hundred h, Zero -> count_letters_in_number h + 7
  | Zero, Onety o ->
    (match o with
     | 19 -> 8
     | 18 -> 8
     | 17 -> 9
     | 16 -> 7
     | 15 -> 7
     | 14 -> 8
     | 13 -> 8
     | 12 -> 6
     | 11 -> 6
     | 10 -> 3
     | 9 -> 4
     | 8 -> 5
     | 7 -> 5
     | 6 -> 3
     | 5 -> 4
     | 4 -> 4
     | 3 -> 5
     | 2 -> 3
     | 1 -> 3
     | 0 -> 0
     | _ -> 0)
  | Zero, Multy (t, o) ->
    let tens_digit_count =
      match t with
      | 9 -> 6
      | 8 -> 6
      | 7 -> 7
      | 6 -> 5
      | 5 -> 5
      | 4 -> 5
      | 3 -> 6
      | 2 -> 6
      | _ -> 0
    in
    tens_digit_count + count_letters_in_number o
  | Zero, Zero -> 0
;;

let solve (n : int) : int =
  range (n + 1) 1 []
  |> List.fold_left (fun acc cur -> acc + count_letters_in_number cur) 0
;;

let () =
  let input = 1000 in
  solver solve (input - 1)
;;
