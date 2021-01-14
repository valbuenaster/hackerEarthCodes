/*
 * assortedFunctions.h
 *
 *  Created on: Jan 7, 2021
 *      Author: luis
 */

#ifndef SRC_ASSORTEDFUNCTIONS_H_
#define SRC_ASSORTEDFUNCTIONS_H_

#include <string>
#include <sstream>

using namespace std;

template<class var>
var string2num(string & Str)
{
	var retVal;
	stringstream Var(Str);
	Var >> retVal;
	return retVal;
};


#endif /* SRC_ASSORTEDFUNCTIONS_H_ */
