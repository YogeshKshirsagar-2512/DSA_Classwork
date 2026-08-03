// #include<iostream>
// #include<vector>
// using namespace  std;



// int main(){
    // int size;
    // cin >> size;
    // int arr[size];
    // int n = sizeof(arr)/sizeof(int);
    // double sum = 0;
    // for(int i = 0 ; i < size ; i++){
    //     cout << "Enter element of index "<<i<<" : ";
    //     cin >> arr[i];
    //     sum += arr[i];

    // }
    // cout << "sum of array elements : " << sum << endl;
    // cout << "avg of array elements : " << sum/size << endl;

    // for(int ele : arr){
    //     cout << ele << " ";
    // }

    // int pos,val;
    // cout << "enter position : ";
    // cin >> pos;
    // cout << endl;
    // cout << "enter val : ";
    // cin >> val;
    
    // for(int ele : arr){
    //     cout << ele << " ";
    // }

    // vector<int> arr;
    // for(int i = 0 ; i < 5; i++){
    //     arr.push_back(i);
    // }
    // for(int ele : arr){
    //     cout << ele << " ";
    // }


    // int size;
    // cin >> size;
    // int arr[size];

    // for(int  i = 0 ; i < sizeof(arr)/sizeof(int) ; i++){
    //     cin >> arr[i];
    // }

    // for(int ele : arr){
    //     cout << ele << " ";
    // }
    // int pos, val;
    // cout << "enter pos and ele : ";
    // cin >> pos;
    // cin >> val;
    // cout << endl;
    // if(0 > pos || pos > sizeof(arr)/sizeof(int)){
    //     cout << "invalid pos"<<endl;

    // }else{ 
    // arr[pos-1] = val;
    //     for(int ele : arr){
    //     cout << ele << " ";
    // }
    // }


#include <iostream>
using namespace std;

int main() {
    int arr[100], n, choice;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\nMENU\n";
        cout << "1. Insert Element\n";
        cout << "2. Update Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int pos, value;

            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            if (pos < 1 || pos > n + 1) {
                cout << "Invalid Position!\n";
            } else {
                cout << "Enter value to insert: ";
                cin >> value;

                for (int i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                cout << "Element inserted successfully.\n";
            }
            break;
        }

        case 2: {
            int pos, value;

            cout << "Enter position to update (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n) {
                cout << "Invalid Position!\n";
            } else {
                cout << "Enter new value: ";
                cin >> value;

                arr[pos - 1] = value;
                cout << "Element updated successfully.\n";
            }
            break;
        }

        case 3: {
            int pos;

            cout << "Enter position to delete (1 to " << n << "): ";
            cin >> pos;

            if (pos < 1 || pos > n) {
                cout << "Invalid Position!\n";
            } else {
                for (int i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;
                cout << "Element deleted successfully.\n";
            }
            break;
        }

        case 4: {
            cout << "Array Elements: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
