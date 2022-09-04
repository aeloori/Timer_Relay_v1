#define refLed 1
#define out 2
#define button 3
void setup()
{
  pinMode(out,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}
void loop()
{
  buttonCount();  
  relay();
  digitalWrite(refLed,HIGH);
}

// Takes input to select the mode by using count
int buttonCount()
{
  int count=0;
  for(int i=0;i<4;i++)
  {
    if(button==HIGH)
    {
      count++;
    }
    delay(400);
//    if(count>4)
//    {
//      break;
//    }
    if(button!=HIGH)
    {
      delay(1000);
      break;
    }
  }
  return count;
}

// Turn's on the relay and turn off the relay after desired time

void relay()
{
  int count =buttonCount();
  switch(count)
  {
    case 1:
    {
      digitalWrite(out,HIGH);
      for(int i=0;i<900;i++)
      {
        delay(1000);
      }
      digitalWrite(out,LOW);
    }
    case 2:
    {
      digitalWrite(out,HIGH);
      for(int i=0;i<=1800;i++)
      {
        delay(1000);
      }
      digitalWrite(out,LOW);
    }
    case 3:
    {
      digitalWrite(out,HIGH);
      for(int i=0;i<=3600;i++)
      {
        delay(1000);
      }
      digitalWrite(out,LOW);
    }
    case 4:
    {
      digitalWrite(out,HIGH);
      for(int i=0;i<=5400;i++)
      {
        delay(1000);
      }
      digitalWrite(out,HIGH);
    }
  }
}