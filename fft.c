#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<complex.h>
#include<time.h>//This library is declared before fftw3.h
#include<fftw3.h>

int main(void)
{   
    FILE *fp = NULL;
    fp = fopen("spectrum.txt", "w");
    srand((unsigned)time(NULL));
	int i;
	double Npoints = 500;
    double frequency = 2000;
    double sampleRate = 80000;
    
    
    fftw_complex *in, *out;
	fftw_plan plan;

	in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*Npoints);			//allocating memory
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*Npoints);		//allocating memory
	plan = fftw_plan_dft_1d(Npoints, in, out, FFTW_FORWARD, FFTW_ESTIMATE); 	//Here we set which kind of transformation we want to perform

	printf("\nCoefficcients of the expansion:\n\n");
	for(i = 0; i < Npoints; i++)
	{
        // build input signal for testing, when using to test signals in practice the sampled signal will be
        // placed into this array.
		in[i] =  1 * sin(frequency*2*M_PI*(i/sampleRate))+ 1 * sin(7000*2*M_PI*(i/sampleRate)) + 1 * sin(30000*2*M_PI*(i/sampleRate)); 
		printf("%d %11.3f %11.3f\n", i, creal(in[i]), cimag(in[i]));		//creal and cimag are functions of complex.h 
	}
	printf("\n");

	fftw_execute(plan); 								//Execution of FFT

	printf("Output:\n\n");
	for(i = 0; i < Npoints/2; i++)
	{
		int freq = i*sampleRate/Npoints;
        double x = creal(out[i])/Npoints;
        double y = cimag(out[i])/Npoints;
        double mag = sqrt(x*x+y*y);
        printf("%d %f\n", freq, mag);
        fprintf(fp, "%d\t %1f\n", freq, mag);
	}

	fftw_destroy_plan(plan);							//Destroy plan
	fftw_free(in);			 						//Free memory
	fftw_free(out);			 						//Free memory
	return 0;
}
