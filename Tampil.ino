void lcdtam()
{
  
  int hours, minutes;
  lcd.setCursor(6,0);         //Penampil Jam
  lcd.print((hour%100)/10);
  lcd.print(hour%10);
  lcd.print(":");
  lcd.print((minute%100)/10);
  lcd.print(minute%10);
  lcd.print(":");
  lcd.print((second%100)/10);
  lcd.print(second%10);
  lcd.setCursor(9,2);

  lcd.setCursor(0,1); //penampil suhu
    lcd.print(0b11011111);
  lcd.setCursor(1,1); //penampil suhu
  lcd.print("Suhu:");
  lcd.print("28,5");
  lcd.write(0b11011111);
  lcd.print("C");
  lcd.print(" ");
  lcd.print("RH:");//penampil kelembapan
  lcd.print("54");
  lcd.print("%");

  lcd.setCursor(0,2);//penampil hari
  lcd.print(*dayOfTheWeek);
  lcd.print(" ");
 
  lcd.setCursor(12,2);          //Penampil Tanggal
  lcd.print((dayOfMonth%100)/10);
  lcd.print(dayOfMonth%10);
  lcd.print("/");
  lcd.print((month%100)/10);
  lcd.print(month%10);
  lcd.print("/");
  lcd.print((year%100)/1);
  lcd.print(year%1);

  
//  lcd.setCursor(0,1);
//  doubleToHrMin(maghrib, hours, minutes);
 //lcd.print(latitu);
  
  if(hitung>120)
  {
    hitung=0;
  }
  if(hitung>100)
  {
    lcd.setCursor(0,3);
    lcd.print("Isya'   ");
    doubleToHrMin(isha, hours, minutes);
    lcd.setCursor(12,3);
  lcd.print((hours%100)/10);
  lcd.print(hours%10);
  lcd.print(":");
  lcd.print((minutes%100)/10);
  lcd.print(minutes%10);
  lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  else if(hitung>80)
  {
    lcd.setCursor(0,3);
    lcd.print("Maghrib  ");
    doubleToHrMin(maghrib, hours, minutes);
    lcd.setCursor(12,3);
  lcd.print((hours%100)/10);
  lcd.print(hours%10);
  lcd.print(":");
  lcd.print((minutes%100)/10);
  lcd.print(minutes%10);
   lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  else if(hitung>60)
  {
    lcd.setCursor(0,3);
    lcd.print("Ashar   ");
    doubleToHrMin(asr, hours, minutes);
    lcd.setCursor(12,3);
  lcd.print((hours%100)/10);
  lcd.print(hours%10);
  lcd.print(":");
  lcd.print((minutes%100)/10);
  lcd.print(minutes%10);
   lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  else if(hitung>40)
  {
    lcd.setCursor(0,3);
    lcd.print("Dzuhur  ");
    doubleToHrMin(zuhr, hours, minutes);
    lcd.setCursor(12,3);
  lcd.print((hours%100)/10);
  lcd.print(hours%10);
  lcd.print(":");
  lcd.print((minutes%100)/10);
  lcd.print(minutes%10);
 lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  
  else if(hitung>20)
  {
    lcd.setCursor(0,3);
    lcd.print("Fajar  ");
    doubleToHrMin(fajr, hours, minutes);
    lcd.setCursor(12,3);
  lcd.print((hours%100)/10);
  lcd.print(hours%10);
  lcd.print(":");
  lcd.print((minutes%100)/10);
  lcd.print(minutes%10);
   lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  else if(hitung>0)
  {
    lcd.setCursor(0,3);
    lcd.print("Imsyak  ");
    doubleToHrMin(fajr, hours, minutes);
    int fahour=hours;
    int famin=minutes;
    famin=famin-10;
    if(famin<0)
    {
      famin=59-famin;
      fahour=fahour-1;
    }
    lcd.setCursor(12,3);
  lcd.print((fahour%100)/10);
  lcd.print(fahour%10);
  lcd.print(":");
  lcd.print((famin%100)/10);
  lcd.print(famin%10);
   lcd.setCursor(18,3);
  lcd.print(">>");
    lcd.setCursor(9,3);
  lcd.print("::");
  }
  
}
void tampil()
{
  int hours, minutes;
//har s[12];
  
  //doubleToHrMin(zuhr, hours, minutes);
  //doubleToHrMin(asr, hours, minutes);
  //doubleToHrMin(maghrib, hours, minutes);
  doubleToHrMin(isha, hours, minutes);
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
  
doubleToHrMin(maghrib, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    


doubleToHrMin(asr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
    doubleToHrMin(zuhr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
    doubleToHrMin(fajr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[year%10]);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(year%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[month%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(month%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[dayOfMonth%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(dayOfMonth%100)/10]);
    
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[second%10]);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(second%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minute%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minute%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hour%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hour%100)/10]); 
    
    digitalWrite(latchpin, HIGH);
    delay(500);
      doubleToHrMin(isha, hours, minutes);
    digitalWrite(latchpin, LOW);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
   
   
doubleToHrMin(maghrib, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
   
   
  doubleToHrMin(asr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
  
  doubleToHrMin(zuhr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]); 
    
    
    doubleToHrMin(fajr, hours, minutes);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minutes%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minutes%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hours%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hours%100)/10]);
    
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[year%10]);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(year%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[month%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(month%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[dayOfMonth%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(dayOfMonth%100)/10]);
    
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[second%10]);
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(second%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[minute%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(minute%100)/10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[hour%10]); 
    shiftOut(datapin, clockpin, LSBFIRST, segdisp[(hour%100)/10]-1); 
    
    digitalWrite(latchpin, HIGH);
    delay(500);

  //digitalWrite(latchpin, HIGH);
}
