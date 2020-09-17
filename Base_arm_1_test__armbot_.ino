
// Motor 
int enA = 10;
int in1 = 5;
int in2 = 6;


// Joystick Input
int joyVert = A0; // Vertical  

// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;

// Joystick Values - Start at 512 (middle position)

int joyposVert = 512;
int joyposHorz = 512;  


void setup()

{
  

  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   
  // Start with motors disabled and direction forward
  
  // Motor A
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
}

void loop() {

    
  // Read the Joystick X and Y positions
  joyposVert = analogRead(joyVert); 

  // Determine if this is a forward or backward motion
  // Do this by reading the Verticle Value
  // Apply results to MotorSpeed and to Direction

  if (joyposVert < 460)
  {
    // This is Backward

    // Set Motor A backward

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    MotorSpeed1 = 255;
    
  } else if(joyposVert > 564){

    // Set Motor A forward

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    MotorSpeed1 = 255;
  }
    else
  {
    // This is Stopped

    MotorSpeed1 = 0; 

  }


  // Adjust to prevent "buzzing" at very low speed

  if (MotorSpeed1 < 8)MotorSpeed1 = 0;

  // Set the motor speeds

  analogWrite(enA, MotorSpeed1);

}
