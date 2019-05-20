/* -------------------------------------------
Name: Md. Hussainul Islam Sajib           
Student number: 137651170
Email: mhisajib@myseneca.ca          
Section: H        
Date: 27 July 2018           
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void) {
  while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
  printf("(Press Enter to Continue)");
  clearKeyboard();
}

// getInt:
int getInt(void) {
  int value;
  char newLine = 'x';
  scanf("%d%c", &value, &newLine);
  while (newLine != '\n') {
    printf("*** INVALID INTEGER *** <Please enter an integer>: ");
    clearKeyboard();
    scanf("%d%c", &value, &newLine);
  }
  return value;
}

// getIntInRange:
int getIntInRange(int lowerBound, int upperBound) {
  int value = getInt();
  while (value < lowerBound || value > upperBound) {
    printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lowerBound, upperBound);
    value = getInt();
  }
  return value;
}

// yes:
int yes(void) {
  char option;
  char newLine;
  int retValue = 0;
  scanf("%c%c", &option, &newLine);
  while (!(option == 'Y' || option == 'y' || option == 'N' || option == 'n') || (newLine != '\n')) {
    printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
    clearKeyboard();
    scanf("%c%c", &option, &newLine);
  }
  if (option == 'Y' || option == 'y') {
    retValue = 1;
  }
  else {
    retValue =0 ;
  }
  return retValue;
}

// menu:
int menu(void) {
  int option = 0;
  printf("Contact Management System\n");
  printf("-------------------------\n");
  printf("1. Display contacts\n");
  printf("2. Add a contact\n");
  printf("3. Update a contact\n");
  printf("4. Delete a contact\n");
  printf("5. Search contacts by cell phone number\n");
  printf("6. Sort contacts by cell phone number\n");
  printf("0. Exit\n");
  printf("\n");
  printf("Select an option:> ");
  option = getIntInRange(0, 6);
  return option;
}

// ContactManagerSystem:
void ContactManagerSystem(void) {
  struct Contact contactDB [MAXCONTACTS]= 
  { { { "Rick", {'\0'}, "Grimes"},
      {11, "Trailer Park", 0, "A7A 2J2", "King City"},
      {"4161112222", "4162223333", "4163334444"} },
    {
      { "Maggie","R.", "Greene" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9051112222", "9052223333", "9053334444" } },
    
    {
      { "Morgan","A.", "Jones" },
      { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
      { "7051112222", "7052223333", "7053334444"  } },
    {
      { "Sasha",{ '\0' }, "Williams" },
      { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
      { "9052223333", "9052223333", "9054445555" } },
  };
  
  int option = 0;
  char optionExit = 'x';

  do {
    option = menu();
    printf("\n");
    switch (option) {

    case 0:
      printf("Exit the program? (Y)es/(N)o: ");
      optionExit = yes();
      if (optionExit == 1) {
        printf("\nContact Management System: terminated\n");
      }
      else {
        printf("\n");
        option = 7;
      }
      break;
    case 1:
      displayContacts(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 2:
      addContact(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 3:
      updateContact(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 4:
      deleteContact(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 5:
      searchContacts(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;
    case 6:
      sortContacts(contactDB, MAXCONTACTS);
      pause();
      printf("\n");
      break;

    default:
      break;
    }
  } while (option != 0);
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
//DONE
void getTenDigitPhone(char telNum[]) {
  int needInput = 1;

  while (needInput == 1) {
    scanf("%10s", telNum);
    clearKeyboard();

    // (String Length Function: validate entry of 10 characters)
    if (strlen(telNum) == 10)
      needInput = 0;
    else
      printf("Enter a 10-digit phone number: ");
  }
}

// findContactIndex:
//DONE
int findContactIndex(const struct Contact contacts[], int sizeOfContact, const char cellNum[]) {
  int counter;
  for (counter = 0; (strcmp(contacts[counter].numbers.cell, cellNum) && counter < sizeOfContact); counter++);
  if (counter != sizeOfContact && !strcmp(contacts[counter].numbers.cell, cellNum));
  else {
    counter = -1;
  }
  return counter;
}

// displayContactHeader
//DONE
void displayContactHeader(void) {
  int dashesline1;
  //line one
  printf("+");
  for (dashesline1 = 0; dashesline1 < 77; dashesline1++) {
    printf("-");
  }
  printf("+\n");
  //line two
  printf("|");
  for (dashesline1 = 0; dashesline1<30; dashesline1++) {
    printf(" ");
  }
  printf("Contacts Listing");
  for (dashesline1 = 0; dashesline1<31; dashesline1++) {
    printf(" ");
  }
  printf("|\n");
  //line three
  printf("+");
  for (dashesline1 = 0; dashesline1 < 77; dashesline1++) {
    printf("-");
  }
  printf("+\n");
}

// displayContactFooter

void displayContactFooter(int numberOfContacts) {
  int dashesline1;
  //line one
  printf("+");
  for (dashesline1 = 0; dashesline1 < 77; dashesline1++) {
    printf("-");
  }
  printf("+\n");
  //line two
  printf("Total contacts: ");
  printf("%d\n\n", numberOfContacts);

}

// displayContact:

void displayContact(const struct Contact* contactptr) {
  if (strlen(contactptr->name.middleInitial) > 0) {
    printf(" %s %s %s\n", contactptr->name.firstName, contactptr->name.middleInitial, contactptr->name.lastName);
  }
  else {
    printf(" %s %s\n", contactptr->name.firstName, contactptr->name.lastName);
  }
  
  printf("    C: %-10s   H: %-10s   B: %-10s\n", contactptr->numbers.cell, contactptr->numbers.home, contactptr->numbers.business);
  printf("       %d %s, ", contactptr->address.streetNumber, contactptr->address.street);
  if (contactptr->address.apartmentNumber) {
    printf("Apt# %d, ", contactptr->address.apartmentNumber);
  }
  printf("%s, %s\n", contactptr->address.city, contactptr->address.postalCode);
}

// displayContacts:

void displayContacts(const struct Contact contacts[], int sizeOfContact) {
  int counter =0;
  int size = 0;
  displayContactHeader();
  while (counter < sizeOfContact) {
    if (strlen(contacts[counter].numbers.cell) > 0) {
      displayContact(&contacts[counter]);
      size++;
    }
    counter++;
  }
  displayContactFooter(size);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int sizeOfContact) {
  char phoneNumber[11];
  int compReturn;
  do {
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNumber);
  } while (strlen(phoneNumber) == 0);

  compReturn = findContactIndex(contacts, sizeOfContact, phoneNumber);
  
  if (compReturn == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }
  
  else {
    printf("\n");
    displayContact(&contacts[compReturn]);
    printf("\n");
  }
}

// addContact:
void addContact(struct Contact contacts[], int sizeOfContact) {
  int counter=0;
  for (counter = 0; (contacts[counter].numbers.cell[0] != '\0' && counter < sizeOfContact); counter++);
  if (counter==sizeOfContact) {
    printf("*** ERROR: The contact list is full! ***\n");
  }
  else {
    getContact(&contacts[counter]);
    printf("--- New contact added! ---\n");
  }
}

// updateContact:
void updateContact(struct Contact contacts[], int sizeOfContact) {
  char phoneNumber[11];
  int compReturn;
  int choice;
  do {
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNumber);
  } while (strlen(phoneNumber) == 0);

  compReturn = findContactIndex(contacts, sizeOfContact, phoneNumber);

  if (compReturn == -1) {
    printf("*** Contact NOT FOUND ***\n");
  }

  else {
    printf("\nContact found:\n");
    displayContact(&contacts[compReturn]);
    printf("\n");

    printf("Do you want to update the name? (y or n): ");
    choice = yes();
    if (choice) getName(&contacts[compReturn].name);
    clearKeyboard();
    printf("Do you want to update the address? (y or n): ");
    choice = yes();
    if (choice) getAddress(&contacts[compReturn].address);
    
    printf("Do you want to update the numbers? (y or n): ");
    choice = yes();
    if (choice) getNumbers(&contacts[compReturn].numbers);

    printf("--- Contact Updated! ---\n");
  }
}

// deleteContact:
void deleteContact(struct Contact contacts[], int sizeOfContact) {
  char phoneNumber[11];
  int compReturn;
  int choice;
  do {
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(phoneNumber);
  } while (strlen(phoneNumber) == 0);
  compReturn = findContactIndex(contacts, sizeOfContact, phoneNumber);
  if (compReturn == -1) printf("*** Contact NOT FOUND ***\n");
  else {
    printf("\nContact found:\n");
    displayContact(&contacts[compReturn]);
    printf("\n");
    printf("CONFIRM: Delete this contact? (y or n): ");
    choice = yes();
    if (choice) {
        strcpy(contacts[compReturn].numbers.cell, "\0");
        printf("--- Contact deleted! ---\n");
    }
  }
}


// sortContacts:
void sortContacts(struct Contact contacts[], int sizeOfContact) {
  int counter=0;
  int secondary = 1;
  int compInt=0;
  struct Contact tempContact = { 
                                  { { '\0' },{ '\0' },{ '\0' } },
                                    { 0,{ '\0' }, 0,{ '\0' },{ '\0' } },
                                    { { '\0' },{ '\0' },{ '\0' } } 
                              };
  for ( counter = 0; counter < sizeOfContact-1; counter++) {
    for (secondary = 1; secondary <sizeOfContact-counter; secondary++) {
      compInt = strcmp(contacts[counter].numbers.cell, contacts[counter + secondary].numbers.cell);
      if (compInt>0) {
        tempContact = contacts[counter];
        contacts[counter] = contacts[counter + secondary];
        contacts[counter + secondary] = tempContact;
      }
    }
  }
  
  printf("--- Contacts sorted! ---\n");
}

