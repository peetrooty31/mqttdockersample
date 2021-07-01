FROM ubuntu:latest
WORKDIR /app
COPY install.sh /app
RUN /app/install.sh
COPY . 	/app
RUN chmod 777 new.sh
RUN mv mosquitto.conf /etc/mosquitto/mosquitto.conf
CMD ["supervisord","-n","-c","supervisord.conf"]
