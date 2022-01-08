#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class billing
{
public:
    string name;
    double price;
};

int getData(billing menu[])
{
    fstream file("menu.txt", ios::in);
    int i = 0;
    billing temp;
    while (file)
    {
        getline(file, temp.name);
        file >> temp.price;
        file.ignore();
        menu[i] = temp;
        i++;
    }
    return i;
}

void showMenu(billing menuList[], int cnt)
{
    int i;
    cout << "\n Welcome to the Cafe \n\n --------Today's Menu-------- \n";
    for (i = 0; i < cnt; i++)
    {
        cout << "\n " << (i + 1) << ". $ " << menuList[i].price << "\t\t" << menuList[i].name;
    }
    cout << "\n \n";
}

int makeSelection(int item[], int quantity[], int cnt)
{
    int i = 0, temp;
    char ch;
    cout << "\n\n Do you want place an order? (y/n): ";
    cin >> ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\n\n Enter item number: ";
        cin >> temp;
        while (temp < 1 || temp > cnt)
        {
            cout << "\n\n Enter item number between 1 and " << cnt << ": ";
            cin >> temp;
        }
        item[i] = temp;
        cout << "\n Enter item quantity: ";
        cin >> temp;
        quantity[i] = temp;
        cout << "\n\n Select another item? (y/n): ";
        cin >> ch;
        i++;
    }
    return i;
}

void priceCheck(billing menuList[], int item[], int quantity[], int items)
{
    int i = 0;
    double total = 0, tax;
    cout << "\n\n Thank you for eating at The Cafe \n\n";
    cout << "----------------------------------------------------------";
    cout << "\n    Amount  \t\tQty \t  Items \n";
    cout << "----------------------------------------------------------\n";
    for (i = 0; i < items; i++)
    {
        cout << "\n $ " << quantity[i] * menuList[item[i] - 1].price << "\t\t" << quantity[i] << "\t"
             << (menuList[item[i] - 1].name);
        total += (quantity[i] * (menuList[item[i] - 1].price));
    }

    tax = (18 / 100.0) * total;
    cout << "\n\n Tax \t\t\t\t $ " << tax;
    cout << "\n----------------------------------------------------------";
    cout << "\n Amount Due  \t\t\t $ " << (total + tax);
    cout << "\n----------------------------------------------------------\n";
}

int main()
{
    while (true)
    {
        billing menuList[10];
        int item[10], quantity[10];
        int totalItems, cnt;
        cnt = getData(menuList);
        showMenu(menuList, cnt);
        totalItems = makeSelection(item, quantity, cnt);
        priceCheck(menuList, item, quantity, totalItems);
        int exit = 1;
        cout << "\n\n----------------------------------------------------------";
        cout << "\n\nEnter Zero(0) To Exit or 1 To Run Again.";
        cin >> exit;
        if (exit == 0)
            break;
        cout << "\n----------------------------------------------------------";
        cout << "\n\n";
    }
    return 0;
}