#!/bin/bash

if [ "$#" -ne 2 ]
then
    exit 1
else
    FILESDIR=$1
    SEARCHSTR=$2
fi

if [ ! -d $FILESDIR ]; then
    exit 1
fi

X=$(find "$FILESDIR" -type f | wc -l)

Y=$(grep -r "$SEARCHSTR" "$FILESDIR" | wc -l)

echo "The number of files are $X and the number of matching lines are $Y"
