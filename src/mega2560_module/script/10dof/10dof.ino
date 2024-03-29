#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
// #include <Adafruit_BMP085_U.h>
// #include <Adafruit_L3GD20_U.h>
// #include <Adafruit_10DOF.h>

/* Assign a unique ID to the sensors */
// Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified   mag   = Adafruit_LSM303_Mag_Unified(30302);
// Adafruit_BMP085_Unified       bmp   = Adafruit_BMP085_Unified(18001);
// Adafruit_L3GD20_Unified       gyro  = Adafruit_L3GD20_Unified(20);

void displaySensorDetails(void)
{
  sensor_t sensor;
  
//   accel.getSensor(&sensor);
//   Serial.println(F("----------- ACCELEROMETER ----------"));
//   Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
//   Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
//   Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
//   Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" m/s^2"));
//   Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" m/s^2"));
//   Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" m/s^2"));
//   Serial.println(F("------------------------------------"));
//   Serial.println(F(""));

//   gyro.getSensor(&sensor);
//   Serial.println(F("------------- GYROSCOPE -----------"));
//   Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
//   Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
//   Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
//   Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" rad/s"));
//   Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" rad/s"));
//   Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" rad/s"));
//   Serial.println(F("------------------------------------"));
//   Serial.println(F(""));
  
  mag.getSensor(&sensor);
  Serial.println(F("----------- MAGNETOMETER -----------"));
  Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" uT"));
  Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" uT"));
  Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" uT"));  
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));

//   bmp.getSensor(&sensor);
//   Serial.println(F("-------- PRESSURE/ALTITUDE ---------"));
//   Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
//   Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
//   Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
//   Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" hPa"));
//   Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" hPa"));
//   Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" hPa"));  
//   Serial.println(F("------------------------------------"));
//   Serial.println(F(""));
  
  delay(500);
}

void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("Adafruit 10DOF Tester")); Serial.println("");
  
  /* Initialise the sensors */
//   if(!accel.begin())
//   {
//     /* There was a problem detecting the ADXL345 ... check your connections */
//     Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
//     while(1);
//   }
  if(!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
//   if(!bmp.begin())
//   {
//     /* There was a problem detecting the BMP085 ... check your connections */
//     Serial.print("Ooops, no BMP085 detected ... Check your wiring or I2C ADDR!");
//     while(1);
//   }
//   if(!gyro.begin())
//   {
//     /* There was a problem detecting the L3GD20 ... check your connections */
//     Serial.print("Ooops, no L3GD20 detected ... Check your wiring or I2C ADDR!");
//     while(1);
//   }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
}

void loop(void)
{
  /* Get a new sensor event */
  sensors_event_t event;
   
//   /* Display the results (acceleration is measured in m/s^2) */
//   accel.getEvent(&event);
//   Serial.print(F("ACCEL "));
//   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
//   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
//   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");

  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  mag.getEvent(&event);
  float mag_x = event.magnetic.x;
  float mag_y = event.magnetic.y;
  float mag_z = event.magnetic.z;
  float angle_rad = atan2(mag_x, mag_y);
  float angle_deg = angle_rad*180/M_PI;
  Serial.print(F("MAG   "));
  Serial.print("X: "); Serial.print(mag_x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(mag_y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(mag_z); Serial.print("  ");Serial.println("uT");
  Serial.print(angle_rad); Serial.print(" radians, "); Serial.print(angle_deg); Serial.println("°");

//   /* Display the results (gyrocope values in rad/s) */
//   gyro.getEvent(&event);
//   Serial.print(F("GYRO  "));
//   Serial.print("X: "); Serial.print(event.gyro.x); Serial.print("  ");
//   Serial.print("Y: "); Serial.print(event.gyro.y); Serial.print("  ");
//   Serial.print("Z: "); Serial.print(event.gyro.z); Serial.print("  ");Serial.println("rad/s ");  

//   /* Display the pressure sensor results (barometric pressure is measure in hPa) */
//   bmp.getEvent(&event);
//   if (event.pressure)
//   {
//     /* Display atmospheric pressure in hPa */
//     Serial.print(F("PRESS "));
//     Serial.print(event.pressure);
//     Serial.print(F(" hPa, "));
//     /* Display ambient temperature in C */
//     float temperature;
//     bmp.getTemperature(&temperature);
//     Serial.print(temperature);
//     Serial.print(F(" C, "));
//     /* Then convert the atmospheric pressure, SLP and temp to altitude    */
//     /* Update this next line with the current SLP for better results      */
//     float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
//     Serial.print(bmp.pressureToAltitude(seaLevelPressure,
//                                         event.pressure,
//                                         temperature)); 
//     Serial.println(F(" m"));
//   }
  
  Serial.println(F(""));
  delay(10);
}