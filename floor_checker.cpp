#include "floor_checker.h"
#include "list_functions.h"

#define BUTTONS_PIN_EXTERIOR_ELEVATOR_1 A0
#define BUTTONS_PIN_INTERIOR_ELEVATOR_1 A1

extern int button_state_1_exterior ;
extern int button_state_2_exterior;
extern int button_state_3_exterior;
extern int button_state_1_interior;
extern int button_state_2_interior;
extern int button_state_3_interior;
extern int floor_1_required;
extern int floor_2_required;
extern int floor_3_required;
extern int floor_1_required_from_interior;
extern int floor_2_required_from_interior;
extern int floor_3_required_from_interior;
extern int number_of_elements_in_list_exterior;
extern int number_of_elements_in_list_interior;
extern int number_of_elements_in_list;

void verificare_comandare_lift_exterior()
{
  //Serial.println(analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1));
  if (analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) >= 800 && analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) <= 900)
  {
    button_state_1_exterior = 1;
  }
  else if (analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) >= 600 && analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) <= 730)
  {
    button_state_2_exterior = 1;
  }
  else if (analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) >= 450  && analogRead(BUTTONS_PIN_EXTERIOR_ELEVATOR_1) <= 550)
  {
    button_state_3_exterior = 1;
  }
  else
  {
    button_state_1_exterior = 0;
    button_state_2_exterior = 0;
    button_state_3_exterior = 0;
  }

  if (button_state_1_exterior == 1 && floor_1_required == 0)
  {
    floor_1_required = 1;
    number_of_elements_in_list++;
    number_of_elements_in_list_exterior++;
    if (number_of_elements_in_list == 1)
    {
      list_creation(1);
    }
    else
    {
      add_in_list_at_end(1);
    }
  }
  else if (button_state_2_exterior == 1 && floor_2_required == 0)
  {
    floor_2_required = 1;
    number_of_elements_in_list++;
    number_of_elements_in_list_exterior++;
    if (number_of_elements_in_list == 1)
    {
      list_creation(2);
    }
    else
    {
      add_in_list_at_end(2);
    }
  }
  else if (button_state_3_exterior == 1 && floor_3_required == 0)
  {
    floor_3_required = 1;
    number_of_elements_in_list++;
    number_of_elements_in_list_exterior++;
    if (number_of_elements_in_list == 1)
    {
      list_creation(3);
    }
    else
    {
      add_in_list_at_end(3);
    }
  }
}

void verificare_comandare_lift_interior()
{
  //Serial.println(analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1));
  if (analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) >= 800 && analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) <= 900)
  {
    button_state_1_interior = 1;
  }
  else if (analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) >= 600 && analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) <= 730)
  {
    button_state_2_interior = 1;
  }
  else if (analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) >= 450  && analogRead(BUTTONS_PIN_INTERIOR_ELEVATOR_1) <= 550)
  {
    button_state_3_interior = 1;
  }
  else
  {
    button_state_1_interior = 0;
    button_state_2_interior = 0;
    button_state_3_interior = 0;
  }

  if (button_state_1_interior == 1 && floor_1_required_from_interior == 0)
  {
    number_of_elements_in_list++;
    number_of_elements_in_list_interior++;
    floor_1_required = 1;
    floor_1_required_from_interior = 1;
    if (number_of_elements_in_list == 1)
    {
      list_creation(1);
    }
    else
    {
      if(number_of_elements_in_list_interior == 1)
      {
        add_in_list_at_beginning(1);
      }
      else
      {
        add_in_list_at_specific_position(1);
      }
      
      if (number_of_elements_in_list_exterior > 0)
      {
        delete_specific_element_from_list(1);
      }
    }
  }
  else if (button_state_2_interior == 1 && floor_2_required_from_interior == 0)
  {
    floor_2_required = 1;
    floor_2_required_from_interior = 1;
    number_of_elements_in_list++;
    number_of_elements_in_list_interior++;
    if (number_of_elements_in_list == 1)
    {
      list_creation(2);
    }
    else
    {
      if(number_of_elements_in_list_interior == 1)
      {
        add_in_list_at_beginning(2);
      }
      else
      {
        add_in_list_at_specific_position(2);
      }
      
      if (number_of_elements_in_list_exterior > 0)
      {
        delete_specific_element_from_list(2);
      }
    }
  }
  else if (button_state_3_interior == 1 && floor_3_required_from_interior == 0)
  {
    floor_3_required = 1;
    floor_3_required_from_interior = 1;
    number_of_elements_in_list++;
    number_of_elements_in_list_interior++;
    if (number_of_elements_in_list == 1)
    {
      list_creation(3);
    }
    else
    {
      if(number_of_elements_in_list_interior == 1)
      {
        add_in_list_at_beginning(3);
      }
      else
      {
        add_in_list_at_specific_position(3);
      }
      
      if (number_of_elements_in_list_exterior > 0)
      {
        delete_specific_element_from_list(3);
      }
    }
  }
}

void verificare_comandare_lift()
{
  verificare_comandare_lift_interior();
  verificare_comandare_lift_exterior();
}
