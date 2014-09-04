S1='saida'
S2='.txt'

if [ "$#" != "0" ] ; then
	NAME=$1	
else
	NAME='calcPi'
fi 

for i in {0..6}
do
	EXIT=$S1$i$S2
	for j in {0..9}
	do
		if [ -f $EXIT ] ; then
			time ./$NAME "$i" < entrada.txt >> "$EXIT"
		else
			time ./$NAME "$i" < entrada.txt > "$EXIT"
		fi
	done

done
