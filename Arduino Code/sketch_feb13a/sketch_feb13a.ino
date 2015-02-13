

//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)


int xStp = 2;  //connect pin 13 to step
int xDir = 5;  // connect pin 12 to dir

int yStp = 3;
int yDir = 6;

int zStp = 4;
int zDir = 7;

int a = 0;     //  gen counter
int enable = 8;

boolean limit = 0;
int i = 0;
int j = 0;
int stepDelay = 1;

void setup() 
{                
  pinMode(xStp, OUTPUT);
  pinMode(xDir, OUTPUT);       
  
  pinMode(yStp, OUTPUT);
  pinMode(yDir, OUTPUT);
  
  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);
}


void loop() 
{
  /*if (!limit && i < 3)
  {
    digitalWrite(enable, LOW);
    for (a = 0; a <580; a++)
    {
      digitalWrite(xStp, HIGH);   
      delay(stepDelay);               
      digitalWrite(xStp, LOW);  
      delay(stepDelay);
      limit = true;
      
    }
    digitalWrite(enable, HIGH);
    digitalWrite(xDir, HIGH);
    digitalWrite(enable, LOW);
    delay(500);
    for (a = 0; a <580; a++)
    {
      digitalWrite(xStp, HIGH);   
      delay(stepDelay);               
      digitalWrite(xStp, LOW);  
      delay(stepDelay);
      limit = false;
    }
    digitalWrite(xDir, LOW);
    delay(500);
    i++;
  }
  digitalWrite(enable, HIGH);*/
// Y motors  
  if (!limit && j < 3)
  {
    digitalWrite(enable, LOW);
    delay(100);
    for (a = 0; a <400; a++)
    {
      digitalWrite(yStp, HIGH);   
      delay(stepDelay);               
      digitalWrite(yStp, LOW);  
      delay(stepDelay);
      limit = true;
      
    }
    digitalWrite(enable, HIGH);
    digitalWrite(yDir, HIGH);
    digitalWrite(enable, LOW);
    delay(500);
    for (a = 0; a <400; a++)
    {
      digitalWrite(yStp, HIGH);   
      delay(stepDelay);               
      digitalWrite(yStp, LOW);  
      delay(stepDelay);
      limit = false;
    }
    digitalWrite(yDir, LOW);
    delay(500);
    j++;
  }
  digitalWrite(enable, HIGH);  
  
}
