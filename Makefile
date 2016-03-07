all: calibrate

clibrate:
	gcc calibrate.o -o calibrate

calibrate.o:
	gcc -c calibrate.c

clean:
	rm *.o calibrate
