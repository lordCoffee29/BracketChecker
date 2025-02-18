
#include <iostream>
#include <string.h>
#include <fstream>
#include <filesystem>
#include "DSStack_array.h"
#include "DSList.h"

class BracketCheck
{

private:
    std::string filename; // Name of file
public:
    void setFileName(std::string name);
    int check_array();
    int check_list();
};