#include <SimpleSDAudio.h>

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  SdPlay.setSDCSPin(4);
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER))
    { while(1); }
    
  delay(4000); //wait for user to change the potentiometer
  int p_value = analogRead(A0);
  Serial.println(p_value);
  p_value = map(p_value, 1, 1023, 1, 5);
  Serial.println(p_value);
  switch (p_value)
  {
    case 1:
    if(!SdPlay.setFile("olivia.wav")) // music name file
    { while(1); }
    Serial.println("olivia.wav");
    break;
    case 2:
    if(!SdPlay.setFile("vanilla.wav")) // music name file
    { while(1); }
    Serial.println("vanilla.wav");
    break;
    case 3:
    if(!SdPlay.setFile("nier.wav")) // music name file
    { while(1); }
    Serial.println("nier.wav");
    break;
    case 4:
    if(!SdPlay.setFile("spoiler.wav")) // music name file
    { while(1); }
    Serial.println("spoiler.wav");
    break;
    default:
    Serial.println("switch statement fail");
  }

//  if(!SdPlay.setFile("deadd.wav")) // music name file
//    { while(1); }
  delay(3000); //3s
  Serial.println("setup done");
}

void loop() {
  SdPlay.play();
  Serial.println("play");
      while(!SdPlay.isStopped())
        { ; }
      delay(12000); // cooldown of 12s
}
