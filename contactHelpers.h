/* ------------------------------------------------------------------
Name: Md. Hussainul Islam Sajib
Student number: 137651170
Email: mhisajib@myseneca.ca
Section: H
Date: 27 July 2018
---------------------------------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:
void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int lowerBound, int upperBound);

// yes:
int yes(void);

// menu:
int menu(void);

// ContactManagerSystem:
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char telNum[]);

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int sizeOfContact, const char cellNum[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int numberOfContacts);

// displayContact:
void displayContact(const struct Contact* contactptr);

// displayContacts:
void displayContacts(const struct Contact contacts[], int sizeOfContact);

// searchContacts:
void searchContacts(const struct Contact contacts[], int sizeOfContact);

// addContact:
void addContact(struct Contact contacts[], int sizeOfContact);

// updateContact:
void updateContact(struct Contact contacts[], int sizeOfContact);

// deleteContact:
void deleteContact(struct Contact contacts[], int sizeOfContact);

// sortContacts:
void sortContacts(struct Contact contacts[], int sizeOfContact);
