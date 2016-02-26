#include <iostream>
#include <fstream> 
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
using namespace std;


void generate_genomic_inserts(string input_name){
	ifstream input_genome;
	ofstream inserts_length; 
	input_genome.open(input_name.c_str());
	inserts_length.open("inserts_lengths.csv");
	bool analyze_line = false;
	string line = "";
	getline(input_genome, line);  // it doesn't read the header row
	while(getline(input_genome, line)){   
				int position=0, next=0, orientation_check = 0;
				string word;
				istringstream iss(line, istringstream::in);
				int i = 0;
				while( iss >> word ){     
					if(i==3){
						istringstream(word) >> position; 
					}
					if(i==7){
						istringstream(word) >> next; 
					}
					if(i==8){
						istringstream(word) >> orientation_check; 
					}
					i++;
				}
				if(orientation_check>0)
				inserts_length<<abs(next-position)<<"\n"; 
	} 
	input_genome.close();
	inserts_length.close();
	cout<<"[Insert-lengths] Done\n\n"; 
} 
 