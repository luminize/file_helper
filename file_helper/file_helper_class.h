#pragma once
#include <string>
#include <istream>
#include <vector>

class file_helper_class
{
public:
	// constructor and destructor
	file_helper_class();
	~file_helper_class();

	// variables
	std::string filename = { "" };

	int set_filename(std::string filename);

private:
	// functions
	int file_open(std::string filename);
	int file_close(std::string filename);

	//variables
	std::vector<std::string> file_vector = {};
};

