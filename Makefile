all:
	g++ -o calcPi -g -pthread -Wall main.c gaussLegendre.c borwein.c montecarlo.c parallelMonteCarlo.c parallelBorwein.c parallelGaussLegendre.c blackscholes.c
run:
	/usr/bin/time -f"%e" ./calcPi < entrada.txt > saida.txt