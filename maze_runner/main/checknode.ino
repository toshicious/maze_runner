void checknode ()
{
  l = 0;
  r = 0;
  s = 0;
  u = 0;
  e = 0;
  paths = 0;

  if (analogRead(7) > threshold) r = 1;
  if (analogRead(0) > threshold) l = 1;
  if ((analogRead(2) < threshold && (analogRead(3) < threshold) && (analogRead(4) < threshold)) && (analogRead(5) < threshold)) {
    u = 1;
  }
  if ((analogRead(2) > threshold) && (analogRead(3) > threshold) && (analogRead(4) > threshold) && (analogRead(5) > threshold)) {
    e = 1;
  }

  if (u == 0)
  {
    for (int i = 0; i < FT; i++)
    {
      //botinchforward ();
      lfspeed = 80;
      PID();
      if (analogRead (7) > threshold) r = 1;
      if (analogRead (0) > threshold) l = 1;
    }

    for (int i = 0; i < FT; i++)
    {
      //botinchforward ();
      lfspeed = 90;
      PID();
      if (analogRead (3) > threshold || (analogRead(4) > threshold)) s = 1;
    }
    if ((e == 1) && (analogRead(2) > threshold) && (analogRead(3) > threshold) && (analogRead(4) > threshold && (analogRead(5) > threshold))) e = 2;
  }
  if (u == 1)
  {
    for (int i = 0; i < 3; i++)
    {
      botinchforward ();
    }
  }
  paths = l + s + r;
}
