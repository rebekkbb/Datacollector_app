#include <SoftwareSerial.h>
#define RxD 3
#define TxD 4
#define DEBUG_ENABLED 1
#define GSR A0

SoftwareSerial BLE(RxD,TxD);
 
void setup(){
  Serial.begin(9600);
  pinMode(RxD,INPUT);
  pinMode(TxD,OUTPUT);
  setupBleConnection();
}
 
void loop(){
  while(1){
    Serial.println(getGSR());
    if (BLE.available()){
      BLE.println(getGSR());
    }
  }
}


int getGSR(){
  //const int GSR=A0;
  int sensorValue=0;
  int gsr_average=0;
  long sum=0;
  
  for(int i=0;i<10;i++)           //Average the 10 measurements to remove the glitch
      {
      sensorValue=analogRead(GSR);
      sum += sensorValue;
      delay(5);
      }
   gsr_average = sum/10;
   Serial.println(gsr_average);
   return (int)gsr_average;
}

void setupBleConnection()
{
  BLE.begin(9600);
  BLE.print("AT+NAMESeeedBTSlave");
  BLE.print("AT+CLEAR");
  BLE.print("AT+ROLE0");
  BLE.print("AT+SAVE1");
}
