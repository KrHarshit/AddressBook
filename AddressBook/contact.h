#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    FILE *fptr;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
int is_Valid_Name(char *name);
int is_Valid_Phone(char *phone);
int is_Valid_Email(char *email);
void newName(AddressBook *addressBook, int pos);
void newPhone(AddressBook *addressBook, int pos);
void newEmail(AddressBook *addressBook, int pos);
void write_to_csv(AddressBook *addressBook);
void read_from_csv(AddressBook *addressBook);
#endif
