#!/bin/bash
f=my_file.txt
touch $f
echo "Hello, Bash!" > $f
cat $f
rm $f
