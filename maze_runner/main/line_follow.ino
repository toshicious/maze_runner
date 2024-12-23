void linefollow()
{
  previousError = 0;
  error = 0;
  paths = 0;
  while ( (analogRead(0) < threshold && analogRead(7) < threshold) && (analogRead(1) > threshold || analogRead(2) > threshold || analogRead(3) > threshold || analogRead(4) > threshold || analogRead(5) > threshold || analogRead(6) > threshold))
  {
    PID();
  }
  digitalWrite(ain1, 0);
  digitalWrite(ain2, 0);
  digitalWrite(bin1, 0);
  digitalWrite(bin2, 0);
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

  if (lsp > 60) {
    lsp = 60;
  }
if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > 60) {
    rsp = 60;
  }
  if (rsp < 0) {
    rsp = 0;
  }
  digitalWrite(stby, HIGH);
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, HIGH);
  digitalWrite(ain2, LOW);
  digitalWrite(bin2, LOW);
  analogWrite(pwma, lsp);
  analogWrite(pwmb,rsp);
}
