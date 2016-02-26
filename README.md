# GenomeAnalyzer

This tool generates useful informations like sequence coverage and physical coverage, giving a .sam file as input.
The tool was built considering the 18-nov-2015 version of the SAM specification [See the SAM specification for more informations about the format: https://samtools.github.io/hts-specs/SAMv1.pdf].
For more informations about the tool and its utility, please consider reading the paper (BioinformaticsProject.pdf). It contains informations on how to create an executable of the tool (on linux) in the case that the given one is not working.

----- Tool functions ------------------------------------------------------------------------------------------------------------

The tool allows to produce some file with several informations, given the .sam file as input:
  - generate a sequence of insert lengths  (input: .sam file);
  - calculate mean and standard deviation (input: insert lengths file, generated with the previous operation);
  - calculate physical coverage and sequence coverage (input: .sam file);
  - produce a list of kmers* (precisely 5-mers, but k can be easily changed) with their frequence in the genome  (input: .sam file);
  - order the list of kmers by frequency  (input: list of kmers file, produced with the previous operation).

*: execution on my pc required more than 2 hours. Please, be patient. 

----- Conclusions ------------------------------------------------------------------------------------------------------

One of the aims of the current tool is to generate useful informations through a .sam file elaboration. However, the main purpose of it is to public a project that could be extended providing always more functions related to .sam file elaboration. With this objective, the hope is that it will be used also as inspiration for further (not personal) projects.
