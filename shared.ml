let solver (func : 'a -> int) (input : 'a) : unit =
  let starttime = Sys.time () in
  let result = func input in
  let endtime = Sys.time () in
  result |> Printf.printf "Solution: %d\n";
  (endtime -. starttime) *. 1000. |> Printf.printf "Time: %f ms\n"
;;
