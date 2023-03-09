//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef doctorStrange_h
#define doctorStrange_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

///STUDENT'S ANSWER BEGINS HERE
///STUDENTS CAN ADD HELPER FUNCTIONS
struct info
{
    int maxHP;
    int HPtemp;
    int LVtemp;
    int EXPtemp;
    int TStemp;

    short livitation;
    bool checkLivitation;
    bool liviationFake;
    bool canTakeLivitation;
    short levelUpLivitation;

    bool checkPoiMushroom;
    short poiMushroom;
    
    bool negotiation;
    
    short wongFake;
    short realWong;
    bool checkRealWong;
    bool checkWongFake;

    bool checkBackTime;
};
struct events
{
    string eventCode;
    string data;
    int event13Matrix[7][7];
    int event14Matrix[1000];
};
int eventorder = 0;
long long toNumber(string str)
{
    int lens = str.length();
    long long temp = 1;
    long long num = 0;
    for(long long i = lens - 1; i >= 0; i--)
    {
        num += temp * (str[i] - 48);
        temp *= 10;
    }
    return num;
}
struct info strangeInfo[1000];
struct events strangeEvent[1000];
int eventOrder = 0;
int iNum = -1;
//process string event
void readEvent(string str)
{
    int lens = str.length();
    for (int i = 0; i < lens; i++)
    {
        if (str[i - 1] == '!' || str[i - 1] == '#')
        {
            iNum++;
            while (str[i] != '#' && str[i] != '!' && str[i] != ' ')
            {
                strangeEvent[iNum].eventCode = strangeEvent[iNum].eventCode + str[i];
                i++;
            }
        }
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (str[i - 1] == ' ' && str[i - 2] != '6' && str[i - 2] != '2')
                strangeEvent[iNum].data = strangeEvent[iNum].data + ' ';
            strangeEvent[iNum].data = strangeEvent[iNum].data + str[i];
        }
        //update to read more digits.
        if (str[i] >= '0' && str[i] <= '9' && strangeEvent[iNum].eventCode == "13")
        {
            string temp;
            for (int k = 0; k < 7; k++)
            {
                for (int p = 0; p < 7; p++)
                {
                    while(str[i] != ' ' && str[i] != '!' && str[i] != '#')
                    {
                        temp = temp + str[i];
                        i++;
                    }
                    strangeEvent[iNum].event13Matrix[k][p] = toNumber(temp);
                    temp = "";
                    i++;
                }
            }
            i--;
        }
        if (str[i] >= '0' && str[i] <= '9' && strangeEvent[iNum].eventCode == "14")
        {
            while (str[i] != ' ')
            {
                strangeEvent[iNum].data += str[i];
                i++;
            }
            int temp = 0;
            while (str[i] != '!' && str[i] != '#')
            {
                if (str[i] == ' ')
                {
                    strangeEvent[iNum].event14Matrix[temp] = stoi(str.substr(i + 1), 0, 10);
                    temp++;
                }
                i++;
            }
            strangeEvent[iNum].event14Matrix[temp] = -8888888;
        }
    }
}
void checkInfo(int eventOrder)
{
    if (strangeInfo[eventOrder].TStemp > 5)
        strangeInfo[eventOrder].TStemp = 5;
    //Strange die
    if (strangeInfo[eventOrder].HPtemp < 1 && strangeInfo[eventOrder].TStemp > 0)
    {
        strangeInfo[eventOrder].checkPoiMushroom = false;
        strangeInfo[eventOrder].poiMushroom = 0;
        strangeInfo[eventOrder].TStemp--;
        strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].maxHP;
        if (strangeInfo[eventOrder].wongFake > 0 && ((strangeEvent[eventOrder - 1].eventCode >= "1"
        && strangeEvent[eventOrder - 1].eventCode <= "5") || 
        strangeEvent[eventOrder - 1].eventCode == "11"))
        {
            strangeInfo[eventOrder].wongFake = 0;
            strangeInfo[eventOrder].checkWongFake = false;
        }
    } else if (strangeInfo[eventOrder].HPtemp < 1 && strangeInfo[eventOrder].TStemp == 0)
    {
        cout << -1;
        exit(0);
    }
    if (strangeInfo[eventOrder].maxHP < strangeInfo[eventOrder].HPtemp)
        strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].maxHP;
    //level up
    while (strangeInfo[eventOrder].EXPtemp >= 100 && strangeInfo[eventOrder].LVtemp < 10)
    {
        strangeInfo[eventOrder].LVtemp++;
        strangeInfo[eventOrder].EXPtemp -= 100;
        strangeInfo[eventOrder].maxHP += 50;
        strangeInfo[eventOrder].HPtemp += 10;
    }
    //set value exceeding limitation
    if (strangeInfo[eventOrder].LVtemp >= 10 && strangeInfo[eventOrder].EXPtemp > 100)
    {
        strangeInfo[eventOrder].LVtemp = 10;
        strangeInfo[eventOrder].EXPtemp = 100;
    }
    if (strangeInfo[eventOrder].LVtemp > 10)
        strangeInfo[eventOrder].LVtemp = 10;
    if (strangeInfo[eventOrder].maxHP > 999)
        strangeInfo[eventOrder].maxHP = 999;
    if (strangeInfo[eventOrder].HPtemp > 999)
        strangeInfo[eventOrder].HPtemp = 999;
}
//event 1-5
    //calculating dame
