#!/bin/sh
for p in "$@"; do
        [ "$p" = "-L/usr/lib" -o "$p" = "-L/usr/lib64" ] || set -- "$@" "$p"
        shift
done
exec "$0.real" "$@"
