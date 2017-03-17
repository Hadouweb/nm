#!/bin/sh

cp ../ft_nm ../ft_otool .

gcc -o test_facile test_facile.c
gcc -o test_moins_facile test_moins_facile.c

./nm_compare1_1.sh /bin/*
./nm_compare1_1.sh /sbin/*
./nm_compare1_1.sh /usr/bin/*
./nm_compare1_1.sh /usr/sbin/*
./nm_compare1_1.sh /*/*/*/*.so
./nm_compare1_1.sh /usr/lib/*

echo "Compare nm 1_1 finished"

./nm_compareAll.sh /bin/*
./nm_compareAll.sh /sbin/*
./nm_compareAll.sh /usr/bin/*
./nm_compareAll.sh /usr/sbin/*
./nm_compareAll.sh /*/*/*/*.so
./nm_compareAll.sh /usr/lib/*

echo "Compare nm All finished"

./nm_compare1_1.sh test_facile
./nm_compare1_1.sh test_moins_facile

echo "Tests nm finished"

./otool_compare1_1.sh /bin/*
./otool_compare1_1.sh /sbin/*
./otool_compare1_1.sh /usr/bin/*
./otool_compare1_1.sh /usr/sbin/*
./otool_compare1_1.sh /*/*/*/*.so
./otool_compare1_1.sh /usr/lib/*

echo "Compare otool 1_1 finished"

./otool_compareAll.sh /sbin/*
./otool_compareAll.sh /*/*/*/*.so

echo "Compare otool All finished"

./otool_compare1_1.sh test_facile
./otool_compare1_1.sh test_moins_facile

echo "Tests otool finished"

rm -f test_facile test_moins_facile ft_nm ft_otool
