#include "cpp/genomic_inserts.cpp"
#include "cpp/generate_deviations.cpp" 
#include "cpp/coverage.cpp"
#include "cpp/kmer_frequency.cpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

string check_file_name(string extension){
	bool check=false;
	string input_name;
	do{
		cout<<"Please, digit the input file name (example: 'name"+extension+"' without quotes)\n";
		cin>>input_name; 
		ifstream file;
		file.open(input_name.c_str());
		if((input_name.find(extension) != string::npos)&&(file))
			check = true;
		else
			cout<<"This file doesn't exist or the extension is wrong.\n";
		file.close();
	}while(!check); 
	cout<<"Execution...\n";
	return input_name;
}

void call_gil(){
	string input = check_file_name(".sam");
	generate_genomic_inserts(input);
}

void call_gmsd(){
	string input = check_file_name(".csv");
	generate_deviations(input);
} 

void call_sc(){
	string input = check_file_name(".sam");
	generate_sequence_coverage(input);
} 

void call_pc(){
	string input = check_file_name(".sam");
	generate_physical_coverage(input);
}  

void call_gk(){
	string input = check_file_name(".sam");
	generate_kmers(input);
} 

void call_skf(){ 
	string input = check_file_name(".txt");
	sort_kmers(input);
}

int main(){
	int command;
	bool stop=false;
	cout<<"Welcome to GenomeAnalyzer,\n";
	do{
		command = -1;
		cout<<"Type one of the following commands to generate files \n"
				"with informations gathered from genome.\n"
		       	"List of commands:\n"
		   		"\t > '1' : 'get a list of insert lengths from a sam file'\n"
		   		"\t > '2' : 'generate mean and standard deviations of insert lengths'\n"
		   		"\t > '3' : 'generate sequence coverage'\n"
		   		"\t > '4' : 'generate physical coverage'\n"		
		   		"\t > '5' : 'generate a list of kmers'\n"
		   		"\t > '6' : 'sort the list of kmers generated on point ""5""'\n"
		   		"\t > '0' : 'end program execution' \n";
		cin>>command; 
		switch (command){
			case(1):
				call_gil();
				break;
			case(2):
				call_gmsd();
				break;
			case(3):
				call_sc();
				break;
			case(4):
				call_pc();
				break;		
			case(5):
				call_gk();
				break;	
			case(6):
				call_skf();
				break;
			case(0):
				cout<<"Program execution ended. \n";
				stop = true;
				break; 
		} 
	}while(!stop);
}