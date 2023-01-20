#include <iostream>
using namespace std;
int partition(int A[], int lo, int hi)
{
    int i = lo + 1;
    int j = hi;
    int pivot = lo;
    while (i <= j)
    {
        while (A[i] <= A[pivot] && i < hi)
        {
            i++;
        }
        while (A[i] >= A[pivot] && j > lo)
        {
            j--;
        }
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    
        int temp2 = A[j];
        A[j] = A[pivot];
        A[pivot] = A[j];
        return j;
    }
 }
void Q_sort(int A[], int lo ,  int hi)
{
    if (lo >= hi)
    {
        return;
    }
    int j = partition( A, lo, hi);
     Q_sort(A, lo, j - 1);
     Q_sort(A, j + 1, hi);
}
int main()
{
    int A[10];
    cout << "Enter 10 integers";
    for (int i = 0; i <= 9; i++)
    {
        cin >> A[i];
    }
    Q_sort(A, 0, 9);
    for (int i = 0; i <= 9; i++)
    {
        cout << A[i]<<endl;
    }
    return 0;
}
