/*
  Magnetic Stirring Plate to produce Yeast Starter for Beer Homebrewers.
  Created By: https://github.com/acremonezi
  Date: 21-Nov-2020
  Components:
    1 - Arduino Nano.
    2 - PC Cooler with 4 Wires (Ground, Vcc, RPM Sensor and PWM Imput).
    3 - Potentiometer R1K.
    4 - LEDs.
    5 - Voltage Regulator IC 7805.
    6 - Neodymium Magnets.
    7 - Several others small components.
*/

int Potentiometer_Pin = A0;             // Potentiometer R1K.
int Potentiometer_Value = 0;            // Initial Variable for Potentiometer position.
int Potentiometer_Value_Current = 0;    // Initial Variable for Potentiometer position.
int Potentiometer_Value_Previous = 0;   // Initial Variable for Potentiometer position.

int PWM_Pin = 9;                        // PC Cooler Fan.
int PWMDutyCycle = 0;                   // Initial Variable that calculate PWM Duty Cycle.

int time_counter = 0;                   // Will store last time Potentiometer was updated
unsigned long time;                     // Initial Variable for Enlapse Time.


// Define LED Pins
int LED_00 = 13; 
int LED_01 = 2;  
int LED_02 = 3;
int LED_03 = 4;
int LED_04 = 5;
int LED_05 = 6;
int LED_06 = 7;
int LED_07 = 8;
int LED_08 = 10;
int LED_09 = 11;
int LED_10 = 12;


void setup() {

    // start serial port to print information
    Serial.begin(9600);
 
    // LEDs Meter
    pinMode(LED_00, OUTPUT);
    pinMode(LED_01, OUTPUT);
    pinMode(LED_02, OUTPUT);
    pinMode(LED_03, OUTPUT);
    pinMode(LED_04, OUTPUT);
    pinMode(LED_05, OUTPUT);
    pinMode(LED_06, OUTPUT);
    pinMode(LED_07, OUTPUT);
    pinMode(LED_08, OUTPUT);
    pinMode(LED_09, OUTPUT);
    pinMode(LED_10, OUTPUT);

    digitalWrite(LED_00, LOW);
    digitalWrite(LED_01, LOW);
    digitalWrite(LED_02, LOW);
    digitalWrite(LED_03, LOW);
    digitalWrite(LED_04, LOW);
    digitalWrite(LED_05, LOW);
    digitalWrite(LED_06, LOW);
    digitalWrite(LED_07, LOW);
    digitalWrite(LED_08, LOW);
    digitalWrite(LED_09, LOW);
    digitalWrite(LED_10, LOW);
}



void loop() {

  // Store Current Enlapse Time
  time = millis() / 1000;

  // Calculate Variables
  Potentiometer_Value = analogRead(Potentiometer_Pin) / 4;
  PWMDutyCycle = Potentiometer_Value * 100 / 255;

  // Send Information to serial port
  Serial.print("PWM Duty Cycle: ");
  Serial.print(PWMDutyCycle);
  Serial.println(" %");

  // Send PWM command to Cooler.
  analogWrite(PWM_Pin, Potentiometer_Value);
  
  // Send Information to serial port
  Serial.print("Time: ");
  Serial.print(time_counter);
  Serial.println(" sec");




  // LEDs Meter

  Potentiometer_Value_Previous = Potentiometer_Value_Current; // Store what was read last time
  Potentiometer_Value_Current = Potentiometer_Value;

  for (int i = 0; i<=1; ++i) {
    time_counter++;
    delay(10);
  }
  

  if (time > 1 ) { 

    digitalWrite(LED_00, HIGH);
    
    if (PWMDutyCycle >= 0 && PWMDutyCycle < 5) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
     
    }
    
    if (PWMDutyCycle >= 10 && PWMDutyCycle < 20) {
      digitalWrite(LED_01, HIGH);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
  
    }
    else if (PWMDutyCycle >= 20 && PWMDutyCycle < 30) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, HIGH);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 30 && PWMDutyCycle < 40) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, HIGH);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 40 && PWMDutyCycle < 50) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, HIGH);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 50 && PWMDutyCycle < 60) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, HIGH);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 60 && PWMDutyCycle < 70) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, HIGH);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 70 && PWMDutyCycle < 80) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, HIGH);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 80 && PWMDutyCycle < 90) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, HIGH);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 90 && PWMDutyCycle < 100) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, HIGH);
      digitalWrite(LED_10, LOW);
    }
    else if (PWMDutyCycle >= 90) {
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, HIGH);
    }
  }
  else {
      digitalWrite(LED_00, LOW);
      digitalWrite(LED_01, LOW);
      digitalWrite(LED_02, LOW);
      digitalWrite(LED_03, LOW);
      digitalWrite(LED_04, LOW);
      digitalWrite(LED_05, LOW);
      digitalWrite(LED_06, LOW);
      digitalWrite(LED_07, LOW);
      digitalWrite(LED_08, LOW);
      digitalWrite(LED_09, LOW);
      digitalWrite(LED_10, LOW);
      
      if (Potentiometer_Value_Previous != Potentiometer_Value_Current) {
        time_counter = 0;
      }
                   
  }
}
