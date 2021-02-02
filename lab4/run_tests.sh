# !/bin/bash

tests_list=(tests/in-*.txt)

for test in "${tests_list[@]}"
do
    echo "Test $test" 
    index=`echo "$test" | sed -n 's/tests\/in-\(.*\)\.txt/\1/p'` #get index

    ./build/app <"$test" > "tests/out-$index.txt"

    if cmp -s "tests/out-expected-$index.txt" "tests/out-$index.txt"
    then
        echo Passed
        else
        echo Fail
        break
    fi
done