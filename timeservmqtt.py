from datetime import datetime
import time
import calendar
import ssl
import paho.mqtt.client as mqtt
broker_address="localhost"
broker_port=8883
client = mqtt.Client("P1") 
client.tls_set(ca_certs="../ca.crt.pem", certfile="../client.crt.pem", keyfile="../client.key.pem", cert_reqs=ssl.CERT_REQUIRED,tls_version=ssl.PROTOCOL_TLS, ciphers=None)
client.connect(broker_address,broker_port) 
while True:
	d= datetime.utcnow()
	unixtime = calendar.timegm(d.utctimetuple())
	client.publish("timeserver",unixtime)
	time.sleep(1)
