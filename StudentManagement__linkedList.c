#include <iostream>

#include<string>

using namespace std;

int MaxSize = 6;
int length = 0;

struct Student {
        int Id;
        string Name;
        char Grade;
};

Student * Arr = new Student[MaxSize];

bool IsEmpty() {
        return length == 0;
}

bool IsFull() {
        return length == 6;
}

void print(Student & S) {
        if (IsEmpty())
                cout << "The List is empty" << endl;
        else {

                cout << "Name      :  " << S.Name << "\t\t";
                cout << "Id number :  " << S.Id << "\t\t";
                cout << "Grade     :  " << S.Grade << endl;
                cout << endl;
        }
}

int SeqSearch(int ID) {
        for (int i = 0; i < length; i++)
                if (Arr[i].Id == ID)
                        return i;

        return -1;
}
void retrive(int loc, Student & obj) {
        if (loc < 0 || loc >= length)
                cout << "out of range" << endl;
        else
                obj = Arr[loc];
}

void remove(int ID) {
        if (IsEmpty())
                cout << "The List Is empty" << endl;
        else if (SeqSearch(ID) == -1)
                cout << "The id number does not exist" << endl;
        else {
                int loc = SeqSearch(ID);
                for (int i = loc; i < length - 1; i++)
                        Arr[i] = Arr[i + 1];
                length--;

                cout << "Your data after deletion is : " << endl;
                for (int i = 0; i < length; i++)
                        print(Arr[i]);
        }
}

void insert(Student & O) {
        if (IsFull())
                cout << "The List is Full" << endl;
        cin >> O.Name;
        cin >> O.Id;
        cin >> O.Grade;

        if (SeqSearch(O.Id) != -1) {
                cout << "The ID number you entered is present. Please enter another number\"No duplicates\" " << endl;
                cin >> O.Id;
        }
        while (O.Id < 100000 || O.Id > 999999) {
                cout << "Please enter your six-digit ID number" << endl;
                cin >> O.Id;

        }
        if (SeqSearch(O.Id) != -1) {
                cout << "The ID number you entered is present. Please enter another number\"No duplicates\" " << endl;
                cin >> O.Id;
        }
        while (O.Grade != 'A' && O.Grade != 'B' && O.Grade != 'C' && O.Grade != 'D' && O.Grade != 'F') {
                cout << "Please enter the tag from the following codes (A,B,C,D,F)" << endl;
                cin >> O.Grade;
        }
        if (IsFull())
                cout << "The List is Full" << endl;
        else {
                Arr[length] = O;
                length++;
        }
        for (int i = 0; i < length; i++)
                for (int j = length - 1; j > i; j--)
                        if (Arr[j].Id < Arr[j - 1].Id) {
                                Student Temp = Arr[j];
                                Arr[j] = Arr[j - 1];
                                Arr[j - 1] = Temp;
                        }

}

int main() {

        cout << "The Max Size of the array is 6" << endl;
        cout << endl;
        cout << "----------call up Function insert----------" << endl;
        cout << "Please enter the student's name, then his ID number and then his mark" << endl;
        for (int i = 0; i < 4; i++)
                insert(Arr[i]);

        cout << "Your data is : " << endl;
        for (int i = 0; i < length; i++)
                print(Arr[i]);
        cout << endl;
        cout << "----------call up Function remove----------" << endl;
        cout << "Delete a student from the system according to his ID number" << endl;
        int id1;
        cin >> id1;
        remove(id1);
        cout << endl;
        cout << "----------call up Function insert \"once again\"----------" << endl;
        for (int i = length; i < MaxSize; i++)
                insert(Arr[i]);

        cout << "Your data is : " << endl;
        for (int i = 0; i < length; i++)
                print(Arr[i]);
        cout << endl;
        cout << "----------call up Function remove \"once again\"----------" << endl;
        cout << "Delete a student from the system according to his ID number" << endl;
        cin >> id1;
        remove(id1);
        cout << endl;
        cout << "----------call up Function Search then Function retrieve by Function searching----------" << endl;
        cout << "Please enter the student ID number you want to search for and then retrieve" << endl;
        int id;
        cin >> id;
        cout << "your Location is : ";
        cout << SeqSearch(id) << endl;
        int x = SeqSearch(id);
        if (x != -1) {
                Student obj;
                retrive(x, obj);
                cout << "Retrive Name is : " << obj.Name << endl;
                cout << "Retrive Grade is : " << obj.Grade << endl;

        }
        cout << endl;
        cout << "----------call up Function print----------" << endl;
        cout << "Your data is : " << endl;
        for (int i = 0; i < length; i++)
                print(Arr[i]);

        return 0;
}