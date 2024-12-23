#define pwma 3 // RIGHT MOTOR 
#define pwmb 5 // LEFT MOTOR
#define ain1 6 // RIGHT FWD
#define ain2 7 // RIGHT BKWD
#define bin1 9 // LEFT FWD
#define bin2 8 // LEFT BKWD
#define stby 4

bool l = 0;
bool r = 0;
bool s = 0;
bool u = 0;
int e = 0;
int paths = 0;

bool endFound = 0;

int threshold = 100;
int maxspeed = 1;

int FT = 30;
int P, D, I, previousError, PIDvalue, error;
int lsp = 40;
int rsp = 40;
int lfspeed = 40;
int rfspeed = 40;
int turnspeed;

float Kp = 0.025;
float Kd = 0.0;
float Ki = 0 ;

String str;

void setup() {
//  Serial.begin(9600);
  pinMode(pwma, OUTPUT);
  pinMode(pwmb, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(bin1, OUTPUT);
  pinMode(bin2, OUTPUT);
  pinMode(stby, OUTPUT);
//  delay(1000);
//  calibrate();
}

void loop() {

  while (endFound == 0)
  {
    linefollow();
    checknode();

    botstop();
    delay(90);

    reposition ();
  }

//  for (int x = 0; x < 10; x++)
//  {
//    str.replace("RURUS", "U");
//    str.replace("RUSUR", "U");
//    str.replace("RUR", "S");
//    str.replace("SUR", "L");
//    str.replace("RUS", "L");
//    str.replace("RUL", "U");
//    str.replace("LUR", "U");
//  }
//  int/ endpos = str.indexOf('E');

  
//  for (int i = 0; i <= endpos; i++)
//  {
//    char node = str.charAt(i);
//    paths = 0;
//    while (paths < 2)
//    {
//      linefollow();
//      checknode();
//      if (paths == 1)
//      {
//        botstop();
//        delay(75);
//        reposition();
//      }
//    }
//    switch (node)
//    {
//      case 'L':
//        botstop();
//        delay(75);
//        botleft();
//        break;
//
//      case 'S':
//        break;
//
//      case 'R':
//        botstop();
//        delay(75);
//        botright();
//        break;
//
//      case 'E':
//        for (int i = 0; i < 10; i++)
//        {
//          botinchforward ();
//        }
//        botstop();
//        delay(1000);
//        break;
//    }//_________end of switch
//  }//_________end of for loop

}
