#include<iostream>
using namespace std;
void max_heapify(int arr[],int i,int N)
{
	int left=2*i;
	int right=2*i+1;
	int largest;
	if(left<=N&&arr[left]>arr[i])
	{
		largest=left;
	}
	else
	largest=i;
	 
	if(right<=N&&arr[right]>arr[largest])
	largest=right;
	
	if(largest!=i)
	{
		int t=arr[i];
		arr[i]=arr[largest];
		arr[largest]=t;
		max_heapify(arr,largest,N);
	}
}
void build(int arr[],int N)
{
	for(int i=N/2;i>=1;i--)
	{
		max_heapify(arr,i,N);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements in heap: ";
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	build(arr,n);
	cout<<"Elements of array after max_heapify are: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
