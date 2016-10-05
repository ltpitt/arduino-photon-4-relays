// ------------
// Magic Relay Box
// ------------


/*-------------

Davide Nastri
Haarlem, September 2016

This code is used to control Relays from Arduino / Photon, using a similar module:
https://www.amazon.de/dp/B00PQC34E6/ref=pe_386171_151021841_TE_item

-------------*/


/////////////////////////////
// Declaring changeRelayS function
int changeRelayS(String command)
{
// Put into commaIndex variable comma character index number, in order to use it later to split the string
    int commaIndex = command.indexOf(',');
// Use the comma separator index to take the 1st part of the command (containing Photon pin port number connected to Relay)
    String pinNumber = command.substring(0, commaIndex);
// Use the comma separator index to take the 2nd part of the command (containing the command being sent e.g. on, off, on_off etc)
    String relayCommand = command.substring(commaIndex+1);
// Convert the pinNumber from string to integer in order to successfully issue the digitalWrite command later on
    int pinNumberI = pinNumber.toInt();
// Print both values to serial for debugging purpose
    Serial.print("Pin Number: " + pinNumber);  
    Serial.println();
    Serial.print("Relay Command: " + relayCommand);  
    Serial.println();

    if (relayCommand == "on") {
        
        digitalWrite(pinNumberI, LOW);
        return pinNumberI;
        
    } else if (relayCommand == "off") {
        
        digitalWrite(pinNumberI, HIGH);
        return pinNumberI;
        
    } else if (relayCommand == "on_off") {
        
        digitalWrite(pinNumberI, LOW);
        delay(1000);
        digitalWrite(pinNumberI, HIGH);
        return pinNumberI;
        
    } else {
        
        return -1;
        
    }

}

/////////////////////////////
//SETUP
void setup() {
// Initialize all pins to receive commands
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
// Turn all pins off
    digitalWrite(D0, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
// Initialize serial port
    Serial.begin(9600);
// Publish function on the cloud
    Particle.function("changeRelayS", changeRelayS);
}

////////////////////////////
//LOOP
void loop() {

}
