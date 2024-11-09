#include <stdio.h>
#include <stdlib.h>

void sortPrices(float *prices, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (prices[j] > prices[j + 1]) {
                // Swap prices[j] and prices[j + 1]
                float temp = prices[j];
                prices[j] = prices[j + 1];
                prices[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    float *prices = (float *)malloc(n * sizeof(float));
    if (prices == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter the product prices:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }
    sortPrices(prices, n);
    printf("Sorted product prices in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\n", prices[i]);
    }
    free(prices);
    return 0;
}




