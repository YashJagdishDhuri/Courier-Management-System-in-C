#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Courier 
{
    char sendername[50];
    char recievername[50];
    char sendercity[50];
    char recievercity[50];
    char senderstate[50];
    char recieverstate[50];
    char sendercountry[50];
    char recievercountry[50];
    char senderphone[20];
    char recieverphone[20];
    char status[20];
    float cost;
    char courier_id[10];
    float weight;
};

void insert() 
{
    struct Courier couriers;

    FILE *fp;
    fp = fopen("couriers.txt", "ab");

    printf("\n\n||------------------------ KINDLY ENTER THE REQUIRED INFORMATION ------------------------||\n\n");

    printf("\nEnter Courier ID : ");
    scanf("%s", couriers.courier_id);

    printf("\nEnter Sender's Name : ");
    scanf("%s", couriers.sendername);
    printf("\nEnter Reciever's Name : ");
    scanf("%s", couriers.recievername);

    printf("\nEnter Sender's City : ");
    scanf("%s", couriers.sendercity);
    printf("\nEnter Reciever's City : ");
    scanf("%s", couriers.recievercity);

    printf("\nEnter Sender's State : ");
    scanf("%s", couriers.senderstate);
    printf("\nEnter Reciever's State : ");
    scanf("%s", couriers.recieverstate);

    printf("\nEnter Sender's Country : ");
    scanf("%s", couriers.sendercountry);
    printf("\nEnter Reciever's Country : ");
    scanf("%s", couriers.recievercountry);

    printf("\nEnter Sender's Phone no. : ");
    scanf("%s", couriers.senderphone);
    printf("\nEnter Reciever's Phone no. : ");
    scanf("%s", couriers.recieverphone);

    printf("\nEnter Weight Of Package (in kg's) : ");
    scanf("%f", &couriers.weight);

    printf("\nEnter Status Of Package : ");
    scanf("%s", couriers.status);

    if (couriers.weight <= 5.0) {
        couriers.cost = 50.0;
    } else if (couriers.weight > 5.0 && couriers.weight <= 20.0) {
        couriers.cost = 150.0;
    } else if (couriers.weight > 20.0 && couriers.weight <= 50.0) {
        couriers.cost = 250.0;
    } else {
        couriers.cost = 300.0;
    }

    fwrite(&couriers, sizeof(struct Courier), 1, fp);

    printf("\n\n\t\t\t      🎉PACKAGE ADDED SUCCESSFULLY🎉\n");
    printf("\n\n\t\t   IF YOU WISH TO DO ANY OTHER OPERATION PROCEED BELOW\n");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");

    fclose(fp);
}

void display() 
{
    struct Courier couriers;
    FILE *fp;
    fp = fopen("couriers.txt", "rb");
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("\n\n\t\t          THERE ISN'T ANY COURIER INFORMATION");
    }
    else
    {
        fseek(fp, 0, SEEK_SET);
        printf("\n\n-------------|| HERE ARE THE INFORMATION OF COURIER'S THAT YOU HAVE INSERTED |---------------");
        while (fread(&couriers, sizeof(struct Courier), 1, fp)) 
        {
            printf("\n\nSender's Name : %s\nReciever's Name : %s\n\nSender's City : %s\nReciever's City :%s\n\nSender's State : %s\nReciever's State : %s\n\nSender's Country : %s\nReciever's Country :%s\n\nSender's Phone no. : %s\nReciever's Phone no. : %s\n\nWeight Of Package (in kg's) : %.2f\n\nStatus Of Package : %s\n\nCost Calculated : ₹%.2f\n\n\n", couriers.sendername, couriers.recievername, couriers.sendercity, couriers.recievercity, couriers.senderstate, couriers.recieverstate, couriers.sendercountry, couriers.recievercountry, couriers.senderphone, couriers.recieverphone, couriers.weight, couriers.status, couriers.cost);
            printf("------------------------------------------------------------------------------------------------\n");
            printf("------------------------------------------------------------------------------------------------");
        }
    }
    printf("\n\t\t   IF YOU WISH TO DO ANY OTHER OPERATION PROCEED BELOW\n");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");
    fclose(fp);
}
    
