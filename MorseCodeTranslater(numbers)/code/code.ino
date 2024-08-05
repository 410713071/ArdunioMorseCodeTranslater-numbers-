int ledPin = 10;
int val;

int x=100;//時間乘數
int ticShort = 2*x;
int ticLong = 10*x;
int space = 5*x;
//定義長短tic 的時間以及間隔



void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);//定義小燈為輸出

}
void loop()
{
 
  val=Serial.read();

  if (val=='S'){
    Serial.print("\n");
    //S指令為space換行
  }

  
  if (val > 40 && val<80)
  {
    Serial.print(val-48);//0=48
    if(val<54)
    {
        for (int i =0;i<(val-48);i++)
      {
      digitalWrite(ledPin, HIGH); 
      delay(ticShort); 
      digitalWrite(ledPin, LOW);
      delay(space); 
      }
      for (int i =0;i<(53-val);i++)
      {
      digitalWrite(ledPin, HIGH); 
      delay(ticLong);
      digitalWrite(ledPin, LOW); 
      delay(space);
      }
    }
     if(val>53)
    {
        for (int i =0;i<(val-53);i++)
      {
      digitalWrite(ledPin, HIGH); 
      delay(ticLong); 
      digitalWrite(ledPin, LOW); 
      delay(space); 
      }
      for (int i =0;i<(58-val);i++)
      {
      digitalWrite(ledPin, HIGH); 
      delay(ticShort); 
      digitalWrite(ledPin, LOW); 
      delay(space); 
      }
    }

  }

}

