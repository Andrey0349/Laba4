#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct mylist {
    float data;
    mylist *next;
    mylist *previous;
};

bool IfHeadNULL(mylist *&head) {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}
bool IfTailNULL(mylist*& tail) {
    if (tail == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void PrintAllHtT(mylist *&head) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    mylist *current = head;
    cout << "Your list:" << endl;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return;
}

void PrintAllTtH(mylist *&tail) {
    if (IfTailNULL(tail) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    mylist *current = tail;
    cout << "Your list:" << endl;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->previous;
    }
    cout << endl;
    return;
}

void NewHead(mylist *&head) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    float mynum;
    cout << "Enter element: ";
    cin >> mynum;

    mylist* add = new mylist;
    add->data = mynum;
    add->next = head;
    add->previous = NULL;

    if (head != NULL) {
        head->previous = add;
    }
    head = add;

    cout << "Element added successfully!" << endl;
    return;
}

void NewTail(mylist *&tail) {
    if (IfTailNULL(tail) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    float mynum;
    cout << "Enter element: ";
    cin >> mynum;

    mylist *add = new mylist;
    add->data = mynum;
    add->next = NULL;
    add->previous = tail;

    if (tail != NULL) {
        tail->next = add;
    }
    tail = add;
    cout << "Element added successfully!" << endl;
    return;
}

void AddElement(mylist *&head, mylist *&tail) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    PrintAllHtT(head);
    cout << "Choose element: ";
    bool found = false;
    float num, mynum;
    cin >> num;

    mylist *current = head;
    while (current != NULL) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    
    if (found == false) {
        cout << "Element not found!" << endl;
        return;
    }

    cout << "Enter new element: ";
    cin >> mynum;

    mylist *temp = new mylist;
    temp->data = mynum;
    temp->next = current->next;
    temp->previous = current;
    
    if (current->next != NULL) {
        mylist *nextElement = current->next;
        nextElement->previous = temp;
    }
    else {
        tail = temp;
    }
    
    current->next = temp;

    cout << "Element added successfully!" << endl;
    return;
}

void MakeList(mylist*& head, mylist*& tail) {
    if (IfHeadNULL(head) == false) {
        cout << "List is already existing!" << endl;
        PrintAllHtT(head);
        return;
    }
    else {
        mylist *add = new mylist;
        cout << "Enter first element of new list: ";
        cin >> add->data;
        add->next = head;
        add->previous = tail;
        head = add;
        tail = add;
        cout << "Created new list succefully!" << endl;
        PrintAllHtT(head);
    }
    return;
}

void Delete(mylist *&head, mylist *&tail) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    PrintAllHtT(head);
    cout << "Choose element to delete: ";
    bool found = false;
    float num;
    cin >> num;

    mylist *current = head;
    while (current != NULL) {
        if (current->data == num) {
            found = true;
            break;
        }
        current = current->next;
    }
    if (found == false) {
        cout << "Element not found!" << endl;
        return;
    }

    //Удаляем первый элемент
    if (current == head) {
        head = current->next;   //перемещаем head на следующий элемент
        if (head != NULL) {
            head->previous = NULL;  //у нового head убираем предыдущий указатель
        }
        else {
            tail = NULL;    //если список стал пустым
        }
    }
    //Удаляем последний элемент
    else if (current == tail) {
        tail = current->previous;   //Перемещаем tail на новый элемент
        tail->next = NULL;  //У нового tail убираем следующий указатель
    }
    //Удаляем элемент из середины
    else {
        mylist *TempNext = current->next;
        mylist *TempPrev = current->previous;

        TempPrev->next = TempNext;  //Предыдущий элемент теперь указывает на следующий
        TempNext->previous = TempPrev;  // Следующий элемент теперь указывает на предыдущий
    }

    delete current;
    cout << "Element deleted successfully!" << endl;
    return;
}

void DeleteAll(mylist *&head, mylist *&tail) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }

    mylist *current = head;
    while (current->next != NULL) {
        mylist *next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    cout << "Deleted list successfully!" << endl;
    
    return;
}

void PrintMAX_MIN(mylist *&head) {
    if (IfHeadNULL(head) == true) {
        cout << "List is empty!" << endl;
        return;
    }


    mylist *current = head;
    float MAX = current->data;
    float MIN = current->data;

    PrintAllHtT(head);

    while (current != NULL) {
        if (MIN >= current->data) {
            MIN = current->data;
        }
        if (MAX <= current->data) {
            MAX = current->data;
        }
        current = current->next;
    }
    cout << "MAX element = " << MAX << endl
        << "MIN element = " << MIN << endl;
    return;
}

int main()
{
    setlocale(LC_ALL, "RU");

    struct mylist *tail, *head, *tempcurr;
    tail = NULL;
    head = NULL;
    
    for (int i = 0; i <= 5; i++) {
        tempcurr = new mylist;
        tempcurr->data = i;
        tempcurr->previous = NULL;
        tempcurr->next = NULL;

        if (head == NULL) {
            head = tempcurr;
            tail = tempcurr;
        } 
        else {
            tail->next = tempcurr;
            tempcurr->previous = tail;
            tail = tempcurr;
        }
    }
    tempcurr = head;
    
    while (true) {
        cout << "\nПрактическая работа 4\n"
            << "Main menu\n"
            << "1.Make list\n"
            << "2. Print All elements (head to tail)\n"
            << "3. Print All elements (tail to head)\n"
            << "4. Add element (new head)\n"
            << "5. Add element (new tail)\n"
            << "6. Add element after element\n"
            << "7. Print MAX and MIN\n"
            << "8. Delete element\n"
            << "9. Delete all list\n"
            << "10. Exit...\n";

        int num;
        cin >> num;

        switch(num) {
        case 1:
            system("cls");
            MakeList(head, tail);
            break;
        case 2:
            system("cls");
            PrintAllHtT(head);
            break;
        case 3:
            system("cls");
            PrintAllTtH(tail);
            break;
        case 4:
            system("cls");
            NewHead(head);
            break;
        case 5:
            system("cls");
            NewTail(tail);
            break;
        case 6:
            system("cls");
            AddElement(head, tail);
            break;
        case 7:
            system("cls");
            PrintMAX_MIN(head);
            break;
        case 8:
            system("cls");
            Delete(head, tail);
            break;
        case 9:
            system("cls");
            DeleteAll(head, tail);
            break;
        case 10:
            system("cls");
            DeleteAll(head, tail);
            cout << "Exit...\n";
            return 0;
        default:
            system("cls");
            cout << "Enter 1-10!";
        }
    }
    return 0;
}
