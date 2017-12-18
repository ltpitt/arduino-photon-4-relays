# Particle Photon (Arduino compatible) code to control 4 relays
This code is used to control a 4 relay board with your Arduino / Photon / Other compatible hardware.  

Here's the board I have used, connecting it to a Particle Photon:  

http://bit.ly/2jV8xoW  
http://amzn.to/2zftSRH  

# How to test
After uploading the code to your Photon use this command to trigger it (example) from a Linux box, please add your device id and access token. 

```bash
curl https://api.particle.io/v1/devices/YOUR_DEVICE_ID/changeRelayS \
     -d access_token=YOUR_ACCESS_TOKEN \
     -d "D0,on"
```

You can also use, to achieve this result (from Linux / Unix operating system) the provided changeRelayS.sh  

Here's an example to turn off relay 2 off:  
```bash
changeRelayS.sh 2 off
```
