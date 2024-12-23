int turnspeed1 = 150;
int turnspeed2 = 150;

void botleft ()
{
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, LOW);
  analogWrite(pwma, turnspeed1);
  analogWrite(pwmb, turnspeed1);
  delay(100);
  while (analogRead(5) < threshold)
  {
    digitalWrite(ain1, HIGH);
    digitalWrite(bin1, LOW);
    analogWrite(pwma, turnspeed2);
    analogWrite(pwmb, turnspeed2);
  }
  analogWrite(ain1, 0);
  analogWrite(bin1, 0);
  delay(50);
}

void botright ()
{
  digitalWrite(ain1, LOW);
  digitalWrite(bin1, HIGH);
  analogWrite(pwma, turnspeed1);
  analogWrite(pwmb, turnspeed1);
  delay(50);
  while (analogRead(2) < threshold)
  {
    digitalWrite(ain1, LOW);
    digitalWrite(bin1, HIGH);
    analogWrite(pwma, turnspeed2);
    analogWrite(pwmb, turnspeed2);
  }
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(50);
}

void botstraight ()
{
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, HIGH);
  analogWrite(pwma, lfspeed);
  analogWrite(pwmb, lfspeed);
}

void botinchforward ()
{
  digitalWrite(ain1, HIGH);
  digitalWrite(bin2, HIGH);
  analogWrite(pwma, turnspeed1);
  analogWrite(pwmb, turnspeed1);
  delay(10);
}
void botstop ()
{
  digitalWrite(ain1, LOW);
  digitalWrite(bin1, LOW);
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
}
void botuturn ()
{
  digitalWrite(ain1, HIGH);
  digitalWrite(bin1, HIGH);
  analogWrite(pwma, 100);
  analogWrite(pwmb, 100);
  delay(50);
  while (analogRead(5) < threshold)
  {
    digitalWrite(ain1, HIGH);
    digitalWrite(bin1, LOW);
    digitalWrite(bin2, HIGH);
    analogWrite(pwma, turnspeed2);
    analogWrite(pwmb, turnspeed2);
  }
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
  delay(50);
}
