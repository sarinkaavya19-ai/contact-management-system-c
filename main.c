#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100
char *contacts[MAX_CONTACTS];
char *numbers[MAX_CONTACTS];
int contact_count = 0;
const char security_pin[] = "admin19";
int check_security_pin() {
 char pin[10];
  printf("Enter security pin: ");
 scanf("%s", pin);
    return strcmp(pin, security_pin) == 0;
}
void add_contact()
 {
    char name[50], number[15];
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i], name) == 0) {
            printf("Contact already exists.\n");
            return;
        } }
    
printf("Enter the phone number: ");
    scanf("%s", number);
    contacts[contact_count] = strdup(name);
    numbers[contact_count] = strdup(number);
    contact_count++;
    printf("Contact added successfully.\n");
}
void remove_contact()
 {
    char name[50];
    printf("Enter the name of the contact to remove: ");
    scanf("%s", name);
    for (int i = 0; i < contact_count; i++) {
if (strcmp(contacts[i], name) == 0) {
            free(contacts[i]);
            free(numbers[i]);
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
                numbers[j] = numbers[j + 1];
            }
            contact_count--;
            printf("Contact removed successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}
void search_contact() {
    char name[50];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i], name) == 0) {
            printf("%s: %s\n", contacts[i], numbers[i]);
            return;
        }}
    printf("No such contact found.\n");}
void display_contacts() {
    if (contact_count == 0)
 { printf("No contacts to display.\n");
        return;
    }
    for (int i = 0; i < contact_count; i++) {
        printf("%s: %s\n", contacts[i], numbers[i]); }}
void menu() {
    while (1)
 {     printf("Menu:\n");
        printf("Press 1 to Add contact\n");
        printf("Press 2 to Remove contact\n");
        printf("Press 3 to Search contact\n");
        printf("Press 4 to Display contacts\n");
        printf("Press 5 to exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) 
{
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_contacts();
                break;
        
case 5: printf("Thank you!\n");
                exit(0);
default:
   printf("Invalid choice. Please select a valid option.\n"); }}}
int main() {
    if (check_security_pin()){
        menu();
    } else {
        printf("Invalid security pin.\n");
    }
    return 0;
}
 


