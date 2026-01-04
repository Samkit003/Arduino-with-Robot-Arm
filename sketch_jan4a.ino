#include <Servo.h>

Servo Waist; // servo ko declare loat chin
Servo Shoulder;
Servo Elbow;
Servo Tweezers;

int Degree_Waist = 90; // servo degree set loat chin
int Degree_Shoulder = 20;
int Degree_Elbow = 50;
int Degree_Tweezers = 0;

#define VRY_2 A0 // joystick 2 Y coordinate ko analogpin A0
#define VRX_2 A1 // joystick 2 X coordinate ko analogpin A1
#define VRY_1 A2 // joystick 1 Y coordinate ko analogpin A2
#define VRX_1 A3 // joystick 1 X coordinate ko analogpin A3

void setup() {
  Waist.attach(6); // servo ko digitalpin 6 
  Shoulder.attach(9);
  Elbow.attach(10);
  Tweezers.attach(11);

  pinMode(VRY_2, INPUT);
  pinMode(VRX_2, INPUT);
  pinMode(VRY_1, INPUT);
  pinMode(VRX_1, INPUT);
}

void loop() {
  int LVRY_1 = analogRead(VRY_1);
  int LVRX_1 = analogRead(VRX_1);
  int LVRY_2 = analogRead(VRY_2);
  int LVRX_2 = analogRead(VRX_2);

  if (LVRY_1 < 340) Degree_Waist -=1;
  else if (LVRY_1 > 680) Degree_Waist +=1;
  Degree_Waist = min(175, max(0,Degree_Waist));

  if (LVRX_1 < 340) Degree_Shoulder +=2;
  else if (LVRX_1 > 680) Degree_Shoulder -=2;
  Degree_Shoulder = min(110, max(10, Degree_Shoulder));

  if (LVRY_2 < 340) Degree_Elbow -=1;
  else if (LVRY_2 > 680) Degree_Elbow +=1;
  Degree_Elbow = min(80,max(0, Degree_Elbow));

  if (LVRX_2 < 340) Degree_Tweezers -=3;
  else if (LVRX_2 > 680) Degree_Tweezers +=2;
  Degree_Tweezers = min(58, max(0,Degree_Tweezers));

  Waist.write(Degree_Waist);
  Shoulder.write(Degree_Shoulder);
  Elbow.write(Degree_Elbow);
  Tweezers.write(Degree_Tweezers);

  delay(40);

}
