#include "Wire.h"
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
#include "EEPROM.h"
//#include <EEPROMex.h>
#include "DHT.h"
#include "Arduino.h"
#define DS1307_I2C_ADDRESS 0x68
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int latchpin = 0; // connect to pin 12 on the '595
int clockpin = 0; // connect to pin 11 on the '595
int datapin = 0; // connect to pin 14 on the '595
int xx;
double lat;
double lon;
float koma;
int wi;
int sim;
float temp, hum;
boolean leng1,leng2,leng3,leng4,leng5;
const int kiri  = 7;
const int kanan = 6;
const int enter = A3;
const int atas  = 5;
const int bawah = 4;
int buzzer      = 3;
int alamat1 = 1;
int alamat2 =2;
int alamat3 =3;
int alamat4 =4;
int alamat5 =5;
int alamat6 =6;
int alamat7 =7;
int alamat0 = 0;
int alamat8 = 8;
int nilai;
int nilai2;
int nilai3;
int nilai4;
int nilai5;
int nilai6;
int nilai7;
int nilai8;
int poskiri;
int poskanan;
int posenter;
int posatas;
int posbawah;
int laskiri;
int laskanan;
int lasenter;
int lasatas;
int lasbawah;
long hitung;
int segdisp[] = {
 3,159,37,13,153,73,65,27,1,9,254 };

 
long previousMillis = 0;        // will store last time time was updated
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
long interval = 200;

int zero=0;
char  *dayOfTheWeek[7] = {"Minggu","Senin","Selasa","Rabu","Kamis","Jum'at","Sabtu"};
double fajr, sunRise, zuhr, asr, maghrib, isha;

byte decToBcd(byte val)
{
return ( (val/10*16) + (val%10) );
}

byte bcdToDec(byte val)
{
return ( (val/16*10) + (val%16) );
}

void getDateDs1307()
{
// Reset the register pointer
Wire.beginTransmission(DS1307_I2C_ADDRESS);
//Wire.write(0x00);
Wire.write(zero);
Wire.endTransmission();

Wire.requestFrom(DS1307_I2C_ADDRESS, 7);

// A few of these need masks because certain bits are control bits
second     = bcdToDec(Wire.read() & 0x7f);
minute     = bcdToDec(Wire.read());
hour       = bcdToDec(Wire.read() & 0x3f);  // Need to change this if 12 hour am/pm
dayOfWeek  = bcdToDec(Wire.read());
dayOfMonth = bcdToDec(Wire.read());
month      = bcdToDec(Wire.read());
year       = bcdToDec(Wire.read());

}


void setDateDs1307()
{
  
   // Below changes will happen when pin 3 is pull high. Short pin 3 to ground once changes to clock is done.
   // Run out of RAM for serialport or button date, lon, lat adjust. will work on it later. 
//   minute=38;
//   hour=22;
      dayOfWeek=7;
//   dayOfMonth=18;
//   month=7;
    /*
   second = (byte) ((pserial.read() - 48) * 10 + (pserial.read() - 48)); // Use of (byte) type casting and ascii math to achieve result.
   minute = (byte) ((pserial.read() - 48) *10 +  (pserial.read() - 48));
   hour  = (byte) ((pserial.read() - 48) *10 +  (pserial.read() - 48));
   dayOfWeek = (byte) (pserial.read() - 48);
   dayOfMonth = (byte) ((pserial.read() - 48) *10 +  (pserial.read() - 48));
   month = (byte) ((pserial.read() - 48) *10 +  (pserial.read() - 48));
   year= (byte) ((pserial.read() - 48) *10 +  (pserial.read() - 48)); */
   
   Wire.beginTransmission(DS1307_I2C_ADDRESS);
   Wire.write(zero);
   Wire.write(decToBcd(second));    // 0 to bit 7 starts the clock
   Wire.write(decToBcd(minute));
   Wire.write(decToBcd(hour));      // for 12 hour am/pm, need to set bit 6 (also need to change readDateDs1307)
   Wire.write(decToBcd(dayOfWeek));
   Wire.write(decToBcd(dayOfMonth));
   Wire.write(decToBcd(month));
   Wire.write(decToBcd(year));
   Wire.endTransmission();
}

