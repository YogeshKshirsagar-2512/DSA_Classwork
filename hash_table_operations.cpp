#include<iostream>
using namespace std;

void settodefault(int hash_table[], int size){
    for(int i = 0 ; i < size ; i++){
        hash_table[i] = -1;
    }
}

int finding_index(int key, int size){
    return key % size;
}

void insertion(int hash_table[], int size, int index, int key){
    int start_index = index;
    
    while(hash_table[index] != -1){ 
        index = (index + 1) % size; 
        
        if(index == start_index){ 
            cout << "Hash table is full! Cannot insert " << key << endl;
            return;
        }
    }
    hash_table[index] = key; 
    cout << "Successfully inserted " << key << " at index " << index << endl;
}

int search(int hash_table[], int size, int key) {
    int index = finding_index(key, size);
    int start_index = index;
    
    while (hash_table[index] != -1) {
        if (hash_table[index] == key) {
            return index; 
        }
        index = (index + 1) % size;
    
        if (index == start_index) {
            break;
        }
    }
    return -1;
}

void display_hash_table(int hash_table[], int size){
    cout << "\n----- CURRENT HASH TABLE -----\n";
    for(int i = 0 ; i < size; i++){
        if(hash_table[i] == -1){
            cout << "Index " << i << ": Empty index" << endl;
        }else{
            cout << "Index " << i << ": " << hash_table[i] << endl;
        }
    }
    cout << "------------------------------\n";
}

int main(){
    int size;
    cout << "Enter Size of Hash Table: ";
    cin >> size;
    
    int hash_table[size]; 
    settodefault(hash_table, size);
    
    int choice, key, index, found_index;
    int current_elements = 0;
    while (true) {
    
        cout << "\n*** HASH TABLE MENU ***" << endl;
        cout << "1. Insert an Element" << endl;
        cout << "2. Search for an Element" << endl;
        cout << "3. Display Hash Table" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (current_elements >= size) {
                    cout << "Error: Hash table is completely full!" << endl;
                } else {
                    cout << "Enter number to add: ";
                    cin >> key;
                    index = finding_index(key, size);
                    insertion(hash_table, size, index, key);
                    current_elements++;
                }
                break;

            case 2:
                cout << "Enter number to search: ";
                cin >> key;
                found_index = search(hash_table, size, key);
                
                if (found_index != -1) {
                    cout << "Element " << key << " found at index " << found_index << endl;
                } else {
                    cout << "Element " << key << " not found in the hash table." << endl;
                }
                break;

            case 3:
                display_hash_table(hash_table, size);
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please select an option between 1 and 4." << endl;
        }
    }
}
