#define A 5
#define B 4
#define C 3
#define D 2

const int ledArray[12][4] ={
  {A,D,B,C}, //12
  {D,A,B,C}, //11
  {D,B,A,C}, //10
  {B,D,A,C}, //9
  {C,A,B,D}, //8
  {A,C,B,D}, //7
  {C,D,A,B}, //6 
  {D,C,A,B}, //5
  {C,B,A,D}, //4
  {B,C,A,D}, //3
  {A,B,C,D}, //2
  {B, A , C ,D} //1

 };

void setPin(int configurationArray[] ){
  pinMode(configurationArray[0], OUTPUT);
  pinMode(configurationArray[1], OUTPUT);
  pinMode(configurationArray[2], INPUT);
  pinMode(configurationArray[3], INPUT);
  digitalWrite(configurationArray[0],HIGH);
  digitalWrite(configurationArray[1],LOW);
}

void testLedsUpto(int number,int delayTime){
  for(int i=0; i<=number-1;i++){
    setPin(ledArray[i]);
    delay(delayTime);
  }
}
void testLedsWithSpeed(){
  for(int i=0; i<=11;i++){
    setPin(ledArray[i]);
    delay(120 - i*10);
  }
}

void showTime(int hour, int minute){

  volatile int roundMinute= map(minute, 0, 60, 0 , 12);
  

  setPin(ledArray[hour]);
  delay(500);
  setPin(ledArray[roundMinute]);
  delay(30);
}

void fullCircle(){
  for(int i=0; i<=12;i++ ){
    testLedsUpto(i,1);
    delay(10);
  }
}
void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<3;i++){
  testLedsWithSpeed();
  }
  
  
  fullCircle();
  delay(1000);
}

void loop() {
showTime(6, 41);
}
