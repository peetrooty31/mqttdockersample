from datetime import datetime
import time
import calendar
x=1
import paho.mqtt.client as mqtt #import the client1
broker_address="192.168.43.193"
broker_port=8080
client = mqtt.Client("P1") #create new instance
client.connect(broker_address,broker_port) #connect to broker
while True:
	d= datetime.utcnow()
	unixtime = calendar.timegm(d.utctimetuple())
	client.publish("house",unixtime)
	time.sleep(1)

