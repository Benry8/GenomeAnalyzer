#include <cmath>   
#include <fstream> 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

int strToInt(string line){
	int number=0;
	istringstream ss(line); 
	ss>>number;   
	return number;
}

float getMedian(vector<int>& elems, int counter){
	int position = -1;
	float result = 0;
	position = counter/2;
	if(counter%2 == 1){
		result = elems[position];
	}
	else{
		result = (elems[position]+elems[position-1])/2;
	}
	return result;
}

float getSD(vector<int>& elems, float mean, float median){ 
	float result = 0;
	int counter = 0;
	vector<int>::const_iterator it;
	for(it= elems.begin(); it!=elems.end(); it++){ 
		if((*it < median*1.5) && (*it > median/2)){ 
			float diff = (*it)-mean;
			result+=pow(diff ,2); 
			counter++;
		}
	}
	result = result/(counter);
	result = sqrt(result);
	return result;
}

void print_results(double mean, double sd, int counter, int discarded_out_of_range){  
	cout<<"\n";
	cout<<"[Mean and SD] "<<mean<<" is the mean.\n";
	cout<<"[Mean and SD] "<<sd<<" is the standard deviation.\n";
	cout<<"[Mean and SD] "<<counter<<" elements added to the csv file.\n"; 
	cout<<"[Mean and SD] "<<discarded_out_of_range<<" insert lengths were discarded because totally out of range.\n";
	cout<<"\n";
}

void generate_deviations(string input_name){
	ifstream inserts_lengths; 
	ofstream deviations;
	
	double mean = 0, dev_mean = 0;
	
	int counter = 0; 

	string line =""; 
	vector<int> elements, ordered_elements, elements_deviation;
	inserts_lengths.open(input_name.c_str()); 
	while(getline(inserts_lengths, line)){
		
		int number = strToInt(line);   

		ordered_elements.push_back(number); // zeros must be considered to calculate the median
		counter++;
		if(number != 0){ //discard inserts with length = 0 
			elements.push_back(number); 
		}  
	}  
	sort(ordered_elements.begin(), ordered_elements.end()); 
	float median = getMedian(ordered_elements, counter);

	counter = 0;
	vector<int>::const_iterator it;
	for(it= elements.begin(); it!=elements.end(); it++){
		if((*it < median*1.5) && (*it > median/2)){ 
			mean+=*it;
			counter++;
		}
	} 
	mean = mean / (counter);   
	deviations.open("deviations.csv"); 
	counter = 0;
	int discard_out_of_range_elems = 0; // elements out of range
	for(it=elements.begin(); it != elements.end(); ++it){
		if((*it < median*1.5) && (*it > median/2)){ 
			elements_deviation.push_back(abs(*it-mean)); 
			deviations<<(abs(*it-mean))<<"\n";
			counter++;
		}
		else discard_out_of_range_elems++;
	} 
	float sd = getSD(elements, mean, median);
	print_results(mean, sd, counter, discard_out_of_range_elems); // on terminal
 	inserts_lengths.close();
	deviations.close();
}
 