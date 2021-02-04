# versions
US := hfcal_US.c
UK := hfcal_UK.c


# marco to create position-independent code
define generate_object
	gcc -I./includes -fPIC -c $1 -o hfcal.o
endef


# creates hfcal.o (US version) object file
libUS: ./includes/hfcal.h $(US)
	$(call generate_object, $(US))


# creates hfcal.o (UK version) object file
libUK: ./includes/hfcal.h $(UK)
	$(call generate_object, $(UK))


# convert hfcal.o object file to a shared object
libhfcal.so ./libs/libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o ./libs/libhfcal.so


# create elliptical.o object file
elliptical.o: ./includes/hfcal.h elliptical.c
	gcc -I./includes -c elliptical.c -o elliptical.o


# generate elliptical executable
elliptical: elliptical.o ./libs/libhfcal.so
	gcc elliptical.o -L./libs -lhfcal -o elliptical
