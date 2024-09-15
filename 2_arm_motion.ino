#include <Servo.h>

// Define your Touch screen connections
#define X1 A0
#define X2 A1
#define Y1 A2
#define Y2 A3

// Define your screen resolution as per your Touch screen (Max: 1024)
#define Xresolution 320
#define Yresolution 240
#define k1 1
#define k2 2
#define maxx 160
#define maxy 120


Servo servoX; // Define X-axis servo
Servo servoY; // Define Y-axis servo

void setup() {
  Serial.begin(9600);
  servoX.attach(9); // Attach servo to pin 9
  servoY.attach(10); // Attach servo to pin 10
}
int i = 0;
int x, y, x1, y1, movx, movy;
void loop() {
  // Touch coordinates are stored in X, Y variables
  // Read X axis touch position
  pinMode(Y1, INPUT);
  pinMode(Y2, INPUT);
  digitalWrite(Y2, LOW);
  pinMode(X1, OUTPUT);
  digitalWrite(X1, HIGH);
  pinMode(X2, OUTPUT);
  digitalWrite(X2, LOW);
  x = (map(analogRead(Y1), 0, 1023, 0, Xresolution)+i*x)/(i+1); // Map analog value to screen resolution
  
  // Read Y axis touch position
  pinMode(X1, INPUT);
  pinMode(X2, INPUT);
  digitalWrite(X2, LOW);
  pinMode(Y1, OUTPUT);
  digitalWrite(Y1, HIGH);
  pinMode(Y2, OUTPUT);
  digitalWrite(Y2, LOW);
  y = (map(analogRead(X1), 0, 1023, 0, Yresolution)+i*y)/(i+1); // Map analog value to screen resolution
  
  // Control servos based on X and Y coordinates
  if (i == 3) {
  if (x-x1 < maxx && x-x1 > -1*maxx) {
    movx = k1*x + k2*(x-x1);
  }
  else movx = k1*x;
  if (y-y1 < maxy && y-y1 > -1*maxy) {
    movy = k1*y + k2*(y-y1);
  }
  else movy = k1*y;
  if (movx > Xresolution) {
    movx = Xresolution;
  }
  else if (movx < 0) {
    movx = 0;
  }
  if (movy > Yresolution) {
    movy = Yresolution;
  } else if (movy < 0) {
    movy = 0;
  }

  int servoXPos = map(movx, 0, Xresolution, 0, 180); // Map X coordinate to servo position
  int servoYPos = map(movy, 0, Yresolution, 0, 180); // Map Y coordinate to servo position
  servoX.write(servoXPos); // Move X-axis servo
  servoY.write(servoYPos); // Move Y-axis servo
  x1 = x;
  y1 = y;
  int i = -1;
  }

  // Display X and Y on Serial Monitor
  Serial.print("X = ");
  Serial.print(x);
  Serial.print(" Y = ");
  Serial.println(y);
  
  delay(100);
  i++;
}