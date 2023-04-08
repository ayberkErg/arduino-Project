#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_BMP280 bmp280;
TinyGPS gps;
SoftwareSerial ss(10, 11);
SoftwareSerial xbeetest (2,3);
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

int yedekAviyonik = 7 ;
 
static void smartdelay(unsigned long ms);
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);


 float acc;
  float basinc0 ;
float yukseklik;
int asama = 0; // 0 :  yerde, ateşleme yapılmadı, yükseliyor. 1 : 1.aşama gerçekleşti. 2 : 2.aşama gerçekleşti. 


void displaySensorDetails(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}


void displayDataRate(void)
{
  Serial.print  ("Data Rate:    "); 
  
  switch(accel.getDataRate())
  {
    case ADXL345_DATARATE_3200_HZ:
      Serial.print  ("3200 "); 
      break;
    case ADXL345_DATARATE_1600_HZ:
      Serial.print  ("1600 "); 
      break;
    case ADXL345_DATARATE_800_HZ:
      Serial.print  ("800 "); 
      break;
    case ADXL345_DATARATE_400_HZ:
      Serial.print  ("400 "); 
      break;
    case ADXL345_DATARATE_200_HZ:
      Serial.print  ("200 "); 
      break;
    case ADXL345_DATARATE_100_HZ:
      Serial.print  ("100 "); 
      break;
    case ADXL345_DATARATE_50_HZ:
      Serial.print  ("50 "); 
      break;
    case ADXL345_DATARATE_25_HZ:
      Serial.print  ("25 "); 
      break;
    case ADXL345_DATARATE_12_5_HZ:
      Serial.print  ("12.5 "); 
      break;
    case ADXL345_DATARATE_6_25HZ:
      Serial.print  ("6.25 "); 
      break;
    case ADXL345_DATARATE_3_13_HZ:
      Serial.print  ("3.13 "); 
      break;
    case ADXL345_DATARATE_1_56_HZ:
      Serial.print  ("1.56 "); 
      break;
    case ADXL345_DATARATE_0_78_HZ:
      Serial.print  ("0.78 "); 
      break;
    case ADXL345_DATARATE_0_39_HZ:
      Serial.print  ("0.39 "); 
      break;
    case ADXL345_DATARATE_0_20_HZ:
      Serial.print  ("0.20 "); 
      break;
    case ADXL345_DATARATE_0_10_HZ:
      Serial.print  ("0.10 "); 
      break;
    default:
      Serial.print  ("???? "); 
      break;
  }  
  Serial.println(" Hz");  
}

void displayRange(void)
{
  Serial.print  ("Range:         +/- "); 
  
  switch(accel.getRange())
  {
    case ADXL345_RANGE_16_G:
      Serial.print  ("16 "); 
      break;
    case ADXL345_RANGE_8_G:
      Serial.print  ("8 "); 
      break;
    case ADXL345_RANGE_4_G:
      Serial.print  ("4 "); 
      break;
    case ADXL345_RANGE_2_G:
      Serial.print  ("2 "); 
      break;
    default:
      Serial.print  ("?? "); 
      break;
  }  
  Serial.println(" g");  
}




void setup()
{
 
  xbeetest.begin(9600);
  Serial.begin(9600);
  ss.begin(9600);
    //   xbeetest.write("ayberk");
  Serial.println("AURORA ROKET TAKIMI ");
  Serial.println("--------------------------------------------------");
  delay(1000);
    Serial.println("kalibrasyon yapılıyor...");
  delay(1500);
  //Serial.println("Accelerometer Test"); Serial.println("");

  pinMode(yedekAviyonik , OUTPUT);
  pinMode(4 , OUTPUT);//*****************///ATEŞLEME
  pinMode(5 , OUTPUT); ////22222222
  digitalWrite(4 , LOW);
    digitalWrite(5 , LOW);
/*#ifndef ESP8266
  while (!Serial); 
#endif*/
   if (!bmp280.begin()) {
    
    Serial.println("Could not find a valid BMP280 sensor!");
    digitalWrite(yedekAviyonik , HIGH);
    
    while (0);
  }
  
  if(!accel.begin())
  {
    
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(0);
  }


  
{

  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  // accel.setRange(ADXL345_RANGE_2_G);
  
  /* Display some basic information on this sensor */
////  displaySensorDetails();
  
  /* Display additional settings (outside the scope of sensor_t) */
  //displayDataRate();
  //displayRange();
  //Serial.println("");
}

  
  


  int i=0;
  for(i=0;i<10;i++){
    for(int j = 0; j<10; j++)
    {
      bmp280.readTemperature();
      bmp280.readPressure();
      }
      bmp280.readTemperature();
      bmp280.readPressure();
      basinc0 += bmp280.readPressure()/100;
      delay(500);
    }
    basinc0 = basinc0 / 10;
}






