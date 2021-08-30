#include "bst.h"
#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    BinarySearchTree<int, int> b1;

    pair<int, int> p;
    
    cout << "STARTING INSERT" << endl << endl << endl;
    for (int i = 1; i < 12; i++) {
        if ( i % 3 == 0) {
            p = make_pair(i, i);
        }
        else if ( i % 4 == 0) {
            p = make_pair(-i, -i);
        }
        else {
            continue;
        }
        b1.insert(p);
        cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
        b1.print();
        cout << endl << "-----------------------------------" << endl << endl;
    }


    p = make_pair(1, 4);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;


    cout << "OVERWRITING ROOT NODE" << endl << endl << endl;
    p = make_pair(3, 500);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;



    cout << "STARTING REMOVE" << endl << endl << endl;
    for (int i = 1; i < 12; i++) {
        b1.remove(i);
        cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
        b1.print();
        cout << endl << "-----------------------------------" << endl << endl;
    }

    for (int i = -1; i > -12; i--) {
        b1.remove(i);
        cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
        b1.print();
        cout << endl << "-----------------------------------" << endl << endl;
    }

    b1.remove(-4);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    cout << "STARTING INSERT AGAIN TO TEST CLEAR()" << endl << endl << endl;
    for (int i = 1; i < 12; i++) {
        if ( i % 3 == 0) {
            p = make_pair(i, i);
        }
        else if ( i % 4 == 0) {
            p = make_pair(-i, -i);
        }
        else {
            continue;
        }
        b1.insert(p);
        cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
        b1.print();
        cout << endl << "-----------------------------------" << endl << endl;
    }


    p = make_pair(1, 4);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    cout << "STARTING CLEAR" << endl << endl << endl;
    b1.clear();
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;
    p = make_pair(1, 1);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;
    



    
    cout << endl << "-----------------------------------" << endl << endl;
    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << "TESTING ISBALANCED() FUNCTION" << endl;

    b1.clear();
    cout << "empty:" << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;
    p = make_pair(1, 1);
    b1.insert(p);
    cout << "root only" << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;
    b1.clear();

    p = make_pair(10, 10);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(20, 20);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(15, 15);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(13, 13);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(5, 5);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(4, 4);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(7, 7);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(40, 40);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(27, 27);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-1, -1);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-20, -20);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-46, -46);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-52, -52);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-2, -2);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;

    p = make_pair(-3, -3);
    b1.insert(p);
    cout << endl << "BALANCED?: " << b1.isBalanced() << endl;
    b1.print();
    cout << endl << "-----------------------------------" << endl << endl;


    return 1;



}