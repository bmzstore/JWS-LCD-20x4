void babol()
{
  //delay(50);
  poskanan = digitalRead(kanan);
  poskiri = digitalRead(kiri);
  posenter = analogRead(enter);
  posatas = digitalRead(atas);
  posbawah = digitalRead(bawah);
}

void cektombol()
{
  awal:
  babol();
//  if(posenter>=900)
//  {
//    Serial.print("a");
//    delay(2000);
//  }
  if(posbawah!=lasbawah)
  {
    if(posbawah==HIGH)
    {
      tombol();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
    lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("Titik Koordinat");
      lcd.setCursor(0,3);
      lcd.print("Latit");
      delay(500);
      babol();
      while(posenter<=500)
      {
        sim=EEPROM.read(alamat1);
        nilai2=EEPROM.read(alamat2);
        nilai3=EEPROM.read(alamat3);
        //lat=EEPROM.readFloat(20);
//        double lats=lat;
//        double sisa=lat-lats;
        //lcd.print(lat);
        delay(100);
        babol();
        lcd.setCursor(8,3);
        if(sim==1)
        {
          
          lcd.print("+");
        }
        else lcd.print("-");
        
        if(posatas==HIGH)
        {
          sim++;
          if(sim>1)sim=0;
          EEPROM.write(alamat1,sim);
        }
        
        //lcd.setCursor(10,1);
        lcd.print(nilai2);
        if(poskiri==HIGH)
        {
          nilai2++;
          if(nilai2>90)nilai2=0;
        }
        lcd.print(".");
        
        if(poskanan==HIGH)
        {
          nilai3++;
          
          
          if(nilai3>99)nilai3=0;
        }
        if(nilai3<10)lcd.print("0");
        lcd.print(nilai3);
          lcd.print("   ");
        EEPROM.write(alamat1,sim);
        EEPROM.write(alamat2,nilai2);
        EEPROM.write(alamat3,nilai3);
        
        //if(posenter>=900)
        
        //EEPROM.writeFloat(20,lat);
        
        if(posenter>=900)
        {
              lcd.setCursor(0,3);
         //lcd.clear();
      lcd.print("Longi   ");
      tombol();
      delay(500);
      babol();
      while(posenter<=500)
      {
        
        nilai6=EEPROM.read(alamat6);
        nilai7=EEPROM.read(alamat7);
        nilai8=EEPROM.read(alamat8);
        delay(100);
        babol();
        lcd.setCursor(8,3);
        if(nilai6==1) lcd.print("+");
        else lcd.print("-");
        if(posatas==HIGH)
        {
          nilai6++;
          if(nilai6>1)nilai6=0;
        }
        if(poskiri==HIGH)
        {
          nilai7++;
          if(nilai7>180)nilai7=0;
          
        }
        lcd.print(nilai7);
        lcd.print(".");
        if(poskanan==HIGH)
        {
          nilai8++;
          if(nilai8>99)nilai8=0;
        }
        if(nilai8<10)lcd.print("0");
        lcd.print(nilai8);
        lcd.print("   ");
        EEPROM.write(alamat6,nilai6);
        EEPROM.write(alamat7,nilai7);
        EEPROM.write(alamat8,nilai8);
        if(posenter>=900)
        {
          lcd.setCursor(0,3);
          lcd.print("Wkt.Bag.       ");
          tombol();
          delay(500);
          babol();
          while(posenter<=500)
          {
            nilai4=EEPROM.read(alamat4);
            delay(100);
            babol();
            if(posatas==HIGH)
            {
              nilai4++;
              if(nilai4>9)nilai4=7;
            }
            lcd.setCursor(8,3);
            if(nilai4==7)
            {
              lcd.print("Barat  ");
            }
            else if(nilai4==8)lcd.print("Tengah  ");
            else lcd.print("Timur  ");
            
            EEPROM.write(alamat4,nilai4);
          }
        }
        
      }
        }
        //delay(100);
      }
      
      
        
      
      
      lcd.clear();
      
      
     
    }
  }
  if(posatas!=lasatas)
  {
    if(posatas==HIGH)
    {
      tombol();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("-Jam + Waktu Shalat-");
    lcd.setCursor(0,1);
  lcd.print("-->> YOGYAKARTA <<--");
    lcd.setCursor(0,2);
    lcd.print("Aktifkan Adzan?");
    lcd.setCursor(0,3);
    lcd.print("Pilihan : ");
    
    while(posenter<=500)
    {
      babol();
      nilai5=EEPROM.read(alamat5);
      lcd.setCursor(10,3);
      if(nilai5==1)
      {
        lcd.print("Ya   ");
      }
      else
      {
        lcd.print("Tidak");
      }
      
      if(poskiri!=laskiri)
      {
        if(poskiri==HIGH)
        {
        tombol();
        nilai5--;
        if(nilai5<0)
        {
          nilai5=1;
        }
      }
      }
      if(poskanan!=laskanan)
      {
        if(poskanan==HIGH)
        {
        tombol();
        nilai5++;
        if(nilai5>1)
        {
          nilai5=0;
        }
        }
      }
      laskiri=poskiri;
      laskanan=poskanan;
      EEPROM.write(alamat5,nilai5);
      delay(150);
      
      }
       lasbawah=posbawah;
  lasatas=posatas;
  laskiri=poskiri;
  laskanan=poskanan;
    }
    tombol();
    babol();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("-Jam + Waktu Shalat-");
    lcd.setCursor(0,1);
   lcd.print("-->> YOGYAKARTA <<--");
    lcd.setCursor(0,2);
    lcd.print("    Suara  Adzan    ");
    lcd.setCursor(0,3);
    nilai5=EEPROM.read(alamat5);
    if(nilai5==1)
    lcd.print("       Aktif        ");
    else
    lcd.print("    Tidak  Aktif    ");
    
    delay(3000);
    lcd.clear();
    }
    
    if(poskiri!=laskiri)
    {
      if(poskiri==HIGH)
      {
      tombol();
    delay(500);
    babol();
    while(posenter<=500)
    {
      getDateDs1307();
      lcdtam();
      delay(100);
      setjam();
      babol();
      
      if(poskanan==HIGH)
      {
        tombol();
        jamplus();
      }
      if(poskiri==HIGH)
      {
        tombol();
        jammin();
      }
      
      if(posenter>=900)
      {
        tombol();
        delay(500);
        babol();
        
        while(posenter<=500)
        {
          getDateDs1307();
          lcdtam();
          delay(100);
          setmin();
          babol();
          
          if(poskiri==HIGH)
          {
            tombol();
            menmin();
          }
          if(poskanan==HIGH)
          {
            tombol();
            menplus();
          }
          if(posenter>=900)
          {
            tombol();
            
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("--------------------");
            lcd.setCursor(0,1);
            lcd.print("      Berhasil      ");
            lcd.setCursor(0,2);
            lcd.print("     Dicky B_Mz     ");
            lcd.setCursor(0,3);
            lcd.print("--------------------");
            //sukses();
            delay(2000);
            babol();
            lcd.clear();
            goto awal;
          }
          delay(100);
        }
         tombol();
        delay(100);
        babol();
      }
      
      //setjam();
    delay(100);
    }
     tombol();
      }
      
      lasbawah=posbawah;
  lasatas=posatas;
  laskiri=poskiri;
  laskanan=poskanan;
    }
    
  if(poskanan==HIGH)
  {
    tombol();
    delay(500);
    babol();
    while(posenter<=500)
    {
      getDateDs1307();
          lcdtam();
          delay(100);
          setbul();
          babol();
          if(poskiri==HIGH)
          {
            tombol();
            month--;
            if(month<1)
            {
              month=12;
            }
            
          }
          if(poskanan==HIGH)
          {
            tombol();
            month++;
            if(month>12)
            {
              month=1;
            }
          }
          setDateDs1307();
          if(posenter>=900)
          {
            tombol();
            delay(500);
            babol();
            
            while(posenter<=500)
            {
              getDateDs1307();
          lcdtam();
          delay(100);
          setang();
          suit();
          babol();
          if(poskiri==HIGH)
          {
            tombol();
            dayOfMonth--;
            if(dayOfMonth<1)
            {
              dayOfMonth=xx;
            }
          }
          
          if(poskanan==HIGH)
          {
            tombol();
            dayOfMonth++;
            if(dayOfMonth>xx)
            {
              dayOfMonth=1;
            }
          }
          setDateDs1307();
          if(posenter>=900)
          {
            tombol();
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("-Jam + Waktu Shalat-");
            lcd.setCursor(0,1);
          lcd.print("-->> YOGYAKARTA <<--");
            lcd.setCursor(0,2);
            lcd.print("setTahun : ");
            lcd.setCursor(0,3);
            lcd.print("setHari  : ");
            delay(500);
            babol();
            while(posenter<=500)
            {
            getDateDs1307();
            char buf[12];
            lcd.setCursor(12,2);
            lcd.print("20");
            lcd.print(itoa(year,buf,10));
            eet();
            delay(100);
            lcd.setCursor(10,2);
            lcd.print("      ");
            babol();
            
            if(poskiri==HIGH)
            {
              tombol();
              year--;
              if(year<15)
              {
                year=99;
              }
              
            }
            if(poskanan==HIGH)
            {
              tombol();
              year++;
              if(year>99)
              {
                year=15;
              }
            }
            setDateDs1307();
            if(posenter>=900)
            {
              tombol();
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("-Jam + Waktu Shalat-");
              lcd.setCursor(0,1);
              lcd.print("-->> YOGYAKARTA <<--");
              lcd.setCursor(0,2);
              lcd.print("setTahun : ");
              lcd.setCursor(0,3);
              lcd.print("setHari  : ");
              delay(500);
              babol();
                while(posenter<500)
                {
                  getDateDs1307();
                  char buf[12];
                  lcd.setCursor(12,2);
                  lcd.print("20");
                  lcd.print(itoa(year,buf,10));
                  eet();
                  delay(100);
                  lcd.setCursor(10,3);
                  lcd.print("      ");
                  babol();
                  if(poskiri==HIGH)
                  {
                    tombol();
                    dayOfWeek--;
                    if(dayOfWeek<1)
                    {
                      dayOfWeek=7;
                    }
                  }
                  if(poskanan==HIGH)
                  {
                    tombol();
                    dayOfWeek++;
                    if(dayOfWeek>7)
                    {
                      dayOfWeek=1;
                    }
                  }
                  setDateDs1307();
                  if(posenter>=900)
                  {
                    tombol();
           
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("--------------------");
            lcd.setCursor(0,1);
            lcd.print("      Berhasil      ");
            lcd.setCursor(0,2);
            lcd.print("     Dicky B_Mz     ");
            lcd.setCursor(0,3);
            lcd.print("--------------------");
            //sukses();
            delay(2000);
             babol();
            lcd.clear();
            goto awal;
                    
                  }
                  delay(100);
                }
                tombol();
                babol();
            }
            delay(100);
            }
            
          }
          delay(100);
            }
            
          }
          delay(100);
    }
  }
  
  lasbawah=posbawah;
  lasatas=posatas;
  laskiri=poskiri;
  laskanan=poskanan;
}

