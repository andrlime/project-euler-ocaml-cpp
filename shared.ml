module Util = struct
  let read_file path =
    let channel = open_in path in
    let len = in_channel_length channel in
    let content = really_input_string channel len in
    close_in channel;
    content
  ;;
end

let solver func input =
  let starttime = Sys.time () in
  let result = func input in
  let endtime = Sys.time () in
  result |> Printf.printf "Solution: %d\n";
  (endtime -. starttime) *. 1000. |> Printf.printf "Time: %f ms\n"
;;
