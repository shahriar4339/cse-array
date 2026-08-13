#include<stdio.h>
int print(int n, int arr[]){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
int max(int n, int arr[]){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int min(int n, int arr[]){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
float avg(int n, int arr[]){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return (float)sum/n;
}
int rev(int n, int arr[]){
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
int find(int n, int arr[], int x){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            arr[count] = i;
            count++;
        }
    }
    return count;
}
int secondlarge(int n, int arr[]){
    int max = arr[0];
    int smax = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            smax = max;
            max = arr[i];
        }
        else if(arr[i] > smax){
            smax = arr[i];
        }
    }
    return smax;
}
int movezero(int n, int arr[]){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            arr[count++] = arr[i];
        }
    }
    while(count < n){
        arr[count++] = 0;
    }
}
int rotate(int n, int arr[], int x){
    int temp[n];
    for(int i=0; i<n; i++){
        temp[i] = arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[(i+x)%n];
    }
}
int common_elements(int n, int arr1[], int arr2[]){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr1[i] == arr2[j]){
                arr1[count++] = arr2[j];
                break;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {

            if (arr1[i] == arr1[j]) {

                for (int k = j; k < count - 1; k++) {
                    arr1[k] = arr1[k + 1];
                }

                count--;
                j--;  
            }
        }
    }
    return count;
}
int sum_two_elements(int n, int arr1[],int x){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr1[i] + arr1[j] == x) {
                return 1;
            }
        }
    }
    return 0;
}
int bubble_sort(int n, int arr[]){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return 0;
}
int selection_sort(int n, int arr[]){
    int swap=0;
    for(int i=0; i<n-1; i++){
        int min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swap++;
        }
    }
    return swap;
}
int sort(int n,int arr[]){
    int swap = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swap++;
            }
        }
    }
    return swap;
}
int bst(int arr[], int l, int h, int x){
    if(l>h){
        return -1;
    }
    int mid = (l+h)/2;
    if(arr[mid]==x){
        return mid;
    }
    if(arr[mid]>x){
        return bst(arr, l, mid-1, x);
    }
    else{
        return bst(arr,mid+1,h,x);
    }
}
int max_sum(int n,int arr[]){
    int current_sum = 0,max_sum = arr[0];
    for(int i=0; i<n; i++){
        current_sum += arr[i];
        if(current_sum > max_sum){
            max_sum = current_sum;
        }
        if(current_sum < 0){
            current_sum = 0;
        }
    }
    return max_sum;
}
int inversion_count(int n, int arr[]){
    int count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}
int first_occurrence(int l, int h, int arr[], int x){
    if(l > h){
        return -1;
    }
    int mid = (l + h) / 2;
    if(arr[mid] == x){
       int left = first_occurrence(l, mid - 1, arr, x);

        if (left != -1)
            return left;

        return mid;
    }
    if(arr[mid] > x){
        return first_occurrence(l, mid - 1, arr, x);
    }
    else{
        return first_occurrence(mid + 1, h, arr, x);
    }
}
int last_occurrence(int l, int h, int arr[], int x){
    if(l > h){
        return -1;
    }
    int mid = (l + h) / 2;
    if(arr[mid] == x){
        int right = last_occurrence(mid + 1, h, arr, x);

        if (right != -1)
            return right;

        return mid;
    }
    if(arr[mid] > x){
        return last_occurrence(l, mid - 1, arr, x);
    }
    else{
        return last_occurrence(mid + 1, h, arr, x);
    }
}

int main(){
    int n,x;
    scanf("%d", &n);
    int arr[n];
    int temp[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }

    printf("max: %d\n", max(n, arr));
    printf("min: %d\n", min(n, arr));
    printf("average: %f\n", avg(n, arr));
    printf("Reversed array: ");
    rev(n, temp);
    for(int i=0; i<n; i++){
        printf("%d ", temp[i]);
    }
    scanf("%d", &x);
    int count = find(n, temp, x);
    printf("%d\n Positions: ", count);
    for(int i=0; i<count; i++){
        printf("%d ", temp[i]);
    }
    printf("\n%d\n", secondlarge(n, arr));
    movezero(n, arr);
    printf("Array after moving zeros to the end: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    // Removing duplicates from the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (arr[i] == arr[j]) {

                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }

                n--;
                j--;  
            }
        }
    }
printf("Array after removing duplicates: ");
for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
}
rotate(n, arr, 2);
printf("Rotated array: ");
for(int i=0; i<n; i++){
    printf("%d ", arr[i]); 
}
int arr1[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr1[i]);
    }
    int arr2[n];
    for(int i=0; i<n; i++){
      scanf("%d", &arr2[i]);
    }
    int count = common_elements(n, arr1, arr2);
    printf("Common elements: ");
    for(int i=0; i<count; i++){
        printf("%d ", arr1[i]);
    }
    int t = sum_two_elements(n, arr1, x);
    if(t == 1){
        printf("Yes two elements sum to x\n");
    }else{
        printf("No two elements sum to x\n");
    }
    int swaps = sort(n, arr1);
    printf("Selection Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nNumber of swaps: %d", swaps);
    int result = bst(arr1, 0, n-1, x);
    if(result != -1){
        printf("\nElement found at index %d\n", result);
    }else{
        printf("%d\n",result);
    }
    int sum_result = max_sum(n, arr1);
    printf("Maximum sum of subarray: %d\n", sum_result);
    int first = first_occurrence(0, n-1, arr1, x);
    int last = last_occurrence(0, n-1, arr1, x);
    if(first != -1 && last != -1){
        printf("First occurrence: %d\n", first);
        printf("Last occurrence: %d\n", last);
        printf("All occurrences: ");
        for(int i=first; i<=last; i++){
            printf("%d ", i);
        }
    }
    return 0;
}