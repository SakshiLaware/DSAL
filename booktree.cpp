#include<iostream>
#include<string.h>
using namespace std;

struct node{
    char label[20];
    int ch_count;
    struct node *child[20];
}*root;

class GT{
    public:
    void create_tree();
    void display(node *r1);
    GT(){
	root = NULL;
    }
};
void GT :: create_tree(){
    int tchapters, i, j, k;
    root = new node;
    cout<<"Enter name of book: ";
    cin>>root->label;
    cout<<"Enter no of chapters in book : ";
    cin>>root->ch_count;
    for(i = 0; i<root->ch_count; i++){
	root->child[i] = new node;
        cout << "Enter Chapter name\n";
        cin >> root->child[i]->label;
        cout << "Enter no. of sections in  Chapter: " << root->child[i]->label << " : ";
        cin >> root->child[i]->ch_count;
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "Enter Section " << j + 1 << " name\n";
            cin >> root->child[i]->child[j]->label;
            cout << "Enter no. of subsections in " << root->child[i]->child[j]->label << " : ";
            cin >> root->child[i]->child[j]->ch_count;
            for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "Enter SubSection " << k + 1 << " name\n";
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void GT::display(node *r1)
{
    int i, j, k, tchapters;
    if (r1 != NULL)
    {
        cout << "\n-----Book Hierarchy-----";

        cout << "\n Book title : " << r1->label;
        tchapters = r1->ch_count;
        for (i = 0; i < tchapters; i++)
        {
            cout << "\n  Chapter " << i + 1;
            cout << "   " << r1->child[i]->label;

            for (j = 0; j < root->child[i]->ch_count; j++)
            {
                cout << "\n Sections " << j + 1;
                cout << "\n       " << r1->child[i]->child[j]->label;
                for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    cout << "\n Subsections " << k + 1;
                    cout << "\n           " << r1->child[i]->child[j]->child[k]->label;
                }
            }
        }
    }
}

int main()
{
    int choice;
    GT gt;
    do
    {
        cout << "Book Tree Creation" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
	cout << "3. Quit "<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;
        case 2:
            gt.display(root);
            break;
 
        default:
            cout << "Wrong choice" << endl;
	    break;
        }
    }while(choice == 1 or choice == 2);
}