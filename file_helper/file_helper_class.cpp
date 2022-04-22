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
		filepath = filename;
		return 0;
	}
	
	// if only a filename given, then check for file to exist in current directory
	std::filesystem::path current_directory = std::filesystem::current_path();
	if (std::filesystem::exists(current_directory / filename)) 
	{ 
		// file exists
		filepath = current_directory / filename;
		return 0;
	}
	else
	{
		std::cout << "\"" << filename << "\" does not exist in " << current_directory << "\n";
		return -1;
	}
}

int file_helper_class::load_file()
{
	if (file_open() == 0)
	{
		std::string line;
		while (std::getline(csv_file, line))
		{
			file_vector.push_back(line);
		}
		nr_of_lines = file_vector.size();
		file_close();
		return 0;
	}
	else
	{
		std::cout << "Error loading file\n";
		return -1;
	}
}

int file_helper_class::get_nr_of_lines()
{
	return nr_of_lines;
}

std::string file_helper_class::get_line(int line_nr)
{
	if (line_nr <= (file_vector.size() - 1))
	{
		std::string line = file_vector[line_nr];
		return line;
	}
	else
	{
		std::cout << "Error: line_nr too big for vector content\n";
		return "";
	}
}

std::vector<std::string> file_helper_class::split_comma(std::string line)
{
	std::vector<std::string> columns;
	int pos_first_comma = 0;

	while (line.length() > 0)
	{
		pos_first_comma = line.find_first_of(",");
		if (pos_first_comma > 0)
		{
			// get characters up to comma
			// push_back on the comlumns vector
			// reuse string from comma upwards
			std::string part = line.substr(0, pos_first_comma);
			columns.push_back(part);
			line = line.substr(pos_first_comma + 1, line.length());
		}
		else
		{
			// the last part of the string contains no comma
			// so just put this last part onto the vector
			columns.push_back(line);
			// line is now consumed, exit while loop
			line = "";
		}
	}
	return columns;
}

int file_helper_class::file_open()
{
	if (filepath == "")
	{
		std::cout << "The filepath is not set. Please set a filename\n";
		return -1;
	}
	csv_file.open(filepath);
	if (csv_file.is_open())
	{
		return 0;
	}
	else
	{
		std::cout << "Error opening file\n";
		return -1;
	}
}

int file_helper_class::file_close()
{
	csv_file.close();
	return 0;
}

