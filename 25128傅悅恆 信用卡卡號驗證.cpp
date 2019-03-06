#include <iostream>
using namespace std;
int main() {
  long int cardnumber;
  cout << "請輸入信用卡號:\n";
  cin >> cardnumber;//輸入卡號
  long int odd = cardnumber, even = cardnumber / 10, total = 0,checknumber = 0;//odd和even各為前兩位數(包含後面的一整串)
  for ( int a = 0 ; a < 8; a++ ) {
    int number = odd % 10;//提出最後一位(第1位，總共16位)
    odd = odd / 100;//消滅最後兩位
    total = total + number;//奇數位加總
  }
  for ( int a = 0 ; a < 8 ; a++ ) {
    int number = even % 10;//提出最後一位(第1位，總共15位)
    even = even / 100;//消滅最後兩位
    if ( number > 4 ) 
    {number = number * 2 / 10 + number * 2 % 10;}
    else 
    {number = number * 2;}
    total = total + number;//奇數加上偶數位套公式後加總
  }
  for ( int a = 0 ; a < 15 ; a++ ) 
  {cardnumber = cardnumber / 10;}//消滅最後一位，消到只剩最頭的數字
  if (total % 10 == 0) 
  {checknumber = 0;}
  else 
  {checknumber = 10 - total % 10;}
  if ( ( total + checknumber ) % 10 == 0 ) {
    if ( cardnumber == 4 ) cout << "這是Visa card";
    else if ( cardnumber == 5 ) cout << "這是Master card";
    else cout << "這是其他信用卡";
  }
  else cout << "這是其他信用卡\n";
}
