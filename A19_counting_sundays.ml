open Shared

type day =
  | Sunday
  | Monday
  | Tuesday
  | Wednesday
  | Thursday
  | Friday
  | Saturday

type month =
  | January
  | February
  | March
  | April
  | May
  | June
  | July
  | August
  | September
  | October
  | November
  | December

type year = int
type date_t = year * month

let is_leap (y : year) : bool =
  if y mod 4 <> 0 then false else if y mod 100 == 0 then y mod 400 == 0 else true
;;

let get_day_count (m : month) (y : year) : int =
  match m with
  | January -> 31
  | February -> if is_leap y then 29 else 28
  | March -> 31
  | April -> 30
  | May -> 31
  | June -> 30
  | July -> 31
  | August -> 31
  | September -> 30
  | October -> 31
  | November -> 30
  | December -> 31
;;

let next_month (month : month) : month =
  match month with
  | January -> February
  | February -> March
  | March -> April
  | April -> May
  | May -> June
  | June -> July
  | July -> August
  | August -> September
  | September -> October
  | October -> November
  | November -> December
  | December -> January
;;

let get_next_date ((y, m) : date_t) : date_t =
  match m with
  | December -> y + 1, January
  | _ -> y, next_month m
;;

let add_to_day (d : day) (amount : int) : day =
  let current_index =
    match d with
    | Sunday -> 0
    | Monday -> 1
    | Tuesday -> 2
    | Wednesday -> 3
    | Thursday -> 4
    | Friday -> 5
    | Saturday -> 6
  in
  match (current_index + amount) mod 7 with
  | 0 -> Sunday
  | 1 -> Monday
  | 2 -> Tuesday
  | 3 -> Wednesday
  | 4 -> Thursday
  | 5 -> Friday
  | 6 -> Saturday
  | _ -> Sunday
;;

let rec get_count (day : day) (cur : year * month) (target : year) (accum : int) : int =
  let cur_year, cur_month = cur in
  if cur_year > target
  then accum
  else (
    let number_of_days = get_day_count cur_month cur_year in
    match day with
    | Sunday ->
      get_count (add_to_day day number_of_days) (get_next_date cur) target (accum + 1)
    | _ -> get_count (add_to_day day number_of_days) (get_next_date cur) target accum)
;;

let solve ((syear, eyear) : year * year) : int =
  get_count Tuesday (syear, January) eyear 0
;;

let () =
  let start_year = 1901 in
  let end_year = 2000 in
  let input = start_year, end_year in
  solver solve input
;;
