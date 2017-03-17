#!/bin/sh

for file in $@
do
	./ft_otool $file 1> 1 2> /dev/null
	otool -t $file 1> 2 2> /dev/null
	diff 1 2
	rm -f 1 2
done