bool isPrime(int num);
long long primeNumber(int HP);
int damage(int LV0, int code)
{
    int ans = 0;
    switch(code)
    {
        case 1:
            ans =  (1.5 * LV0 * 10);
            break;
        case 2:
            ans = (2.5 * LV0 * 10);
            break;
        case 3:
            ans = (4.5 * LV0 * 10);
            break;
        case 4:
            ans = (7.5 * LV0 * 10);
            break;
        case 5:
            ans = (9.5 * LV0 * 10);
            break;
    }
    return ans;
}
    //calculating exp recieved
int increasedExp(int code)
{
    int ans = 0;
    switch(code)
    {
        case 1:
            ans = 10;
            break;
        case 2:
            ans = 20;
            break;
        case 3:
            ans = 40;
            break;
        case 4:
            ans = 50;
            break;
        case 5:
            ans = 70;
            break;
    }
    return ans;
}
void eventOneTofive(int eventOrder, int eventCode)
{
    int LVo = 0;
    int b = 0;
    b = eventOrder % 10;
    LVo = (eventorder > 6) ? (b > 5 ? b : 5) : b;
    //fighting
    if (strangeInfo[eventOrder].wongFake > 0)
    {
        strangeInfo[eventOrder].wongFake--;
        goto strangeLose;
    }
    if (strangeInfo[eventOrder].LVtemp > LVo || strangeInfo[eventOrder].realWong > 0)
    {
        strangeInfo[eventOrder].EXPtemp += increasedExp(eventCode);
        if (strangeInfo[eventOrder].realWong > 0)
            strangeInfo[eventOrder].realWong--;
    }
    else if (strangeInfo[eventOrder].LVtemp == LVo)
        strangeInfo[eventOrder].EXPtemp += (increasedExp(eventCode) / 2);
    else {
    strangeLose :
        if (strangeInfo[eventOrder].checkLivitation && strangeInfo[eventOrder].liviationFake == false
        && strangeInfo[eventOrder].livitation > 0)
        {
            strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].HPtemp - int((damage(LVo, eventCode) * 
            (100 - (eventOrder + primeNumber(strangeInfo[eventOrder].HPtemp)) % 100)) / 100);
            strangeInfo[eventOrder].livitation--;
        }
        else 
            strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].HPtemp - damage(LVo, eventCode);
    }
    checkInfo(eventOrder);
}

