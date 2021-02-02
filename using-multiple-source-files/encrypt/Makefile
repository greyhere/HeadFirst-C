encrypt.o: encrypt.h encrypt.c
	gcc -c encrypt.c

message_hider.o: encrypt.h message_hider.c
	gcc -c message_hider.c

message_hider: encrypt.o message_hider.o
	gcc encrypt.o message_hider.o -o message_hider
