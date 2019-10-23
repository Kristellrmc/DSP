#include <iostream>
#include <cmath>
#include <fstream>
#include "DFT.hpp"

#define SIG_LENGTH 320
using namespace std;

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double Output_REX[SIG_LENGTH];
double Output_IMX[SIG_LENGTH];
double Output_MAG[SIG_LENGTH];
double Output_IDFT[SIG_LENGTH];

int main()
{
    DFT *testsignal= new DFT(
                             (double *)&InputSignal_f32_1kHz_15kHz [0],
                             (double *)& Output_REX[0],
                             (double *)& Output_IMX[0],
                             (int) SIG_LENGTH,
                            (double *)&Output_MAG[0],
                            (double *)&Output_REX [0],
                            (double *)&Output_IMX [0],
                            (double *)&Output_IDFT[0],
                             (int) SIG_LENGTH
                            );

    ofstream file1,file2,file3,file4,file5;




        testsignal -> calc_sig_dft( (double *)&InputSignal_f32_1kHz_15kHz[0], (double *)&Output_REX[0], (double *)&Output_IMX[0], (int) SIG_LENGTH);
        testsignal -> get_dft_output_mag((double *)&Output_MAG[0],(double *)&Output_REX[0],(double *) &Output_IMX[0]);
        testsignal -> calc_idft((double *)&Output_IDFT[0], (double *)&Output_REX[0], (double *)&Output_IMX[0], (int) SIG_LENGTH);


     file1.open("input_signal.DAT");
     file2.open("output_REX.DAT");
     file3.open("output_IMX.DAT");
     file4.open("output_mag.DAT");
     file5.open("output_IDFT.DAT");

          for(int i=0;i<SIG_LENGTH;i++)
            {
            file1<<InputSignal_f32_1kHz_15kHz[i]<<endl;

            file2<<Output_REX[i]<<endl;
            file3<<Output_IMX[i]<<endl;
            file4<<Output_MAG[i]<<endl;

            file5<<Output_IDFT[i]<<endl;


            }

    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();

    return 0;
}


