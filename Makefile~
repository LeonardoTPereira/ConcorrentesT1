all:
	gcc -o calcPi main.c rand_bm.c gaussLegendre.c borwein.c montecarlo.c parallelMonteCarlo.c parallelBorwein.c parallelGaussLegendre.c blackscholes.c -g -pthread -lgmp -lm -Wall
run:
	/usr/bin/time -f"%e" ./calcPi < entrada.txt 
#> saida.txt
