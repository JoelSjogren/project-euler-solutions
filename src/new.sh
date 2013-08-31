#!/bin/bash
outdir="$(dirname $0)"
cp "$outdir/solution_1.h" "$outdir/solution_$1.h"
cp "$outdir/solution_1.cpp" "$outdir/solution_$1.cpp"
