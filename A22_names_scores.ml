open Shared

module Name = struct
  type t =
    { name : string
    ; index : int
    }

  let get_value_of_char c = Char.code c - Char.code 'A' + 1

  let get_score t =
    t.name |> String.fold_left (fun acc cur -> acc + get_value_of_char cur) 0
  ;;

  let get_value t = get_score t * t.index
  let get_name t = t.name
  let get_index t = t.index
  let make_name i n = { name = n; index = i + 1 }
  let print n = print_endline (string_of_int n.index ^ " " ^ n.name)
end

module Parser = struct
  type t = Name.t list

  let rec parse head rest cur acc =
    let lastindex = String.length rest - 1 in
    let first = rest.[lastindex] in
    let rest = String.sub rest 0 lastindex in
    if String.length rest = 0
    then cur :: acc
    else (
      match head with
      | '\n' | ' ' | '"' -> parse first rest cur acc
      | ',' -> parse first rest "" (cur :: acc)
      | _ -> parse first rest (String.make 1 head ^ cur) acc)
  ;;

  let parse_text_into_names text = parse ' ' text "" []
end

let solve names =
  names
  |> List.sort String.compare
  |> List.mapi Name.make_name
  |> List.map Name.get_value
  |> List.fold_left ( + ) 0
;;

(* 871198282 *)

let () =
  let text = Util.read_file "input_0022.txt" in
  let input = Parser.parse_text_into_names (" " ^ text) in
  solver solve input
;;
