#include "BluetoothSerial.h"
#define Speed 15
#define light1 18
#define light2 19
#define light3 21

#define detect 2
#define gate 4
#define pulse 500

int speed=10000;  
int state=0;



char cmnd;
BluetoothSerial SerialBT;

void setup()
{
Serial.begin(115200);
  
  pinMode(Speed,OUTPUT);
  digitalWrite(Speed,LOW);
  
  SerialBT.begin("SMART LIGHTS"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(light3,OUTPUT);
  
  pinMode(detect , INPUT);
  digitalWrite(detect, HIGH);
  pinMode(gate , OUTPUT);
  attachInterrupt(detect,zeroCrossingInterrupt,RISING);

}


void zeroCrossingInterrupt(){
  

 if (state==0){
     
     delayMicroseconds(speed);
     digitalWrite(gate,HIGH); 
     delayMicroseconds(pulse );
     state=1;
 }
  else
  { 
    digitalWrite(gate,LOW);
    state=0;
    }
}

void loop(){

int val;
  
  if (SerialBT.available()) {
   
   cmnd=SerialBT.read();
   if (cmnd=='F')
    {   val=SerialBT.parseInt();
    {
      speed=map(val,0,255,10000,500);
    }
    }

    if (cmnd=='A')
      {
        digitalWrite(light1,HIGH);
      }

    if (cmnd=='a')
      {
        digitalWrite(light1,LOW);
      }

      if (cmnd=='B')
      {
        digitalWrite(light2,HIGH);
      }

    if (cmnd=='b')
      {
        digitalWrite(light2,LOW);
      }

    if (cmnd=='C')
      {
        digitalWrite(light3,HIGH);
        Serial.println(cmnd);
      }

    if (cmnd=='c')
      {
        digitalWrite(light3,LOW);
      }
      
delay(20);    
  }




if (speed>9999 ){detachInterrupt(2);digitalWrite(gate,LOW);}
  else
    attachInterrupt(2,zeroCrossingInterrupt,RISING);


}
