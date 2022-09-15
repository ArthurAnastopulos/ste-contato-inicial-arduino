
volatile int btn_scale = 0;
volatile int btn_hold = 0;

static unsigned long ultima_interrupcao = 0;
static unsigned long tempo_botao = 500;
unsigned long int agora;
unsigned int a0;

int last_check = 1;

enum State_t
{
  Wait = 0,
  E1 = 1,
  V = 2,
  mV = 3,
  E2 = 4
};

State_t state = Wait;

unsigned int scale_ = 0;

void scale()
{ 
  scale_ = !scale_;
}

void setup() 
{
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  state = Wait;
  attachInterrupt(digitalPinToInterrupt(2), scale, RISING);
  Serial.println("Setup");
  Serial.begin(9600); // open serial port to host
}

void loop() 
{
  noInterrupts();
  int b_scale = btn_scale;
  btn_scale = 0;
  interrupts();

  btn_hold = digitalRead(8);
  switch(state)
  {
    case Wait:
      agora = millis();
      if((agora - ultima_interrupcao) >= tempo_botao){
        Serial.println("Atingiu o Tempo de Espera");
        state = E1;
        ultima_interrupcao = agora;
      }
      break;
    case E1:
      if(b_scale == 1) //Inicialmente em Volts
      {
        if(scale_ == 0)
        {
          //Serial.println("E1  - V");
          state = V;
        }
        else
        {
          //Serial.println("E1 - mV");
          state = mV;
        }
      }
      else
      {
        if(scale_ == 0)
        {
          //Serial.println("E1  - V");
          state = V;
        }
        else
        {
          //Serial.println("E1 - mV");
          state = mV;
        }
      }
      break;
    case V:
      Serial.println("V");
      a0 = analogRead(A0);
      Serial.println( ( (float) a0) * (5.0/1023.0) );
      if(btn_hold == 1)
      {
        state = E2;
      }
      else
      {
        state = Wait;
      }
      break;
    case mV:
      Serial.println("mV");
      a0 = analogRead(A0);
      Serial.println( (float) ((( (long) a0) * ( (long) 5000000 / (long) 1023))/100) );
      if(btn_hold == 1)
      {
        state = E2;
      }
      else 
      {
        state = Wait;
      }
      break;
    case E2:
      while(btn_hold == 1){
        //hold
        if(last_check == 0) break;
        last_check = digitalRead(8);
      }
      if(btn_hold == 0)state = Wait;
      break;
  }

  delay(500);
}
