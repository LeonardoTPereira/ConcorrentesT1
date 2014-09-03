S1='saida'
S2='.txt'

for i in {0..6}
do
	EXIT=$S1$i$S2
	for j in {0..9}
	do
		if [ -f $EXIT ] ; then
			/usr/bin/time -f"%e" ./calcPi "$i" < entrada.txt >> "$EXIT"
		else
			/usr/bin/time -f"%e" ./calcPi "$i" < entrada.txt > "$EXIT"
		fi
	done

done
