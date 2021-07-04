CC = gcc

INCLUDES = -L../sqlite-amalgamation

CFLAGS = -g -Wall 

LDFLAGS = -L../paho.mqtt.c/build/output

TARGET=pubsub
	
pubsub:	pubsub3.o ../paho.mqtt.c/build/output ../sqlite-amalgamation
	$(CC) pubsub3.o $(LDFLAGS) -lpaho-mqtt3a $(INCLUDES) -lsqlite3 -o pubsub
	
pubsub.o:	pubsub3.c 
	$(CC) $(CFLAGS) -c pubsub3.c 
	
clean:
	rm *.o $(TARGET)
