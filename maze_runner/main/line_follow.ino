void linefollow()
{ 
  paths = 0;
  while ((analogRead(0) > threshold ) && (analogRead(4) > threshold ) && (analogRead(2) > threshold || analogRead(1) > threshold || analogRead(3) > threshold))
  {
    lfspeed = 70;
    PID();
  }
}
void PID()
{
  int error = analogRead(1) - analogRead(3);

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > 140) {
    lsp = 140;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 140) {
    rsp = 140;
  }
  if (rsp < 0) {
    rsp = 0;
  }

  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(9, lsp);
  analogWrite(10, rsp);
}
