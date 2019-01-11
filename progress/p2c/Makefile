
project_2C: driver_2C.o my_struct.o
	gcc -o project_2C my_struct.o driver_2C.o

driver_2C.o: driver_2C.c prototypes.h my_struct.h
	gcc -c -I. driver_2C.c

my_struct.o: driver_2C.c prototypes.h my_struct.h
	gcc -c -I. my_struct.c

clean:
	rm -f *.o
