void linefollow()
{ 
  paths = 0;
  while ((analogRead(0) < threshold ) && (analogRead(7) < threshold ) && (analogRead(1) > threshold) || analogRead(2) > threshold || analogRead(3) > threshold || analogRead(4) > threshold ||analogRead(5) > threshold ||analogRead(6) > threshold)
  {
    lfspeed = 70;
    PID();
  }
  digitalWrite(ain1, LOW);
  digitalWrite(bin1, LOW);
}
void PID()
{
  int error = (analogRead(1) + analogRead(2) + analogRead(3) ) - (analogRead(4) + analogRead(5) + analogRead(6) );

  P = error;
  I = I + error;
  D = error - previousError;

  PIDvalue = (Kp * P) + (Ki * I) + (Kd * D);
  previousError = error;

  lsp = lfspeed - PIDvalue;
  rsp = lfspeed + PIDvalue;

  if (lsp > maxspeed) {
    lsp = maxspeed;
  }
  if (lsp < 0) {
    lsp = 0;
  }
  if (rsp > maxspeed) {
    rsp = maxspeed;
  }
  if (rsp < 0) {
    rsp = 0;
  }
  digitalWrite(stby, HIGH);
  
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, HIGH);

  analogWrite(pwma, lsp);
  analogWrite(pwmb, rsp);
}
