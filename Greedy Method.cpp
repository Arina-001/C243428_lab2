#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    Activity arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }

    sort(arr, arr + n, compare);

    int count = 1;
    int lastFinish = arr[0].finish;

    cout << "Selected activities:\n";
    cout << arr[0].start << " " << arr[0].finish << endl;

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= lastFinish) {
            cout << arr[i].start << " " << arr[i].finish << endl;
            lastFinish = arr[i].finish;
            count++;
        }
    }

    cout << "Total activities: " << count;

    return 0;
}
