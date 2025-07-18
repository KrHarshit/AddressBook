#include "contact.h"
#include <ctype.h>

void newEmail(AddressBook *addressBook, int pos)
{
    int check_email=1;
    char new_email[50];
    if(check_email)
    {
        while(check_email)
        {
            printf("Enter new Email id: ");
            scanf(" %[^\n]",new_email);
            if(!is_Valid_Email(new_email))
            {
                printf("Please enter a valid email address!\n");
                continue;
            }
            int count=0;
            for(int i=0; i<addressBook->contactCount; i++)
            {
                if(strcmp(new_email,addressBook->contacts[i].email)==0)
                {
                    printf("Contact with this email address already exists!\n");
                    break;
                }
                count++;
            }
            if(count==addressBook->contactCount)
                check_email=0;
        }
    }
    strcpy(addressBook->contacts[pos].email,new_email);
}

void newPhone(AddressBook *addressBook, int pos)
{
    int check_phone=1;
    char new_phone[20];
    if(check_phone)
    {
        while(check_phone)
        {
            printf("Enter new Phone no: ");
            scanf(" %[^\n]",new_phone);
            if(!is_Valid_Phone(new_phone))
            {
                    printf("Please enter a valid phone number of 10 digits!\n");
                    continue;
            }
            int count=0;
            for(int i=0; i<addressBook->contactCount; i++)
            {
                if(strcmp(new_phone,addressBook->contacts[i].phone)==0)
                {
                    printf("Contact with this phone number already exists!\n");
                    break;
                }
                count++;
            }
            if(count==addressBook->contactCount)
                    check_phone=0;
        }
    }
    strcpy(addressBook->contacts[pos].phone,new_phone);
}

void newName(AddressBook *addressBook, int pos)
{
    char new_name[50];
    int check_name=1;
    if(check_name)
    {
            printf("\n");
            while(check_name)
            {
                    printf("Enter new Name: ");
                    scanf(" %[^\n]", new_name);
                    if(!is_Valid_Name(new_name))
                    {
                            printf("Please enter a valid name!\n");
                            continue;
                    }
                    check_name=0;

            }
    }
    strcpy(addressBook->contacts[pos].name,new_name);
}



int is_Valid_Name(char *name)
{
	int flag=0;
	for(int i=0; name[i]!='\0'; i++)
	{
		if(name[i]==' ' || name[i]=='.')
			continue;
		if(!isalpha(name[i]))
			return flag;
	}
	return flag+1;
}

int is_Valid_Phone(char *phone)
{
	int flag=0;
	for(int i=0; phone[i]!='\0'; i++)
	{
		if(!isdigit(phone[i]))
			return flag;
	}
        if(strlen(phone)!=10)
		return flag;
	return flag+1;
}

int is_Valid_Email(char *email)
{
	if(strchr(email,'@') && strchr(email,'.') && strchr(email,'@') < strchr(email,'.'))
		return 1;
	return 0;
}


