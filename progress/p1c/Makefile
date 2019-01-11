all:
				mkdir -p include; \
				cp math330.h include; \
				mkdir -p lib; \
				gcc  -c trig/*.c -I include; \
     		gcc  -c exp/*.c -I include; \
				ar r libmath330.a exp330.o log330.o sin330.o cos330.o tan330.o arccos.o arcsin.o arctan.o; \
				cp libmath330.a lib; \
				mkdir -p bin; \
				gcc -o bin/cli cli/cli.c -I include -L lib -lmath330 -lm; \
