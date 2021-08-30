# FFT_and_graphing
perform fft of signal and output a graph in frequency domain
FFTW3 and GNUplot must be installed on your computer to use this program.

	FFTW
	Will use fftw such that the program can take either a test waveform that will be created in the program itself or it can be fed an array from actual test data.  The program will calculate the fft of the input waveform and show us the component frequencies.  This output will be saved in an output file with two columns (magnitude and frequency).  The output file can then be used by the GNUplot portion of the project.  

	GNUplot
	The GNUplot software is fairly simple to use.  We simply use it to visualize the output of the fft so we don’t simply have to look at a table of values.  GNUplot is opened on the command line with “gnuplot” then we will use the command “plot 'spectrum.txt' with impulses”  with ‘spectrum.txt’ being the name of the file.  This will open a graph of the frequency spectrum output of the fft. 

	
	With this program we can do an FFT of any signal and view it's output in the frequency domain.  This is the main point of this program which allows for testing of radar, satellite, radio, and other RF systems.   Matlab can do the same thing but for a price.  When compiling the program be sure to include a link command such as in "gcc filename.c -lfftw3 -lm".  
