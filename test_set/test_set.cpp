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
extern const char test_set_path_int[] = "D:\\Projects\\001_codeblocks_project\\c++\\WD_DS\\test_set\\test_set_int.txt";

/**********************************************************************/
/*
 * get the nth line of a file
 * only for char string
 * Parameters: an exist string, line num, file path
 * Returns: status
 */
/**********************************************************************/
bool get_line_char(string &str,int n,const char* file_path){

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
                test_input.close();
                return false;
            }

        }
//        cout << str << endl;
    }
    else{
        test_input.close();
        return false;
    }
    test_input.close();
    return true;
}

bool get_line_int(int &val, int n, const char* file_path){

    if( n<1 ){
        cout << "line number out of range" << endl;
    }

    string str;
    ifstream test_input(file_path);
    if(test_input.good()){
        for(int i=0; i<n; i++){
            if(!test_input.eof())
                getline(test_input, str);
            else{
                cout << "end of file" << endl;
                test_input.close();
                return false;
            }
        }
    }
    else{
        test_input.close();
        return false;
    }
    stringstream ss(str);
    ss >> val;

    test_input.close();
    return true;
}



