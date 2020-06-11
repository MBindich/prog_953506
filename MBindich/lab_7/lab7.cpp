#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef char tLastname[15];
typedef char tFirstname[15];
typedef char tMiddlename[20];
typedef int tCourse;
typedef int tGroup;
typedef int tRoomNumber;
typedef char tOffence[3];
typedef char tPhoneNumber[15];
typedef char tProfession[30];

enum Faculties
{
    FKP,
    FITU,
    FRE,
    FKSiS,
    FIK,
    IEF,
    VF
};

struct Resident  			//������ ���������
{
    tLastname lastname;
    tFirstname firstname;
    tMiddlename middlename;
    Faculties faculty;
    tCourse course;
    tGroup group;
    tRoomNumber roomNumber;
    tOffence offence;
    Resident *next, *prev;
};

struct Staff  					//�������� � ���������
{
    tProfession profession;
    tLastname lastname;
    tFirstname firstname;
    tMiddlename middlename;
    tPhoneNumber phoneNumber;
};

struct ResidentList
{
    int amount;
    struct Resident* head;
};

struct ResidentList* Initialization() 				//��������������� ������
{
    struct ResidentList* residentList;
    residentList = (ResidentList*)malloc(sizeof(ResidentList));
    struct Resident* head;
    head = (Resident*)malloc(sizeof(Resident));
    residentList->head = head;
    residentList->head->prev = NULL;
    residentList->head->next = NULL;
    residentList->amount = 0;
    return(residentList);
}

void LoadStaff(Staff* staff) 			//��������� ������ � �������� �� �����
{
    FILE* file;
    file = fopen("C:/Cb_projects(2)/LR7/DormStaff.txt", "r");

    if (!file)
    {
        printf("\nNot found staff");
        return;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            fgets(staff[i].profession, 30, file);
            fgets(staff[i].lastname, 15, file);
            fgets(staff[i].firstname, 15, file);
            fgets(staff[i].middlename, 20, file);
            fgets(staff[i].phoneNumber, 15, file);
        }
    }
    fclose(file);
    return;
}

void ShowStaff(Staff *staff)  				//�������� ������ � �������� � ���������
{
    for (int i = 0; i < 8; i++)
    {
        printf("\n%s", staff[i].profession);
        printf("%s", staff[i].lastname);
        printf("%s", staff[i].firstname);
        printf("%s", staff[i].middlename);
        printf("%s", staff[i].phoneNumber);
    }
}

void LoadResidents(ResidentList* list)  			//��������� ������ � ������� ��������� �� �����
{
    FILE* file;
    file = fopen("C:/Cb_projects(2)/LR7/DormResidents.txt", "r");
    char str[20] = "";
    while (fgets(str, 20, file) != NULL)
    {
        list->amount++;
        if (list->amount != 1)
        {
            Resident* prev = (Resident*)malloc(sizeof(Resident));
            prev->next = list->head;
            list->head->prev = prev;
            list->head = prev;
        }

        strcpy(list->head->lastname, str);
        fgets(list->head->firstname, 15, file);
        fgets(list->head->middlename, 20, file);
        fgets(str, 20, file);
        list->head->faculty = (Faculties)atoi(str);
        fgets(str, 20, file);
        list->head->course = atoi(str);
        fgets(str, 20, file);
        list->head->group = atoi(str);
        fgets(str, 20, file);
        list->head->roomNumber = atoi(str);
        fgets(list->head->offence, 3, file);
    }
}

const char* getFacultyName(enum Faculties fac)			//��� ����������� ����������� ��� ������ ������
{
    switch (fac)
    {
    case FKP:
        return "FKP";
    case FITU:
        return "FITU";
    case FRE:
        return "FRE";
    case FKSiS:
        return "FKSiS";
    case FIK:
        return "FIK";
    case IEF:
        return "IEF";
    case VF:
        return "VF";
    }
}

void Report(ResidentList* list)  			//����� � ������� ��������� (����� ������)
{
    Resident* ptr = list->head;
    int number = 1;
    while (ptr)
    {
        printf("\nStudent #%d %s%s%s", number, ptr->lastname, ptr->firstname, ptr->middlename);
        printf("%s", getFacultyName(ptr->faculty));
        printf("\nCourse: %d", ptr->course);
        printf("\nGroup: %d", ptr->group);
        printf("\nRoom number: %d", ptr->roomNumber);
        printf("\nIs offences: %s\n", ptr->offence);
        ptr = ptr->next;
        number++;
    }

    free(ptr);
}

void Delete(ResidentList* list, Staff* staff) 		//�������� ������
{
    free(staff);

//    nullptr;
    while (list->head->next != nullptr)
    {
        list->head = list->head->next;
        free(list->head->prev);
    }

    free(list->head);
}