void search()
{
    char courier_id[10];
    struct Courier couriers;
    FILE *fp;
    fp = fopen("couriers.txt", "rb");

    printf("\n\nEnter Courier ID To Search For Courier : ");
    scanf("%s", courier_id);

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("\n\n\t\t       THERE ISN'T ANY COURIER HAVING COURIER ID '%s'\n", courier_id);
        printf("\t\t       IF YOU WANT TO ADD ANY PACKAGE PROCEED BELOW\n");
        printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
        printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
        printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
        printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");
    }
    else
    {
        fseek(fp, 0, SEEK_SET);

        while (fread(&couriers, sizeof(struct Courier), 1, fp)) 
        {
            if (strcmp(courier_id, couriers.courier_id) == 0)
            {
                printf("\n\n------------|| HERE!!, THIS IS THE COURIER INFORMATION YOU ARE LOOKING FOR ||------------");
                printf("\n\nSender's Name : %s\nReciever's Name : %s\n\nSender's City : %s\nReciever's City : %s\n\nSender's State : %s\nReciever's State : %s\n\nSender's Country : %s\nReciever's Country : %s\n\nSender's Phone no. : %s\nReciever's Phone no. : %s\n\nWeight Of Package (in kg's) : %.2f\n\nStatus Of Package : %s\n\nCost Calculated : %.2f\n\n", couriers.sendername, couriers.recievername, couriers.sendercity, couriers.recievercity, couriers.senderstate, couriers.recieverstate, couriers.sendercountry, couriers.recievercountry, couriers.senderphone, couriers.recieverphone, couriers.weight, couriers.status, couriers.cost);
                printf("\n\n\t\t   IF YOU WISH TO DO ANY OTHER OPERATION PROCEED BELOW\n");
                printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
                printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
                printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
                printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");
                fclose(fp);
            }
        }
    }
    fclose(fp);
}

void delete_update() 
{
    char courier_id[10];
    int choice;
    struct Courier couriers;
    FILE *fp, *temp;
    fp = fopen("couriers.txt", "rb");
    temp = fopen("temp.txt", "ab");

    printf("\n\nEnter Courier ID To 'DELETE/UPDATE' Courier : ");
    scanf("%s", courier_id);

    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("\n\n\t\t       THERE ISN'T ANY COURIER HAVING COURIER ID '%s'", courier_id);
    }
    else
    {
        fseek(fp, 0, SEEK_SET);
        while (fread(&couriers, sizeof(struct Courier), 1, fp)) 
        {
        
            if (strcmp(courier_id, couriers.courier_id) == 0) 
            {
            printf("\n\n-----------|| HERE IS THE COURIER INFORMATION THAT YOU WANT TO 'DELETE/UPDATE' ||-----------");
            printf("\n\nSender's Name : %s\nReciever's Name : %s\n\nSender's City : %s\nReciever's City : %s\n\nSender's State : %s\nReciever's State : %s\n\nSender's Country : %s\nReciever's Country : %s\n\nSender's Phone no. : %s\nReciever's Phone no. : %s\n\nWeight Of Package (in kg's) : %.2f\n\nStatus Of Package : %s\n\nCost Calculated : ₹%.2f", couriers.sendername, couriers.recievername, couriers.sendercity, couriers.recievercity, couriers.senderstate, couriers.recieverstate, couriers.sendercountry, couriers.recievercountry, couriers.senderphone, couriers.recieverphone, couriers.weight, couriers.status, couriers.cost);

            printf("\n\n\t\t\t       .....CHOOSE ANY OPTION.....  \n\n");
            printf("To DELETE Enter {1}\n");
            printf("To UPDATE Enter {2}\n");
            scanf("%d", &choice);

            if (choice == 1) 
            {
                printf("\n\n\t\t\t     🫡 Courier 'DELETED' Successfully!\n\n");
            } 
            else 
            {
                printf("\n\n||                    KINDLY INSERT THE REQUIRED INFORMATION TO 'UPDATE' IT                   ||\n");
                printf("\nEnter Courier ID : ");
                scanf("%s", couriers.courier_id);

                printf("\nEnter Sender's Name : ");
                scanf("%s", couriers.sendername);
                printf("\nEnter Reciever's Name : ");
                scanf("%s", couriers.recievername);

                printf("\nEnter Sender's City : ");
                scanf("%s", couriers.sendercity);
                printf("\nEnter Reciever's City : ");
                scanf("%s", couriers.recievercity);

                printf("\nEnter Sender's State : ");
                scanf("%s", couriers.senderstate);
                printf("\nEnter Reciever's State : ");
                scanf("%s", couriers.recieverstate);

                printf("\nEnter Sender's Country : ");
                scanf("%s", couriers.sendercountry);
                printf("\nEnter Reciever's Country : ");
                scanf("%s", couriers.recievercountry);

                printf("\nEnter Sender's Phone no. : ");
                scanf("%s", couriers.senderphone);
                printf("\nEnter Reciever's Phone no. : ");
                scanf("%s", couriers.recieverphone);

                printf("\nEnter Weight Of Package (in kg's) : ");
                scanf("%f", &couriers.weight);

                printf("\nEnter Status Of Package : ");
                scanf("%s", couriers.status);

                if (couriers.weight <= 5.0) {
                    couriers.cost = 50.0;
                } else if (couriers.weight > 5.0 && couriers.weight <= 20.0) {
                    couriers.cost = 150.0;
                } else if (couriers.weight > 20.0 && couriers.weight <= 50.0) {
                    couriers.cost = 250.0;
                } else {
                    couriers.cost = 300.0;
                }
                fwrite(&couriers, sizeof(struct Courier), 1, temp);
                printf("\n\n\t\t\t     🫡 Courier UPDATED successfully!\n\n");
            }
            } 
            else 
            {
                fwrite(&couriers, sizeof(struct Courier), 1, temp);
            }
        }
    }
    printf("\n\t\t   IF YOU WISH TO DO ANY OTHER OPERATION PROCEED BELOW\n");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");

    fclose(fp);
    fclose(temp);

    remove("couriers.txt");
    rename("temp.txt", "couriers.txt");
}