void listContacts(AddressBook *addressBook) 
{
    if(addressBook->contactCount==0)
        printf("\nNo contacts in the AddressBook");
    else
    {
        printf("\n|------------------------------------------------------------------------------|\n");
        fprintf(stdout, "|%-4s.|%-30s|%-10s|%-30s|\n", "S.No", "Name", "Phone No", "Email id");
        printf("|------------------------------------------------------------------------------|\n");
        for(int i=0; i<addressBook->contactCount; i++)
        {
            fprintf(stdout,"|%-5d|%-30s|%-10s|%-30s|\n",i+1,addressBook->contacts[i].name,
            addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        printf("|------------------------------------------------------------------------------|\n");
    }
}

/*void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount=0;
    static Contact dummyContacts[] = {
        {"John Doe", "1234567890", "john@example.com"},
        {"Alice Smith", "0987654321", "alice@example.com"},
        {"Bob Johnson", "1112223333", "bob@company.com"},
        {"Carol White", "4445556666", "carol@company.com"},
        {"David Brown", "7778889999", "david@example.com"},
        {"Eve Davis", "6665554444", "eve@example.com"},
        {"Frank Miller", "3334445555", "frank@example.com"},
        {"Grace Wilson", "2223334444", "grace@example.com"},
        {"Hannah Clark", "5556667777", "hannah@example.com"},
        {"Ian Lewis", "8889990000", "ian@example.com"}
    };
    for(int i=0; i<10; i++)
    {
        strcpy(addressBook->contacts[i].name,dummyContacts[i].name);
        strcpy(addressBook->contacts[i].phone,dummyContacts[i].phone);
        strcpy(addressBook->contacts[i].email,dummyContacts[i].email);
        addressBook->contactCount++;
    }

}*/

void createContact(AddressBook *addressBook) 
{
    printf("\nEnter the details:\n");
    newName(addressBook,addressBook->contactCount);
    newPhone(addressBook,addressBook->contactCount);
    newEmail(addressBook,addressBook->contactCount);
    addressBook->contactCount++;
    printf("\nContact added successfully\n");
}

void searchContact(AddressBook *addressBook) 
{
    printf("\nSearch contact by:\n1.Name: \n2.Phone no: \n3.Email id:\n\n");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("\nEnter Name: ");
        char new_name[50];
        scanf(" %[^\n]",new_name);
        int count=0;
	printf("\n");
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].name,new_name)==0)
            {
                count++;
                printf("%d. %s %s %s\n",count,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        if(count==0)
        {
            printf("Name not found\n");
        }
    }
    else if(choice==2)
    {
        printf("\nEnter Phone no: ");
        char new_phone[50];
        scanf(" %[^\n]",new_phone);
        int count=0;
	printf("\n");
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].phone,new_phone)==0)
            {
                count++;
                printf("%d. %s %s %s",count,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
	printf("\n");
        if(count==0)
        {
            printf("Phone number not found\n");
        }
    }
    else if(choice==3)
    {
        printf("\nEnter email id: ");
        char new_email[50];
        scanf(" %[^\n]",new_email);
        int count=0;
	printf("\n");
        for(int i=0; i<addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].email,new_email)==0)
            {
                count++;
                printf("%d. %s %s %s",count,addressBook->contacts[i].name,
                addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
	printf("\n");
        if(count==0)
        printf("Email id not found\n");
    }
}

