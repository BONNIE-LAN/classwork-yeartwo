#include<iostream>
#include<vector>
using namespace std;
int Search(vector<int>& arr,int target);
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    while(cin>>x&&x!=-1)
    {
        cout<<Search(arr,x)<<" ";
    }
    return 0;
}
int Search(vector<int>& arr,int target)
{
    int left=0,right=static_cast<int>(arr.size())-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid+1;
        if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return 0;
}
//AI version
#include <iostream>
#include <vector>
using namespace std;

int Search(const vector<int>& arr, int target) 
{
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) return i + 1; // 位序从 1 开始
    }
    return 0;
}
int main() 
{
    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x;
    while (cin >> x && x != -1) {
        cout << Search(arr, x) << " ";
    }
    return 0;
}
