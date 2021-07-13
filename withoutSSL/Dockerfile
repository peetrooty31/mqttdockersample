FROM ubuntu:latest
WORKDIR /app
COPY install.sh /app
RUN /app/install.sh
COPY install.sh /app/new/new
RUN git clone https://github.com/peetrooty31/mqttdockersample.git 
WORKDIR /app/mqttdockersample/withoutSSL 
RUN make 
RUN mv mosquitto.conf /etc/mosquitto/mosquitto.conf
VOLUME /app
CMD ["supervisord","-n","-c","supervisord.conf"]


