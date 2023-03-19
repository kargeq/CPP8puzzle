/**
 *    
 *
 * @brief      Cpp file for node which is simply the constructor
 *
 * @author     Kareem Ateeqi
 * 
 * @date       11/302021
 */
#include "Node.h"

#include <string>


/**
 * @brief constructor for Node
 * @param combination Grid (in string form to be used)
 * @param steps steps needed to reach goal state
 */
Node::Node(string combination, int steps){

	grid=combination;
	numberofsteps=steps;
}