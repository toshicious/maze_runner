int ena = 3;
int in1 = 6;
int in2 = 7;
int enb = 5;
int in3 = 9;
int in4 = 8;

float P;
float I;
float D;

float Kp = 0.3;
float Ki = 0.1;
float Kd = 0.05;

float previousError = 0;

int lfspeed = 60;
int rfspeed = 70;

int threshold = 700;


void linefollow()
{ //green () ;
  while ((analogRead(0) < threshold || analogRead(2) < threshold || analogRead(1) < threshold || analogRead(3) < threshold) || analogRead(4) < threshold)
  {
    PID();
  }
  digitalWrite(in1, 0);
  digitalWrite(in3, 0);
}
void PID()
{
  int lsp, rsp;
  int error = (analogRead(0)*1.5 + analogRead(1)) - (analogRead(3) + analogRead(4)*1.5);
  P = error;
  I = I + error;
  D = error - previousError;

  I = constrain(I, -100, 100);

  int PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;


  lsp = lfspeed - PIDvalue;
  rsp = rfspeed + PIDvalue;


  if (lsp > 120) {
    lsp = 120;
  }
if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 120) {
    rsp = 120;
  }
  if (rsp < 0) {
    rsp = 0;
  }
  // Serial.println(rsp);

  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  // Serial.println("Lsp : ");
  // Serial.println(lsp);
  analogWrite(ena, lsp);
  analogWrite(enb,rsp);
}


void setup() {
    Serial.begin(9600); // Start serial communication

  // put your setup code here, to run once:
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  linefollow();
}
