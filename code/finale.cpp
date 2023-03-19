/**
 *
 * @brief      finale.cpp file which computes puzzle8
 *
 * @author     Kareem Ateeqi
 * @date       11/30/2021
 */
#include "Node.h"
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
/**
 * @brief      generates neighbor (another grid) in which hole moves to the left
 *
 * @param  original  The original parent grid
 * @param  index     The original index of the hole
 *
 * @return     modfied string
 */
string left(string original, int index) {
    swap(original[index], original[index - 1]);
    return original;
}
/**
 * @brief      generates neighbor (another grid) in which hole moves to down
 *
 * @param  original  The original parent grid
 * @param  index     The original index of the hole
 *
 * @return     modified string
 */
string down(string original, int index) {
    swap(original[index], original[index + 3]);
    return original;
}
/**
 * @brief      generates neighbor (another grid) in which hole moves up
 *
 * @param  original  The original parent grid
 * @param  index     The original index of the hole
 *
 * @return     modified string
 */
string up(string original, int index) {
    swap(original[index], original[index - 3]);
    return original;
}
/**
 * @brief      generates neighbor (another grid) in which hole moves to the right
 *
 * @param  original  The original parent grid
 * @param  index     The original index of the hole
 *
 * @return     modified string
 */
string right(string original, int index) {
    swap(original[index], original[index + 1]);
    return original;
}
/**
 * @brief      Finds index where there is a zero.
 *
 * @param  grid    the grid that is passed in
 * @return     the index of where the hole( zero) is
 * @attention   the function returns -1 if no zero is there
 */
int findZero(string grid) {
    for (int i = 0; i < 9; i++) {
        if (grid[i] == '0') {
            return i;
        }
    }
    return -1;
}
/**
 * @brief      returns a vector of the possible grids that can be developed from the parent grid
 *
 * @param[in]  parent  The parent grid/Node which has its neighbors generated
 *
 * @return     vector of neighbors generated
 */
vector<string> GenerateNeighbors(Node parent) {
    vector<string> toBeReturned;
    int zero = findZero(parent.grid);
    if (zero != 6 and zero != 7 and zero != 8) {
        toBeReturned.push_back(down(parent.grid, zero));
    }
    if (zero != 0 and zero != 1 and zero != 2) {
        toBeReturned.push_back(up(parent.grid, zero));
    }
    if (zero != 2 and zero != 5 and zero != 8) {
        toBeReturned.push_back(right(parent.grid, zero));
    }
    if (zero != 0 and zero != 3 and zero != 6) {
        toBeReturned.push_back(left(parent.grid, zero));
    }
    return toBeReturned;
}
/**
 * @brief      main function which attempts to solve puzzle
 * @details    the main works by asking for a grid which it processes @n
 * then it attempts to see any inversions if possible @n
 * then if there are none it goes on ahead and does a breadth first-search with a queue using a @n
 * hashmap to see if any nodes were already there to prevent duplicates; after generating all possible routes (and putting them in the hashtable), @n
 * it returns the goal state's number of steps
 * @return     main value return of zero
 */
int main() {
    unordered_map<string, int> hashTable; //stores values from nodes so duplicate searches don't happen
    queue<string> tada;

    string data_line;///get data from line
    string combined_string; //resulting strings of lines to form first grid

    cout << "Enter puzzle" << endl;


    for (int i=0;i<9;i++){
        cin>>data_line;
        combined_string+=data_line;
        
    }
   
   
    cout << "Solving puzzle" << endl;
    int inversions=0;
    for (int i = 8; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if ((combined_string[i] - '0') < (combined_string[j] - '0') && (combined_string[i] != '0' && combined_string[j] != '0')) { //we do the minus '0' to basically convert to int; we also must ignore the zero as it represents a blank
                inversions++;
            }
        }
    }
    if (inversions % 2 == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;//exit if impossible
    }
    Node Start(combined_string, 0); //starting node has starting distance of zero


    hashTable.insert(make_pair(Start.grid, Start.numberofsteps));
    tada.push(Start.grid);

    while (!(tada.empty())) {
        Node bob(tada.front(), hashTable[tada.front()]);


        tada.pop();

        vector<string> suspects = GenerateNeighbors(bob);

        vector<string>::iterator it;

        for (it = suspects.begin(); it != suspects.end(); it++) { //go through combinations of neighbors

            if (hashTable.find(*it) != hashTable.end()) { //check if already searched
                continue;
            }
            hashTable.insert(make_pair(*it, bob.numberofsteps + 1)); //if not put in table and queue
            tada.push(*it);
        }

    }


    string solution = "123456780";

    cout << hashTable[solution] << endl; //check number of steps needed to reach goal state from starting combo

    return 0;

}