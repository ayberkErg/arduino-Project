

int LDR_Pin = A0;     
int LDR_degeri = 100 ;                                      //A0 ‘dan ldr ye giden bağlantıyı burada tanımladık ve adını LDR_Pin koyduk

void setup()
{
Serial.begin(9600);                                         // Seri ekranın çalışması için gerekli kodu yazdık.
}

void loop() {
  
LDR_degeri = analogRead(LDR_Pin);                           //LDR’ den aldığımız değeri analog olarak okutup, adını LDR_okuma koyduk.
                                                            //Ekrana Işık Değeri Yazdırdık.
Serial.println(LDR_degeri);                                 // LDR’ nin ölçtüğü değeri ekrana yazdırıyoruz.

delay(1000);                                                // 1 saniye bekleyecek.
}
