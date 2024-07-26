#!/bin/bash

function show_usage {
    echo "USAGE: create-links.sh <path to qmk repository>";
}

if [[ -z $1 ]]; then
    show_usage;
    exit 1;
fi

if [[ ! -d "$1/keyboards" ]]; then
    echo "argument one is not a valid path to a qmk repository"
    echo ""
    show_usage;
    exit 1;
else
    repo_dir="$(dirname -- "$(realpath -- "$0")")"

    # link personal keyboards
    ln -s -f "${repo_dir}/zegonix" "$1/keyboards/zegonix"
    echo "link created successfully"
fi