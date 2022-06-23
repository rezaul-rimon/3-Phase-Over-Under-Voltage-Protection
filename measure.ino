 void measure()
 {
 
        if(micros() >= voltageLastSample + 1000 )                                                                    
          {
            voltageSampleRead = (analogRead(VoltageAnalogInputPin)- 512)+ voltageOffset1;                          
            voltageSampleSum = voltageSampleSum + sq(voltageSampleRead) ;                                            
                                                                                                  
          
          voltageSampleRead2 = (analogRead(VoltageAnalogInputPin2)- 512)+ voltageOffset1;
          voltageSampleSum2 = voltageSampleSum2 + sq(voltageSampleRead2) ;

          voltageSampleRead3 = (analogRead(VoltageAnalogInputPin3)- 512)+ voltageOffset1;
          voltageSampleSum3 = voltageSampleSum3 + sq(voltageSampleRead3) ;
          
          voltageSampleCount = voltageSampleCount + 1;
          voltageLastSample = micros() ;
          
          }
        
        if(voltageSampleCount == 1000)                                                                           
          {
            voltageMean = voltageSampleSum/voltageSampleCount;                                                       
            RMSVoltageMean = (sqrt(voltageMean))*1.5;                                                                     
            adjustRMSVoltageMean = RMSVoltageMean + voltageOffset2;                                                                                                                                                                                                       /* square root of the average value*/                                                                                                             
            FinalRMSVoltage = RMSVoltageMean + voltageOffset2;                                                       
            if(FinalRMSVoltage <= 20)                                                                                
            {FinalRMSVoltage = 0;}

            voltageMean2 = voltageSampleSum2/voltageSampleCount; 
            RMSVoltageMean2 = (sqrt(voltageMean2))*1.5;
            adjustRMSVoltageMean2 = RMSVoltageMean2 + voltageOffset2;
            FinalRMSVoltage2 = RMSVoltageMean2 + voltageOffset2;
            if(FinalRMSVoltage2 <= 20)
            {FinalRMSVoltage2 = 0;}

            voltageMean3 = voltageSampleSum3/voltageSampleCount; 
            RMSVoltageMean3 = (sqrt(voltageMean3))*1.5;
            adjustRMSVoltageMean3 = RMSVoltageMean3 + voltageOffset2;
            FinalRMSVoltage3 = RMSVoltageMean3 + voltageOffset2;
            if(FinalRMSVoltage3 <= 20)
            {FinalRMSVoltage3 = 0;}

           
             if(mode == true)
            {            
              lcd.setCursor(3,0);
              lcd.print("Mode: 3-Phase");
              
              lcd.setCursor(0,1);
              lcd.print("Upper="); 
              lcd.setCursor(7,1);
              lcd.print("   " );
              lcd.setCursor(7,1); 
              lcd.print(upperL);
          
              lcd.setCursor(11,1);
              lcd.print("Lower=");
              lcd.setCursor(17,1);
              lcd.print("   " ); 
              lcd.setCursor(17,1); 
              lcd.print(lowerL);

              lcd.setCursor(1,2);
              lcd.print("R=");
              lcd.setCursor(3,2);
              lcd.print("   " );
              lcd.setCursor(3,2);
              lcd.print(FinalRMSVoltage);

              lcd.setCursor(7,2);
              lcd.print("Y=");
              lcd.setCursor(9,2);
              lcd.print("   " );
              lcd.setCursor(9,2);
              lcd.print(FinalRMSVoltage2);

              lcd.setCursor(13,2);
              lcd.print("B=");
              lcd.setCursor(15,2);
              lcd.print("   " );
              lcd.setCursor(15,2);
              lcd.print(FinalRMSVoltage3);

              
              if(((FinalRMSVoltage <= upperL) && (FinalRMSVoltage >= lowerL)) && ((FinalRMSVoltage2 <= upperL) && (FinalRMSVoltage2 >= lowerL)) && ((FinalRMSVoltage3 <= upperL) && (FinalRMSVoltage3 >= lowerL)))
              {

              lcd.setCursor(0,3);
              lcd.print("                    ");
              lcd.setCursor(1,3);
              lcd.print("Voltage is Normal");

              digitalWrite(0, LOW);
              digitalWrite(1, LOW);
              digitalWrite(2, LOW);
             
                
              }

              else
              {
                  if(FinalRMSVoltage > upperL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(8,3);
                    lcd.print("  ");
                    lcd.setCursor(8,3);
                    lcd.print("R=");
                    lcd.setCursor(10,3);
                    lcd.print("O ");             
                  }
                  else if(FinalRMSVoltage < lowerL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(8,3);
                    lcd.print("  ");
                    lcd.setCursor(8,3);
                    lcd.print("R=");
                    lcd.setCursor(10,3);
                    lcd.print("L ");
                  }
                  else
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(8,3);
                    lcd.print("  ");
                    lcd.setCursor(8,3);
                    lcd.print("R=");
                    lcd.setCursor(10,3);
                    lcd.print("N ");
                  }


                  if(FinalRMSVoltage2 > upperL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(12,3);
                    lcd.print("  ");
                    lcd.setCursor(12,3);
                    lcd.print("Y=");
                    lcd.setCursor(14,3);
                    lcd.print("O ");             
                  }
                  else if(FinalRMSVoltage2 < lowerL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(12,3);
                    lcd.print("  ");
                    lcd.setCursor(12,3);
                    lcd.print("Y=");
                    lcd.setCursor(14,3);
                    lcd.print("L ");
                  }
                  else
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(12,3);
                    lcd.print("  ");
                    lcd.setCursor(12,3);
                    lcd.print("Y=");
                    lcd.setCursor(14,3);
                    lcd.print("N ");
                  }


                  if(FinalRMSVoltage3 > upperL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(16,3);
                    lcd.print("  ");
                    lcd.setCursor(16,3);
                    lcd.print("B=");
                    lcd.setCursor(18,3);
                    lcd.print("O ");             
                  }
                  else if(FinalRMSVoltage3 < lowerL)
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(16,3);
                    lcd.print("  ");
                    lcd.setCursor(16,3);
                    lcd.print("B=");
                    lcd.setCursor(18,3);
                    lcd.print("L ");
                  }
                  else
                  {
                    lcd.setCursor(0,3);
                    lcd.print("        ");
                    lcd.setCursor(1,3);
                    lcd.print("Fault!");
                    lcd.setCursor(16,3);
                    lcd.print("  ");
                    lcd.setCursor(16,3);
                    lcd.print("B=");
                    lcd.setCursor(18,3);
                    lcd.print("N ");
                  }

                  digitalWrite(0, HIGH);
                  digitalWrite(1, HIGH);
                  digitalWrite(2, HIGH);
              }              
                        
            }

            else if (mode == false)
            {

              digitalWrite(1, HIGH);
              digitalWrite(2, HIGH);

              lcd.setCursor(3,0);
              lcd.print("Mode: 1-Phase");
              
              lcd.setCursor(0,1);
              lcd.print("Upper="); 
              lcd.setCursor(7,1);
              lcd.print("   " );
              lcd.setCursor(7,1); 
              lcd.print(upperL);
          
              lcd.setCursor(11,1);
              lcd.print("Lower=");
              lcd.setCursor(17,1);
              lcd.print("   " ); 
              lcd.setCursor(17,1); 
              lcd.print(lowerL);

              lcd.setCursor(1,2);
              lcd.print("Supply Voltage=");
              lcd.setCursor(16,2);
              lcd.print("   " );
              lcd.setCursor(16,2);
              lcd.print(FinalRMSVoltage);
              
              if(FinalRMSVoltage > upperL)
              {
              digitalWrite(0, HIGH);
              lcd.setCursor(0,3);
              lcd.print("                    ");
              lcd.setCursor(3,3);
              lcd.print("Over Voltage!!");
              }

              else if(FinalRMSVoltage < lowerL)
              {
              digitalWrite(0, HIGH);
              lcd.setCursor(0,3);
              lcd.print("                    ");
              lcd.setCursor(4,3);
              lcd.print("Low Voltage!!");
              }

              else if((FinalRMSVoltage >= lowerL) && (FinalRMSVoltage <= upperL))
              {
              digitalWrite(0, LOW);
              lcd.setCursor(0,3);
              lcd.print("                    ");
              lcd.setCursor(1,3);
              lcd.print("Voltage is Normal");
              }
              
            }

            voltageSampleSum =0;                                                                                              
            voltageSampleSum2 =0;
            voltageSampleSum3 =0; 

            
            voltageSampleCount=0;                                                                                     
          }
 }

 
