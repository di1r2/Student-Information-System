
#include <iostream>
#include <string.h>
using namespace std;
#define optimizer 30
int counter = 0;
struct studentInformation
{
    char id[optimizer];
    char name[optimizer];
    char departement[optimizer];
    char gender[optimizer];
    float gpa;
};
void setSudentInformation(studentInformation &studinfo)
{
    system("cls");
    cin.ignore();
    cout << "\n enter student  id :";
    cin.getline(studinfo.id, optimizer);
    cout << "\n enter student name:";
    cin.getline(studinfo.name, optimizer);
    cout << "\n enter student departement:";
    cin.getline(studinfo.departement, optimizer);
    cout << "\n enter student gender:";
    cin.getline(studinfo.gender, optimizer);
    cout << "\n enter student gpa:";
    cin >> studinfo.gpa;
}
void displayStudentInfo(studentInformation studinfo[])
{
    int index = 0;
    cout << "\tNO"
         << "\t"
         << "ID"
         << "\t\t"
         << "Name"
         << "\t\t"
         << "Departement"
         << "\t\t"
         << "Gender"
         << "\t"
         << "Gpa" << endl;
    cout << "==========================================================================================" << endl;
    for (int index; index < counter; index++)
    {
        cout << "\t" << index << ".\t" << studinfo[index].id << "\t\t" << studinfo[index].name;
        cout << "\t\t" << studinfo[index].departement << "\t\t\t";
        cout << studinfo[index].gender << "\t" << studinfo[index].gpa << endl;
    }
}
/*function for bubble sorting by id*/
void BubbleSortingById(studentInformation Info[])
{
    studentInformation temp;
    int index, index1;
    int flag = 0;
    for (index = 0; index < counter - 1; index++)
    {
        for (index1 = 0; index1 < counter - index - 1; index1++)
        {
            if (strcmp(Info[index1].id, Info[index1 + 1].id) > 0)
            {
                temp = Info[index1];
                Info[index1] = Info[index1 + 1];
                Info[index1 + 1] = temp;
            }
        }
        if (flag == 0)
            cout << "student id is already sorted\n";
        break;
    }
}
/*  function for selection sorting by name*/
void selectionsortingbyname(studentInformation Info[])
{
    studentInformation temp, smalleststring;
    int index, index1, smallest;
    for (index = 0; index < counter - 1; index++)
    {
        smallest = index;
        smalleststring = Info[index];
        for (index1 = index + 1; index1 < counter; index1++)
        {
            if (strcmp(Info[index1].name, Info[smallest].name) < 0)
            {
                smallest = index1;
                smalleststring = Info[index1];
            }
        }
        if (smallest != index)
        {
            temp = Info[smallest];
            Info[smallest] = Info[index];
            Info[index] = temp;
        }
    }
} /*function for sorting gpa by inserting*/
void InsertionBYGpa(studentInformation Info[])
{
    int index, index2;
    studentInformation temp;
    for (index = 1; index < counter; index++)
    {
        temp = Info[index];
        for (index2 = index; index2 > 0 && Info[index2 - 1].gpa > temp.gpa; index2--)
        {
            Info[index2] = Info[index2 - 1];
        }
        Info[index2] = temp;
    }
}
/*linear searching by student ID*/
int LinearSearchingById(studentInformation Info[], char item[optimizer])
{
    int index = 0, pos = -1;

    for (index; index < counter; index++)
    {
        if (strcmp(item, Info[index].id) == 0)
        {
            pos = index;
        }
    }
    if (pos >= 0)
    {

        return pos;
    }
    else

        return -1;
}
int BinarySearchingById(studentInformation Info[], char key[optimizer])
{
    BubbleSortingById(Info);

    int start, mid, last, index = 0;
    start = 0;
    last = counter - 1;
    int flag = -1;
    for (index; index < counter && start < last && flag == -1; index++)
    {
        mid = (start + last) / 2;
        if (strcmp(key, Info[mid].id) == 0)
        {
            flag = mid;
        }
        else if (strcmp(key, Info[mid].id) < 0)
        {
            last = mid - 1;
        }
        else
            start = mid + 1;
    }
    if (flag >= 0)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}
void DeleteById(studentInformation Info[], char item[optimizer])
{
    int index, iter, found = -1;
    for (index = 0; index < counter && found == -1; index++)
    {
        if (strcmp(item, Info[index].id) == 0)
        {
            for (iter = index; iter < counter - 1; iter++)
            {
                Info[iter] = Info[iter + 1];
                found++;
                counter--;
            }
        }
    }
    if (found >= 0)
    {
        cout << "u deleted student with id " << item << "from Info:";
    }

    else
    {
        cout << " No student with id " << item;
    }
}
int main()
{
    studentInformation Info[100];
    char item[optimizer];

    int i, pos;
    char ch, selector;
    do
    {
        system("cls");
        cout << "press 1 to set student information\n";
        cout << "press 2 to display student information\n";
        cout << "press 3 to sort  student id by bubble\n";
        cout << "press 4 to sort  student name by selection\n";
        cout << "press 5 to sort  student gpa by insertion\n";
        cout << "press 6 to search linearly student by id \n";
        cout << "press 7 to search student by id  using binary searching\n";
        cout << "press 8  to delete student info by id\n";

        cout << "press 0 exit \n";

        cin >> selector;
        switch (selector)
        {
        case '1':
            setSudentInformation(Info[counter]);
            counter++;
            break;
        loc:

        case '2':

            displayStudentInfo(Info);
            break;
        case '3':
            BubbleSortingById(Info);
            cout << "student information after sorted by id is:\n";
            displayStudentInfo(Info);
            break;
        case '4':
            selectionsortingbyname(Info);
            cout << "student information after sorting by name\n";
            displayStudentInfo(Info);
            break;
        case '5':
            InsertionBYGpa(Info);
            cout << "student information after gpa is sorted by insertion\n";
            displayStudentInfo(Info);
            break;
        case '6':

            cout << "enter student id u want to search:";
            cin >> item;
            pos = LinearSearchingById(Info, item);
            if (pos >= 0)
            {
                displayStudentInfo(Info);
                cout << "\t" << pos << "\t" << Info[pos].id << "\t\t" << Info[pos].name;
                cout << "\t\t" << Info[pos].departement << "\t\t\t";
                cout << Info[pos].gender << "\t" << Info[pos].gpa << endl;
            }
            else
            {
                cout << " \n NO element found";
            }

            break;
        case '7':
            cout << "enter id of student u want to search by binary searching:";
            cin >> item;

            pos = BinarySearchingById(Info, item);
            if (pos >= 0)
            {
                cout << "\t" << pos << "\t" << Info[pos].id << "\t\t" << Info[pos].name;
                cout << "\t\t" << Info[pos].departement << "\t\t\t";
                cout << Info[pos].gender << "\t" << Info[pos].gpa << endl;
            }
            else
            {
                cout << " \n NO element found";
            }

            break;
        case '8':
            cout << "enter id of student u want delete :";
            cin >> item;
            DeleteById(Info, item);

            break;

        case '0':
            exit(0);
            break;
        default:
            cout << " selector is incorrect";
        }
        cout << "\n press any key except z to continue";
        cin >> ch;

    } while (ch != 'z');
    return 0;
}

