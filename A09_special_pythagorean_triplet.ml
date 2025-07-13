open Shared

let rec range (cur : int) (max : int) (accum : int list) : int list =
  match cur = max with
  | true -> cur :: accum
  | false -> range (cur + 1) max (cur :: accum)
;;

let solve (n : int) : int =
  let tbl = Hashtbl.create 31 in
  let rng = range 1 998 [] in
  rng |> List.map (fun x -> x, x * x) |> List.iter (fun (e, s) -> Hashtbl.add tbl s e);
  let pairs = List.concat_map (fun n -> List.map (fun m -> n, m) rng) rng in
  pairs
  |> List.map (fun (n, m) -> n, m, 1000 - n - m, (n * n) + (m * m))
  |> List.filter (fun (n, m, d, prod) ->
    Hashtbl.mem tbl prod && Hashtbl.find tbl prod = d)
  |> List.map (fun (n, m, d, _) -> n * m * d)
  |> List.hd
;;

let () =
  let input = 1000 in
  solver solve input
;;