void setup()  {
  dht.begin();
  Serial.begin(9600);
  nilai5=EEPROM.read(alamat8);
  if(nilai5>1)nilai5=0;
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Wire.begin();
  getDateDs1307() ;
  lcd.begin(20,4);
  lcd.home();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("--------------------");
  lcd.setCursor(0,1);
  lcd.print(">>Digital Clock V1<<");//lcd.write(1);
  lcd.setCursor(0,2);
  lcd.print("     Dicky B_Mz     ");
  lcd.setCursor(0,3);
  lcd.print("--------------------");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("--------------------");\
  lcd.setCursor(0,1);
  lcd.print("-Jam + Waktu Shalat-");//lcd.write(1);
  lcd.setCursor(0,2);
  lcd.print("--->>YOGYAKARTA<<---");
  lcd.setCursor(0,3);
  lcd.print("--------------------");

  tone(8,1500,50);
  delay(100);
  tone(8,1500,50);
  delay(100);
  
  tone(8,2400,50);
  delay(100);
  
  
  delay(2000);
  lcd.clear();
  //EEPROM.writeFloat(20,-8.99);
}

double degToRad(double degree)
{
    return ((3.1415926 / 180) * degree);
}

double radToDeg(double radian)
{
    return (radian * (180/3.1415926));
}

double moreLess360(double value)
{
    while(value > 360 || value < 0)
    {
        if(value > 360)
            value -= 360;

        else if (value <0)
            value += 360;
    }

    return value;
}

double moreLess24(double value)
{
    while(value > 24 || value < 0)
    {
        if(value > 24)
            value -= 24;

        else if (value <0)
            value += 24;
    }

    return value;
}
void doubleToHrMin(double number, int &hours, int &minutes)
{
    hours = floor(moreLess24(number));
    minutes = floor(moreLess24(number - hours) * 60);
}

void calcPrayerTimes(int year, int month, int day,
                     double longitude, double latitude, int timeZone,
                     double fajrTwilight, double ishaTwilight,
                     double &fajrTime, double &sunRiseTime, double &zuhrTime,
                     double &asrTime, double &maghribTime, double &ishaTime)
{
    double D = (367 * year) - ((year + (int)((month + 9) / 12)) * 7 / 4) + (((int)(275 * month / 9)) + day - 730531.5);

    double L = 280.461 + 0.9856474 * D;
    L = moreLess360(L);

    double M = 357.528 + (0.9856003) * D;
    M = moreLess360(M);

    double Lambda = L + 1.915 * sin(degToRad(M)) + 0.02 * sin(degToRad(2 * M));
    Lambda = moreLess360(Lambda);

    double Obliquity = 23.439 - 0.0000004 * D;
    double Alpha = radToDeg(atan((cos(degToRad(Obliquity)) * tan(degToRad(Lambda)))));
    Alpha = moreLess360(Alpha);

    Alpha = Alpha - (360 * (int)(Alpha / 360));
    Alpha = Alpha + 90 * (floor(Lambda / 90) - floor(Alpha / 90));

    double ST = 100.46 + 0.985647352 * D;
    double Dec = radToDeg(asin(sin(degToRad(Obliquity)) * sin(degToRad(Lambda))));
    double Durinal_Arc = radToDeg(acos((sin(degToRad(-0.8333)) - sin(degToRad(Dec)) * sin(degToRad(latitude))) / (cos(degToRad(Dec)) * cos(degToRad(latitude)))));

    double Noon = Alpha - ST;
    Noon = moreLess360(Noon);


    double UT_Noon = Noon - longitude;

//lcd.setCursor(0,1);
//lcd.print (Dec);
    ////////////////////////////////////////////
    // Calculating Prayer Times Arcs & Times //
    //////////////////////////////////////////

    // 2) Zuhr Time [Local noon]
    zuhrTime = UT_Noon / 15 + timeZone;

    // Asr Hanafi
    //double Asr_Alt =radToDeg(atan(2+tan(degToRad(latitude - Dec))));
    //double Asr_Alt =radToDeg(atan(1.7+tan(degToRad(latitude - Dec))));
    // Asr Shafii
    double Asr_Alt = radToDeg(atan(1 + tan(degToRad(latitude - Dec))));
    double Asr_Arc = radToDeg(acos((sin(degToRad(90 - Asr_Alt)) - sin(degToRad(Dec)) * sin(degToRad(latitude))) / (cos(degToRad(Dec)) * cos(degToRad(latitude)))));
    Asr_Arc = Asr_Arc / 15;
    // 3) Asr Time
    asrTime = zuhrTime + Asr_Arc;

    // 1) Shorouq Time
    sunRiseTime = zuhrTime - (Durinal_Arc / 15);

    // 4) Maghrib Time
    maghribTime = zuhrTime + (Durinal_Arc / 15);


    double Esha_Arc = radToDeg(acos((sin(degToRad(ishaTwilight)) - sin(degToRad(Dec)) * sin(degToRad(latitude))) / (cos(degToRad(Dec)) * cos(degToRad(latitude)))));
    // 5) Isha Time
    ishaTime = zuhrTime + (Esha_Arc / 15);

    // 0) Fajr Time
    double Fajr_Arc = radToDeg(acos((sin(degToRad(fajrTwilight)) - sin(degToRad(Dec)) * sin(degToRad(latitude))) / (cos(degToRad(Dec)) * cos(degToRad(latitude)))));
    fajrTime = zuhrTime - (Fajr_Arc / 15);

    return;
}


