int ena = 3;
int enb = 5;
int in1 = 6;
int in2 = 7;
int in3 = 9;
int in4 = 8;

int P, D, I, previousError, PIDvalue, error;
int lsp, rsp;

float Kp = 0.05;
float Ki = 0.0;
float Kd = 0.0;


int lfspeed = 60;
int rfspeed = 60;

int threshold = 400;


void linefollow()
{
  while (analogRead(2) > threshold || analogRead(1) > threshold || analogRead(3) > threshold)
  {
    PID();
  }
  digitalWrite(in1, 0);
  digitalWrite(in3, 0);
}
void PID()
{
  int error = (analogRead(0)*1.5 + analogRead(1)) - (analogRead(3) + analogRead(4)*1.5);
  P = error;
  I = I + error;
  D = error - previousError;

  I = constrain(I, -1000, 1000);

  int PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = rfspeed + PIDvalue;

  if (lsp > 90) {
    lsp = 90;
  }
if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 90) {
    rsp = 90;
  }
  if (rsp < 0) {
    rsp = 0;
  }

  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  analogWrite(ena, lsp);
  analogWrite(enb,rsp);
}


void setup() {
    Serial.begin(9600);

  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  linefollow();
}
