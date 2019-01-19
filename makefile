forking: client fserver

select: sclient sserver

sserver: select_server.o networking.o
	gcc -o host select_server.o networking.o

fserver: forking_server.o networking.o connect4.o
	gcc -o host forking_server.o networking.o connect4.o

sclient: select_client.o networking.o
	gcc -o player select_client.o networking.o

client: client.o networking.o connect4.o
	gcc -o player client.o networking.o connect4.o

select_client.o: select_client.c networking.h connect4.h
	gcc -c select_client.c connect4.h

client.o: client.c networking.h connect4.h
	gcc -c client.c connect4.h

select_server.o: select_server.c networking.h connect4.h
	gcc -c select_server.c connect4.h

forking_server.o: forking_server.c networking.h connect4.h
	gcc -c forking_server.c connect4.h

networking.o: networking.c networking.h connect4.h
	gcc -c networking.c connect4.h

connect4.o: connect4.c connect4.h
	gcc -c connect4.c connect4.h

clean:
	rm *.o
	rm ./host
	rm ./player
