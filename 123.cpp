#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

const int N = 20; // Liczebność zbioru.

int d[N],p[N];

// Procedura sortująca
//--------------------

void MergeSort(int i_p, int i_k)
{
  int i_s,i1,i2,i;

  i_s = (i_p + i_k + 1) / 2;
  if(i_s - i_p > 1) MergeSort(i_p, i_s - 1);
  if(i_k - i_s > 0) MergeSort(i_s, i_k);
  i1 = i_p; i2 = i_s;
  for(i = i_p; i <= i_k; i++)
    p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++];
  for(i = i_p; i <= i_k; i++) d[i] = p[i];
}

// Program główny
//---------------

int main()
{
  int i;
  
  cout << " Sortowanie przez scalanie\n";

//Otwórz pliki dla odczytu i zapisu
  fstream plik,plik2;
  plik.open("xxx.txt");
  plik2.open("yyy.txt",ios::out);
  for(i = 0; i < N; i++) plik>>d[i];
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

// Sortujemy

  MergeSort(0,N-1);
  
// Wy�wietlamy wynik sortowania i zapisujemy do pliku

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  for(int i=0;i<N;i++) plik2<<d[i]<<endl;
  return 0;
}