void loop()
{
  Wire.beginTransmission(0x77);
  byte error = Wire.endTransmission();

  if(error == 0){
     digitalWrite(yedekAviyonik , LOW);
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
 
  acc = sqrt( pow(event.acceleration.x,2) + pow(event.acceleration.y,2) + pow(event.acceleration.z,2) );
  /* Display the results (acceleration is measured in m/s^2) */
  //Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  //Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");

  Serial.print("Accelerometer: "); Serial.print(acc); Serial.println("  ");
  //delay(100);

  bmp280.readTemperature();
  bmp280.readPressure();
  yukseklik = bmp280.readAltitude(basinc0);
// acc = sqrt( pow(event.acceleration.x,2) + pow(event.acceleration.y,2) + pow(event.acceleration.z,2) );
  
  if(yukseklik > 2500 && acc < 5) // Buraya ivme gelecek ve yukseklik 100-600 arası olacak
  {
    // ApoGee tespit edildi 1.aşamayı gerçekleştir
    digitalWrite(4, HIGH);
    asama = 1;    
  }

  if(yukseklik < 600 && yukseklik > 100 && asama == 1) // 2.aşama için gerekli koşullar
  {
    // 1.aşama yapılmış, düşüş gerçekleşiyor ve 600 mt den daha alçakta
    digitalWrite(5, HIGH);
    asama = 2;
  }


    /*Serial.print("Temperature = ");
    Serial.print(bmp280.readTemperature());
    Serial.println(" *C");*/
       //////////  xbeetest.println(bmp280.readTemperature());
    Serial.print("Pressure = ");
    Serial.print(bmp280.readPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp280.readAltitude(basinc0)); // this should be adjusted to your local forcase
    Serial.println(" m");

    Serial.println();

    //delay(1000);

    // Sensör ile iletişim var,
    // Sensör ile alakalı bütün işlemler burada yapılacak.
    //algpritma ateşleme
    }

    
  else if(error != 0){ //
    Serial.println("Sensör hatası!");
    digitalWrite(yedekAviyonik , HIGH);
     digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    // Sensörde arıza var. Sensör işlemi yapma, yedeğe bilgi gönder, ateşleme kontrollerini kes
  }
  
  

  float flat, flon;

  unsigned short sentences = 0, failed = 0;

  gps.f_get_position(&flat, &flon);
  Serial.print("LAT,LON : ");

    //  xbeetest.print(" flat ");
      //xbeetest.write("ayberk");
  print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 10, 6);
  Serial.print(",");
    xbeetest.print(",");
  print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 11, 6);
  Serial.println(" ");
  xbeetest.println("");
  smartdelay(1000);


}

static void smartdelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void print_float(float val, float invalid, int len, int prec)
{
  if (val == invalid)
  {
    while (len-- > 1)
      Serial.print('*');
              xbeetest.println('*');
    Serial.print(' ');
             xbeetest.println(' ');
  }
  else
  {
    Serial.print(val, prec);
    xbeetest.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i = flen; i < len; ++i)
      Serial.print(' ');
       xbeetest.print(' ');
  }
  
  
  smartdelay(0);
}

static void print_int(unsigned long val, unsigned long invalid, int len)
{
  char sz[32];
  if (val == invalid) 
 { xbeetest.print("********");
    strcpy(sz, "*******");
 }
  else
    sprintf(sz, "%ld", val);  
  sz[len] = 0;
  for (int i = strlen(sz); i < len; ++i)
    sz[i] = ' ';
  if (len > 0)
    sz[len - 1] = ' ';
  Serial.print(sz);
  smartdelay(0);
}
static void print_str(const char *str, int len)
{
  int slen = strlen(str);
  for (int i = 0; i < len; ++i)
    Serial.print(i < slen ? str[i] : ' ');
  smartdelay(0);
}
