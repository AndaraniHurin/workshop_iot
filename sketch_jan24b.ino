 int M, sensor_analog;
 const int sensor_pin = 34;
 void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.print("Workshop Monitoring Tanaman SMKN7 Baleendah\n");


}

void loop() {
 sensor_analog = analogRead(sensor_pin);
 M = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
 if (isnan(M)) {
  Serial.println("sensor tidak terbaca!");
  return;
 }

 Serial.print("=======Monitoring tanaman=======\n");
 Serial.print("Kelembapan air tanah:");
 Serial.print(M); /*print kelembapan air*/
 Serial.println("%");
 delay(2000);

}