void loop() {
  temp = dht.readTemperature();
  hum  = dht.readHumidity();
  int hours, minutes;
  hitung++;
  cektombol();
  getDateDs1307() ;
  lcdtam();
  nilai4=EEPROM.read(alamat4);
  nilai2=EEPROM.read(alamat2);
  nilai3=EEPROM.read(alamat3);
  sim=EEPROM.read(alamat1);
  nilai6=EEPROM.read(alamat6);
        nilai7=EEPROM.read(alamat7);
        nilai8=EEPROM.read(alamat8);
float b=nilai3;
 
b=b/100;
  
  float latitu=nilai2+b;
  if(sim==0)latitu=latitu*(-1);
  float c=nilai8;
  c=c/100;
  float longitu=nilai7+c;
  
  if(nilai6==0)longitu=longitu*(-1);
//  lcd.setCursor(0,1);
//  lcd.print(longitu);
  calcPrayerTimes(year, month, dayOfMonth, longitu, latitu, nilai4, -18, -18, fajr, sunRise, zuhr, asr, maghrib, isha);
  doubleToHrMin(fajr, hours, minutes);
  getDateDs1307() ;
if(hour==hours)
{
  if(minute==minutes)
  {
    if(second==0)
    {
      leng1=true;
    }
  }
}

doubleToHrMin(zuhr, hours, minutes);
if(hour==hours)
{
  if(minute==minutes)
  {
    if(second==0)
    {
      leng2=true;
    }
  }
}

doubleToHrMin(asr, hours, minutes);
if(hour==hours)
{
  if(minute==minutes)
  {
    if(second==0)
    {
      leng3=true;
    }
  }
}

doubleToHrMin(maghrib, hours, minutes);
if(hour==hours)
{
  if(minute==minutes)
  {
    if(second==0)
    {
      leng4=true;
    }
  }
}

doubleToHrMin(isha, hours, minutes);
if(hour==hours)
{
  if(minute==minutes)
  {
    if(second==0)
    {
      leng5=true;
    }
  }
}
  unsigned long currentMillis = millis();
  
  //lcd.print(latitu);
  
  if(currentMillis - previousMillis > interval) {
  // save the last time you printed and updated

  previousMillis = currentMillis;
//  TV.delay(1);
//  printTime();
//tampil();

//delay(50);

  //read RTC
  
}

bell();
}
  
