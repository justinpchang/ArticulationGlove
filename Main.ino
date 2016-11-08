/*  Only uses 1 flex sensor and 1 sensor stick.
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to the sensor */
//Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
/* Assign the flex sensor input pin to Analog 0 */
int flexSensorPin0 = A0;
int flexSensorPin1 = A1;
int flexSensorPin1 = A2;
int flexSensorPin1 = A3;
int flexSensorPin1 = A4;

void setup(void) {
  /* Initialize serial monitor */
  Serial.begin(9600);

  /* Initialize the accelerometer */
  /*
  if(!accel.begin()) {
    Serial.println("[FATAL] No ADXL345 detected... Check wiring.");
    while(1);
  }
  */

  /* Set accelerometer range */
  //accel.setRange(ADXL345_RANGE_16_G);
}

void loop(void) {
  /* Get a new sensor event */
  //sensors_event_t event;
  //accel.getEvent(&event);

  /* Read from the flex sensor */
  int flexSensorReading0 = analogRead(flexSensorPin0) - 600;
  int flexSensorReading1 = analogRead(flexSensorPin1) - 600;
  int flexSensorReading2 = analogRead(flexSensorPin2) - 600;
  int flexSensorReading3 = analogRead(flexSensorPin3) - 600;
  int flexSensorReading4 = analogRead(flexSensorPin4) - 600;

  /* Display the results (acceleration is measured in m/s^2) */
  /* SERIAL MONITOR VERSION
  Serial.print("Flex: "); Serial.print(flexSensorReading); Serial.print("  ");
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  "); Serial.println("m/s^2");
  */

  /* vPython VERSION */
  Serial.print(flexSensorReading0); Serial.print(",");
  Serial.print(flexSensorReading1); Serial.print(",");
  Serial.print(flexSensorReading2); Serial.print(",");
  Serial.print(flexSensorReading3); Serial.print(",");
  Serial.print(flexSensorReading4); Serial.print(",");
  /*
  Serial.print(event.acceleration.x); Serial.print(",");
  Serial.print(event.acceleration.y); Serial.print(",");
  Serial.print(event.acceleration.z);
  */
  Serial.println("");
  delay(200);
}
