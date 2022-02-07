#include <iostream>
#include <fstream>
using namespace std;

string zaszyfruj(string s, int key[], int keyLen) 
{
  char temp;
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) 
  {
    temp = s[i];
    s[i] = s[key[keyIndex] - 1];
    s[key[keyIndex] - 1] = temp;
    keyIndex++;
    if (keyIndex == keyLen) keyIndex = 0;
  }
  return s;
}

void zad1() 
{
  cout << "zad1:" << endl;
  ifstream in("szyfr1.txt");
  string tab[6];
  int key[50];
  for (int i = 0; i < 6; i++) in >> tab[i];
  for (int i = 0; i < 50; i++) in >> key[i];
  for (int i = 0; i < 6; i++) cout << zaszyfruj(tab[i], key, 50) << endl;
  cout << endl;
}

void zad2() 
{
  cout << "zad2:" << endl;
  ifstream in ("szyfr2.txt");
  string s;
  in >> s;
  int key[15];
  for (int i = 0; i < 15; i++) in >> key[i];
  cout << zaszyfruj(s, key, 15) << endl << endl;
}

string deszyfruj(string s, int key[], int keyLen) 
{
  int keyIndex = (s.length() % keyLen - 1);
  char temp;
  for (int i = s.length() - 1; i >= 0; i--) 
  {
    temp = s[i];
    s[i] = s[key[keyIndex] - 1];
    s[key[keyIndex] - 1] = temp;
    keyIndex--;
    if (keyIndex == -1) keyIndex = keyLen - 1;
  }
  return s;
}

void zad3() 
{
  cout << "zad3:" << endl;
  ifstream in("szyfr3.txt");
  string s;
  in >> s;
  int key[] = {6, 2, 4, 1, 5, 3};
  cout << deszyfruj(s, key, 6) << endl;
}

int main() {
  zad1();
  zad2();
  zad3();
}