//event 6
void lowerCase(string &str)
{
    int lens = str.length();
    for (int i = 0; i < lens; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
}
void checkArchaism(string str, int &atk, int &defe)
{
    int lens = str.length();
    lowerCase(str);
    //check attack
    for (int i = 0; i <= lens - 6; i++)
    {
        if (str[i] == 'a')
        {
            for (int j = i + 1; j <= lens - 5; j++)
            {
                if (str[j] == 't')
                {
                    for (int k = j + 1; k <= lens - 4; k++)
                    {
                        if (str[k] == 't')
                        {
                            for (int p = k + 1; p <= lens - 3; p++)
                            {
                                if (str[p] == 'a')
                                {
                                    for (int h = p + 1; h <= lens - 2; h++)
                                    {
                                        if (str[h] == 'c')
                                        {
                                            for(int r = h + 1; r <= lens - 1; r++)
                                            {
                                                if (str[r] == 'k')
                                                    atk++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //check defense
    for (int u = 0; u <= lens - 7; u++)
    {
        if (str[u] == 'd')
        {
            for (int i = 0; i <= lens - 6; i++)
            {
                if (str[i] == 'e')
                {
                    for (int j = i + 1; j <= lens - 5; j++)
                    {
                        if (str[j] == 'f')
                        {
                            for (int k = j + 1; k <= lens - 4; k++)
                            {
                                if (str[k] == 'e')
                                {
                                    for (int p = k + 1; p <= lens - 3; p++)
                                    {
                                        if (str[p] == 'n')
                                        {
                                            for (int h = p + 1; h <= lens - 2; h++)
                                            {
                                                if (str[h] == 's')
                                                {
                                                    for(int r = h + 1; r <= lens - 1; r++)
                                                    {
                                                        if (str[r] == 'e')
                                                            defe++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void event6(int eventorder, string &archaism)
{
    int atk = 0;
    int defe = 0;
    int rateWin = 0;
    int rateLoseHP = 0;
    //set up rates
    checkArchaism(archaism, atk, defe);
    int F = (eventorder + archaism.length()) % 100;
    rateWin = 10 *  atk;
    rateLoseHP = 10 * defe;
    if (strangeInfo[eventOrder].checkLivitation && strangeInfo[eventOrder].liviationFake == false
    && strangeInfo[eventOrder].livitation > 0)
    {
        rateLoseHP += (eventorder + primeNumber(strangeInfo[eventOrder].HPtemp)) % 100;
        rateWin += (eventorder + primeNumber(strangeInfo[eventOrder].HPtemp)) % 100;
    }
    //fighting
    if (rateWin > F)
    {
        strangeInfo[eventOrder].EXPtemp += 200;
        strangeInfo[eventOrder].TStemp++;
    }
    else
    { 
        if (strangeInfo[eventOrder].livitation && strangeInfo[eventOrder].liviationFake == false
        && strangeInfo[eventOrder].checkLivitation == true)
            strangeInfo[eventOrder].livitation--;
        if (strangeInfo[eventOrder].HPtemp < 100)
            strangeInfo[eventOrder].HPtemp = -1;
        else if (rateLoseHP >= 100)
            strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].HPtemp;
        else
            strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].HPtemp - 
            strangeInfo[eventOrder].HPtemp * (100 - rateLoseHP) / 100;
    }
    checkInfo(eventOrder);
}

//event 7
    //Prime number
bool isPrime(int num)
{
    if (num == 2) return true;
    if (num <= 1) return false;
    for (int i = 2; i < num - 1; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
long long primeNumber(int HP)
{
    long long ans = HP + 1;
    while (!isPrime(ans))
        ans++;
    return ans;
}
void event7(int eventOrder)
{
    if ((!strangeInfo[eventOrder].checkLivitation || strangeInfo[eventOrder].liviationFake == true)
    && strangeInfo[eventOrder].canTakeLivitation == true && strangeInfo[eventOrder].negotiation == true)
    {
        if (strangeInfo[eventOrder].checkLivitation == false)
            strangeInfo[eventOrder].livitation = 3;
        strangeInfo[eventOrder].levelUpLivitation = strangeInfo[eventOrder].LVtemp;
        strangeInfo[eventOrder].LVtemp += 2;
        strangeInfo[eventOrder].liviationFake = false;
        strangeInfo[eventOrder].checkLivitation = true;
        checkInfo(eventOrder);
        strangeInfo[eventOrder].levelUpLivitation = strangeInfo[eventOrder].LVtemp - 
        strangeInfo[eventOrder].levelUpLivitation;
        //change livitation
        if (strangeInfo[eventOrder].checkWongFake == true && strangeInfo[eventOrder].wongFake > 0)
        {
            strangeInfo[eventOrder].LVtemp -= strangeInfo[eventOrder].levelUpLivitation;
            strangeInfo[eventOrder].wongFake--;
            strangeInfo[eventOrder].liviationFake = true;
        }
  
    }
    
}

//event 8
void event8(int eventOrder)
{
    if (strangeInfo[eventOrder].checkRealWong == false)
    {
        strangeInfo[eventOrder].checkRealWong = true;
        strangeInfo[eventOrder].realWong = 3;
    } else if (strangeInfo[eventOrder].realWong > 0)
        strangeInfo[eventOrder].realWong--;
    else if (strangeInfo[eventOrder].realWong == 0 && strangeInfo[eventOrder].wongFake > 0)
        strangeInfo[eventOrder].wongFake--;
    else if (strangeInfo[eventOrder].realWong == 0 && strangeInfo[eventOrder].wongFake == 0 && 
    strangeInfo[eventOrder].checkWongFake == false)
    {
        strangeInfo[eventOrder].checkWongFake = true;
        strangeInfo[eventOrder].wongFake = 3;
        //change to fake livitation
        if (strangeInfo[eventOrder].checkLivitation == true && strangeInfo[eventOrder].liviationFake == false)
        {
            strangeInfo[eventOrder].liviationFake = true;
            if (strangeInfo[eventOrder].livitation > 0)
            {
                if (strangeInfo[eventOrder].LVtemp >= 3)
                    strangeInfo[eventOrder].LVtemp -= strangeInfo[eventOrder].levelUpLivitation;
                else
                    strangeInfo[eventOrder].LVtemp = 1;
            }
        }
    }
    if (strangeInfo[eventOrder].LVtemp > 7)
    {
        strangeInfo[eventOrder].wongFake = 0;
        strangeInfo[eventOrder].checkWongFake = false;
    }
}
//event 9
void event9(int eventOrder)
{
    strangeInfo[eventOrder].HPtemp = strangeInfo[eventOrder].maxHP;
    strangeInfo[eventOrder].poiMushroom = 0;
    strangeInfo[eventOrder].checkPoiMushroom = false;
    if (strangeInfo[eventOrder].checkLivitation)
    {
        strangeInfo[eventOrder].livitation = 3;
        strangeInfo[eventOrder].liviationFake = false;
    }
    strangeInfo[eventOrder].wongFake = 0;
    strangeInfo[eventOrder].checkWongFake = false;
}
//event 10
    //Fibonacci
long long Fibo(int max)
{
    long long ans[3] = {1, 1, 2};
    while (ans[2] < max)
    {
        ans[0] = ans[1];
        ans[1] = ans[2];
        ans[2] = ans[0] + ans[1];
    }
    return ans[1];
}
void event10(int eventOrder)
{
    strangeInfo[eventOrder].HPtemp += Fibo(strangeInfo[eventOrder].HPtemp);
    checkInfo(eventOrder);
}
//event 11
void event11(int eventOrder)
{
    if (strangeInfo[eventOrder].realWong > 0)
        strangeInfo[eventOrder].realWong--;
    else
    {
        strangeInfo[eventOrder].HPtemp -= 50;
        if (!strangeInfo[eventOrder].checkPoiMushroom)
        {
            strangeInfo[eventOrder].poiMushroom = 3;
            strangeInfo[eventOrder].checkPoiMushroom = true;
        }
        if (strangeInfo[eventOrder].wongFake > 0)
            strangeInfo[eventOrder].wongFake--;
    }
    checkInfo(eventOrder);
}

//event 12
void reverse2Sides(string &str)
{
    if (str.length() >= 3)
    {
        int temp = 0;
        int lens = str.length();
        for (int i = 0; i <= (lens / 2 - 1) / 2; i++)
            swap(str[i], str[int(lens / 2) - 1 - i]);
        for ( int i = lens / 2 + 1; i <= lens / 2 + 1 + (lens - lens / 2 - 2) / 2; i++)
        {
            swap(str[i], str[lens - 1 - temp]);
            temp++;
        }
    }
}
void shiftLetter(string &text, int shift) { 
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a')
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        else
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
    }
}
bool encrypt(string str)
{
    string str1 = str.substr(0, str.find(' '));
    string str2 = str.substr(str.find(' ') + 1);
    reverse2Sides(str1);
    shiftLetter(str1, str2.length() % 10);
    if (str1.find(str2) >= 0 && str1.find(str2) <= str1.length() - 1)
        return true;
    return false;
}
void event12(int eventOrder)
{
    if (encrypt(strangeEvent[eventOrder - 1].data))
    {
        strangeInfo[eventOrder].negotiation = true;
        strangeInfo[eventOrder].HPtemp = (strangeInfo[eventOrder].HPtemp * 9) / 10;
        strangeInfo[eventOrder].maxHP = (strangeInfo[eventOrder].maxHP * 9) / 10;
        strangeInfo[eventOrder].EXPtemp += 30;
        if (strangeInfo[eventOrder].HPtemp <= 0)
            strangeInfo[eventOrder].HPtemp = 1;
    } else
    {
        strangeInfo[eventOrder].negotiation = false;
        if (strangeInfo[eventOrder].liviationFake == false && strangeInfo[eventOrder].checkLivitation == true)
        {
            strangeInfo[eventOrder].checkLivitation = false;
            strangeInfo[eventOrder].canTakeLivitation = false;
        }
        else if(strangeInfo[eventOrder].liviationFake == true && strangeInfo[eventOrder].checkLivitation == true)
        {
            strangeInfo[eventOrder].wongFake = 0;
            strangeInfo[eventOrder].checkWongFake = false;
        }
        //event 14
        strangeInfo[eventOrder].TStemp = 0;
        strangeInfo[eventOrder].EXPtemp += 15;
    }
    checkInfo(eventOrder);
}
//event 13
    //sum of submatrix
int sumMatrix(int row, int col, int m)
{
    int sum = 0;
    for (int i = row; i <= row + m - 1; i++)
    {
        for (int j = col; j <= col + m - 1; j++)
            sum += strangeEvent[eventOrder - 1].event13Matrix[i][j];
    }
    return sum;
}
bool checkIncreasedCol(int startRow, int startCol, int m)
{   
    for(int i = startCol; i <= startCol + m - 1; i++)
    {
        for(int j = startRow + 1; j <= startRow + m - 1; j++)
        {
            if(strangeEvent[eventOrder - 1].event13Matrix[j][i] < strangeEvent[eventOrder - 1].event13Matrix[j - 1][i])
                return false;
        }
    }
    return true;   
}
void event13(int eventOrder)
{
    int m = 0;
    m = (eventorder % 7) > 2 ? (eventorder % 7) : 2;
    int lowestSum = 1000000;
    int sumTemp;
    int firstRow, firstCol;
    for (int k = 0; k <= 7 - m; k++)
    {
        for (int h = 0; h <= 7 - m; h++)
        {
            sumTemp = sumMatrix(k, h, m);
            if (sumTemp < lowestSum)
            {
                lowestSum = sumTemp;
                firstCol = h;
                firstRow = k;
            }
        }
    }
    if (checkIncreasedCol(firstRow, firstCol, m))
        strangeInfo[eventOrder].HPtemp += (firstCol + firstRow + 2) * lowestSum;
    else 
        strangeInfo[eventOrder].HPtemp -= (firstCol + firstRow + 2) * lowestSum;
    if (strangeInfo[eventOrder].HPtemp <= 0 && strangeInfo[eventOrder].negotiation)
        strangeInfo[eventOrder].HPtemp = 1;
    checkInfo(eventOrder);
}
//event 14
int lenArr(int arr[])
{
    int len = 0;
    for (int i = 0; arr[i] != -8888888; i++)
        len++;
    return len;
}
int binarySearch(int eventOrder, int arr[])
{
    int len = lenArr(arr);
    int left = 0;
    int right = len - 1;
    int mid = 0;
    int count = 0;
    bool find = false;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == toNumber(strangeEvent[eventOrder - 1].data))
        {
            find = true;
            count++;
            break;
        } else if (arr[mid] < toNumber(strangeEvent[eventOrder - 1].data))
        {
            count++;
            right = mid - 1;
        } else
        {
            count++;
            left = mid + 1;
        }
    }
    if (find == false)
        return -1;
    else 
        return count;
}
void event14(int eventOrder)
{
    int stepWanda = binarySearch(eventOrder, strangeEvent[eventOrder - 1].event14Matrix);
    if ( stepWanda != -1 &&
    int(log2(lenArr(strangeEvent[eventOrder - 1].event14Matrix))) >= stepWanda)
    {
        strangeInfo[eventOrder].LVtemp = 1;
        strangeInfo[eventOrder].HPtemp -= stepWanda * (eventorder % 10) * 7;
        if (strangeInfo[eventOrder].HPtemp < 1 &&strangeInfo[eventOrder].negotiation == true)
            strangeInfo[eventOrder].HPtemp = 1;
    } else
    {
        strangeInfo[eventOrder].EXPtemp += 150;
        int temp = eventOrder;
        while (strangeEvent[temp].eventCode != "12" && temp != 0)
            temp--;
        if (temp > 0 && strangeInfo[eventOrder].negotiation == false)
        {
            if (strangeInfo[temp - 1].liviationFake == false && strangeInfo[temp - 1].checkLivitation == true)
            {
                strangeInfo[eventOrder].liviationFake = false;
                strangeInfo[eventOrder].checkLivitation = strangeInfo[temp - 1].checkLivitation;
                strangeInfo[eventOrder].livitation = strangeInfo[temp - 1].livitation;
                strangeInfo[eventOrder].canTakeLivitation = true;
            }
            strangeInfo[eventOrder].TStemp += strangeInfo[temp - 1].TStemp;
        }
    }
    checkInfo(eventOrder);
}

//event 15
void event15()
{
    if (strangeInfo[eventOrder].checkBackTime == false && strangeInfo[eventOrder].TStemp > 0)
    {
        strangeInfo[eventOrder].checkBackTime = true;
        int backTime = eventOrder;
        int eventMaxHP = eventOrder;
        for (int x = backTime - 1; x > 0; x--)
        {
            if (strangeInfo[x].HPtemp > strangeInfo[x + 1].HPtemp)
                eventMaxHP = x;
        }
        eventOrder = eventMaxHP;
        //cout << 'x' << eventOrder << 'x' ;
        strangeInfo[eventOrder].TStemp = strangeInfo[backTime].TStemp - 1;
        if (eventOrder != backTime)
        {
            strangeInfo[eventOrder].LVtemp = 10;
            strangeInfo[eventOrder].EXPtemp = 100;
        }
    }
}
int iNums = 0;
int handleEvents(string & HP, string & LV, string & EXP, string & TS, string & events) {
    ///Students have to complete this function and DO NOT modify any parameters in this function.
    strangeInfo[0].HPtemp = toNumber(HP);
    strangeInfo[0].maxHP = toNumber(HP);
    strangeInfo[0].LVtemp = toNumber(LV);
    strangeInfo[0].EXPtemp = toNumber(EXP);
    strangeInfo[0].TStemp = toNumber(TS);

    strangeInfo[0].livitation = 0;
    strangeInfo[0].checkLivitation = false;
    strangeInfo[0].liviationFake = false;
    strangeInfo[0].levelUpLivitation = 0;
    strangeInfo[0].canTakeLivitation = true;

    strangeInfo[0].checkPoiMushroom = false;
    strangeInfo[0].poiMushroom = 0;
     
    strangeInfo[0].negotiation = true;

    strangeInfo[0].checkRealWong = false;
    strangeInfo[0].checkWongFake = false;
    strangeInfo[0].wongFake = 0;
    strangeInfo[0].realWong = 0;

    strangeInfo[eventOrder].checkBackTime = false;
     
    int result = 0;
    readEvent(events);
    //cout << strangeEvent[0].data;
    for (iNums = 0; iNums <= iNum; iNums++)
    {
        eventOrder++;
        eventorder++;
        //cout << 'x' << eventOrder << 'x' ;
        strangeInfo[eventOrder] = strangeInfo[eventOrder - 1];
        //kill wong fake
        if (strangeInfo[eventOrder].LVtemp > 7)
        {
            strangeInfo[eventOrder].wongFake = 0;
            strangeInfo[eventOrder].checkWongFake = false;
        }
        //check wong fake
        if (strangeEvent[eventOrder - 1].eventCode == "12" ||strangeEvent[eventOrder - 1].eventCode == "13"
        || strangeEvent[eventOrder - 1].eventCode == "14")
        {
            strangeInfo[eventOrder].checkWongFake = false;
            strangeInfo[eventOrder].wongFake = 0;
        }
        if (strangeInfo[eventOrder].wongFake == 0)
            strangeInfo[eventOrder].checkWongFake = false;
        //check poiMushroom
        if (strangeInfo[eventOrder].poiMushroom == 3)
        {
            if (strangeInfo[eventOrder].LVtemp >= 3)
                strangeInfo[eventOrder].LVtemp -= 2;
            else 
                strangeInfo[eventOrder].LVtemp = 1;
        }
        if (strangeInfo[eventOrder].checkPoiMushroom && strangeInfo[eventOrder].poiMushroom > 0)
            strangeInfo[eventOrder].poiMushroom--;

        if (strangeInfo[eventOrder].checkPoiMushroom && strangeInfo[eventOrder].poiMushroom == 0)
        {
            strangeInfo[eventOrder].checkPoiMushroom = false;
            //calculating lv after poiMushroom  
            if (strangeInfo[eventOrder - 4].LVtemp == 2)
                strangeInfo[eventOrder].LVtemp += 1;
            else if  (strangeInfo[eventOrder - 4].LVtemp >= 3)
                strangeInfo[eventOrder].LVtemp += 2;
        }
        checkInfo(eventOrder);
        switch (toNumber(strangeEvent[iNums].eventCode))
        {
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 :
                eventOneTofive(eventOrder, toNumber(strangeEvent[iNums].eventCode)); 
                break;
            case 6 :
                event6(eventOrder, strangeEvent[iNums].data);
                break;
            case 10 :
                event10(eventOrder);
                break;
            case 7 :
                event7(eventOrder);
                break;
            case 12 :
                event12(eventOrder);
                break;
            case 11 :
                event11(eventOrder);
                break;
            case 13 :
                event13(eventOrder);
                break;
            case 9 :
                event9(eventOrder);
                break;
            case 14 :
                event14(eventOrder);
                break;
            case 8 :
                event8(eventOrder);
                break;
            case 15 :
                event15();
                iNums = eventOrder - 1;
                break;
        }
        //check livitation disappear
        if (strangeInfo[eventOrder].checkLivitation == false && strangeInfo[eventOrder - 1].checkLivitation == true
        && strangeInfo[eventOrder].livitation > 1)
        {
            if (strangeInfo[eventOrder].LVtemp < 3)
                strangeInfo[eventOrder].LVtemp = 1;
            else 
                strangeInfo[eventOrder].LVtemp += strangeInfo[eventOrder].levelUpLivitation;
        }
        //check livitation expire
        if (strangeInfo[eventOrder].livitation == 0 && strangeInfo[eventOrder - 1].livitation == 1)
        {
            if (strangeInfo[eventOrder].LVtemp < 3)
                strangeInfo[eventOrder].LVtemp = 1;
            else 
                strangeInfo[eventOrder].LVtemp += strangeInfo[eventOrder].levelUpLivitation;
        }
        checkInfo(eventOrder);

        // cout << strangeInfo[eventOrder].maxHP <<' '<< strangeInfo[eventOrder].HPtemp <<  ' ' 
        // <<  strangeInfo[eventOrder].LVtemp << ' ' << 
        // strangeInfo[eventOrder].EXPtemp << ' ' << strangeInfo[eventOrder].TStemp << ' ' 
        // << strangeInfo[eventOrder].poiMushroom << endl;
    }
    //cout << 'x' << strangeInfo[eventOrder].realWong << 'x';
    result = strangeInfo[eventOrder].HPtemp + strangeInfo[eventOrder].LVtemp + 
    strangeInfo[eventOrder].EXPtemp + strangeInfo[eventOrder].TStemp;
    // cout << HP << " " << LV << " " << EXP << " " << TS << endl;
    // cout << events << endl;
    return result;
}

///END OF STUDENT'S ANSWER

#endif /* studyInPink_h */


