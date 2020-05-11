void bell()
{
  nilai5=EEPROM.read(alamat5);
  if(nilai5==1)
  {
    if(leng1==true)
    {
      Serial.print("a");
      leng1=false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
      lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("   Waktunya Untuk   ");
      lcd.setCursor(0,3);
      lcd.print("    Sholat Subuh    ");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      delay(5000);
  lcd.clear();
    }
    if(leng2==true)
    {
      //Serial.print("a");
      leng2=false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
      lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("   Waktunya Untuk   ");
      lcd.setCursor(0,3);
      lcd.print("    Sholat Zuhur    ");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
  delay(5000);
  lcd.clear();
    }
    if(leng3==true)
    {
      //Serial.print("a");
      leng3=false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
      lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("   Waktunya Untuk   ");
      lcd.setCursor(0,3);
      lcd.print("    Sholat Ashar    ");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
  delay(5000);
  lcd.clear();
    }
    if(leng4==true)
    {
      Serial.print("b");
      leng4=false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
      lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("   Waktunya Untuk   ");
      lcd.setCursor(0,3);
      lcd.print("   Sholat Maghrib   ");
      digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
  delay(5000);
  lcd.clear();
    }
    if(leng5==true)
    {
      //Serial.print("a");
      leng5=false;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("-Jam + Waktu Shalat-");
      lcd.setCursor(0,1);
      lcd.print("-->> YOGYAKARTA <<--");
      lcd.setCursor(0,2);
      lcd.print("   Waktunya Untuk   ");
      lcd.setCursor(0,3);
      lcd.print("    Sholat  Isya    ");
     digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
       digitalWrite(buzzer, HIGH);
      delay(2000);
      digitalWrite(buzzer, LOW);
      delay(1000);
  delay(5000);
  lcd.clear();
    }
  }
}
