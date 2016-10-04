# arduino-photon-4-relays  
This code is used to control a 4 relay board with you Arduino / Photon / Other compatible hardware

# Testing
After deploying your code use this command to trigger it (example) from a Linux box:  

```bash
curl https://api.particle.io/v1/devices/YOUR_DEVICE_ID/changeRelayS \
     -d access_token=YOUR_ACCESS_TOKEN \
     -d "D0,on"
```
