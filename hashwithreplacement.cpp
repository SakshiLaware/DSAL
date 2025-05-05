#include <iostream>
#include <string.h>
#define max 10
using namespace std;
struct node
{
    char name[10];
    long int mn;
    int chain;
    node()
    {
        mn = 0;
        chain = -1;
        strcpy(name, "-----");
    }
};
class telephone
{
public:
    node ht[max];
    int count;
    telephone() { count = 0; }

    int hashfun(long int);
    void insert();
    void find();
    void delno();
    void display();
};

int telephone::hashfun(long int num)
{
    return (num % 10);
}

void telephone::insert()
{
    node s;
    int ind;
    cout << "Enter name and telephone number: \n";
    cin >> s.name >> s.mn;
    ind = hashfun(s.mn);
    
    if (count == max - 1)
        cout << "Hash table full\n";
    if (ht[ind].mn == 0)
    {
        ht[ind] = s;
        count++;
    }
    else if (hashfun(ht[ind].mn) == ind)
    {
        int prev = ind;
        while (ht[ind].mn != 0)
        {
            if (ht[ind].chain != -1){
                ind = ht[ind].chain;
                prev = ind;
            }else
            {
                while (ht[ind].mn != 0)
                    ind = (ind + 1) % max;
                ht[prev].chain = ind;
            }
        }
        ht[ind] = s;
        count++;
    }
    else
    {
        int newIndex = ind;
        while (ht[newIndex].mn != 0)
            newIndex = (newIndex + 1) % max;

        node temp = ht[ind];
        ht[newIndex] = temp;
        ht[ind] = s;

        int tempIndex = hashfun(temp.mn);
        while (ht[tempIndex].chain != ind)
            tempIndex = ht[tempIndex].chain;
        ht[tempIndex].chain = newIndex;

        ht[ind].chain = -1;
        count++;
    }
}

void telephone::find()
{
    long int num;
    int cnt = 0;
    cout << "Enter the telephone number to search: ";
    cin >> num;
    int ind = hashfun(num);

    while (ind != -1)
    {
        cnt++;
        if (ht[ind].mn == num)
        {
            cout << "Record Found!\n";
            cout << "Name: " << ht[ind].name << "\tPhone: " << ht[ind].mn << " found at index " << ind << " comparison " << cnt << endl;

            return;
        }
        ind = ht[ind].chain;
    }
    cout << "Record Not Found!\n";
}

void telephone::delno()
{
    long int num;
    cout << "Enter the telephone number to delete: ";
    cin >> num;
    int ind = hashfun(num);
    int prev = -1;

    while (ind != -1)
    {
        if (ht[ind].mn == num)
        {
            cout << "Record Deleted!\n";
            ht[ind].mn = 0;
            strcpy(ht[ind].name, "-----");
            if (prev != -1)
                ht[prev].chain = ht[ind].chain;
            ht[ind].chain = -1;
            return;
        }
        prev = ind;
        ind = ht[ind].chain;
    }
    cout << "Record Not Found!\n";
}

void telephone::display()
{
    for (int i = 0; i < max; i++)
    {
        cout << i << "\t" << ht[i].name << "\t" << ht[i].mn << "\t" << ht[i].chain << endl;
    }
}

int main()
{
    telephone t;
    int ch;
    char ans;
    do
    {
        cout << "Enter your choice" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Display" << endl;
        cout << "3.Find" << endl;
        cout << "4.Delete" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.insert();
            break;
        case 2:
            t.display();
            break;
        case 3:
            t.find();
            break;
        case 4:
            t.delno();
            break;
        default:
            cout << "Invalid choice!!";
        }
        cout << "Do you want to continue? (1/0)";
        cin >> ans;
    } while (ans == '1');
    return 0;
}
