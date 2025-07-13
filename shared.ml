let solver (func : int -> int) (input : int) =
  let starttime = Sys.time () in
  let result = func input in
  let endtime = Sys.time () in
  input |> Printf.printf "Input: %d\n";
  result |> Printf.printf "Solution: %d\n";
  (endtime -. starttime) *. 1000. |> Printf.printf "Time: %f ms\n"
;;
