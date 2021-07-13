from datetime import datetime
import time
import calendar
import paho.mqtt.client as mqtt
broker_address="localhost"
broker_port=1883
client = mqtt.Client("P1") 
client.connect(broker_address,broker_port) 
while True:
	d= datetime.utcnow()
	unixtime = calendar.timegm(d.utctimetuple())
	client.publish("timeserver",unixtime)
	time.sleep(1)
