CC=gcc

SRCS= main.c rand_bm.c gaussLegendre.c borwein.c montecarlo.c parallelMonteCarlo.c parallelBorwein.c parallelGaussLegendre.c blackscholes.c parallelBlackScholes.c

FLAGS= -g -Wall

LIBS= -pthread -lgmp -lm

NAME=calcPi

SCRIPT=script.sh

all:
	$(CC) -o $(NAME) $(FLAGS) $(SRCS) $(LIBS)
run:
	./$(SCRIPT) $(NAME)
clean:
	rm -rf *.o saida*.txt
