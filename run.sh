#!/bin/bash

SHARED_LIB="shared"
OCAML_INPUT=$1
INPUT_BASENAME="${OCAML_INPUT%.ml}"

ocamlopt -c "$SHARED_LIB.ml"
ocamlopt -c "$OCAML_INPUT"
ocamlopt -O3 -o main "$SHARED_LIB.cmx" "$INPUT_BASENAME.cmx"
rm *.o
rm *.cmi
rm *.cmx

./main
rm ./main
