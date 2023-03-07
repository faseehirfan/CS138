#!/bin/bash

# student files might have Windows/Mac line endings
# student outputs might have noeol on last line etc.
# $1 --- name of the input file
# returns name of sanitized tmp file via stdout
sanitize () {
    touch "$1"
    if [ -s "$1" ] ; then
        # file has contents, so sanitize them
        sanitized=`mktemp`
        touch "$sanitized"
        dos2unix --newfile "$1" "$sanitized" &> /dev/null
        # https://unix.stackexchange.com/questions/31947/how-to-add-a-newline-to-the-end-of-a-file
        sed -i -e '$a\' "$sanitized"
        # return the name of the new tmp file
        echo "$sanitized"
    else
        # file is empty, so do nothing
        # return the original file name
        echo "$1"
    fi
}

