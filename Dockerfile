FROM ubuntu:latest
WORKDIR /app
COPY install.sh /app
RUN /app/install.sh
RUN git clone https://github.com/peetrooty31/mqttdockersample.git 
WORKDIR /app/mqttdockersample 
RUN make 
RUN mv mosquitto.conf /etc/mosquitto/mosquitto.conf
CMD ["supervisord","-n","-c","supervisord.conf"]


