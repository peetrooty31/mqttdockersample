from datetime import datetime
import time
import calendar
x=1
while True:
	now = datetime.now()
	current_time = now.strftime("%H:%M:%S")
	print("Current Time : ",current_time)
	d = datetime.utcnow()
	unixtime = calendar.timegm(d.utctimetuple())
	print("UnixTime     : ",unixtime)
	print("***********")	
	time.sleep(1)
x+=1
