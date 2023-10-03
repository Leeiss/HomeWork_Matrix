#!/bin/bash
for ((a = 0; a <= 19; a++))
do
    $(cat tests/mtest/text$a.txt | ./cmatrix > tests/test_result.txt) //читаем содержимое файла
    if ["$(cmp tests/test_result.txt tests/mtest/asnv$a.txt)" = ""]
        then
            echo "Test $a PASSED"
        else
            echo "Test $a FAILED"
    fi
done