void editContact(AddressBook *addressBook) 
{
    printf("\nEdit contact by\n1.Name: \n2.Phone no: \n3.Email id:\n\n");
    int choice;
    scanf("%d",&choice);
    char new_name[50];
    char new_phone[20];
    char new_email[50];
    int check_name=0;
    int check_phone=0;
    int check_email=0;
    switch(choice)
    {
        case 1:
	    printf("\n");
            while(check_name==0)
            {
                char name[50];
                printf("Enter Name: ");
                scanf(" %[^\n]",name);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].name),name)==0)
                    check_name++;
                    strcpy(new_name,name);
                }
                if(check_name==0)
                {
                    printf("No contact with such name\n");
                }
            }
            if(check_name==1)
            {
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].name),new_name)==0)
                    {
			int choose;
			printf("What do you want to edit:\n1.Name\n2.Phone no.\n3.Email id.\n\n");
			scanf("%d",&choose);
			if(choose==1)
			{
				strcpy(addressBook->contacts[i].name,"");
				newName(addressBook, i);
			}
			if(choose==2)
			{
				strcpy(addressBook->contacts[i].phone,"");
				newPhone(addressBook, i);
			}
			if(choose==3)
			{
				strcpy(addressBook->contacts[i].email," ");
				newEmail(addressBook,i);
			}
			break;
                    }
                }
                printf("\nContact edited successfully\n");
            }
            else if(check_name>1)
            {
                int k=0;
                int arr[check_name];
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].name),new_name)==0)
                    {
                    arr[k++]=i;
                    }
                }
                printf("Select the contact you want to edit\n\n");
                for(int i=0; i<check_name; i++)
                {
                    fprintf(stdout,"|%-5d|%-30s|%-10s|%-30s|\n",arr[i]+1,addressBook->contacts[arr[i]].name,
                    addressBook->contacts[arr[i]].phone,addressBook->contacts[arr[i]].email);
                }
		printf("\n");
                int num;
                scanf("%d",&num);
		int choose;
                printf("What do you want to edit:\n1.Name\n2.Phone no.\n3.Email id.\n\n");
                scanf("%d",&choose);
                if(choose==1)
                {
                        strcpy(addressBook->contacts[num-1].name,"");
                        newName(addressBook, num-1);
                }
                if(choose==2)
                {
                        strcpy(addressBook->contacts[num-1].phone,"");
                        newPhone(addressBook, num-1);
                }
                if(choose==3)
                {
                        strcpy(addressBook->contacts[num-1].email," ");
                        newEmail(addressBook,num-1);
                }
                printf("\nContact edited successfully\n");
            }
            break;

        case 2:
	    printf("\n");
            while(check_phone==0)
            {
                char phone[20];
                printf("Enter the Phone no: ");
                scanf(" %[^\n]",phone);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].phone),phone)==0)
                    {
                        check_phone=1;
                        strcpy(new_phone,phone);
                        break;
                    }
                }
                if(check_phone==0)
                {
                    printf("No contact with such phone no\n");
                }
            }
            for(int i=0; i<addressBook->contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].phone,new_phone)==0)
                {
		        int choose;
                        printf("What do you want to edit:\n1.Name\n2.Phone no.\n3.Email id.\n\n");
                        scanf("%d",&choose);
                        if(choose==1)
                        {
                                strcpy(addressBook->contacts[i].name,"");
                                newName(addressBook, i);
                        }
                        if(choose==2)
                        {
                                strcpy(addressBook->contacts[i].phone,"");
                                newPhone(addressBook, i);
                        }
                        if(choose==3)
                        {
                                strcpy(addressBook->contacts[i].email," ");
                                newEmail(addressBook,i);
                        }
                        break;
                }
            }
            printf("\nContact edited successfully\n");
            break;
        
        case 3:
	    printf("\n");
            while(check_email==0)
            {
                char email[50];
                printf("\nEnter the Email id: ");
                scanf(" %[^\n]",email);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].email),email)==0)
                    {
                        check_email=1;
                        strcpy(new_email,email);
                        break;
                    }
                }
                if(check_email==0)
                {
                    printf("No contact with such email\n");
                }
            }
            for(int i=0; i<addressBook->contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].email,new_email)==0)
                {
		        int choose;
                        printf("What do you want to edit:\n1.Name\n2.Phone no.\n3.Email id.\n\n");
                        scanf("%d",&choose);
                        if(choose==1)
                        {
                                strcpy(addressBook->contacts[i].name,"");
                                newName(addressBook, i);
                        }
                        if(choose==2)
                        {
                                strcpy(addressBook->contacts[i].phone,"");
                                newPhone(addressBook, i);
                        }
                        if(choose==3)
                        {
                                strcpy(addressBook->contacts[i].email," ");
                                newEmail(addressBook,i);
                        }
                        break;
                }
            }
            printf("\nContact edited successfully\n");
            break;
        
        default: 
            printf("Wrong Choice\n");
    }
}

