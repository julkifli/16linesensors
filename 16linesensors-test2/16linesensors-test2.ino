/* MiCROBOT 
 * 16 line sensors test code
 * 
 * May 2021
 *  This code test via serial monitor
 */
#define s0      2
#define s1      3
#define s2      4
#define s3      5
#define AI      A0 //Analog Input
int sensores[16];
int threshold=750;

//////LINE COLOR//////////
//I.M WHITE=1 BLACK=0
//PHOENIX WHITE=0 BLACK=1
int linea=0;
//////////////////////////


void setup() {
Serial.begin(9600);
pinMode(s0,OUTPUT);
pinMode(s1,OUTPUT);
pinMode(s2,OUTPUT);
pinMode(s3,OUTPUT);
pinMode(AI,INPUT);
}

void loop() {

  for(int i=0;i<16;i++){
    digitalWrite(s0,i&0x01);
    digitalWrite(s1,i&0x02);
    digitalWrite(s2,i&0x04);
    digitalWrite(s3,i&0x08);
    sensores[i]=analogRead(AI);
    if(linea==0){if(sensores[i]<=threshold){sensores[i]=0;}else{sensores[i]=1;}}
    if(linea==1){if(sensores[i]<=threshold){sensores[i]=1;}else{sensores[i]=0;}}
    Serial.print(sensores[i]);
    Serial.print("\t");
  }
  Serial.println(" ");

}
