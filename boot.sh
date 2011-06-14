#!/bin/sh -e

aclocal
autoheader
autoconf
libtoolize
automake -a -i -c
