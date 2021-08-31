
#include <Servo.h>
#define speedPinR 3   // RIGHT PWM pin connect MODEL-X ENA
#define RightMotorDirPin1  12   //Right Motor direction pin 1 to MODEL-X IN1 
#define RightMotorDirPin2  11   //Right Motor direction pin 2 to MODEL-X IN2
#define speedPinL 6        //  Left PWM pin connect MODEL-X ENB
#define LeftMotorDirPin1  7     //Left Motor direction pin 1 to MODEL-X IN3 
#define LeftMotorDirPin2  8     //Left Motor direction pin 2 to MODEL-X IN4 
#define LPT 2 // scan loop counter
#define SERVO_PIN     9  //servo connect to D9
#define Echo_PIN    2 // Ultrasonic Echo pin connect to D11
#define Trig_PIN    10  // Ultrasonic Trig pin connect to D12
#define BUZZ_PIN     13
#define SPEED  120     //both sides of the motor speed
const int distancelimit = 15; //distance limit for obstacles in front (in cm)           
const int sidedistancelimit = 15; //distance in cm to obstacles at both sides (in cm)   

Servo head;
/*motor control*/
/*Defining the robot's movements*/
void go_straight(void)  //Forward
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
}
void turn_Left(int t=0)  //Turn left for t milliseconds
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
  delay(t);
}
void turn_Right(int t=0)  //Turn right for t milliseconds
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
  delay(t);
}
void reverse(int t=0)  //Reverse for t milliseconds
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,HIGH);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,HIGH);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
  delay(t);
}
void brake()    //Stop
{
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,LOW);
  digitalWrite(LeftMotorDirPin2,LOW);
}
/*set motor speed */
void set_Motorspeed(int speed_L,int speed_R)
{
  analogWrite(speedPinL,speed_L); 
  analogWrite(speedPinR,speed_R);   
}

void buzz_On()   //open buzzer
{
  
  for(int i=0;i<100;i++){
   digitalWrite(BUZZ_PIN,LOW);
   delay(1);//wait for 1ms
   digitalWrite(BUZZ_PIN,HIGH);
   delay(1);//wait for 1ms
  }
}
void buzz_Off()  //close buzzer
{
  digitalWrite(BUZZ_PIN, HIGH);
  
}
void alarm()
{
   buzz_On();
   buzz_Off();
}

/*detection of ultrasonic distance*/
int watch()
{
  long echo_distance;
  digitalWrite(Trig_PIN,LOW);
  delayMicroseconds(5);                                                                              
  digitalWrite(Trig_PIN,HIGH);
  delayMicroseconds(15);
  digitalWrite(Trig_PIN,LOW);
  echo_distance=pulseIn(Echo_PIN,HIGH);
  echo_distance=echo_distance*0.01657; //how far away is the object in cm
  return round(echo_distance);
}

// Measures the distance between the front wall and the robot. Returns the value in cm
float distanceFront()
{
  head.write(90); //90 aims the ultrasonic sensor straight forward
  delay(100);
  float center = watch();
  return center;
}

//Measures the distance between the left wall and the robot. Returns the value in cm
float distanceLeft()
{
  head.write(180); //180 aims the ultrasonic sensor to the left. If 180 does not work, use 170
  delay(100);
  float left = watch();
  return left;
}

//Measures the distance between the right wall and the robot. Returns the value in cm
float distanceRight()
{
  head.write(0); //0 aims the ultrasonic sensor to the right
  delay(100);
  float right = watch();
  return right;
}

void setup()
{
  /*setup L298N pin mode*/
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
  brake();//stop move
  /*init HC-SR04*/
  pinMode(Trig_PIN, OUTPUT); 
  pinMode(Echo_PIN,INPUT); 
  /*init buzzer*/
  pinMode(BUZZ_PIN, OUTPUT);
  digitalWrite(BUZZ_PIN, HIGH);  
  buzz_Off(); 
  digitalWrite(Trig_PIN,LOW);
  /*init servo*/
  head.attach(SERVO_PIN); 
  head.write(90);
  delay(2000);
  Serial.begin(9600);
 
}

void loop()
{
/*
 Use the functions given to you to write your code for this competition. Feel free to change them to accomate your needs.
 */
}
