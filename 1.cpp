#include <iostream>
#include <ctime>
using namespace std;


void quicksort(int *arr, int first, int last) 
{
	int m, count;
	int f=first, l=last;
	m=arr[(f+l) / 2]; 
	do{
		while (arr[f]<m) f++;
		while (arr[l]>m) l--;
		if (f<=l){ 
			count=arr[f];
			arr[f]=arr[l];
			arr[l]=count;
			f++;
			l--;
		}
	} 
	while (f<l);
	if (first<l) quicksort(arr, first, l); 
	if (f<last) quicksort(arr, f, last);
	return;
}


void main()
{
	setlocale(LC_ALL,"Rus");
	cout << "Введите количество элементов массива" << endl;
	int n = 0;
	cin >> n;
	int *arr=new int[n]; 
	srand(time(NULL));
	cout<<"Исходный массив: ";
	for (int i=0; i<n; i++){
		arr[i]=rand()%1000; 
		cout<<arr[i]<<" ";
	} 
	int first=0;
	int last=n-1;
	quicksort(arr, first, last); 
	cout<<endl<<"Результирующий массив: ";
	for (int i=0; i<n; i++) cout<<arr[i]<<" ";
	cout << endl;
	delete []arr; 
	return;
}