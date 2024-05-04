#include<stdio.h>
int binarysearch(int arr[],int target,int n)
{
    int f=0,l=n-1,mid;
    while(f<=l)
    {
        mid=(f+l)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            f=mid+1;
        }
        else{
            l=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n,tar;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&tar);
    printf("The element is present at index %d\n",binarysearch(arr,tar,n));
    return 0;
}