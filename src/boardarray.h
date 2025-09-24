#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;
 
class BoardArray : public Board {
    Entry* array;
    int index;
 
    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }
 
 ~BoardArray() {
        delete[] array;
    }
 
   void add(Entry* entry) override {
    int pos = index;
 
   
    for (int i = 0; i < index; i++) {
        if (entry->compare(array + i)) {
            pos = i;
            break;
        }
    }
 
    if (pos >= SIZE) {
       
        cout << entry->name << "'s score is too low to be added!\n";
        return;
    }
 
   
    if (index < SIZE) index++;
 
   
    for (int j = index - 1; j > pos; j--) {
        array[j] = array[j - 1];
    }
 
   
    array[pos] = *entry;
}
 
 
    void print() override {
        for (int i = 0; i < index; i++) {
            cout << i + 1 << ". ";
            array[i].print();
        }
    }
};
