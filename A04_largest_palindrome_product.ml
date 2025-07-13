open Shared

let rec range (cur : int) (max : int) (accum : int list) : int list =
  match cur = max with
  | true -> cur :: accum
  | false -> range (cur + 1) max (cur :: accum)
;;

let generate_pairs ((min, max) : int * int) : (int * int) list =
  let domain = range min max [] in
  domain |> List.concat_map (fun n -> List.map (fun m -> n, m) domain)
;;

let generate_min_max (n : int) : int * int =
  let nfloat = Float.of_int n in
  let min = Float.to_int @@ Float.pow 10. (nfloat -. 1.) in
  let max = (Float.to_int @@ Float.pow 10. nfloat) - 1 in
  min, max
;;

let reverse_string (s : string) : string =
  let len = String.length s in
  String.init len (fun index -> String.get s (len - index - 1))
;;

let generate_products (list : (int * int) list) : int list =
  list |> List.map (fun (n1, n2) -> n1 * n2)
;;

let filter_palindromes (numbers : int list) : int list =
  numbers
  |> List.filter (fun n ->
    let stringrep = Int.to_string n in
    stringrep = reverse_string @@ stringrep)
;;

let find_max (list : int list) : int =
  list |> List.fold_left (fun acc cur -> if cur > acc then cur else acc) 0
;;

let solve (n : int) : int =
  n
  |> generate_min_max
  |> generate_pairs
  |> generate_products
  |> filter_palindromes
  |> find_max
;;

let () =
  let input = 3 in
  solver solve input
;;
