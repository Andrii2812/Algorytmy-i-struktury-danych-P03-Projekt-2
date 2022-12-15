#include <iostream> 
#include <fstream> 
#include <vector> 
 
using namespace std; 
 
// Funkcja do sortowania przez wybieranie 
void selectionSort(vector<int>& v) { 
  // Iterujemy przez wszystkie elementy w wektorze 
  for (int i = 0; i < v.size(); i++) { 
    // Szukamy najmniejszego elementu w reszcie wektora 
    int minIndex = i; 
    for (int j = i + 1; j < v.size(); j++) { 
      if (v[j] < v[minIndex]) { 
        minIndex = j; 
      } 
    } 
    // Zamieniamy element na pozycji i z najmniejszym znalezionym elementem 
    swap(v[i], v[minIndex]); 
  } 
} 
 
int main() { 
  // Otwieramy plik wejœciowy 
  ifstream inputFile("in.txt"); 
  if (!inputFile.is_open()) { 
    cout << "B³¹d otwarcia pliku wejœciowego!" << endl; 
    return 1; 
  } 
 
  // Wczytujemy dane z pliku do wektora 
  vector<int> data; 
  int x; 
  while (inputFile >> x) { 
    data.push_back(x); 
  } 
 
  // Sortujemy dane przy u¿yciu funkcji selectionSort 
  selectionSort(data); 
 
  // Otwieramy plik wyjœciowy 
  ofstream outputFile("out.txt"); 
  if (!outputFile.is_open()) { 
    cout << "B³¹d otwarcia pliku wyjœciowego!" << endl; 
    return 1; 
  } 
 
  // Zapisujemy posortowane dane do pliku 
  for (int x : data) { 
    outputFile << x << " "; 
  } 
 
  return 0; 
}
