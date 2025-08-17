open Shared

module Name = struct
  type t =
    { name : string
    ; index : int
    }

  let[@inline] get_value_of_char c = Char.code c - Char.code 'A' + 1

  let get_score t =
    t.name |> String.fold_left (fun acc cur -> acc + get_value_of_char cur) 0
  ;;

  let get_value t = get_score t * t.index
  let[@inline] get_name t = t.name
  let[@inline] get_index t = t.index
  let[@inline] make_name i n = { name = n; index = i + 1 }
end

let[@inline] unquote str =
  String.sub str 1 @@ (String.length str) - 2
;;

let solve names =
  names
  |> String.trim
  |> String.split_on_char ','
  |> List.map unquote
  |> List.sort String.compare
  |> List.mapi Name.make_name
  |> List.map Name.get_value
  |> List.fold_left ( + ) 0
;;

let () =
  let text = Util.read_file "input_0022.txt" in
  let input = text in
  solver solve input
;;
