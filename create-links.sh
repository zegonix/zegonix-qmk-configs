#!/bin/bash

function show_usage {
    echo "USAGE: create-links.sh <path to qmk repository>";
}

if [[ -z $1 ]]; then
    show_usage;
    exit 1;
fi

if [[ ! -d $1 ]]; then
    show_usage;
    exit 1;
else
    config_dir="$(dirname -- "$(realpath -- "$0")")"

    # link directory for keebsforall/freebirdtkl
    ln -s -f "${config_dir}/keyboards/keebsforall/freebirdtkl" "$1/keyboards/keebsforall/fbtkl"
    # link directories for mode/envoy and mode/mode80
    ln -s -f "${config_dir}/keyboards/mode/envoy" "$1/keyboards/mode/envoy"
    ln -s -f "${config_dir}/keybaords/mode/mode80" "$1/keyboards/mode/mode80"
    # link directory for sofle
    ln -s -f "${config_dir}/keyboards/sofle/keymaps/quaken" "$1/keyboards/sofle/keymaps/quaken"
    # link personal keyboards
    ln -s -f "${config_dir}/keyboards/zegonix" "$1/keyboards/zegonix"
fi