#include <stdio.h>
#include "list.h"

int checkNumber(int *number);
int checkConfirmation(char *confirmation);
int checkFileName(char *fileName);

int main(void)
{
    FILE *inputFile;
    FILE *outputFile;
    
    Node *head = NULL;
    Node *newHead = NULL;

    int number;
    int choice;
    int targetValue;
    int newValue;
    int outputChoice;
    char fileName[256];
    char confirmation;

    do
    {
        printf("\n===== MENIU =====\n");
        printf("0. Sukurti tuscia sarasa\n");
        printf("1. Nuskaityti sarasa is failo\n");
        printf("2. Spausdinti sarasa (ekranas arba failas)\n");
        printf("3. Iterpti elementa pries nurodyta reiksme\n");
        printf("4. Istrinti visa sarasa\n");
        printf("5. Baigti programa\n");
        printf("\nPasirinkite veiksma: ");

        if (checkNumber(&choice) != 1)
        {
            if (feof(stdin))
            {
                printf("\nIvestis baigta. Programa baigiama.\n");
                break;
            }

            printf("\nKlaida: iveskite sveikaji skaiciu.\n");            
            continue;
        }

        switch (choice)
        {
            case 0:
                if (head != NULL)
                {
                    printf("Sarasas jau egzistuoja.\n");
                    printf("Ar norite sukurti tuscia sarasa (t/n): ");

                    if (checkConfirmation(&confirmation) != 1)
                    {
                        printf("Klaida: nepavyko nuskaityti pasirinkimo.\n");
                        break;
                    }

                    if (confirmation == 't')
                    {
                        destroyList(&head);
                        printf("Tuscias sarasas sukurtas.\n");
                    }   
                    else if (confirmation == 'n')
                    {
                        printf("Veiksmas atsauktas.\n");
                    }
                    else
                    {
                        printf("Klaida: neteisinga ivestis. Iveskite t arba n.\n");
                    }
                }

                else
                {
                    printf("Tuscias sarasas sukurtas\n");
                }
                
                break;

            case 1:

                if (head != NULL)
                {
                    printf("Sarasas jau egzistuoja.\n");
                    printf("Ar norite ji pakeisti? (t/n): ");

                    if (checkConfirmation(&confirmation) != 1)
                    {
                        printf("Klaida: nepavyko nuskaityti pasirinkimo.\n");
                        break;
                    }
   
                    if (confirmation == 'n')
                    {
                        printf("Veiksmas atsauktas.\n");
                        break;
                    }
                    else if (confirmation != 't')
                    {
                        printf("Klaida: neteisinga ivestis. Iveskite t arba n.\n");
                        break;
                    }
                }

                printf("Iveskite failo pavadinima: ");

                if (checkFileName(fileName) != 1)
                {
                    printf("Klaida: nepavyko nuskaityti failo pavadinimo.\n");
                    break;
                }

                inputFile = fopen(fileName, "r");

                if (inputFile == NULL)
                {
                    printf("Klaida: nepavyko atidaryti failo.\n");
                    break;
                }

                newHead = NULL;

                while (fscanf(inputFile, "%d", &number) == 1)
                {
                    if (insertEnd(&newHead, number) == 0)
                    {
                        printf("Klaida: nepavyko prideti elemento.\n");
                        fclose(inputFile);
                        destroyList(&newHead);
                        destroyList(&head);
                        return 1;
                    }   
                }

                if (!feof(inputFile))
                {
                    printf("Klaida: nepavyko nuskaityti visu duomenu.\n");
                    fclose(inputFile);
                    destroyList(&newHead);
                    break;
                }

                fclose(inputFile);
                destroyList(&head);
                head = newHead;
                newHead = NULL;

                printf("Failas sekmingai nuskaitytas.\n");

                break;

            case 2:
                printf("Kur norite spausdinti sarasa?\n");
                printf("1. I ekrana\n");
                printf("2. I faila\n");
                printf("Pasirinkite: ");

                if (checkNumber(&outputChoice) != 1)
                {
                    printf("Klaida: neteisinga ivestis.\n");
                    break;
                }

                if (outputChoice == 1)
                {
                    printList(head, stdout);
                }

                else if (outputChoice == 2)
                {
                    printf("Iveskite rezultatu failo pavadinima: ");

                    if (checkFileName(fileName) != 1)
                    {
                        printf("Klaida: nepavyko nuskaityti failo pavadinimo.\n");
                        break;
                    }

                    printf("Demesio! Jei failas jau egzistuoja, jo turinys bus perrasytas.\n");
                    printf("Ar norite testi? (t/n): ");
                    
                    if (checkConfirmation(&confirmation) != 1)
                    {
                        printf("Klaida: iveskite tik t arba n.\n");
                        break;
                    }

                    if (confirmation == 'n')
                    {
                        printf("Veiksmas atsauktas.\n");
                        break;
                    }

                    outputFile = fopen(fileName, "w");

                    if (outputFile == NULL)
                    {
                        printf("Klaida: nepavyko sukurti rezultatu failo.\n");
                        break;
                    }

                    printList(head, outputFile);

                    if (fclose(outputFile) == 0)
                    {
                        printf("Sarasas sekmingai issaugotas faile.\n");
                    }
                    else
                    {
                        printf("Klaida: nepavyko tinkamai uzdaryti failo.\n");
                    }

                }

                else
                {
                    printf("Klaida: neteisinga ivestis. Iveskite 1 arba 2.\n");
                }

                break;

            case 3:
                if (head == NULL)
                {
                    printf("Klaida: sarasas tuscias.\n");
                    break;
                }

                printf("Pries kokia reiksme norite iterpti elementa? ");
                if (checkNumber(&targetValue) != 1)
                {
                    printf("Klaida: iveskite sveikaji skaiciu.\n");
                    break;
                }

                printf("Iveskite naujo elemento reiksme: ");
                if (checkNumber(&newValue) != 1)
                {
                    printf("Klaida: iveskite sveikaji skaiciu.\n");
                    break;
                }

                if (insertBefore(&head, targetValue, newValue) == 1)
                {
                    printf("Elementas sekmingai iterptas.\n");
                }

                else
                {
                    printf("Klaida: nurodytas elementas nerastas arba iterpti nepavyko.\n");
                }

                break;

            case 4:
                if (head != NULL)
                {
                    printf("Sarasas jau egzistuoja.\n");
                    printf("Ar norite istrinti sarasa (t/n): ");

                    if (checkConfirmation(&confirmation) != 1)
                    {
                        printf("Klaida: nepavyko nuskaityti pasirinkimo.\n");
                        break;
                    }

                    if (confirmation == 't')
                    {
                        destroyList(&head);
                        printf("Sarasas sekmingai istrintas.\n");
                    }   
                    else if (confirmation == 'n')
                    {
                        printf("Veiksmas atsauktas.\n");
                    }
                    else
                    {
                        printf("Klaida: neteisinga ivestis. Iveskite t arba n.\n");
                    }
                }

                else
                {
                    printf("Sarasas jau tuscias\n");
                }
                
                break;

            case 5:
                printf("Programa baigiama.\n");
                break;

            default:
                printf("Klaida: tokio meniu pasirinkimo nera.\n");
                break;
        }  
        
        if (feof(stdin))
        {
            printf("\nIvestis baigta. Programa baigiama.\n");
            break;
        }

    } while (choice != 5);

    destroyList(&head);

    return 0;
}

