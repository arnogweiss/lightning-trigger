// A. Weiss
// 2018-01-28

#define LED 5      // LED at pin 5
#define SENSOR 0   // photocell at ananog pin 0

int trigger = LOW;
float lastValue = 0.0;
float threshold = 1.33;
int lastTrigger = 0;
int delayUpdate = 1000; // 1 second
int resetTrigger = 500; // reset trigger after 1/2 second
int lastLoop = 0;

void setup() {
  // put your setup code here, to run once:
  lastTrigger = millis();
  lastLoop = lastTrigger;
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

/*
   Update the trigger.
   If reading > threshold * last reading, set trigger to HIGH.
   Reset trigger to LOW after resetTrigger ms.
   Ignore reading if last update is less than delayUpdate ago.
*/
void updateTrigger(int reading)
{
  float value = (float) reading;
  int t = millis();
  if (t < lastTrigger + delayUpdate)
  {
    if (t > lastTrigger + resetTrigger)
    {
      trigger = LOW;
    }
    // else do nothing
  }
  else if (value > lastValue * threshold)
  {
    trigger = HIGH;
    lastTrigger = t;
  }
  lastValue = value;
}

/*
   Get next reading from sensor and update trigger.
   Set LED to trigger value - LED lights up as long as trigger is triggered.
   Perform only every 1/100 sec (10 millis)
*/
void loop() {
  int t = millis();
  if (t - lastLoop < 10) {
    return;
  }
  lastLoop = t;
  int reading = analogRead(SENSOR);

  updateTrigger(reading);

  digitalWrite(LED, trigger);

  Serial.print("reading: ");
  Serial.print(reading);
  Serial.print(" - trigger: ");
  if (trigger == LOW)
  {
    Serial.print("LOW");
  } else
  {
    Serial.print("HIGH");
  }
  Serial.println("");
}
