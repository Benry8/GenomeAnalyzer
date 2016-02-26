#include <iostream>
#include <fstream> 
#include <string>
#include <cmath> 
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

int get_length(string line){
	istringstream iss(line, istringstream::in);
	string word = "";
	iss >> word;
	int position = line.find("LN:");
	if(position > -1){
		word = line.substr(position+3, line.length()-1);
	}
	istringstream ist(word);
	int length = 0;
	ist >> length; 
	return length;	
}

void generate_sequence_coverage(string input_name){
	ifstream input_genome;
	ofstream sequence_coverage;
	input_genome.open(input_name.c_str());
	sequence_coverage.open("sequence_coverage.wig");
	vector<int> sequence_coverage_vector; 
	string line = "";
	int length=0;
	getline(input_genome, line);  
	if(line[0] == '@'){
		istringstream iss(line, istringstream::in);
		length = get_length(line); 
	}
	sequence_coverage_vector.resize(length, 0);
	while(getline(input_genome, line)){
			int position=0;
			string word;
			istringstream iss(line, istringstream::in);
			int i = 0;
			bool check_row = true;
			int orientation_check = 0;
			while( iss >> word ){     
				int seq_length= 0; 
				if(i==1){
					int bit_control = 0;
					istringstream(word) >> bit_control;
					if((bit_control & 3) != 3){
						check_row = false;
					}
				}
				if(i==3){
					istringstream(word) >> position; 
				}
				if(i==8){
					istringstream(word) >> orientation_check; 
				}
				if(i==9){
					seq_length = word.length(); 
					if(check_row){
						if(orientation_check>0){
							for(int it = position; it!= position+seq_length; it++){
								sequence_coverage_vector[it]++;
							}
						}
						else{
							for(int it = position; it!=0 && it!= position-seq_length; it--){
								sequence_coverage_vector[it]++;
							}
						}
					}
				}
				i++;
			}
	}
	sequence_coverage << "fixedStep chrom=genome start=1 step=1 span=1\n";
	for(vector<int>::iterator it = sequence_coverage_vector.begin(); it!= sequence_coverage_vector.end(); it++)
		sequence_coverage << *it << "\n"; 		
	input_genome.close();
	sequence_coverage.close();
	cout<<"[sequence_coverage] Done\n\n"; 
} 

void generate_physical_coverage(string input_name){
	ifstream input_genome;
	ofstream physical_coverage;
	input_genome.open(input_name.c_str());
	physical_coverage.open("physical_coverage.wig");
	vector<int> physical_coverage_vector; 
	string line = "";
	int length=0;
	getline(input_genome, line);  
	if(line[0] == '@'){
		istringstream iss(line, istringstream::in);
		length = get_length(line); 
	}
	physical_coverage_vector.resize(length, 0); 
	while(getline(input_genome, line)){
			int start_position=0, end_position=0;
			string word;
			istringstream iss(line, istringstream::in);
			int i = 0;
			bool check_row = true;
			int orientation_check = 0;
			while( iss >> word ){   
				int seq_length= 0; 
				if(i==1){
					int bit_control = 0;
					istringstream(word) >> bit_control;
					if((bit_control & 3) != 3){
						check_row = false;
					}
				}
				if(i==3){
					istringstream(word) >> start_position; 
				}				
				if(i==7){
					istringstream(word) >> end_position; 
				}
				if(i==8){
					istringstream(word) >> orientation_check; 
				}
				if(i==9){
					seq_length = word.length(); 
					if(check_row && orientation_check>0){  
						for(int it = start_position; it!=physical_coverage_vector.size() && it!= end_position; it++){
								physical_coverage_vector[it]++;
						} 
					}
				}
				i++; 
			}
	} 
	physical_coverage << "fixedStep chrom=genome start=1 step=1 span=1\n";
	for(vector<int>::iterator it = physical_coverage_vector.begin(); it!= physical_coverage_vector.end(); it++)
		physical_coverage << *it << "\n"; 		
	input_genome.close();
	physical_coverage.close();
	cout<<"[physical_coverage_vector] Done\n\n";
}
 