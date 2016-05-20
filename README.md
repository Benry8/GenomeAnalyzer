#GenomeAnalyzer - a SAM file elaboration tool written in c++.

* [Introduction](https://github.com/Benry8/GenomeAnalyzer/blob/master/README.md#introduction);
* [Tool Features](https://github.com/Benry8/GenomeAnalyzer/blob/master/README.md#features);
* [License](https://github.com/Benry8/GenomeAnalyzer/blob/master/README.md#license);
* [Conclusions](https://github.com/Benry8/GenomeAnalyzer/blob/master/README.md#conclusions).

###Introduction

GenomeAnalyzer is a c++ program that provides some options to make several elaborations on a SAM file.
This tool generates useful information like **sequence coverage** and **physical coverage**, giving a .sam file as input.
The tool was built considering the 18-nov-2015 version of the [SAM specification](https://samtools.github.io/hts-specs/SAMv1.pdf) (see the SAM specification for more information about the format).
Please, consider reading the document ([BioinformaticsProject.pdf](https://github.com/Benry8/GenomeAnalyzer/blob/master/BioinformaticsProject.pdf)) to get an accurate view of the tool and how it should be used. It contains information on how to create an executable of the tool (on linux) in the case that the given one is not working.

###Features

The tool allows to produce some file with several data, given the .sam file as input:
  * generate a sequence of insert lengths  (input: .sam file);
  * calculate mean and standard deviation (input: insert lengths file, generated with the previous operation);
  * calculate physical coverage and sequence coverage (input: .sam file);
  * produce a list of kmers* (precisely 5-mers, but k can be easily changed) with their frequence in the genome  (input: .sam file);
  * order the list of kmers by frequency  (input: list of kmers file, produced with the previous operation).

*: execution on my pc required more than 2 hours. Please, be patient. 

###Licence

GenomeAnalizer is licensed under the [MIT License](https://github.com/Benry8/GenomeAnalyzer/blob/master/LICENSE.md).

###Conclusions

One of the aims of the current tool is to generate useful information through a .sam file elaboration. However, the main purpose of it is to public a project that could be extended providing always more functions related to .sam file elaboration. The tool was released in the hope that it will be also used as inspiration for further (not personal) projects.
