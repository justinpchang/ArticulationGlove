#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to the sensor */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
/* Assign the flex sensor input pins to analog pins 0-4 */
int flexSensorPins[] = {A0, A1, A2, A3, A4};

void setup(void) {
  /* Initialize serial monitor */
  Serial.begin(9600);

  /* Initialize the accelerometer */
  if(!accel.begin()) {
    Serial.println("[FATAL] No ADXL345 detected... Check wiring.");
    while(1);
  }

  /* Set accelerometer range */
  accel.setRange(ADXL345_RANGE_16_G);
}

void loop(void) {
  /* Get a new sensor event */
  sensors_event_t event;
  accel.getEvent(&event);

  /* Read from the flex sensor */
  int flexSensorReadings[4];
  for(int i = 0; i < 5; i++) {
    flexSensorReadings[i] = analogRead(flexSensorPins[i]) - 500; // 500 is the calibration constant
  }

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("Flex 0: "); Serial.print(flexSensorReadings[0]); Serial.print("\t");
  Serial.print("Flex 1: "); Serial.print(flexSensorReadings[1]); Serial.print("\t");
  Serial.print("Flex 2: "); Serial.print(flexSensorReadings[2]); Serial.print("\t");
  Serial.print("Flex 3: "); Serial.print(flexSensorReadings[3]); Serial.print("\t");
  Serial.print("Flex 4: "); Serial.print(flexSensorReadings[4]); Serial.print("\t");
  Serial.println(" ");
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.println("m/s^2");
  delay(200);
}
