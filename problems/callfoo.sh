#!/bin/bash

#Call program 'foo' for each file in a directory and log the text output (in Bash)
if [ $# -ne 2 ]
then
    printf "Usage: $0 <command-to-call> <target-directory>"
    exit 1
fi
command=$1
target_dir=$2
for file in ${target_dir}/*
do
    echo "file = ${file}"
    if [ -f ${file} ]
    then
        base_filename=`basename ${file}`
        `${command} ${file} > /tmp/${command}_${base_filename}.log`
    fi
done
