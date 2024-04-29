// Gabriel Moya Ibarra - A01644106

const int pinTrigger = 2;
const int pinEcho = 3;
const int pinVibrator = 1;
float time = 0;
float distance = 0;

void setup() 
{
  // Setup pins 
  pinMode(pinTrigger, OUTPUT);  // Trigger is Output
  pinMode(pinEcho, INPUT);    // Echo receives a signal
  pinMode(pinVibrator, OUTPUT); // Vibrator is Output
  pinMode(LED_BUILTIN, OUTPUT); // Internal LED
  Serial.begin(9600);     // Init monitor @ 9600 bauds
}

void loop() 
{
  digitalWrite(pinTrigger, LOW);
  delayMicroseconds(4);
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrigger, LOW);

  // This is the part where calculations happen
  time = pulseIn(pinEcho, HIGH);    // Feed echo the pong time in ms
  distance = 0.0172 * time;       // Formula to calculate distance
  Serial.println("Distancia (cm)");
  Serial.println(distance);
  delay(50);

  // This is the ifs and elses part
  if (distance < 200) 
  {
    if (distance <= 90) 
    {
      digitalWrite(pinVibrator, HIGH);
      delay(4000);
      digitalWrite(pinVibrator, LOW);
      digitalWrite(LED_BUILTIN, LOW);
      delay(2000);
    } 
    else if (distance <= 50) 
    {
      digitalWrite(pinVibrator, HIGH);
      delay(4000);
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(pinVibrator, LOW);
      delay(2000);
    } 
    else if (distance <= 20) 
    {
      digitalWrite(pinVibrator, HIGH);
      delay(4000);
      digitalWrite(pinVibrator, LOW);
      digitalWrite(LED_BUILTIN, LOW);
      delay(2000);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    delay(distance * 10);
    digitalWrite(LED_BUILTIN, LOW);
    delay(distance * 10);
  } 
  else 
  {
    digitalWrite(pinVibrator, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
