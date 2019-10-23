#include "Convolution.hpp"

Convolution::Convolution(double* _sig_src_arr,double* _sig_dest_arr, double* _imp_response_arr, int _sig_src_length, int  _imp_response_length)
{
     sig_src_arr = _sig_src_arr;
     sig_dest_arr = _sig_dest_arr;
     imp_response_arr = _imp_response_arr;
     sig_src_length = _sig_src_length;
     imp_response_length = _imp_response_length;

            file1.open("output_signal.dat");
            file2.open("input_signal.dat");

            for(int i =0;i<_sig_src_length+_imp_response_length;i++){

                file1<<OutputSignal[i]<<endl;
                if(i <sig_src_length){
                file2<<InputSignal_f32_1kHz_15kHz[i]<<endl;
                }
            }
            file1.close();
            file2.close();
            return 0;
}

double Convolution::convolution_output()
{
    int i,j;

    for(i =0;i<(sig_src_length+ imp_response_length);i++)
    {
        sig_dest_arr[i] = 0;
    }

     for(i =0;i<sig_src_length;i++)
     {
         for(j =0;j<imp_response_length;j++)
         {
             sig_dest_arr[i+j] =  sig_dest_arr[i+j] + sig_src_arr[i]*imp_response_arr[j];
         }
     }
}

double Convolution::convolution_input()
{
    int i,j;
    for(i =0;i<(sig_src_length+ imp_response_length);i++)
    {

        sig_dest_arr[i] = 0;

    }
    for(i =0;i<sig_src_length+ imp_response_length-1;i++)
            {
                sig_dest_arr[i] = 0;

                     for(j =0;j<imp_response_length;j++)
                     {
                         if((i-j >0) && (i-j >0) <(sig_src_length-1) );

                         sig_dest_arr[i] =  sig_dest_arr[i] + imp_response_arr[j]*InputSignal_f32_1kHz_15kHz[i-j];

                     }
            }

}


