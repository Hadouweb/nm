#!/bin/sh

for file in $@
do
	./ft_nm $file 1> 1 2> /dev/null
	nm $file 1> 2 2> /dev/null
	diff 1 2
	rm -f 1 2
done
