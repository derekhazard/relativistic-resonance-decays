#!/bin/csh

setenv EVENT /Users/derekhazard/Desktop/Final_Project/Lib
setenv LD_LIBRARY_PATH ${EVENT}:${LD_LIBRARY_PATH}
setenv DYLD_LIBRARY_PATH ${EVENT}:${DYLD_LIBRARY_PATH}

if ($?TERM == 0 || $?prompt == 0) exit 0

echo ''
echo 'Setup GSL and ROOT'
echo '====================================='
echo ''
echo "<I>---------------Info--------------------<I>"
echo "Setting up the following environments: "
echo "event " $EVENT
echo "<I>---------------Info--------------------<I>"
echo ""
