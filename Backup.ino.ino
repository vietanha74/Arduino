#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

float value;  
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonEmergency = 3;     // the number of the pushbutton pin
const int ledPin =  5;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonEmergencyState = 0;         // variable for reading the pushbutton status
unsigned int count = 0;
unsigned int SensorCount = 0;
bool state = false;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonEmergency, INPUT);
  Serial.begin(9600);

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
   lcd.setCursor(1,0);
   lcd.print("STARTING");
   lcd.setCursor(1,1);
   lcd.print("MG/L");
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  buttonEmergencyState = digitalRead(buttonEmergency);
  Serial.println(buttonEmergencyState);

  if(buttonEmergencyState == 0)
  {
    if (buttonState == 1)
    {
        state = true;
        
        lcd.setCursor(1,0);
        lcd.print("           ");
        lcd.setCursor(1,1);
        lcd.print("           ");
        
        if (count >= 50)
        {
          
        }
        else
        {
          count ++;
          lcd.setCursor(1,0);
          lcd.print(count);
  
          value = analogRead(A0);
          lcd.setCursor(1,1);
          lcd.print((value/1000)-(-0.01)-0.03);   
  
          if(count == 1 )
          {
            lcd.setCursor(1,0);
            lcd.print("STARTING");
            lcd.setCursor(1,1);
            lcd.print("MG/L");
            digitalWrite(ledPin, LOW);
          }
          
          delay(100);
        } 
    }
    else if(buttonState == 0)
    {
        count = 0;
    }
  
  
    
     if (count == 50)
     {
        lcd.setCursor(1,0);
        if ( ((value/1000)-(-0.01)-0.03) > 0.17)
        {
           lcd.print("Say roi");
        }
        else
        {
          lcd.print("OK");
          digitalWrite(ledPin, HIGH);
        }
     } 
  }
  else
  {
    Starting();
  }
}


void Starting()
{
  lcd.setCursor(1,0);
  lcd.print("KHOI DONG XE.......");
  lcd.setCursor(1,1);
  lcd.print("                   ");
}
