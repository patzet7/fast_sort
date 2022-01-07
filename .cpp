#include <iostream>
using namespace std;

void print(int tab[],int left, int right){
  for(int i=left; i<=right; i++){
    cout << tab[i] << ", ";
  }
  cout << endl;
}

void change(int tab[], int e1, int e2){
  int bufor =  tab[e1];
  tab[e1] = tab[e2];
  tab[e2] = bufor;
}

void sort(int tab[], int left, int right){
  if (left>=right) return; 
  cout << " start with: " << endl;
  print(tab, left, right);

  int pointer = tab[right]; 
  int border = left -1;
  int counter = left;  

  while(counter<right) {
    if (tab[counter]<pointer){
      border++;
      if(border!=counter){
        change(tab, border, counter);
      }
    }
    counter++;
  }

  border++;
  if (border!=right){
    change(tab, border, right);
  }

  cout << "exit: ";
  print(tab, left, right);

  sort(tab, left, border-1);
  sort(tab, border+1, right);
}


int main() {
  const int size = 10;
  int table[size] = {73,65,32,76,34,16,19,93,33,65};

  sort(table, 0, size-1);
  cout << "------------------------------------------------\n";
  print(table, 0, size-1);
