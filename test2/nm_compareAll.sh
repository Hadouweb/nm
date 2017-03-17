#!/bin/sh

./ft_nm $@ 1> 1 2> /dev/null
nm $@ 1> 2 2> /dev/null
diff 1 2
rm -f 1 2
