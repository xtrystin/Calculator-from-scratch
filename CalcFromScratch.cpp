#include <iostream>
#include <vector>>
using namespace std;


int Adder(int numb1, int numb2)                           
{
    int a, b;
    if (numb1 > numb2)
    {
        a = numb1;    
        b = numb2;
    }
    else
    {
        a = numb2;          
        b = numb1;
    }
    
    int digitA, digitB;
    int CarryIn = 0;
    int CarryOut = 0;
    vector <int> vScore;
    int temp;
    // decimal to binary
    while (a > 0)                       //a must be > than b         //what happen when a = b ??
    {
        digitA = a % 2;

        while (b > 0)   //if b is shorter, next digitB are 0
        {
            digitB = b % 2;

            b = b / 2;
            break;
        }
        //cout << digitA << " " << digitB << "\t";
       
        temp = (digitA ^ digitB) ^ CarryIn;     // xor xor
        vScore.push_back(temp);

        CarryOut = (digitA & digitB) | (CarryIn & (digitA ^ digitB));   // and or and xor
        //cout << CarryOut << " " << temp << endl;

        CarryIn = CarryOut;
        digitA = 0;
        digitB = 0;
        a = a / 2;
    }
    //Carry on last digit(before most significant bit, bacause score is reversed)
    if (CarryIn == 1)
        vScore.push_back(1);

   // for (int x : vScore)
   //     cout << x << " ";
   // cout << vScore.size();


   // bin to dec
    int score = vScore[vScore.size() - 1];
    for (int i = vScore.size()-1-1; i >= 0; i--)
    {

        score = (score * 2) + vScore[i];
    }
    cout << score;

    return score;
}



int main()
{
    int numb1, numb2;
    cout << "Number 1: ";
    cin >> numb1;
    cout << "Number 2: ";
    cin >> numb2;

    Adder(numb1, numb2);


    return 0;
}

