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
#include <string.h>
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* nameptr) {
  int option = 5;
  printf("Please enter the contact's first name: ");
  scanf("%30[^\n]", nameptr->firstName);
  clearKeyboard();
  printf("Do you want to enter a middle initial(s)? (y or n): ");
  option = yes();
  if (option == 1) {
    printf("Please enter the contact's middle initial(s): ");
    scanf("%6[^\n]", nameptr->middleInitial);
    clearKeyboard();
  }
  else {
    strcpy(nameptr->middleInitial, "\0");
  }
  printf("Please enter the contact's last name: ");
  scanf("%35[^\n]", nameptr->lastName);
}
// getAddress:
void getAddress(struct Address* addressptr) {
  int option = 5;
  printf("Please enter the contact's street number: ");
  addressptr->streetNumber = getInt();

  printf("Please enter the contact's street name: ");
  scanf("%40[^\n]", addressptr->street);
  clearKeyboard();

  printf("Do you want to enter an apartment number? (y or n): ");
  option = yes();
  if (option == 1) {
    printf("Please enter the contact's apartment number: ");
    scanf("%d", &addressptr->apartmentNumber);
    clearKeyboard();
  }
  else {
    addressptr->apartmentNumber=0;
  }
  printf("Please enter the contact's postal code: ");
  scanf("%7[^\n]", addressptr->postalCode);
  clearKeyboard();

  printf("Please enter the contact's city: ");
  scanf("%40[^\n]", addressptr->city);
  clearKeyboard();
}
// getNumbers:
void getNumbers(struct Numbers* numbersptr) {
  int option = 5;
  
  printf("Please enter the contact's cell phone number: ");
  getTenDigitPhone(numbersptr->cell);

  printf("Do you want to enter a home phone number? (y or n): ");
  option = yes();
  if (option == 1) {
    printf("Please enter the contact's home phone number: ");
    getTenDigitPhone(numbersptr->home);
  }
  else {
    strcpy(numbersptr->home, "\0");
  }
  printf("Do you want to enter a business phone number? (y or n): ");
  option = yes();
  if (option == 1) {
    printf("Please enter the contact's business phone number: ");
    getTenDigitPhone(numbersptr->business);
  }
  else {
    strcpy(numbersptr->business, "\0");
  }
}
// getContact:
void getContact(struct Contact* contactptr) {
  getName(&contactptr->name);
  getAddress(&contactptr->address);
  getNumbers(&contactptr->numbers);
}