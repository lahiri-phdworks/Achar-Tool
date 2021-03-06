#!/usr/bin/bash
set -e
set -u
set -o pipefail

export CC=$(which hfuzz-clang)
export CXX=$(which hfuzz-clang++)
export AFL=$(which honggfuzz)

if [[ -z $1 ]];
then
    echo "Specify Timeout and example (single run)"
    exit -1
fi

if [[ -z $2 ]];
then
    echo "Specify Timeout and example (single run)"
    exit -1
fi

example=$1
timeout=$2

echo  ======== Compiling $example ========
# echo "#define PHI 1 // generated by code2inv" > include/hybrid_$example.h
./start.sh -b bin -o output -t tests -e hybrid_$example

echo  ======== Executing $example ========
timeout $timeout ./fuzz.sh -b bin -o output -t tests -e hybrid_$example

# for index in {1..10};
# do
#     timeout=10
#     echo  ======== Compiling $index ========
#     echo "#define PHI 1 // generated by code2inv" > include/hybrid_$index.h
#     ./start.sh -b bin -o output -t tests -e hybrid_$index

#     echo  ======== Executing $index ========
#     timeout $timeout ./fuzz.sh -b bin -o output -t tests -e hybrid_$index
# done

# rm -rf *.fuzz *.TXT