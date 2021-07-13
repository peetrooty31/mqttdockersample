CC = gcc

INCLUDES = -L/app/sqlite-amalgamation

CFLAGS = -g -Wall 

LDFLAGS = -L/app/paho.mqtt.c/build/output

TARGET=pubsub
	
pubsub:	pubsub3.o /app/paho.mqtt.c/build/output /app/sqlite-amalgamation
	$(CC) pubsub3.o $(LDFLAGS) -lpaho-mqtt3a $(INCLUDES) -lsqlite3 -o pubsub
	
pubsub.o:	pubsub3.c 
	$(CC) $(CFLAGS) -c pubsub3.c 
	
clean:
	rm *.o $(TARGET)
