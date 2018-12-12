
 /*
 * This is the Arduino code for  HC-SR04 Ultrasonic Distance Sensor with TP1637 Display
 * to measure the distance using arduino for robotoic car and other applications
 * Watch the video https://youtu.be/SlgLj_T5GaY
 *  * 
 * Written by Ahmad Nejrabi for Robojax Video
 * Date: Dec 21, 2017, in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */

/* Original Code 
   from https://github.com/avishorp/TM1637
// https://playground.arduino.cc/Code/NewPing
 * Modified for Robojax video on Dec 21, 2017
// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------
*/

#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.



NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


////////////////////////////
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 3
#define DIO 4

// The amount of time (in milliseconds) between tests
#define TEST_DELAY  500
TM1637Display display(CLK, DIO);

/////////////////////////


void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.

  pinMode(5, OUTPUT); // červená LED
  pinMode(6, OUTPUT); // žlutá LED
  pinMode(7, OUTPUT); // zelená LED


}

void loop() {
  display.setBrightness(0x0f);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
  int distance = sonar.ping_cm();// get the distance and store it in "distance" variable
                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  display.showNumberDec(distance, false, 3,1);
  delay(1000);  

if (distance <= 150 && distance >= 100) {
  digitalWrite(7, HIGH);  // zapínání/vypínání LED
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);

    delay(600);
}
else if (distance <= 100 && distance >= 50) {
  digitalWrite(7, LOW);  // zapínání/vypínání LED
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);

    delay(600);
}
else if (distance <= 50 && distance >= 0) {
  digitalWrite(7, LOW);  // zapínání/vypínání LED
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);

    delay(600);
}


  
}
