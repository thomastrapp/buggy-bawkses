#!/usr/bin/env bash

# gnu only

# wrapper for gperftools' heap checker
# see https://code.google.com/p/gperftools/

# debug
# set -x

pprof="/usr/local/bin/pprof"
gv="/usr/bin/gv"

assert_dependencies()
{
  # Try to execute pprof
  "$pprof" --help > /dev/null 2>&1 \
    || { echo >&2 "Cannot execute pprof at $pprof"; exit 1; }
  
  # Try to execute gv (pprof uses gv to display graphical information)
  "$gv" --help > /dev/null 2>&1 \
    || { echo >&2 "Warning: Cannot execute gv at $gv"; }

  # check if first parameter is executable 
  [ -x "$1" ] \
    || { echo >&2 "Given parameter is not an executable"; exit 1; } 

  # check if the executable is linked with libtcmalloc
  objdump -p "$1" | grep tcmalloc > /dev/null 2>&1 \
    || { echo >&2 "Executable needs to be linked with libtcmalloc"; exit 1; }
}

print_usage()
{
  echo "Usage:" "$0" "[executable binary linked with libtcmalloc]"
}

# print usage and exit if number of arguments != 1
[ $# -eq 1 ] || { print_usage ; exit 0; }

# exit if any dependencies are not met
assert_dependencies "$1"

# Setup env and run 
env HEAPCHECK=normal PPROF=$pprof $(readlink -f $1)

# proxy return code 
exit $?
