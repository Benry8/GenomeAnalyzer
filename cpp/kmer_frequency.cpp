#include <iostream>
#include <fstream> 
#include <string>
#include <cmath> 
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;



class kmer{
	private: 
		string sequence; 	
		int frequency;
	public:
		static const int dimension = 5; 
		kmer(string seq){
			sequence = seq;
			frequency = 1;
		}

		kmer(string seq, int freq){
			sequence = seq;
			frequency = freq;
		} 

		string get_sequence(){
			return sequence;
		}

		int get_frequency(){
			return frequency;
		}

		void increment_frequency(){
			frequency++;
		}

		bool operator<(const kmer& y) const{
			return(frequency < y.frequency);
		}
};

void get_kmers(string sequence, vector<kmer>& kmers){
	int size = sequence.size(), vector_size = kmers.size(), incr = 0;
	for(int i=0; i< size - kmer::dimension; i++){
		string analyz_kmer = sequence.substr(i, kmer::dimension); 
		vector<kmer>::iterator it;
		for(it = kmers.begin(); (it!= kmers.end()) && (it->get_sequence() != analyz_kmer); it++);
		if(it!=kmers.end()){
			it->increment_frequency();
		}else{
			kmer* x = new kmer(analyz_kmer);
			kmers.push_back(*x);		
		}
	} 
}

void generate_kmers(string input_name){ 
	cout<<"It can take some hours.\n";
	ifstream input_genome;
	ofstream kmers_output;
	vector<kmer> kmers;
	input_genome.open(input_name.c_str());  
	string line = "";
	int c=0;
	while(getline(input_genome, line)){  
		if(line[0] != '@'){ 
				int position=0, next=0;
				string sequence;
				istringstream iss(line, istringstream::in);
				int i = 0;
				while( iss >> sequence ){     
					if(i==9){
						get_kmers(sequence, kmers); 
					} 
					i++;
				} 
		}
		c++;
	} 
	kmers_output.open("kmers_frequency.csv");
	for(vector<kmer>::iterator it = kmers.begin(); it!= kmers.end(); it++){
		kmers_output<<it->get_sequence()<<", "<<it->get_frequency()<<"\n";
	}
	input_genome.close();
	kmers_output.close();
	cout<<"[Generate Kmers frequency] Done\n\n"; 
}

void sort_kmers(string input_name){
	vector<kmer> kmers;
	ifstream input_genome;
	input_genome.open(input_name.c_str()); 
	string line = "";
	while(getline(input_genome, line)){  
		istringstream iss(line, istringstream::in);
		string seq, temp; int freq;
		iss >> seq; iss >> temp; istringstream(temp) >> freq;
		kmers.push_back(kmer(seq, freq));
	}
	sort(kmers.begin(), kmers.end());
	reverse(kmers.begin(), kmers.end());
	ofstream sorted_kmers;
	sorted_kmers.open("sorted_kmers_frequency.csv");
	for(vector<kmer>::iterator it = kmers.begin(); it!= kmers.end(); it++){
		sorted_kmers<<it->get_sequence()<<" "<<it->get_frequency()<<"\n";
	}
	input_genome.close();
	sorted_kmers.close();
	cout<<"[Sort Kmers frequency] Done\n\n"; 

}