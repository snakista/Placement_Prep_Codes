#include<bits/stdc++.h>
using namespace std;
void subsetsum(int arr[],int n,int sum)
{
    bool table[n+1][sum+1];
    for(int i=0;i<=n;i++)
    table[i][0]=true;
    for(int i=1;i<=sum;i++)
    table[0][i]=false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]>j)
            table[i][j]=table[i-1][j];
            else
            {
                table[i][j]=(table[i-1][j]||table[i-1][j-arr[i-1]]);
            }
        }
    }
    if(table[n][sum])
    cout<<"Yes there is a subset of given sum!";
    else
    cout<<"No subset is there of given sum!";
}
int main()
{
    int arr[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int sum;
    cin>>sum;
    subsetsum(arr,n,sum);
}
