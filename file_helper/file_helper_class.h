#pragma once
#include <string>
#include <istream>
#include <vector>
#include <filesystem>
#include <fstream>

class file_helper_class
{
public:
	// constructor and destructor
	file_helper_class();
	~file_helper_class();
	
	// variables
	std::string filename = { "" };
	int set_filename(std::string filename);
	int load_file();
	int get_nr_of_lines();
	std::string get_line(int line_nr);
	std::vector<std::string> split_comma(std::string line);

private:
	// functions
	int file_open();
	int file_close();

	//variables
	std::vector<std::string> file_vector = {};
	std::filesystem::path filepath = { "" };
	std::ifstream csv_file;
	int nr_of_lines;
};

