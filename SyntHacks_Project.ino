#define buzzer 12 //The following lines define
int LED = 13;     //all the components used
int isObstaclePin = 2;
int isObstacle = HIGH;
int x = 0;


void setup() {
  pinMode(LED, OUTPUT); //Declare the LED as an output
  pinMode(isObstaclePin, INPUT); //Declare the avoidance sensor as an input
  Serial.begin(9600); //Initiate contact between the Arduino board and the computer
  digitalWrite(LED, HIGH); //Turn the LED on
  delay(1000); //Pause for one second
}

void loop() {
  isObstacle = digitalRead(isObstaclePin); //Recording inputs from the sensor
  if (isObstacle == LOW) { //If there is an object...
    Serial.println("OBSTACLE!"); 
    digitalWrite(LED, HIGH); //Turn light on
    digitalWrite(buzzer, LOW); //Turn buzzer off
    delay(1000); //Pause for one second
    x = 0; //Reset counter to 0
  }else{
    Serial.println("No Movement");
    Serial.println(x);
    x = x + 1; //Increase counter value
    delay(100); //Pause
    if (x<30) { //If x is smaller than 30
      digitalWrite(buzzer, HIGH); //Turn buzzer on
    }else{
      digitalWrite(buzzer, LOW); //Turn buzzer off
      digitalWrite(LED, LOW); //Turn the light off
    }
  }
}
    
