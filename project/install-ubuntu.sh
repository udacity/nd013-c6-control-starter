#! /bin/bash
sudo apt-get update
sudo apt-get install libuv1-dev libssl-dev libz-dev
git clone https://github.com/uWebSockets/uWebSockets 
cd uWebSockets
git checkout e94b6e1
mkdir build
cd build
cmake ..
make 
sudo make install
cd ..
cd ..
sudo rm -r uWebSockets
sudo ln -s /usr/lib64/libuWS.so /usr/lib/libuWS.so

sudo apt-get update -y
sudo apt-get install -y gnuplot
