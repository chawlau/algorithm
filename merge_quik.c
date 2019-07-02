#include <stdio.h>
#include <stdlib.h>

int merge(int a[], int l, int m, int r) {
  int* dumy = (int*)malloc(r - l + 1);

  int i = l;
  int j = m + 1;
  int k = 0;

  while (i <= m && j <= r) {
    if (a[i] <= a[j])
      dumy[k++] = a[i++];
    else
      dumy[k++] = a[j++];
  }

  while (i <= m)
    dumy[k++] = a[i++];
  while (j <= r)
    dumy[k++] = a[j++];


  memcpy(a + l, dumy, r - l + 1);
  free(dumy);
}

void merge_sort(int a[], int l, int r) {
  if (l >= r) return;

  int mid = (l + r) / 2;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);
  merge(a, l, mid, r);
}

int main() {
  int a[] = {6,3,4,1,7,8};
  int i;
  merge_sort(a, 0, 5);
  for (i = 0; i < 6; i++) {
    printf(" data %d", a[i]);
  }
  printf("\n");
}
