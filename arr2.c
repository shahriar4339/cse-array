#include<stdio.h>
int max_area(int n, int arr[]){
    int max_area = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int area = (j-i) * (arr[i]<arr[j]?arr[i]:arr[j]);
            if(area > max_area){
                max_area = area;
            }
        }
    }
    return max_area;
}
int third_largest(int n, int arr[]){
    int max = arr[0];
    int smax = arr[0];
    int tmax = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            tmax = smax;
            smax = max;
            max = arr[i];
        }
        else if(arr[i] > smax && arr[i] != max){
            tmax = smax;
            smax = arr[i];
        }
        else if(arr[i] > tmax && arr[i] != smax && arr[i] != max){
            tmax = arr[i];
        }
    }
    if(tmax == max || tmax == smax){
        return -1;
    }
    else{
        return tmax;
    }
}
int tower(int n, int arr[]){
    int sum=arr[0],current_max=arr[0];
    for(int i=0; i<n-1; i++){
       if(current_max<arr[i]){
            current_max=arr[i];
       }
       if(arr[i+1]>current_max){
            sum+=arr[i+1]-current_max;
       }
    }
    return sum;
}
int sort(int n, int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int print(int n, int arr[]){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
int array_sum(int n1,int n2,int arr1[],int arr2[]){
    int number1=0,number2=0;
    int place = 1;
    for(int i=0; i<n1; i++){
        number1 += arr1[i] * place;
        place *= 10;
    }
    place = 1;
    for(int i=0; i<n2; i++){
        number2 += arr2[i] * place;
        place *= 10;
    }

    int sum = number1 + number2;
    int temp = sum;
    int digit = 0;

    if (temp == 0)
        digit = 1;

    while (temp > 0)
    {
        temp = temp / 10;
        digit++;
    }

    int s[digit];

    for (int i = 0; i < digit; i++)
    {
        s[i] = sum % 10;
        sum = sum / 10;
    }
    print(digit,s);
}
int profit(int n1, int arr1[]){
    int profit=0,temp=0;
    for(int i=0;i<n1-1;i++){
        for(int j=i+1;j<n1;j++){
            temp=arr1[j]-arr1[i];
            if(profit<temp){
                profit=temp;
            }
        }
    }
    if(profit>0){
        return profit;
    }
    else{
        return 0;
    }
}
int main(){
    int n1,n2,x;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }
    
    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }
    int left = 0, right = n1 - 1;
    int left_max = 0, right_max = 0;
    long long total_water = 0;

    while (left < right) {
        if (arr1[left] < arr1[right]) {
            if (arr1[left] >= left_max) {
                left_max = arr1[left];
            } else {
                total_water += left_max - arr1[left];
            }
            left++;
        } else {
            if (arr1[right] >= right_max) {
                right_max = arr1[right];
            } else {
                total_water += right_max - arr1[right];
            }
            right--;
        }
    }

    printf("%lld\n", total_water);
    return 0;
}