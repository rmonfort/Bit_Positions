#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::stoi;
using std::bitset;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		string temp;

		// Get parts of the line seperated by a commas
		getline(iss, temp, ',');
		int n = stoi(temp);

		// Convert n to binary
		string bin = bitset<32>(n).to_string(); 
		string r_bin;

		// Reverse the ordering of the string so I can just use the positions as indexes outright
		for (string::reverse_iterator rit = bin.rbegin(); rit != bin.rend(); ++rit)
		{
			r_bin += *rit;
		}

		// Get each position and account for the numbers being 1 based
		getline(iss, temp, ',');
		int p1 = stoi(temp) - 1;
		getline(iss, temp, ',');
		int p2 = stoi(temp) - 1;

		// Evaluate the bits according the positions 
		if (r_bin[p1] == r_bin[p2])
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}

	}
	return 0;
}