
  int led1 = 10; // Pin 10
  int led2 = 11;
  int led;
  int input;
  void setup()
  {
    pinMode(9, OUTPUT);
      pinMode(led1, OUTPUT); // Set pin 13 as digital out
      pinMode(led2, OUTPUT);
     // Start up serial connectio
     Serial.begin(9600); // baud rate
     Serial.flush();
}
 void loop()
{      
     // Read any serial input
    // while (Serial.available() == 0);      
     
         input =  Serial.parseInt();
// //   Test sole run
//        analogWrite(led, HIGH);
//        Serial.print(led);
//  //   Serial.print(input);
  if (input>0){
  
      if (input==256||input==257)
      { if (input==256)
        led = led1;
       
       if (input==257)      
        led = led2;
      }
      
 else{
   Serial.print("set "+input);
  //brightness command 258 for 33% 33/100*255
   if (input==258)
    analogWrite(led,100 );
  //brightness command 259 for 66%
    if (input==259)
    analogWrite(led, 1255);
 
 
         analogWrite(led, input); // on
          if (input==500){  
     analogWrite(led1, 0);
        analogWrite(led2, 0);
          }
         //       digitalWrite(led, HIGH);
//        Serial.print(led);
//  //   Serial.print(input);
     }  
       Serial.print(led);
  //   Serial.print(input);
}
}
