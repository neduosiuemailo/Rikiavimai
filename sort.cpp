#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &);
template <class T> void compexch(T &, T &, int &);
template <class T> void selection(T *, int, int, int &, int &);
template <class T> void insertion(T *, int, int, int &, int &);
template <class T> void bubble(T *, int, int, int &, int &);
template <class T> void quicksort(T *, int, int, int &, int &);
using namespace std;

int main(void)
{
    int i, N=1000;
    int *a = new int[N];
    int L=0, S=0, La=0, Sa=0, Lb=0, Sb=0;
    for (i = 0; i < N; i++)
      a[i] = 1000*(1.0*rand()/RAND_MAX);
//    cout << "Įvestas skaičių masyvas yra:" << endl;
//    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
//    selection(a, 0, N-1, L, S);
    bubble(a, 0, N-1, L, S);
    //Darom masyva nuo 0 iki 1000
    for (i = 0; i < N; i++)
      a[i] = i;
//    selection(a, 0, N-1, La, Sa);
    bubble(a, 0, N-1, La, Sa);

    //Darom masyva nuo 1000 iki 0
    for (i = 0; i < N; i++)
      a[i] = 1000-i;
//    selection(a, 0, N-1, Lb, Sb);
    bubble(a, 0, N-1, Lb, Sb);

//    cout << "Surūšiuotas skaičių masyvas yra:" << endl;
//    for (i = 0; i < N; i++) cout << a[i] << " ";

    cout << endl;
    cout << "Burbulo metodas" << endl;
    cout << "Sukeitimo operaciju (random): " << S << endl;
    cout << "Lyginimo operaciju (random):  " << L << endl;
    cout << "Sukeitimo operaciju (0-1000): " << Sa << endl;
    cout << "Lyginimo operaciju (0-1000):  " << La << endl;
    cout << "Sukeitimo operaciju (1000-0): " << Sb << endl;
    cout << "Lyginimo operaciju (1000-0):  " << Lb << endl;
    cout << endl;

    for (i = 0; i < N; i++)
      a[i] = 1000*(1.0*rand()/RAND_MAX);
    L=0;
    S=0;
    La=0;
    Sa=0;
    Lb=0;
    Sb=0;

    selection(a, 0, N-1, L, S);
    //Darom masyva nuo 0 iki 1000
    for (i = 0; i < N; i++)
      a[i] = i;
    selection(a, 0, N-1, La, Sa);
    //Darom masyva nuo 1000 iki 0
    for (i = 0; i < N; i++)
      a[i] = 1000-i;
    selection(a, 0, N-1, Lb, Sb);

    cout << endl;
    cout << "Selection metodas" << endl;
    cout << "Sukeitimo operaciju (random): " << S << endl;
    cout << "Lyginimo operaciju (random):  " << L << endl;
    cout << "Sukeitimo operaciju (0-1000): " << Sa << endl;
    cout << "Lyginimo operaciju (0-1000):  " << La << endl;
    cout << "Sukeitimo operaciju (1000-0): " << Sb << endl;
    cout << "Lyginimo operaciju (1000-0):  " << Lb << endl;
    cout << endl;

    for (i = 0; i < N; i++)
      a[i] = 1000*(1.0*rand()/RAND_MAX);
    L=0;
    S=0;
    La=0;
    Sa=0;
    Lb=0;
    Sb=0;

    insertion(a, 0, N-1, L, S);
    //Darom masyva nuo 0 iki 1000
    for (i = 0; i < N; i++)
      a[i] = i;
    insertion(a, 0, N-1, La, Sa);
    //Darom masyva nuo 1000 iki 0
    for (i = 0; i < N; i++)
      a[i] = 1000-i;
    insertion(a, 0, N-1, Lb, Sb);

    cout << endl;
    cout << "Insertion metodas" << endl;
    cout << "Sukeitimo operaciju (random): " << S << endl;
    cout << "Lyginimo operaciju (random):  " << L << endl;
    cout << "Sukeitimo operaciju (0-1000): " << Sa << endl;
    cout << "Lyginimo operaciju (0-1000):  " << La << endl;
    cout << "Sukeitimo operaciju (1000-0): " << Sb << endl;
    cout << "Lyginimo operaciju (1000-0):  " << Lb << endl;
    cout << endl;



}

// Sukeičia elementus vietomis
template <class T>
  void exch(T &A, T &B)
    { T t = A ; A = B; B = t; }
// Sukeičia elementus vietomis tik jei patenkinta sąlyga
template <class T>
  void compexch(T &A, T &B, int &S)
    { if (B < A) {
        exch(A, B);
        S++;
        }
    }

//-------------------------------------------
// Išrinkimo algoritmo realizacija
//-------------------------------------------
template <class T>
void selection(T a[], int l, int r, int &L, int &S)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) {
            min = j;
            L++;
            }
        exch(a[i], a[min]);
        S++;
      }
  }


//-------------------------------------------
// Įterpimo algoritmo realizacija
//-------------------------------------------
template <class T>
void insertion(T a[], int l, int r, int &L, int &S)
  { int i;
    for (i = r; i > l; i--) {
        compexch(a[i-1], a[i], S);
        //L++;
        }
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1]) {
            a[j] = a[j-1]; j--;
            L++;
            }
        a[j] = v;
      }
  }

//-------------------------------------------
// Burbulo algoritmas
//-------------------------------------------
template <class T>
void bubble(T a[], int l, int r, int &L, int &S)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--){
        compexch(a[j-1], a[j], S);
        L++;
      }
  }

//-------------------------------------------
// quicksort algoritmas
//-------------------------------------------
template <class T>
void quicksort(T a[], int l, int r, int &L, int &S)
  {

  }

