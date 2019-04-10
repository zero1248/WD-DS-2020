/*
*********************************************************************************************************
*
* file name:   test_set.h
* creator:     Isaac
* date:        20190405
* description: get test set
*
*********************************************************************************************************
*/
#ifndef __TEST_SET_H__
#define __TEST_SET_H__

//#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

extern const char test_set_path[];
extern const char test_set_path_int[];

bool get_line_char(string&, int, const char*);
bool get_line_int(int&, int, const char*);


#endif // __TEST_SET_H__
