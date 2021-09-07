/*From left to right*/
#define LFSensor_0 A0           //1st light sensor from the left
#define LFSensor_1 A1           //2nd light sensor from the left
#define LFSensor_2 A2           //middle light sensor
#define LFSensor_3 A3           //2nd light sensor from the right
#define LFSensor_4 A4           //1st light sensor from the right

/*Defining the motors*/
#define SPEED 150               //The range for the motor is 0 to 255. 
#define RightMotorDirPin1  12   //Right Motor direction pin 1 to MODEL-X IN1 
#define RightMotorDirPin2  11   //Right Motor direction pin 2 to MODEL-X IN2
#define LeftMotorDirPin1  7     //Left Motor direction pin 1 to MODEL-X IN3 
#define LeftMotorDirPin2  8     //Left Motor direction pin 2 to MODEL-X IN4 
#define speedPinR 9             //Right PWM pin connect MODEL-X ENB
#define speedPinL 6             //Left PWM pin connect MODEL-X ENB

/*Reading individual sensor and returning True if it is on white
  DigitalRead() reads the value of the sensor
  returns 1 if the sensor is on a surface above the threshold (white surface)
  returns 0 if the sensor is on a surface below the threshold (black surface)*/

//Return true if 1st light sensor from the left is on a white surface
boolean LeftFirstOnWhite(){
  return digitalRead(A0); 
}

//Return true if 2nd light sensor from the left is on a white surface
boolean LeftSecondOnWhite(){
  return digitalRead(A1); 
}

//Return true if middle light sensor is on a white surface
boolean MiddleOnWhite(){
  return digitalRead(A2); 
}

//Return true if 2nd light sensor from the right is on a white surface
boolean RightSecondOnWhite(){
  return digitalRead(A3); 
}

//Return true if 1st light sensor from the right is on a white surface
boolean RightFirstOnWhite(){
  return digitalRead(A0); 
}

/*Defining the robot's movements*/
void go_straight(int t=0)  //Forward
{
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2,LOW);
  digitalWrite(LeftMotorDirPin1,HIGH);
  digitalWrite(LeftMotorDirPin2,LOW);
  analogWrite(speedPinL,SPEED);
  analogWrite(speedPinR,SPEED);
  delay(t);
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
void setup()
{
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT); 
  brake();
}

void loop()
{ 
  /*
   Use the functions given to you to write your code for this competition. Feel free to change them to accomate your needs.
   */
}
