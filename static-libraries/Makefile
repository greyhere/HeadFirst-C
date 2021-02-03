encrypt.o: encrypt.c
	gcc -c encrypt.c -o encrypt.o

checksum.o: checksum.c
	gcc -c checksum.c -o checksum.o

libhfsecurity.a: encrypt.o checksum.o
# this will create libhfsecurity.a archive
# -rcs :- r means that the .a file will be updated if it already exists
#         c means that the archive will be created without any feedbacks
#         s tells ar to creat an index at the start of the file
	ar -rcs libhfsecurity.a encrypt.o checksum.o

bank_vault: bank_vault.c libhfsecurity.a
# bank_vault.c :- the program's source code needs to be listed before the library code
# -I           :- we need -I because header files are in the "." (current) directory
# -L           :- we need -L because the archive is in the current directory
# -lhfsecurity :- we need -lhfsecurity because the archive is called libhfsecurity.a
	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault


# if we put archive and header files in the standard directory then we can compile bank_vault using
#
# gcc bank_vault.c -lhfsecurity -o bank_vault
