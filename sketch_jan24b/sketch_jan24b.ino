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
 kirimPesanTelegram(humid, tempe, moist);

                 

}
void kirimPesanTelegram(float humid, float tempe, int moist) {
  String pesan = "Suhu satta ini : " + String (tempe, 2 ) + "°C\n" +
                  "Humiditas udara saat ini : " + String(humid, 2) + "%\n" +
                  "Tingkat kelembapan tanah saat ini : " + String(moist) + "%\n";

 if (bot.sendMessage(CHAT_ID, pesan, "Markdown")) {
  Serial.println("Pesan berhasil dikirim");
 }   else {
  serial.println("Gagal mengirim pesan ");
 }   
 delay(1000); //Menunggu sejenak sebelum mengirim pesan lagi
}           
