#include <Servo.h>

#include "motor.h"
#include "list_functions.h"
#include "elevator_movement.h"
#include "floor_checker.h"
#include "door_functions.h"

#define ENDSTOP_PIN_1 2
#define ENDSTOP_PIN_2 3
#define ENDSTOP_PIN_3 4
#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11
#define SERVO_PIN 12
#define BUTTONS_PIN_EXTERIOR_ELEVATOR_1 A0
#define BUTTONS_PIN_INTERIOR_ELEVATOR_1 A1

struct node
{
  int floor_number;
  struct node *link;
};

Servo servo;

int step_number = 0;
int button_state_1_exterior = 0;
int button_state_2_exterior = 0;
int button_state_3_exterior = 0;
int button_state_1_interior = 0;
int button_state_2_interior = 0;
int button_state_3_interior = 0;
int endstop_state_1 = 0;
int endstop_state_2 = 0;
int endstop_state_3 = 0;
int etaj;
int floor_1_required = 0;
int floor_2_required = 0;
int floor_3_required = 0;
int floor_1_required_from_interior = 0;
int floor_2_required_from_interior = 0;
int floor_3_required_from_interior = 0;
int number_of_elements_in_list_exterior = 0;
int number_of_elements_in_list_interior = 0;
int number_of_elements_in_list = 0;
long servo_millis = 0;
long servo_interval = 15;
long waiting_time = 5000;
long current_time = 0;
long previous_time = 0;
struct node *head = NULL;

void setup()
{
  pinMode(ENDSTOP_PIN_1, INPUT);
  pinMode(ENDSTOP_PIN_2, INPUT);
  pinMode(ENDSTOP_PIN_3, INPUT);
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  servo.attach(SERVO_PIN);
  servo.write(0);

  calibrare();

  Serial.begin(9600);
}

void loop()
{
  verificare_comandare_lift();

  if (head != NULL)
  {
    if (etaj == 1)
    {
      if (head->floor_number == 1)
      {
        functions_for_list_and_printing();
        printare();
        Serial.print("Deschidere usi etaj 1\n");
        elevator_arrived();
        floor_1_required = 0;
        floor_1_required_from_interior = 0;
      }
      else if (head->floor_number == 2)
      {
        functions_for_list_and_printing();
        e1_e2();
        printare();
        Serial.print("Deschidere usi etaj 2\n");
        elevator_arrived();
        floor_2_required = 0;
        floor_2_required_from_interior = 0;
      }
      else if (head->floor_number == 3)
      {
        functions_for_list_and_printing();
        e1_e3();
        printare();
        Serial.print("Deschidere usi etaj 3\n");
        elevator_arrived();
        floor_3_required = 0;
        floor_3_required_from_interior = 0;
      }
    }
    else if (etaj == 2)
    {
      if (head->floor_number == 1)
      {
        functions_for_list_and_printing();
        e2_e1();
        printare();
        Serial.print("Deschidere usi etaj 1\n");
        elevator_arrived();
        floor_1_required = 0;
        floor_1_required_from_interior = 0;
      }
      else if (head->floor_number == 2)
      {
        functions_for_list_and_printing();
        printare();
        Serial.print("Deschidere usi etaj 2\n");
        elevator_arrived();
        floor_2_required = 0;
        floor_2_required_from_interior = 0;
      }
      else if (head->floor_number == 3)
      {
        functions_for_list_and_printing();
        e2_e3();
        printare();
        Serial.print("Deschidere usi etaj 3\n");
        elevator_arrived();
        floor_3_required = 0;
        floor_3_required_from_interior = 0;
      }
    }
    else if (etaj == 3)
    {
      if (head->floor_number == 1)
      {
        functions_for_list_and_printing();
        e3_e1();
        printare();
        Serial.print("Deschidere usi etaj 1\n");
        elevator_arrived();
        floor_1_required = 0;
        floor_1_required_from_interior = 0;
      }
      else if (head->floor_number == 2)
      {
        functions_for_list_and_printing();
        e3_e2();
        printare();
        Serial.print("Deschidere usi etaj 2\n");
        elevator_arrived();
        floor_2_required = 0;
        floor_2_required_from_interior = 0;
      }
      else if (head->floor_number == 3)
      {
        functions_for_list_and_printing();
        printare();
        Serial.print("Deschidere usi etaj 3\n");
        elevator_arrived();
        floor_3_required = 0;
        floor_3_required_from_interior = 0;
      }
    }
  }
}
