#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void sort_bubble(int *a, int n) {
   bool sorted = false;
   while (!sorted) {
      sorted = true;
      for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
           int tmp = a[i];
           a[i] = a[i+1];
           a[i+1] = tmp;
           sorted = false;
        }
      }
    }
}

void sort_insertion(int *a, int n) {
  for (int i = n-1; i > 0; i--) {
    if (a[i-1] > a[i]) {
      int tmp = a[i-1]; a[i-1] = a[i]; a[i] = tmp;
    }
  }
  for (int i = 2; i < n; i++) {
    int j = i;
    int tmp = a[i];
    while (tmp < a[j-1]) {
       a[j] = a[j-1]; j--;
    }
    a[j] = tmp;
  }
}

void sort_shell(int  *a, int n) {
   int h;
   for (h = 1; h <= n / 9; h = 3*h + 1)
      ;
   for ( ; h > 0; h /= 3) {
      for (int i = h; i < n; i++) {
        int j = i;
        int tmp = a[i];
        while (j >= h && tmp < a[j-h]) {
          a[j] = a[j-h];
          j -= h;
        }
        a[j] = tmp;
      }
   }
}

void merge(int *a, int low, int mid, int high, int *aux) {
   int i,j;
   for (i = mid+1; i > low; i--) aux[i-1] = a[i-1];
   for (j = mid; j < high; j++) aux[high+mid-j]=a[j+1];
   for (int k = low; k <= high; k++) {
      if (aux[j] < aux[i])
         a[k] = aux[j--];
      else
         a[k] = aux[i++];
   }
}

void mergeSort(int a[], int low, int high, int *aux) {
   const int THRESHOLD = 10;
   if (high - low < THRESHOLD) {
      sort_insertion(a+low, high-low+1);
   } else {
      int mid = (low + high) / 2;
      mergeSort(a, low, mid, aux);
      mergeSort(a, mid+1, high, aux);
      merge(a, low, mid ,high, aux);
  }
}

void sort_merge(int *a, int n) {
    int *aux = new int[n];
    mergeSort(a,0,n-1, aux);
    delete [] aux;
}

void quickSortBase(int *a, int l, int r) {
    int i = l, j = r;
    int pp[3] = { a[l], a[r], a[(l+r)>>1]};
    int p = pp[0];
    if (pp[1] >= pp[0] && pp[1]<=pp[0]) p=pp[1];
    else if (pp[2] >= pp[0] && pp[2]<=pp[1]) p=pp[2];

    while (i <= j) {
        while (p > a[i])
           i++;
        while (a[j] > p)
           j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }
    if (l < j)
       quickSortBase(a, l, j);
    if (i < r)
       quickSortBase(a, i, r);
}

void sort_quick_recursive(int *a, int n) {
   quickSortBase(a,0,n-1);
}

static void heapify(int *a, int i, int n)
{
    int curr = a[i];
    int index = i;
    for (;;) {
        int left = index + index + 1;
        int right = left + 1;
        if ( left < n && a[left] > curr)
            index = left;
        if ( right < n && a[right] > a[index])
            index = right;
        if (index == i ) break;
        a[i] = a[index];
        a[index] = curr;
        i = index;
    }
}

void sort_heap(int *a, int n) {
    for(int i = n/2-1; i >= 0; i--) {
        heapify(a, i, n);
    }
    while( n > 1 ) {
        n--;
        int tmp = a[0];
        a[0] = a[n];
        a[n] = tmp;
        heapify(a, 0, n);
    }
}

void sort_vector(int *a, int n) {
   sort(a+0,a+n);
}

int compare_int(const void *a, const void *b) {
   return *(const int *)a - *(const int *)b;
}

void sort_qsort(int *a, int n) {
   qsort(a, n, sizeof(int), compare_int);
}


#endif // SORT_H_INCLUDED
