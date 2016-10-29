clear
echo "Relay number:"
echo $1
echo
echo "State:"
echo $2
echo
echo "Result:"
DEVICE_ID="YOURDEVICEID"
TOKEN_ID="YOURTOKENID"

curl https://api.particle.io/v1/devices/$DEVICE_ID/changeRelayS \
     -d access_token=$TOKEN_ID \
     -d "args=$1,$2"
echo
echo
