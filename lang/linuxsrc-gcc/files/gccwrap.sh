#!/bin/sh
for p in "$@"; do
        [ "$p" = "-L/usr/lib" ] || set -- "$@" "$p"
        shift
done
exec "$0.real" "$@"
