#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int max (int a, int b) {
    if (a > b) return a;
    else return b;
}

int min (int a, int b) {
    if (a < b) return a;
    else return b;
}

int hcf (int a, int b) {
    if (max(a, b) % min(a,b) == 0) return min (a, b);
    return hcf ((max(a,b) % min(a,b)), min (a,b));
}

int lcm (int a, int b) {
    return (a / hcf(a, b)) * b;
}

int gcd_of_array (int arr[], int n) {
    int result = arr[0];
    for (int i = 0; i < n; i++) {
        result = hcf(result, arr[i]);
    }
    return result;
}

int lcm_of_array (int arr[], int n) {
    int result = arr[0];
    for (int i = 0; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main () {
    int n; 
    printf ("Enter the number for numbers: ");
    scanf ("%d",&n);
    printf ("Enter the numbers:\n");
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf ("%d",&arr[i]);
    }

    printf("hcf = %d\n",gcd_of_array(arr, n));
    printf("lcm = %d",lcm_of_array(arr, n));
}