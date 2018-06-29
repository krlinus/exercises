#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <directory-name>"
    exit 1
fi

TARGET_DIR=$1

ls -lrt ${TARGET_DIR} | awk 'match($1,"^-") {
    sum += $5; #print $1,$5,$9
} END {
    suffix=" KMGT";
    usersum=sum; 
    for(i=1;usersum>1024 && i < length(suffix); i++)
        usersum /= 1024;
    print sum,"Bytes or", int(usersum) substr(suffix, i, 1);
}'
