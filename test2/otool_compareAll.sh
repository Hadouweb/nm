#!/bin/sh

./ft_otool $@ 1> 1 2> /dev/null
otool -t $@ 1> 2 2> /dev/null
diff 1 2
rm -f 1 2
