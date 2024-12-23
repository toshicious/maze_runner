#define pwma 3
#define pwmb 5
#define ain1 6
#define ain2 7
#define bin1 9
#define bin2 8
#define stby 4

int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;

float Kp = 0.09;
float Ki = 0.0;
float Kd = 0.0;


int lfspeed = 120;
int rfspeed = 120;

int threshold = 100;


void linefollow()
{
  while (analogRead(1) > threshold || analogRead(2) > threshold || analogRead(3) > threshold || analogRead(4) > threshold || analogRead(5) > threshold || analogRead(6) > threshold)
  {
    PID();
  }
  digitalWrite(ain1, 0);
  digitalWrite(ain2, 0);
}
void PID()
{
  int error = (analogRead(1)*3 + analogRead(2)*2 + analogRead(3)) - (analogRead(4) + analogRead(5)*2 + analogRead(6)*3);
  P = error;
  I = I + error;
  D = error - previousError;

  I = constrain(I, -1000, 1000);

  int PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = rfspeed + PIDvalue;

  if (lsp > 180) {
    lsp = 180;
  }
if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 180) {
    rsp = 180;
  }
  if (rsp < 0) {
    rsp = 0;
  }
  digitalWrite(stby, HIGH);
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, HIGH);
  analogWrite(pwma, lsp);
  analogWrite(pwmb,rsp);
}


void setup() {
    Serial.begin(9600);

  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin2, OUTPUT);
}

void loop() {
  linefollow();
}
