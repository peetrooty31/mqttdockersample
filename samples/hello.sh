#USE install.sh instead. 
sudo apt update
sudo apt-add-repository -y ppa:mosquitto-dev/mosquitto-ppa    
sudo apt-get update
sudo apt-get install -y mosquitto
sudo apt-get install -y  mosquitto-clients
sudo apt clean
sudo apt update
sudo apt install -y software-properties-common
sudo add-apt-repository -y ppa:deadsnakes/ppa
sudo apt update
sudo apt install -y python3.8
sudo apt install -y python3-pip
sudo apt-get install -y libsqlite3-dev	
sudo pip3 install -y sqlite3
pip3 install -y paho-mqtt
sudo apt update
sudo apt install -y build-essential
sudo apt-get install -y manpages-dev
sudo apt install -y git
git clone https://github.com/azadkuh/sqlite-amalgamation
git clone https://github.com/eclipse/paho.mqtt.c.git 
sudo apt install -y sqlite
sudo apt-get install -y  sqlite3
sudo apt install -y  supervisor
sudo apt clean
