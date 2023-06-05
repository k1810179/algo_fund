// バイトニックソート
// http://jp.wsxdn.com/pn014i/qo145i/1001079430.html#:~:text=%E3%82%B9%E3%83%86%E3%83%83%E3%83%971%20%E2%88%92%E3%83%90%E3%82%A4%E3%83%88%E3%83%8B%E3%83%83%E3%82%AF%E3%82%B7%E3%83%BC%E3%82%B1%E3%83%B3%E3%82%B9%E3%82%92%E4%BD%9C%E6%88%90%E3%81%97%E3%81%BE%E3%81%99%E3%80%82%20%E3%82%B9%E3%83%86%E3%83%83%E3%83%972,%E2%88%92%E3%81%93%E3%82%8C%E3%81%A7%E3%80%81%E3%81%82%E3%82%8B%E9%83%A8%E5%88%86%E3%81%8C%E6%98%87%E9%A0%86%E3%81%A7%E3%80%81%E4%BB%96%E3%81%AE%E9%83%A8%E5%88%86%E3%81%8C%E9%99%8D%E9%A0%86%E3%81%A7%E3%81%82%E3%82%8B%E3%83%90%E3%82%A4%E3%83%88%E3%83%8B%E3%83%83%E3%82%AF%E3%82%B7%E3%83%BC%E3%82%B1%E3%83%B3%E3%82%B9%E3%81%8C%E3%81%A7%E3%81%8D%E3%81%BE%E3%81%97%E3%81%9F%E3%80%82%20%E3%82%B9%E3%83%86%E3%83%83%E3%83%973%20%E2%88%92%E4%B8%A1%E6%96%B9%E3%81%AE%E5%8D%8A%E5%88%86%E3%81%AE%E6%9C%80%E5%88%9D%E3%81%AE%E8%A6%81%E7%B4%A0%E3%82%92%E6%AF%94%E8%BC%83%E3%81%97%E3%81%A6%E4%BA%A4%E6%8F%9B%E3%81%97%E3%81%BE%E3%81%99%E3%80%82

#include<bits/stdc++.h>
using namespace std;

void bitonicSeqMerge(int a[], int start, int BseqSize, int direction) {
   if (BseqSize>1){
      int k = BseqSize / 2;
      for (int i = start; i < start + k; i++)
      if (direction == (a[i]>a[i+k])){
        swap(a[i], a[i+k]);
      }
      bitonicSeqMerge(a, start, k, direction);
      bitonicSeqMerge(a, start+k, k, direction);
   }
}

void bitonicSortrec(int a[],int start, int BseqSize, int direction) {
   if (BseqSize > 1){
      int k = BseqSize / 2;
      bitonicSortrec(a, start, k, 1);
      bitonicSortrec(a, start+k, k, 0);
      bitonicSeqMerge(a,start, BseqSize, direction);
   }
}

void bitonicSort(int a[], int size, int up) {
   bitonicSortrec(a, 0, size, up);
}

int main() {
   int a[] = {5, 10, 51, 8, 1, 9, 6, 22};
   int size = sizeof(a) / sizeof(a[0]);

   cout << "Original array: " << endl;
   for (int i = 0; i < size; i++){
    cout <<  a[i] << " ";
   }

   bitonicSort(a, size, 1);
   cout << endl << "Sorted array: " << endl;

   for (int i = 0; i < size; i++){
    cout << a[i] << " ";
   }
   cout << endl;
}
