/*
  This code is for the Project of "3-Phase and 1-Phase
  Under and Over Voltage Protection with some Advance Features"
  This code is developed by Md. Rezaul Islam Khan, in Nov 2021.
*/

#include<LiquidCrystal.h>
#include<math.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4); 

        bool mode;
        int upperL;
        int lowerL;
        int timer=6;       
        
        int decimalPrecision = 2;                  
        
        int VoltageAnalogInputPin = A2;             
        int VoltageAnalogInputPin2 = A0;
        int VoltageAnalogInputPin3 = A1;
        
        float voltageSampleRead  = 0;              
        float voltageSampleRead2  = 0;
        float voltageSampleRead3  = 0;
        
        float voltageLastSample  = 0;               
        float voltageLastSample2  = 0;
        float voltageLastSample3  = 0;
        
        float voltageSampleSum   = 0;               
        float voltageSampleSum2   = 0;
        float voltageSampleSum3   = 0;
        
        float voltageSampleCount = 0;              
        float voltageSampleCount2 = 0;
        float voltageSampleCount3 = 0;
        
        float voltageMean ;                         
        float voltageMean2 ;
        float voltageMean3 ;
        
        float RMSVoltageMean ;                     
        float RMSVoltageMean2 ;
        float RMSVoltageMean3 ;
        
        float adjustRMSVoltageMean;
        float adjustRMSVoltageMean2;
        float adjustRMSVoltageMean3;
                
        int FinalRMSVoltage;                     
        int FinalRMSVoltage2;
        int FinalRMSVoltage3;
        
        float voltageOffset1 =0.00 ;          
                                                            
        float voltageOffset2 = 0.00;          

void setup() {
 
  lcd.begin(20, 4);
  pinMode(VoltageAnalogInputPin, INPUT);
  pinMode(VoltageAnalogInputPin2, INPUT);
  pinMode(VoltageAnalogInputPin3, INPUT);

  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT_PULLUP);

  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);

  lcd.clear();
  for(int i=0; i<400; i++)
  {
    
    lcd.setCursor(0,0);
    lcd.print("Please set the Mode");
    lcd.setCursor(5,1);
    lcd.print("1-P or 3-P");

    if(digitalRead(A5)==0)
    {
      mode = true;
      lcd.setCursor(2,2);
      lcd.print("Current Mode: ");  
      lcd.print("3-P");
    }

    else if(digitalRead(A5)==1)
    {
    mode = false;
    lcd.setCursor(2,2);
    lcd.print("Current Mode: ");  
    lcd.print("1-P");
    }

      lcd.setCursor(5,3);
      lcd.print("Timer: ");
      lcd.print(timer);

    if(i%79 == 0)
    {
      timer--;   
    }
     
  delay(10);
  }


  lcd.clear();
  timer=11;
  for(int i=0; i<800; i++)
  {
    
      lcd.setCursor(0,0);
      lcd.print(" Please set Voltage");
      lcd.setCursor(2,1);
      lcd.print("Upper and Lower");

      upperL=analogRead(A3);
      upperL=upperL/4;
      if(upperL<190) upperL=190;
      lowerL=analogRead(A4);
      lowerL=lowerL/4;
      if(lowerL>180) lowerL=180;
    
      lcd.setCursor(0,2);
      lcd.print("Upper="); 
      lcd.setCursor(7,2);
      lcd.print("   ");
      lcd.setCursor(7,2);
      lcd.print(upperL);
  
      
      lcd.setCursor(11,2);
      lcd.print("Lower=");
      lcd.setCursor(17,2);
      lcd.print("   "); 
      lcd.setCursor(17,2); 
      lcd.print(lowerL);
    
      lcd.setCursor(5,3);
      lcd.print("Timer: ");
      lcd.setCursor(12,3);
      lcd.print("   ");
      lcd.setCursor(12,3);
      lcd.print(timer);

    if(i%79 == 0)
    {
      timer--;   
    }
     
  delay(10);
  }
  
lcd.clear();
lcd.setCursor(0,0);

}
     
void loop() 

{
  measure();

}