void tombol()
{
  tone(8,900,2);

}
void setjam()
{
  lcd.setCursor(0,2);
  lcd.print("  ");
}

void jamplus()
{
  hour++;
  if(hour > 23)
  {
   hour = 0; 
   
  }
  
  setDateDs1307();
  
}

void jammin()
{
  hour--;
  if(hour < 0)
  {
   hour = 23; 
   
  }
  
  setDateDs1307();
  
}

void setmin()
{
  lcd.setCursor(3,2);
  lcd.print("  ");
}

void menmin()
{
  minute--;
  if(minute<0)
  {
    minute=59;
  }
  setDateDs1307();
}

void menplus()
{
  minute++;
  if(minute>59)
  {
    minute=0;
  }
 setDateDs1307();
}

void setbul()
{
  lcd.setCursor(14,2);
  lcd.print("  ");
}

void setang()
{
  lcd.setCursor(11,2);
  lcd.print("  ");
}

void suit()
{
  switch (month)
  {
  case 1:
    xx=31;
    break;
  case 2:
    if (year%4==0)
    {
      if(year%100==0)
      {
        if(year%400==0)
        {
          xx=29;
        }
        else
          xx=28;
      }
      else
        xx=29;
    }
    else
      xx=28;
    break;
  case 3:
    xx=31;
    break;
  case 4:
    xx=30;
    break;
  case 5:
    xx=31;
    break;
  case 6:
    xx=30;
    break;
  case 7:
    xx=31;
    break;
  case 8:
    xx=31;
    break;
  case 9:
    xx=30;
    break;
  case 10:
    xx=31;
    break;
  case 11:
    xx=30;
    break;
  case 12:
    xx=31;
    break;

  }
}

void eet()
{
  switch (dayOfWeek)
  {
    case 1:
    lcd.setCursor(11,3);
    lcd.print("Senin");
    break;
    case 2:
    lcd.setCursor(10,3);
    lcd.print("Selasa");
    break;
    case 3:
    lcd.setCursor(12,3);
    lcd.print("Rabu");
    break;
    case 4:
    lcd.setCursor(11,3);
    lcd.print("Kamis");
    break;
    case 5:
    lcd.setCursor(11,3);
    lcd.print("Jumat");
    break;
    case 6:
    lcd.setCursor(11,3);
    lcd.print("Sabtu");
    break;
    case 7:
    lcd.setCursor(10,3);
    lcd.print("Minggu");
    break;
  }
}
