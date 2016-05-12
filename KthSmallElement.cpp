#include <iostream>
#include <algorithm>

using namespace std;
//#define debug 1
void swap (int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void print_array(int *ar, int s,int size) {
	cout<<"\nArray is : ";
	for(int i = s; i < size; i++) {
		cout<<ar[i]<<" ";
	}

}
int partion(int *ar,int start,int end) {
#ifdef mdebug	
	cout<<"\nPartionng ";
	print_array(ar,start,end+1);
#endif
	int j = start;
	int pv_data = ar[end];
	for(int i = start ; i < end; i++) {
		if(ar[i] <= pv_data) {
			swap(ar[i],ar[j]);
			j++;
		}
	}
	swap(ar[j],ar[end]);
#ifdef mdebug
	print_array(ar,start,end+1);
	cout <<"\n Partion returned :"<<j;
#endif
	return j;
}

int findkthSmall(int *ar, int start, int end, int k) {
#ifdef mdebug
	cout<<"\nfindkthSmall called with start end and k : "<<start<<" "<<end<<" "<<k;
#endif
	int p = partion(ar, start,end);
	
	
	if(p-start == k) {
		return ar[p];
	}
	if(k <= end-start+1) {
		if(k < p-start) {
			//find in left
			return findkthSmall(ar,start,p-1,k);
		} else {
			return findkthSmall(ar,p+1,end,k-p+start-1);
		}
	}
	return 10000;
}
int main() {
	int ar[] = { 100,12 , 4 , 7, 19,33,81, 23, 45, 11, 20};
//	int ar[] = {10 ,18, 12 };
	int size = sizeof(ar)/sizeof(ar[0]);
	int k = 3;
	int ans = findkthSmall(ar,0,size-1,k);
	cout<<"\n"<<k<<"th smallest is "<< ans;

	cout<<"\n Sorted array is : ";
	sort(ar,ar+size);
	print_array(ar,0,size);
/*	int p = partion(ar,0,size-1);
	print_array(ar,size);
	cout<<"\n Value of p is " <<p;
	*/
	cout<<"\n";
	return 0;
}