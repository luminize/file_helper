#include <iostream>
#include "file_helper_class.h"

int main()
{
    // instantiate variable of type file_helper_class
    // this variable is a helper to read a .csv file
    // the variable can return the content of the file
    file_helper_class filecontent;
    filecontent.set_filename("sample_file.csv");
    filecontent.load_file();
    std::string row = filecontent.get_line(1);
    std::vector<std::string> column = filecontent.split_comma(row);
}
