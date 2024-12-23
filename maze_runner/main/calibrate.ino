int max[] = {0, 0, 0, 0, 0, 0, 0, 0};
int min[] = {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000};
float weight[8];
int speed = 40;

void calibrate()
{

  for(int j=0; j<3000; j++)
  {
    analogWrite(pwma, speed);
    analogWrite(pwmb, 0);
    digitalWrite(ain1, HIGH);
    digitalWrite(bin1, HIGH);

    for(int i=0; i<8; i++)
    {
      if(max[i] < analogRead(i))
      max[i] = analogRead(i);
      if(min[i] > analogRead(i))
      min[i] = analogRead(i);
    }
  }
    for(int i=0; i<8; i++)
    {
      weight[i] = 400.0 / max[i];
    }
  analogWrite(pwma, 0);
  analogWrite(pwmb, 0);
}

//void setup() {
//  Serial.begin(9600);
//  delay(3000);
//  // put your setup code here, to run once:
//  calibrate();
//  Serial.print("maximum values : ");
//    for(int i=0; i<8; i++)
//  {
//    Serial.print(max[i]);
//    Serial.print("\t");
//  }
//  Serial.print("minimum values : ");
//
//   for(int i=0; i<8; i++)
//  {
//    Serial.print(min[i]);
//    Serial.print("\t");
//  }
//  Serial.println("\n");
//
//  for(int i=0; i<8; i++)
//  {
//    Serial.print(weight[i]);
//    Serial.print("\t");
//  }
//  Serial.print("\n");
//  delay(1000);
//}
