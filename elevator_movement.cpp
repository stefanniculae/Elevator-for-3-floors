#include "elevator_movement.h"
#include "motor.h"
#include "floor_checker.h"

#define ENDSTOP_PIN_1 2
#define ENDSTOP_PIN_2 3
#define ENDSTOP_PIN_3 4

extern int endstop_state_1;
extern int endstop_state_2;
extern int endstop_state_3;
extern int etaj;

void urcare()
{
  for (int a = 0 ; a < 4 ; a++)
  {
    OneStep(true);
    delay(2);
  }
}

void coborare()
{
  for (int a = 0 ; a < 4 ; a++)
  {
    OneStep(false);
    delay(2);
  }
}

void calibrare()
{
  endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
  while (endstop_state_1 == LOW)
  {
    coborare();
    endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
  }

  etaj = 1;
}

void e1_e2()
{
  endstop_state_2 = digitalRead(ENDSTOP_PIN_2);
  while (endstop_state_2 == LOW)
  {
    urcare();
    endstop_state_2 = digitalRead(ENDSTOP_PIN_2);
    verificare_comandare_lift();
  }
  etaj = 2;
}
void e1_e3()
{
  endstop_state_3 = digitalRead(ENDSTOP_PIN_3);
  while (endstop_state_3 == LOW)
  {
    urcare();
    endstop_state_3 = digitalRead(ENDSTOP_PIN_3);
    verificare_comandare_lift();
  }
  etaj = 3;
}

void e2_e1()
{
  endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
  while (endstop_state_1 == LOW)
  {
    coborare();
    endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
    verificare_comandare_lift();
  }
  etaj = 1;
}

void e2_e3()
{
  endstop_state_3 = digitalRead(ENDSTOP_PIN_3);
  while (endstop_state_3 == LOW)
  {
    urcare();
    endstop_state_3 = digitalRead(ENDSTOP_PIN_3);
    verificare_comandare_lift();
  }
  etaj = 3;
}

void e3_e1()
{
  endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
  while (endstop_state_1 == LOW)
  {
    coborare();
    endstop_state_1 = digitalRead(ENDSTOP_PIN_1);
    verificare_comandare_lift();
  }
  etaj = 1;
}

void e3_e2()
{
  endstop_state_2 = digitalRead(ENDSTOP_PIN_2);
  while (endstop_state_2 == LOW)
  {
    coborare();
    endstop_state_2 = digitalRead(ENDSTOP_PIN_2);
    verificare_comandare_lift();
  }
  etaj = 2;
}
