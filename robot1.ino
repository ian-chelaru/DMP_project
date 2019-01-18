// Pins of motor 1  //left wheel
#define dir1 5
#define en1 6

// Pins of motor 2  // right wheel
#define dir2 2
#define en2 3

int b1,b2,b3,b4;

void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(en2, OUTPUT);
  
  analogWrite(en1,0);
  
  pinMode(53,INPUT_PULLUP);   // right
  pinMode(52,INPUT_PULLUP);
  pinMode(51,INPUT_PULLUP);
  pinMode(50,INPUT_PULLUP);   // left
  Serial.begin(9600);
}


void delayStopped(int ms)
{
  analogWrite(en1,0);
  analogWrite(en2,0);
  delay(ms);
}

void goBackward(int speed1, int ms)
{
  digitalWrite(dir1,LOW);   // LOW goes forward
  digitalWrite(dir2,HIGH);
  analogWrite(en1,speed1+5);
  analogWrite(en2,speed1);
  delay(ms);
}

void goForward(int speed1, int ms)
{
  digitalWrite(dir1,HIGH);    // HIGH goes backward
  digitalWrite(dir2,LOW);
  analogWrite(en1,speed1+5); 
  analogWrite(en2,speed1);
  delay(2000);
}

void goLeft(int speed1, int ms)
{
  digitalWrite(dir1,LOW);    // HIGH goes backward
  digitalWrite(dir2,LOW);
  analogWrite(en1,speed1+5); 
  analogWrite(en2,speed1);
  delay(ms);
}

void goRight(int speed1, int ms)
{
  digitalWrite(dir1,HIGH);    // HIGH goes backward
  digitalWrite(dir2,HIGH);
  analogWrite(en1,speed1+5); 
  analogWrite(en2,speed1);
  delay(ms);
}

void loop() {
  // put your main code here, to run repeatedly:
  b1 = digitalRead(53);
  b2 = digitalRead(52);
  b3 = digitalRead(51);
  b4 = digitalRead(50);
  Serial.println(b1);
  delay(1000);

  goForward(40, 2000);
  delayStopped(1000);

  goBackward(40, 2000);
  delayStopped(1000);

  goLeft(40,2000);
  delayStopped(1000);

  goRight(40,2000);
  delayStopped(1000);
}
