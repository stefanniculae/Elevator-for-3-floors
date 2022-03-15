#include "list_functions.h"

struct node
{
  int floor_number;
  struct node *link;
};

extern int floor_number_pressed;
extern struct node *head;
extern int number_of_elements_in_list_exterior;
extern int number_of_elements_in_list_interior;
extern int number_of_elements_in_list;
extern int etaj;

void list_creation(int floor_number_pressed)
{
  head = (struct node*) malloc(sizeof(struct node));
  head->floor_number = floor_number_pressed;
  head->link = NULL;
}

void add_in_list_at_end(int floor_number_pressed)
{
  struct node *new_element, *current_element;

  new_element = (struct node*) malloc(sizeof(struct node));
  new_element->floor_number = floor_number_pressed;
  new_element->link = NULL;

  current_element = head;

  while (current_element->link != NULL)
  {
    current_element = current_element->link;
  }

  current_element->link = new_element;
}

void delete_first_in_list()
{
  struct node *current;

  current = head;

  head = head->link;

  free(current);
  current = NULL;
}

void add_in_list_at_beginning(int floor_number_pressed)
{
  struct node *new_element;

  new_element = (struct node*) malloc(sizeof(struct node));
  new_element->floor_number = floor_number_pressed;
  new_element->link = NULL;

  new_element->link = head;
  head = new_element;
}

void delete_specific_element_from_list(int floor_number_pressed)
{
  struct node *current;
  struct node *previous;
  int pos = 0;
  int ct = 0;

  pos = number_of_elements_in_list_interior;
  ct = number_of_elements_in_list_exterior;

  current = head;
  previous = head;

  while (current->link != NULL && pos > 0)
  {
    previous = current;
    current = current->link;
    pos--;
  }

  while (ct != 0)
  {
    if (current->floor_number == floor_number_pressed)
    {
      previous->link = current->link;
      free(current);
      current = NULL;
      number_of_elements_in_list_exterior--;
      break;
    }

    previous = current;
    current = current->link;
    ct--;
  }
}

void number_of_elements_regulator()
{
  if (number_of_elements_in_list_interior > 0)
  {
    number_of_elements_in_list_interior--;
  }
  else
  {
    number_of_elements_in_list_exterior--;
  }

  number_of_elements_in_list--;
}

void printare()
{
  struct node *current;

  current = head;

  Serial.println("coada de etaje este:");

  if (current != NULL)
  {
    while (current != NULL)
    {
      Serial.print(current->floor_number);
      Serial.print(" ");
      current = current->link;
    }
  }

  Serial.print("\n");
  Serial.println("etajul curent este:");
  Serial.println(etaj);
}

void functions_for_list_and_printing()
{
  printare();
  delete_first_in_list();
  number_of_elements_regulator();
}

void add_in_list_at_specific_position(int floor_number_pressed)
{
  struct node *current;
  struct node *new_element;
  int pos = 0;
  int ct = 0;

  new_element = (struct node*) malloc(sizeof(struct node));
  new_element->floor_number = floor_number_pressed;
  new_element->link = NULL;

  pos = number_of_elements_in_list_interior;

  current = head;

  while (current->link != NULL && pos > 0)
  {
    current = current->link;
    pos--;
  }

  new_element->link = current->link;
  current->link = new_element;
}
