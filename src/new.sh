#!/bin/bash
outdir="$(dirname $0)"
num="`printf "%04d" $1`"
numshort="$1"
hout="$outdir/solution_$num.h"
cppout="$outdir/solution_$num.cpp"
#cp "$outdir/solution_1.h" "$outdir/solution_$1.h" -i
#cp "$outdir/solution_1.cpp" "$outdir/solution_$1.cpp" -i
cat > "$hout" << EOL
/**********************************
*  solution_XXXX.h                *
**********************************/
#pragma once
#include "solution.h"
class SolutionXXXX : public Solution {
protected:
    virtual answer_t get_answer();
public:
    SolutionXXXX();
};
EOL
cat > "$cppout" << EOL
/**********************************
*  solution_XXXX.cpp              *
**********************************/
#include "solution_XXXX.h"
SolutionXXXX sXXXX;
SolutionXXXX::SolutionXXXX() : Solution(YYYY, this) {};
answer_t SolutionXXXX::get_answer() {
    return 0;
}
EOL
mysed() {
    sed -i "s/XXXX/$num/g" $1
    sed -i "s/YYYY/$numshort/g" $1
}
mysed "$hout"
mysed "$cppout"
