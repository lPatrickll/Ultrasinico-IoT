class Ultrasonico 
{
  private:
    int triggerPin;
    int echoPin;

  public:
    Ultrasonico(int triggerPin, int echoPin) 
    {
      this->triggerPin = triggerPin;
      this->echoPin = echoPin;
      pinMode(triggerPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }

    long leerDistancia() 
    {
      digitalWrite(triggerPin, LOW);
      delayMicroseconds(2);
      digitalWrite(triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin, LOW);
      return pulseIn(echoPin, HIGH);
    }
};

class Leds 
{
  private:
    int* leds;
    int numLeds;

  public:
    Leds(int* leds, int numLeds) 
    {
      this->leds = leds;
      this->numLeds = numLeds;
      for(int i = 0; i < numLeds; i++) 
      {
        pinMode(leds[i], OUTPUT);
      }
    }

    void encender(int led) 
    {
      digitalWrite(led, HIGH);
    }

    void apagar(int led) 
    {
      digitalWrite(led, LOW);
    }
};

int leds[] = {12, 27, 26, 25, 33, 32, 22, 23};
Ultrasonico sensorUltrasonico(4, 2);
Leds ledsControl(leds, 8);

void setup() 
{
}

void loop() 
{
  float distanciaCentimetros = 0.01723 * sensorUltrasonico.leerDistancia();

  if (distanciaCentimetros <= 10) 
  {
    for (int i = 0; i < 8; i++) 
    {
      if (leds[i] == 12 || leds[i] == 27) 
      {
        ledsControl.encender(leds[i]);
        delay(500);
      }
      ledsControl.apagar(leds[i]);
    }
  }

  if (distanciaCentimetros > 10 && distanciaCentimetros <= 30) 
  {
    for (int i = 0; i < 8; i++) 
    {
      if (leds[i] > 24 && leds[i] < 27) 
      {
        ledsControl.encender(leds[i]);
        delay(500);
      }
      ledsControl.apagar(leds[i]);
    }
  }

  if (distanciaCentimetros > 30 && distanciaCentimetros <= 60) 
  {
    for (int i = 0; i < 8; i++) 
    {
      if (leds[i] > 31) 
      {
        ledsControl.encender(leds[i]);
      } 
      else 
      {
        ledsControl.apagar(leds[i]);
      }
    }
  }

  if (distanciaCentimetros > 60) 
  {
    for (int i = 0; i < 8; i++) 
    {
      if (leds[i] > 21 && leds[i] < 24) 
      {
        ledsControl.encender(leds[i]);
      } 
      else 
      {
        ledsControl.apagar(leds[i]);
      }
    }
  }
}