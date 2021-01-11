#!/bin/csh
# This is a comment;

./a.out

if ($status == 0) then
	echo "program is terminated normally"
else
	echo "program is not terminated normally"
endif

