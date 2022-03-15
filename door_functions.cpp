#include "door_functions.h"
#include "floor_checker.h"
#include <Servo.h>

extern long servo_millis;
extern long servo_interval;
extern long waiting_time;
extern long current_time;
extern long previous_time;
extern Servo servo;

void open_door()
{
  int i = 0, ok  = 0;

  for (i = 0 ; i < 90 ; i++)
  {
    while (ok == 0)
    {
      verificare_comandare_lift();
      if (millis() - servo_millis > servo_interval)
      {
        ok = 1;
        servo_millis = millis();
        servo.write(i);
      }
    }
    ok = 0;
  }
}

void close_door()
{
  int i = 0, ok  = 0;

  for (i = 90 ; i > 0 ; i--)
  {
    while (ok == 0)
    {
      verificare_comandare_lift();
      if (millis() - servo_millis > servo_interval)
      {
        ok = 1;
        servo_millis = millis();
        servo.write(i);
      }
    }
    ok = 0;
  }
}

void waiting_time_for_pressing_floor()
{
  int ok = 0;

  verificare_comandare_lift();
  previous_time = current_time;

  while (ok == 0)
  {
    verificare_comandare_lift();
    if (millis() - previous_time > waiting_time)
    {
      ok = 1;
    }
  }
}

void elevator_arrived()
{
  open_door();
  current_time = millis();
  waiting_time_for_pressing_floor();
  close_door();
}
