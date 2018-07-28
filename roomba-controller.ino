
//PIN   NAME    Description
//1     Vpwr    Roomba battery + (unregulated)
//2     Vpwr    Roomba battery + (unregulated)
//3     RXD     0 – 5V Serial input to Roomba
//4     TXD     0 – 5V Serial output from Roomba
//5     BRC     Baud Rate Change
//6     GND     Roomba battery ground
//7     GND     Roomba battery ground

int pinBRC = D0;
char localIp[] = "xxx.xxx.xxx.xxx";

void setup() {
    pinMode(pinBRC, OUTPUT);
    Particle.function("wakeup", wakeUp);
    Particle.function("controlMode", controlMode);
    Particle.function("safemode", startSafeMode);
    Particle.function("startCommand", startCmd);
    Particle.function("playSong", playSong);
    Particle.function("despacito", playDespacito);
    Particle.function("vacuumOn", vacuumOn);
    Particle.function("startClean", startClean);
    Particle.function("trigroomba", triggerRoomba);
    Particle.variable("localIp", localIp);
    setLocalIp();
    wakeUp("");
    controlMode("");  
}

void loop() {

}

void setLocalIp(){
    IPAddress myAddr = WiFi.localIP();

    byte first_octet = myAddr[0];
    byte second_octet = myAddr[1];
    byte third_octet = myAddr[2];
    byte fourth_octet = myAddr[3];

     sprintf(localIp, "%d.%d.%d.%d", first_octet, second_octet, third_octet, fourth_octet);
}
int wakeUp(String baudRate){
    Serial1.begin(115200);
    Serial.begin(115200);
    digitalWrite(pinBRC, HIGH);
    delay(100);
    digitalWrite(pinBRC, LOW);
    delay(500);
    digitalWrite(pinBRC, HIGH);
    delay(2000);
    return 0;
}

void setBaudRateLow(){
    digitalWrite(pinBRC, LOW);
    delay(100);
    digitalWrite(pinBRC, LOW);
    delay(500);
    digitalWrite(pinBRC, LOW);
    delay(2000);
}

int controlMode(String cmd){
     // Get the Roomba into control mode 
    Serial1.write(128);                               // Passive mode
    delay(50);
    return 0;
}

int startCmd(String start){
    Serial1.write(128);
    return 0;
}

int startSafeMode(String cmd){
    //wakeUp("");
    Serial1.write(128);
    delay(50);
    Serial1.write(131);
    return 0;
}

int startClean(String cm){
    Serial1.write(128);
    delay(50);
    Serial1.write(135);
    return 0;
}

int playSong(String cmd) {                          // Makes the Roomba play a little ditty
  Serial1.write(140);                         	    // Define a new song
  Serial1.write(0);                                 // Write to song slot #0
  Serial1.write(8);                                 // 8 notes long
  Serial1.write(60);                                // Everything below defines the C Major scale 
  Serial1.write(32); 
  Serial1.write(62);
  Serial1.write(32);
  Serial1.write(64);
  Serial1.write(32);
  Serial1.write(65);
  Serial1.write(32);
  Serial1.write(67);
  Serial1.write(32);
  Serial1.write(69);
  Serial1.write(32);
  Serial1.write(71);
  Serial1.write(32);
  Serial1.write(72);
  Serial1.write(32);
 
  Serial1.write(141);                               // Play a song
  Serial1.write(0);    
  
  return 0;
  // Play song slot #0
}

int vacuumOn(String cmd){
    vacOn();
    return 0;
}
void vacOn() {                                   // Turns on the vacuum
  Serial1.write(128);
  delay(50);
  Serial1.write(7);
}

int triggerRoomba(String cmd){
    wakeUp("a");
    startClean("a");
    return 0;
}

int playDespacito(String cmd){
  wakeUp("");
  startSafeMode("");
  Serial1.write(140);                         	    // Define a new song
  Serial1.write(0);                                 // Write to song slot #0
  
  Serial1.write(40);    
  
  Serial1.write(62);   //D
  Serial1.write(32);   
  
  Serial1.write(61);   //C  
  Serial1.write(32);
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(54);   //F
  Serial1.write(16);

  Serial1.write(54);   //F
  Serial1.write(16);
  
  Serial1.write(54);   //F
  Serial1.write(16);
  
  Serial1.write(54);   //F
  Serial1.write(16); 
  
  Serial1.write(54);   //F
  Serial1.write(16);  
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(32); 
  
  Serial1.write(57);   //A
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(32); 
  
  Serial1.write(55);   //G
  Serial1.write(32); 
  
  Serial1.write(55);   //G
  Serial1.write(16);
  
   Serial1.write(55);   //G
  Serial1.write(16); 
  
  Serial1.write(55);   //G
  Serial1.write(16);
  
   Serial1.write(55);   //G
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(16); 
  
  Serial1.write(59);   //B
  Serial1.write(32); 
  
  Serial1.write(61);   //C  
  Serial1.write(16);
  
   Serial1.write(62);   //D
  Serial1.write(32);
  
  Serial1.write(57);   //A
  Serial1.write(32); 
  
  Serial1.write(57);   //A
  Serial1.write(16); 
  
  Serial1.write(57);   //A
  Serial1.write(16); 
  
  Serial1.write(57);   //A
  Serial1.write(16); 
  
  Serial1.write(57);   //A
  Serial1.write(16); 
  
   Serial1.write(62);   //D
  Serial1.write(16);  
  
  Serial1.write(62);   //D
  Serial1.write(16);   
  
  Serial1.write(62);   //D
  Serial1.write(16);   
  
  Serial1.write(62);   //D
  Serial1.write(16);   
  
  Serial1.write(62);   //D
  Serial1.write(16);   
  
  Serial1.write(64);   //E
  Serial1.write(32);   
  
  Serial1.write(64);   //E
  Serial1.write(32);   
  
  Serial1.write(61);   //E
  Serial1.write(64);   
  
  Serial1.write(61);   //C  
  Serial1.write(32);  
  
  Serial1.write(141);  // Play a song
  Serial1.write(0);
  
  return 0;
}
