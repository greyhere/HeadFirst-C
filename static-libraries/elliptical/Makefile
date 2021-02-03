hfcal.o: ./includes/hfcal.h hfcal.c
	gcc -I./includes -c hfcal.c -o hfcal.o

elliptical.o: ./includes/hfcal.h elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o

./libs/libhfcal.a: hfcal.o
	ar -rcs ./libs/libhfcal.a hfcal.o

elliptical: elliptical.o ./libs/libhfcal.a
	gcc elliptical.o -L./libs -lhfcal -o elliptical
