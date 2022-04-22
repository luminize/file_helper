#include "file_helper_class.h"
#include <iostream>
#include <filesystem>

file_helper_class::file_helper_class()
{
}

file_helper_class::~file_helper_class()
{
}

int file_helper_class::set_filename(std::string filename)
{
	if (filename == "") { return -1; }
	
	// string contains valid path including exsting filename 
	if (std::filesystem::exists(filename))
	{
		std::cout << filename << " exists\n";
		filepath = filename;
		return 0;
	}
	
	// if only a filename check for file to exist in current directory
	std::filesystem::path current_directory = std::filesystem::current_path();
	if (std::filesystem::exists(current_directory / filename)) 
	{ 
		// file exists
		std::cout << current_directory << " exists\n";
		filepath = current_directory / filename;
		return 0;
	}
	else
	{
		std::cout << "\"" << filename << "\" does not exist in " << current_directory << "\n";
		return -1;
	}
}

int file_helper_class::file_open(std::string filename)
{
	return 0;
}

int file_helper_class::file_close(std::string filename)
{
	return 0;
}

