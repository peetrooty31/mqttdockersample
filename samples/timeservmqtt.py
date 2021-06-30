from datetime import datetime
import time
import calendar

import paho.mqtt.client as mqtt #import the client1
broker_address="localhost"
broker_port=2020
client = mqtt.Client("P1") #create new instance
client.connect(broker_address,broker_port) #connect to broker
while True:
	d= datetime.utcnow()
	unixtime = calendar.timegm(d.utctimetuple())
<<<<<<< HEAD
	client.publish("timeserver",unixtime)
=======
	client.publish("time",unixtime)
>>>>>>> b564318a96eaf64f3f86eab9e51b9b0d817474fd
	time.sleep(1)

