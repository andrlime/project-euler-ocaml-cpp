open Shared

let rec range cur min accum =
  match cur = min with
  | true -> cur :: accum
  | false -> range (cur - 1) min (cur :: accum)
;;

let solve n =
  let arr = Array.init (n + 1) (fun _ -> Array.make (n + 1) 0) in
  arr.(0).(0) <- 1;
  let rng = range n 0 [] in
  rng
  |> List.iter (fun row ->
    rng
    |> List.iter (fun col ->
      match row > 0, col > 0 with
      | true, true -> arr.(row).(col) <- arr.(row).(col - 1) + arr.(row - 1).(col)
      | true, false -> arr.(row).(col) <- arr.(row).(col) + arr.(row - 1).(col)
      | false, true -> arr.(row).(col) <- arr.(row).(col - 1) + arr.(row).(col)
      | false, false -> arr.(row).(col) <- arr.(row).(col)));
  arr.(n).(n)
;;

let () =
  let input = 20 in
  solver solve input
;;
