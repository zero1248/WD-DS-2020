/*
*********************************************************************************************************
*
* file name:   test_set.cpp
* creator:     Isaac
* date:        20190405
* description: get test set
*
*********************************************************************************************************
*/

#include "test_set.h"

extern const char test_set_path[] = "D:\\Projects\\001_codeblocks_project\\c++\\WD_DS\\test_set\\test_set.txt";


/**********************************************************************/
/*
 * get the nth line of a file
 * Parameters: an exist string, line num, file path
 * Returns: status
 */
/**********************************************************************/
bool get_line_n(string &str,int n,const char* file_path){

    if( n<1 ){
        cout << "line number out of range" << endl;
    }

    ifstream test_input(file_path);
    if(test_input.good()){
        for(int i=0; i<n; i++){
            if(!test_input.eof())
                getline(test_input, str);
            else{
                cout << "line number out of range" << endl;
                return false;
            }

        }
//        cout << str << endl;
    }
    else
        return false;
    return true;
}


