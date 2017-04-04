/*
The application will send only one character that represents the button pressed, where:
0 = no key pressed;
1 = UP key pressed;
2 = DOWN key pressed;
3 = LEFT key pressed;
4 = RIGHT key pressed;
5 = X button pressed;
6 = O key pressed;
7 = SQUARE button pressed;
8 = TRIANGLE button pressed;
9 = SELECT key pressed;
A = START key pressed;


the app sends "0" before close the connection.

*/

int motor_A1=2; 
int motor_A2=3; 
int motor_B1=4;
int motor_B2=5;
//leds
int Red1 = 9;
int Green1 = 8;
int Blue1 = 10;
int Red2 = 12;
int Green2 = 11;
int Blue2 = 13;


char val; // variable to receive data from the serial port
int ledpin = 13; // LED connected to pin 48 (on-board LED)
void setup() 
  {  
  //Motor Pins:
  pinMode(motor_A1,OUTPUT);  
  pinMode(motor_A2,OUTPUT);  
  pinMode(motor_B1,OUTPUT);  
  pinMode(motor_B2,OUTPUT); 
  //Led Pins
  pinMode(ledpin, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Green1, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Green2, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Red1, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Red2, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Blue1, OUTPUT);  // pin 48 (on-board LED) as OUTPUT
  pinMode(Blue2, OUTPUT);  // pin 48 (on-board LED) as OUTPUT

//init leds
      digitalWrite(Green1,LOW);  
      digitalWrite(Green2,LOW);
      digitalWrite(Red1,HIGH);  
      digitalWrite(Red2,HIGH);
      digitalWrite(Blue1,LOW);  
      digitalWrite(Blue2,LOW);

  //init serial connection
  Serial.begin(9600);       // start serial communication at 9600bps
}

void loop()
{
  if( Serial.available() )       // if data is available to read
    {
       val = Serial.read();         // read it and store it in 'val'
    }

    //Input key switch
    switch (val) {
    case '0':    
        {
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,LOW);
      break;
    case '1':  
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,HIGH); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,HIGH); 
      break;
    case '2':    
        digitalWrite(motor_A1,HIGH);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,HIGH);  
        digitalWrite(motor_B2,LOW);
       break;
    case '3':    
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,HIGH); 
        digitalWrite(motor_B1,HIGH);  
        digitalWrite(motor_B2,LOW); 
      break;   
    case '4':    
        digitalWrite(motor_A1,HIGH);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,HIGH);  
      break;
    case '5':    
      //Code when SELECT key is pressed 
      digitalWrite(Green1,LOW);  
      digitalWrite(Green2,LOW);
      digitalWrite(Red1,LOW);  
      digitalWrite(Red2,LOW);
      digitalWrite(Blue1,HIGH);  
      digitalWrite(Blue2,HIGH);
      
      break;
    case '6':    
      //Code when Start key is pressed 
      digitalWrite(Green1,LOW);  
      digitalWrite(Green2,LOW);
      digitalWrite(Red1,LOW);  
      digitalWrite(Red2,LOW);
      digitalWrite(Blue1,LOW);  
      digitalWrite(Blue2,LOW);
      break;
    case '7':    
      //Code when TRIANGLE key is pressed
      digitalWrite(Green1,HIGH);  
      digitalWrite(Green2,HIGH);
      digitalWrite(Red1,LOW);  
      digitalWrite(Red2,LOW);
      digitalWrite(Blue1,LOW);  
      digitalWrite(Blue2,LOW);
      break;
    case '8':    
      //Code when SQUARE key is pressed
      digitalWrite(Green1,LOW);  
      digitalWrite(Green2,LOW);
      digitalWrite(Red1,HIGH);  
      digitalWrite(Red2,HIGH);
      digitalWrite(Blue1,LOW);  
      digitalWrite(Blue2,LOW);
      break;
    case '9':    
      //Code when X key is pressed 
   for (int i=0; i <= 13; i++){
      digitalWrite(Green1,LOW);  
      digitalWrite(Green2,LOW);
      digitalWrite(Red1,LOW);  
      digitalWrite(Red2,LOW);
      digitalWrite(Blue1,LOW);  
      digitalWrite(Blue2,LOW);
      delay(60);
      digitalWrite(Green1,HIGH);  
      digitalWrite(Green2,HIGH);
      digitalWrite(Red1,HIGH);  
      digitalWrite(Red2,HIGH);
      digitalWrite(Blue1,HIGH);  
      digitalWrite(Blue2,HIGH);
      delay(60);
   } 
      break;
    case 'A':    
      //Code when START key is pressed 
      break;
    case 'B': 
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,HIGH); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,LOW);   
      break;
    case 'C':    
        digitalWrite(motor_A1,HIGH);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,LOW); 
      break;
    case 'D':    
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,LOW);  
        digitalWrite(motor_B2,HIGH); 
      break;
    case 'E':    
        digitalWrite(motor_A1,LOW);  
        digitalWrite(motor_A2,LOW); 
        digitalWrite(motor_B1,HIGH);  
        digitalWrite(motor_B2,LOW); 
      break;
    default:
      // default code (should never run)
      //init leds
      break;
    }
delay(50);
  }
}