void AddResident(ResidentList* residentList) 			//�������� ������ ������ � ���������
{
    residentList->amount++;
    if (residentList->amount != 1)
    {
        Resident* prev = (Resident*)malloc(sizeof(Resident));
        prev->next = residentList->head;
        residentList->head->prev = prev;
        residentList->head = prev;
    }

    int student;
    printf("Enter Student's Lastname: ");
    fgets(residentList->head->lastname, 15, stdin);
    fgets(residentList->head->lastname, 15, stdin);
    fflush(stdin);
    printf("Enter Student's Firstname: ");
    fgets(residentList->head->firstname, 15, stdin);
    fflush(stdin);
    printf("Enter Student's Middlename: ");
    fgets(residentList->head->middlename, 20, stdin);
    fflush(stdin);
    printf("Enter Student's Faculty number: ");
    scanf("%d", &student);
    residentList->head->faculty = (Faculties)student;
    printf("Enter Student's course: ");
    scanf("%d", &student);
    residentList->head->course = student;
    printf("Enter Student's group: ");
    scanf("%d", &student);
    residentList->head->group = student;
    printf("Enter Student's room number: ");
    scanf("%d", &student);
    residentList->head->roomNumber = student;
    printf("Is offence?(+ or -) ");
    fgets(residentList->head->offence, 3, stdin);
    fgets(residentList->head->offence, 15, stdin);
    fflush(stdin);
}

void DeleteResident(ResidentList* list) 		//������� ������ �� ��������� �� ������
{
    printf("Enter number: ");
    int forDelete;
    scanf("%d", &forDelete);
    if (forDelete == 1)
    {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
        list->amount--;
    }
    else if (forDelete == list->amount)
    {
        Resident *temp = list->head;
        for (int i = 1; i < forDelete; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
        list->amount--;
    }
    else if (forDelete < list->amount)
    {
        Resident* temp = list->head;
        for (int i = 1; i < forDelete; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        list->amount--;
    }
}

void SearchName(ResidentList* list) 		//������ ������� ��������� �� �������
{
    int counter = 0;
    Resident* temp = list->head;
    printf("Enter Lastname: ");
    tFirstname nameSearch;
    fgets(nameSearch, 15, stdin);
    fgets(nameSearch, 15, stdin);
    fflush(stdin);

    while (temp)
    {
        tFirstname subNameSearch;
        strcpy(subNameSearch, nameSearch);
        subNameSearch[0] -= 32;
        if (!strcmp(temp->lastname, nameSearch) || !strcmp(temp->lastname, subNameSearch))
        {
            printf("\nLastname: %s", temp->lastname);
            printf("Firstname: %s", temp->firstname);
            printf("Middlename: %s", temp->middlename);
            printf("Course: %d", temp->course);
            printf("\nGroup: %d", temp->group);
            printf("\nFaculty: %s", getFacultyName(temp->faculty));
            printf("\nRoom: %d", temp->roomNumber);
            printf("\nIs offences: %s\n", temp->offence);
            counter++;
        }

        temp = temp->next;
    }

    if (!counter)
    {
        printf("\nA resident with this Lastname does not live in the Dorm\n");
    }
}

void SearchRoom(ResidentList* list) 			//������ ������� ��������� �� �������
{
    int counter = 0;
    printf("Enter room: ");
    tRoomNumber roomSearch;
    scanf("%d", &roomSearch);
    Resident* temp = list->head;

    while (temp)
    {
        if (temp->roomNumber == roomSearch)
        {
            printf("\nLastname: %s", temp->lastname);
            printf("Firstname: %s", temp->firstname);
            printf("Middlename: %s", temp->middlename);
            printf("Course: %d", temp->course);
            printf("\nGroup: %d", temp->group);
            printf("\nFaculty: %s", getFacultyName(temp->faculty));
            printf("\nRoom: %d", temp->roomNumber);
            printf("\nIs offences: %s\n", temp->offence);
            counter++;
        }

        temp = temp->next;
    }

    if (!counter)
    {
        printf("\nThis room is not occupied or does not exist\n");
    }
}

void Menu()  			//���������� ���� ��������� ��������
{
    printf("\n\t\t Menu");
    printf("\n1) Add a resident to the dorm");
    printf("\n2) Delete a resident from the dorm");
    printf("\n3) Search by Lastname");
    printf("\n4) Search by room number");
    printf("\n5) Report");
    printf("\n6) Contact information about the staff.");
    printf("\n7) Exit\n");
    printf("\nYour select: ");
}

int main()
{
    ResidentList* residentList = Initialization();
    LoadResidents(residentList);
    Staff* staff;
    staff = (Staff*)malloc(8 * sizeof(Staff));
    LoadStaff(staff);

    printf("Welcome to the DormDatabase!");
    bool forExit = true;
    do
    {
        Menu();
        int switcher = 0;
        scanf("%d", &switcher);
        switch (switcher)
        {
        case 1:
            AddResident(residentList);
            break;
        case 2:
            DeleteResident(residentList);
            break;
        case 3:
            SearchName(residentList);
            break;
        case 4:
            SearchRoom(residentList);
            break;
        case 5:
            Report(residentList);
            break;
        case 6:
            ShowStaff(staff);
            break;
        case 7:
            forExit = false;
            break;
        }

        fflush(stdin);
    }
    while (forExit);

    Delete(residentList, staff);
}