void sort() 
{
    char courier_id[10];
    int choice1;
    struct Courier couriers[100], temp;
    FILE *fp;
    int i, j, count = 0;
    fp = fopen("couriers.txt", "rb");
    fseek(fp, 0, SEEK_END);
    if (ftell(fp) == 0)
    {
        printf("\n\n\t\t          THERE ISN'T ANY COURIER INFORMATION");
    }
    else
    {
        fseek(fp, 0, SEEK_SET);
        while (fread(&couriers[count], sizeof(struct Courier), 1, fp))
        {
            count++;
        }

        for (i = 0; i < count - 1; i++) 
        {
            for (j = i + 1; j < count; j++) 
            {
                if (strcmp(couriers[i].courier_id, couriers[j].courier_id) < 0) 
                {
                    temp = couriers[i];
                    couriers[i] = couriers[j];
                    couriers[j] = temp;
                }
            }
        }
    
        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------------");
        printf("\n     COURIER ID\t\tRECIEVER'S NAME\t\tRECIEVER'S ADDRESS\t\tRECIEVER'S PHONE\t\tWEIGHT\t\tCOST(₹)");
        printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        for (i = 0; i < count; i++) 
        {
            printf("  \t%s\t\t  %s\t \t      %s, %s, %s\t    %s\t\t       %.2f kg\t        ₹%.2f\n", couriers[i].courier_id, couriers[i].recievername, couriers[i].recievercity, couriers[i].recieverstate, couriers[i].recievercountry, couriers[i].recieverphone, couriers[i].weight, couriers[i].cost);
            printf("--------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        }
    }
    printf("\n\t\t   IF YOU WISH TO DO ANY OTHER OPERATION PROCEED BELOW\n");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\t|   |   |   |   |   |   |   |   |   |   |   |   |   |   |");
    printf("\n\t\tV   V   V   V   V   V   V   V   V   V   V   V   V   V   V\n");
    fclose(fp);
}

int main() 
{
    int choice;
    printf("\n\n-------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\tCOURIER MANAGEMENT SYSTEM\n");
        printf("\n-------------------------------------------------------------------------------------------");
    do 
    {
        
        printf("\n\nEnter {1} To Insert Courier Details\n");
        printf("Enter {2} To Display All Courier Details\n");
        printf("Enter {3} To Search For A Courier\n");
        printf("Enter {4} To DELETE/UPDATE Courier Details\n");
        printf("Enter {5} To Sort A Courier\n");
        printf("Enter {6} To Exit From The Program\n");
        printf("\nCHOOSE ANY OPTION : ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete_update();
                break;
            case 5:
                sort();
                break;
            case 6:
                printf("\n\n...........................................................................................");
                printf("\n\t\t\t          __EXITING PROGRAM__\n");
                printf("...........................................................................................\n\n\n");
                break;
            default:
                printf("\n\n\t\t\t\t    😶INVALID OPTION!😶\n\n");
        }
    } 
    while (choice != 6);
    return 0;
}