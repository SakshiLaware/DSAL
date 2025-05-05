#include<iostream>
#include<fstream>
using namespace std;

class student {
public:
    int roll;
    char name[20];
    char Class[4];
    char div;

public:
    void getdata() {
        cout << "Enter roll number: " << endl;
        cin >> roll;
        cout << "Enter name of student: " << endl;
        cin >> name;
        cout << "Enter class of student: " << endl;
        cin >> Class;
        cout << "Enter division: " << endl;
        cin >> div;
    }

    void putdata() {
        cout << "\n" << roll;
        cout << "\t" << name;
        cout << "\t" << Class;
        cout << "\t" << div;
    }

    int getroll() {
        return roll;
    }
};

void displaySpecific() {
    ifstream fin("a.txt", ios::in);
    if (!fin) {
        cout << "\nFile not found";
        return;
    }

    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    student s;
    bool found = false;

    while (fin.read((char*)&s, sizeof(s))) {
        if (s.getroll() == roll) {
            cout << "\nData of student";
            cout << "\nRoll\tName\tClass\tDivision";
            s.putdata();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent with roll number: " << roll << " not found";
    }

    fin.close();
}

void deleteSpecific() {
    ifstream fin("a.txt", ios::in);
    if (!fin) {
        cout << "\nFile not found";
        return;
    }

    ofstream fout("temp.txt", ios::out);
    int roll;
    cout << "\nEnter roll number to delete: ";
    cin >> roll;

    student s;
    bool found = false;

    while (fin.read((char*)&s, sizeof(s))) {
        if (s.getroll() == roll) {
            found = true;
            cout << "\nStudent with roll number: " << roll << " deleted successfully";
        } else {
            fout.write((char*)&s, sizeof(s));
        }
    }

    if (!found) {
        cout << "\nStudent with roll number " << roll << " not found";
    }

    fin.close();
    fout.close();
    remove("a.txt");
    rename("temp.txt", "a.txt");
}

int main() {
    int choice;
    char a;

    do {
        cout << "Enter your choice: ";
        cout << "\n1. Write \n2. Read\n3. Append\n4. Display Specific\n5. Delete Specific" << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            student s;
            int i, n;
            cout << "\nEnter how many students' data you want to add: " << endl;
            cin >> n;

            ofstream fout;
            fout.open("a.txt", ios::out | ios::binary); // Open in binary mode
            for (i = 0; i < n; i++) {
                s.getdata();
                fout.write((char*)&s, sizeof(s));
            }
            fout.close();
            break;
        }

        case 2: {
            ifstream fin("a.txt", ios::in | ios::binary); // Open in binary mode
            if (!fin) {
                cout << "\nFile not found";
                break;
            }

            student s1;
            cout << "\nData of students: ";
            cout << "\nRoll No.\tName\tClass\tDivision";

            while (fin.read((char*)&s1, sizeof(s1))) {
                s1.putdata();
            }

            fin.close();
            break;
        }

               case 3:
		{
		ofstream fout;
		fout.open("a.txt",ios::app);
		student s2;
		s2.getdata();
		fout.write((char*)&s2,sizeof(s2));
		fout.close();
		break;
		}


            case 4:
                displaySpecific();
                break;
            case 5:
                deleteSpecific();
                break;
            default:
                cout<<"\nInvalid Error";
            }
            
            cout<<"\n Do you want to continue?\n1.yes\n2.No"<<endl;
            cin>>a;
            }
        
        while(a=='1');
        return 0;
    }