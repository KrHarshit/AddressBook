#include "contact.h"
int main()
{
    //all function calls should be inside the main 
    AddressBook addressBook;
    read_from_csv(&addressBook);
    char ch[]="Yes";
    while(strcmp(ch,"Yes")==0)
    {
        printf("\n1.View Contacts:\n2.Add Contacts:\n3:Edit Contacts:\n4.Delete Contacts:\n5.Search Contacts:\n6.Exit:\n\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                listContacts(&addressBook);
                break;
            case 2:
                createContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                searchContact(&addressBook);
                break;
	    case 6:
		strcpy(ch,"No");
		break;
            default:
                printf("\nWrong Choice");
        }
    }
    write_to_csv(&addressBook);
}