void deleteContact(AddressBook *addressBook) 
{
    printf("\nDelete Contact by\n1.Name: \n2.Phone no:\n3.Email id:\n\n");
    int choice;
    scanf("%d",&choice);
    char new_name[50];
    char new_phone[20];
    char new_email[50];
    int check_name=0;
    int check_phone=0;
    int check_email=0;
    switch(choice)
    {
        case 1:
            while(check_name==0)
            {
                char name[50];
                printf("\nEnter Name: ");
                scanf(" %[^\n]",name);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].name),name)==0)
                    check_name++;
                    strcpy(new_name,name);
                }
                if(check_name==0)
                {
                    printf("No contact with such name\n");
                }
            }
            if(check_name==1)
            {
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].name,new_name)==0)
                    {
                        for(int j=i; j<addressBook->contactCount-1; j++)
                        {
                            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                            strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                        }
                        addressBook->contactCount--;
                    }
                }
                printf("\nContact deleted successfully\n");
            }
            else if(check_name>1)
            {
                int k=0;
                int arr[check_name];
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].name),new_name)==0)
                    {
                    arr[k++]=i;
                    }
                }
                printf("\nSelect the contact to be deleted\n");
                for(int i=0; i<check_name; i++)
                {
                    fprintf(stdout,"|%-5d|%-30s|%-10s|%-30s|\n",arr[i]+1,addressBook->contacts[arr[i]].name,
                    addressBook->contacts[arr[i]].phone,addressBook->contacts[arr[i]].email);
                }
		printf("\n");
                int num;
                scanf("%d",&num);
                for(int i=num-1; i<addressBook->contactCount-1; i++)
                {
                    strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
                    strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
                    strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);    
                }
		addressBook->contactCount--;
                printf("\nContact deleted successfully\n");
            }
            break;
        
        case 2:
         while(check_phone==0)
            {
                char phone[20];
                printf("\nEnter the Phone no: ");
                scanf(" %[^\n]",phone);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].phone),phone)==0)
                    {
                        check_phone=1;
                        strcpy(new_phone,phone);
                        break;
                    }
                }
                if(check_phone==0)
                {
                    printf("No contact with such phone no\n");
                }
            }
            for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].phone,new_phone)==0)
                    {
                        for(int j=i; j<addressBook->contactCount-1; j++)
                        {
                            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                            strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                        }
                        addressBook->contactCount--;
                    }
                }
            printf("\nContact deleted successfully\n");
            break;
        
        case 3:
            while(check_email==0)
            {
                char email[50];
                printf("\nEnter the Email id: ");
                scanf(" %[^\n]",email);
                for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp((addressBook->contacts[i].email),email)==0)
                    {
                        check_email=1;
                        strcpy(new_email,email);
                        break;
                    }
                }
                if(check_email==0)
                {
                    printf("No contact with such email\n");
                }
            }
            for(int i=0; i<addressBook->contactCount; i++)
                {
                    if(strcmp(addressBook->contacts[i].email,new_email)==0)
                    {
                        for(int j=i; j<addressBook->contactCount-1; j++)
                        {
                            strcpy(addressBook->contacts[j].name,addressBook->contacts[j+1].name);
                            strcpy(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone);
                            strcpy(addressBook->contacts[j].email,addressBook->contacts[j+1].email);
                        }
                        addressBook->contactCount--;
                    }
                }
            printf("\nContact deleted successfully\n");
	    break;
        default:
            printf("Wrong choice\n");
    }
}

void read_from_csv(AddressBook *addressBook)
{
	addressBook->fptr = fopen("addressbook.csv","r");
	if(addressBook->fptr == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}
	char line[256];
	addressBook->contactCount=0;
	if(fgets(line,sizeof(line),addressBook->fptr)==NULL)
	{
		perror("File is empty or corrupted");
		fclose(addressBook->fptr);
		return;
	}
	while(fgets(line, sizeof(line), addressBook->fptr))
	{
		line[strcspn(line,"\n")]='\0';
		char name[50];
		char phone[20];
		char email[50];
		if(sscanf(line,"%49[^,],%19[^,],%49[^,\n]",name,phone,email)==3)
		{
			strcpy(addressBook->contacts[addressBook->contactCount].name,name);
			strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
			strcpy(addressBook->contacts[addressBook->contactCount].email,email);
			addressBook->contactCount++;
		}
		else
		{
			fprintf(stderr, "Skipping malformed line: %s",line);
		}

	}

}

void write_to_csv(AddressBook *addressBook)
{
	FILE *file = fopen("addressbook.csv","w");
	if(file == NULL)
	{
		perror("Unable to open file");
		exit(1);
	}
	fprintf(file,"Name,Phone,Email\n");
	for(int i=0; i<addressBook->contactCount; i++)
	{
		fprintf(file,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	}
	fclose(file);

}

