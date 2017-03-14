#!/bin/bash
if [ "$#" -ne 1 ]
then
	dir="./"
else
	dir=$1
fi

bon=0
total=0

for fichier in $( ls "$dir" )
do
	# Lance nm et ft_nm avant de comparer les deux resultats
	nm $dir/$fichier > 1 2>/dev/null
	../ft_nm $dir/$fichier > 2 2>/dev/null
	resultat=$(diff 1 2)

	# S'il n'y a pas de difference
	if [ $? -eq  0 ]
	then
		echo -e "\033[32mOK\033[0m :" $fichier
		bon=$(($bon + 1))

	# S'il y a une difference
	else
		echo -e "\033[31mKO\033[0m :" $fichier
	fi

	total=$(($total + 1))
	rm -f 1 2
done

# Affichage du score
echo "-------------"
if [ $bon == $total ]
then
	echo -e "\033[32mScore : "$bon/$total"\033[0m"
else
	echo -e "\033[31mScore : "$bon/$total"\033[0m"
fi
echo "-------------"
