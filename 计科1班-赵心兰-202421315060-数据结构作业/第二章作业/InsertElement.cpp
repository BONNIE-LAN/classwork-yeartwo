#include <iostream>
using namespace std;

// 有序线性表类（使用顺序存储）
template<typename T>
class OrderedList {
private:
    T arr[100];  // 存储数据的数组
    int length;    // 当前元素个数

public:
    // 构造函数
    OrderedList() {
        length = 0;
    }

    // 输入数据
    bool inputList() {
        cout << "please enter the number of element you want(enter -1 exit):";
        cin >> length;
        if (length == -1) {
            return false;
        }
        cout << "please enter " << length << " numbers of elements:";
        for (int i = 0; i < length; i++) {
            cin >> arr[i];
        }
        return true;
    }

    // 显示数组
    void displayList(const string& msg) {
        cout << msg;
        for (int i = 0; i < length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // 插入元素并保持有序
    void insertElement(int x) {
        int i = length - 1;
        // 从后往前移动比 x 大的元素
        while (i >= 0 && arr[i] > x) {
            arr[i + 1] = arr[i];
            i--;
        }
        // 在合适位置插入 x
        arr[i + 1] = x;
        length++;
    }
};

int main() {
    OrderedList<int> list;
    while (true) {
        if (!list.inputList()) break;

        int x;
        cout << "The element you want to insert: ";
        cin >> x;

        list.displayList("Array before inserting:");
        list.insertElement(x);
        list.displayList("Array after inserting:");
        cout << endl;
    }
    return 0;
}

