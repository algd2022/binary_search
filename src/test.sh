#!/bin/bash

### run example
# $ ./test.sh array
# $ ./test.sh spear.c
###

# 拡張子を除いたファイル名を取得
FILE_NAME=${1%.*}

C_FILE=$FILE_NAME.c
READ_FILE=$FILE_NAME.txt

i=0

# コンパイル
clang -Wall $C_FILE

# 二行すつ読み込んで実行
while true
do
    read LINE1
    read LINE2

    if [ -z "$LINE1" ] ; then break
    fi

    i=$(($i+1))

    echo "--- sample $i ---"

    # 入力を受け取って実行
    echo "$LINE1 $LINE2" | ./a.out

    echo "----------------"
done < "${READ_FILE}"
