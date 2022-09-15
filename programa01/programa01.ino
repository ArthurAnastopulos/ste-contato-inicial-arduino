volatile int botao = 0;
int led = 0;

enum State_t
{
  OFF = 0,
  E1 = 1,
  ON = 2,
  E2 = 3
};
State_t state = OFF;

void botao_isr()
{
  static unsigned long ultima_interrupcao = 0;
  static unsigned long tempo_botao = 25;

  unsigned long agora = millis();

  if ((agora - ultima_interrupcao) >= tempo_botao )
  {
    Serial.println("b");
    botao = 1;
    ultima_interrupcao = agora;
  }
}

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);

  state = OFF;
  Serial.println("OFF");

  attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
}

void loop()
{
  // Atualiza entradas
  noInterrupts();
  int b = botao;
  botao = 0;
  interrupts();

  // Atualiza máquina de estados
  switch (state)
  {
    case OFF:
      if (b == 1)
      {
        state = E1;
        Serial.println("E1");
        attachInterrupt(digitalPinToInterrupt(2), botao_isr, FALLING);
        led = 1;
      }
      break;

    case E1:
      if (b == 1)
      {
        state = ON;
        Serial.println("ON");
        attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
        led = 1;
      }
      break;

    case ON:
      if (b == 1)
      {
        state = E2;
        Serial.println("E2");
        attachInterrupt(digitalPinToInterrupt(2), botao_isr, FALLING);
        led = 0;
      }
      break;

    case E2:
      if (b == 1)
      {
        state = OFF;
        Serial.println("OFF");
        attachInterrupt(digitalPinToInterrupt(2), botao_isr, RISING);
        led = 0;
      }
      break;

    default: /* não deveria acontecer */
      break;
  }

  // Atualiza saídas
  digitalWrite(13, led);

  delay(25);
}
