#include <iostream>
#include <string>
using namespace std;

float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void refCal(float ref, float curRef, float curKey)
{
    float i = ref/curRef;
    float prce = i * curKey;
    int n = static_cast<int>(i);
    float key = i - n;
    float f = curRef*key;
    cout << "You have " << round(i) << " keys\n" << n << " keys and " << round(f) << " refined\n" << "Price: " << round(prce) << endl;
}

void mainCal(float metal, string type, float curRef, float curKey)
{
    float i = metal/3;
    if(type == "E"||type == "e")
    {
        if(i >= curRef)
        {
            cout << "You have " << round(i) << " refined" << endl;
            refCal(i, curRef, curKey);
        }
        else
        {
            cout << "You have " << round(i) << " refined";
        }
    }
    else if(type == "S"||type == "s")
    {
        if(i >= 3)
        {
            cout << "You have " << round(i) << " reclaimed";
            i = i/3;
            if(i >= curRef)
            {
                cout << " or " << round(i) << " refined" << endl;
                refCal(i, curRef, curKey);
            }
            else
            {
                cout << " or " << round(i) << " refined";
            }
        }
        else
        {
            cout << "You have " << round(i) << " reclaimed";
        }
    }
}

void keyCal(float key, float curRef, float curKey)
{
    float i = curRef*key;
    cout << "You have " << round(i) << " refined.";
    i = i*3;
    cout << " or " << round(i) << " reclaimed";
    i = i*3;
    cout << " or " << round(i) << " scrap" << endl;
}

int main()
{
    string type = "";
    float amount = 0;
    float curRef = 0;
    float curKey = 0;

    cout << "\nCurrent refined to key conversion rate: \n";
    cin >> curRef;
    cout << "Current key price: \n";
    cin >> curKey;
    cout << "[R]efined, R[e]claimed, [S]crap or [K]ey" << endl;
    cin >> type;

    if(type == "R"||type == "r")
    {
        cout << "How much refined metal do you want to convert? ";
        cin >> amount;
        refCal(amount, curRef, curKey);
    }
    else if (type == "E"||type == "e")
    {
        cout << "How much reclaimed metal do you want to convert? ";
        cin >> amount;
        mainCal(amount, type, curRef, curKey);
    }
    else if (type == "S"||type == "s")
    {
        cout << "How much scrap metal do you want to convert? ";
        cin >> amount;
        mainCal(amount, type, curRef, curKey);
    }
    else if (type == "K"||type == "k")
    {
        cout << "How many keys do you want to convert? ";
        cin >> amount;
        keyCal(amount, curRef, curKey);
    }
    else
    {
        cout << "Error: Not a valid type";
    }
   
    return EXIT_SUCCESS;
}