int checkFileName(char *fileName)
{
    int inputChar;
    int result;

    result = scanf("%255s", fileName);

    if (result != 1)
    {
        while ((inputChar = getchar()) != '\n' && inputChar != EOF)
        {
        }

        return 0;
    }

    inputChar = getchar();

    while (inputChar == ' ' || inputChar == '\t')
    {
        inputChar = getchar();
    }

    if (inputChar != '\n' && inputChar != EOF)
    {
        while ((inputChar = getchar()) != '\n' && inputChar != EOF)
        {
        }

        return 0;
    }

    return 1;
}

int checkConfirmation(char *confirmation)
{
    int inputChar;
    int nextChar;

    inputChar = getchar();

    if (inputChar != 't' && inputChar != 'n')
    {
        while ((inputChar = getchar()) != '\n' && inputChar != EOF)
        {
        }
        return 0;
    }

    nextChar = getchar();

    if (nextChar != '\n' && nextChar != EOF)
    {
        while ((nextChar = getchar()) != '\n' && nextChar != EOF)
        {
        }
        return 0;
    }

    *confirmation = (char)inputChar;

    return 1;
}


int checkNumber(int *number)
{
    char input[256];
    int index = 0;
    int value = 0;
    int negative = 0;
    int limit;
    int digit;
    int inputChar;

    if (fgets(input, sizeof(input), stdin) == NULL)
    {
        return 0;
    }

    while (input[index] != '\0' && input[index] != '\n')
    {
        index++;
    }

    if (input[index] != '\n' && !feof(stdin))
    {
        while ((inputChar = getchar()) != '\n' && inputChar != EOF)
        {
        }

        return 0;
    }

    index = 0;

    while (input[index] == ' ' || input[index] == '\t')
    {
        index++;
    }

    if (input[index] == '-' || input[index] == '+')
    {
        negative = (input[index] == '-');
        index++;
    }

    if (input[index] < '0' || input[index] > '9')
    {
        return 0;
    }

    limit = negative ? -2147483647 - 1 : -2147483647;

    while (input[index] >= '0' && input[index] <= '9')
    {
        digit = input[index] - '0';

        if (value < (limit + digit) / 10)
        {
            return 0;
        }

        value = value * 10 - digit;
        index++;
    }

    while (input[index] == ' ' || input[index] == '\t')
    {
        index++;
    }

    if (input[index] != '\n' && input[index] != '\0')
    {
        return 0;
    }

    *number = negative ? value : -value;

    return 1;
}
