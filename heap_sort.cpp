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
void heap_sort(int arr[],int N)
{
	int size=N;
	build(arr,size);
	for(int i=N;i>=2;i--)
	{
		int t=arr[1];
		arr[1]=arr[i];
		arr[i]=t;
		size-=1;
		max_heapify(arr,1,size);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements in heap: ";
	cin>>n;
	cout<<"Enter elements: "<<endl;
	int arr[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	heap_sort(arr,n);
	cout<<"Elements of array after heap sort is: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
