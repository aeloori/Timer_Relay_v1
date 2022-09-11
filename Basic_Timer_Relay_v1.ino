#define setPin  13      //defining pin number 13 for setButton
#define relayPin  11    //defining Pin number for relay
#define modePin  12     //defining pin number 12 for mode pin

// variables will change:
int set = 0;         // variable for reading the pushbutton status
int mode=0;
int count =0;
int prestate =0;

void setup() {
  // initialize the relay pin as an output:
  pinMode(relayPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(setPin, INPUT);
  // initialize the pushbutton pin as an input:
  pinMode(modePin,INPUT);
  //setting baud rate for communication
  Serial.begin(9600);
}

void loop() {
  Counter();
  Serial.print("Mode number is :");
  Serial.println(count);
  Relay();
  Reset();
}

//Turning on relay for certain time
void Relay()
{
  switch(count)
  {
    //relay turned on for 10 mins (600 sec)
    case 1:
    {
      Serial.println("relay turned ON");
      digitalWrite(relayPin,HIGH);
      for(short t=1;t<10;t++)
      {
        delay(1000);
      }
      delay(1000);
      digitalWrite(relayPin,LOW);
      Serial.println("relay turned off");
      break;
    }

    //relay turned on for 30 mins (600 sec)
    case 2:
    {
      Serial.println("relay turned ON");
      digitalWrite(relayPin,HIGH);
      for(short t=1;t<30;t++)
      {
        delay(1000);
      }
      digitalWrite(relayPin,LOW);
      Serial.println("relay turned off");
      break;
    }

    
    case 3:
    {
      Serial.println("relay turned ON");
      digitalWrite(relayPin,HIGH);
      for(short t=1;t<60;t++)
      {
        delay(1000);
      }
      digitalWrite(relayPin,LOW);
      Serial.println("relay turned off");
      break;
    }

     case 4:
    {
      Serial.println("relay turned ON");
      digitalWrite(relayPin,HIGH);
      for(short t=1;t<90;t++)
      {
        delay(1000);
      }
      digitalWrite(relayPin,LOW);
      Serial.println("relay turned off");
      break;
    }
    default:
    {
      Serial.println("Select a mode to begin");
      break;
    }
  }
}


// Setting mode for the relay timer
void Counter()
{
  while(mode!=HIGH)
  {
    set=digitalRead(setPin);
    mode=digitalRead(modePin);
    if(set==HIGH && prestate==0)
    {
      count++;
        if(count>4)
           {
             count=1;
           }
      prestate++;
//      Serial.println(count);
      delay(100);
    }
    else if(set==LOW)
    {
      prestate=0;
    }

  }
}

void Reset()
{
  count=0;
  prestate=0;
  set=0;
  mode=0;
  Serial.print("count value is: ");
  Serial.println(count);
  Serial.print("prestate value is : ");
  Serial.println(prestate);
}
