/**
 
 *
 * @brief      This file is the header implementation for Node.
 *
 * @author     Kareem Ateeqi
 * @date       11/30/2021
 */
#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

using namespace std;
/**
 * @brief      This class describes a node which contains a string and an int
 */
class Node{


public:
	/**@var string grid
	 *@brief 3x3 grid represented as string of length 9

	**/ 
	string grid;

    Node(string combination, int steps);

    /**
     * @var numberofsteps
	 *@brief numberofsteps from starting point
     */

	int numberofsteps;
};





#endif