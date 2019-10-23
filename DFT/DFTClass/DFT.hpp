#include <iostream>
#include <cmath>
#include <fstream>
#define SIG_LENGTH 320

#ifndef DFT_H
#define DFT_H

class DFT
{
private:
    double* sig_src_arr;
    double* sig_dest_rex_arr;
    double* sig_dest_imx_arr;
    int sig_length;

    double* sig_dest_mag_arr;
    double* sig_src_rex_arr;
    double* sig_src_imx_arr;

    double* idft_out_arr;
    int idft_length;

public:

    DFT(double *_sig_src_arr, double *_sig_dest_rex_arr,double  *_sig_dest_imx_arr,int _sig_length,
        double *_sig_dest_mag_arr, double *_sig_src_rex_arr, double *_sig_src_imx_arr, double *_idft_out_arr, int _idft_length);

        void calc_sig_dft(double* sig_src_arr, double* sig_dest_rex_arr, double* sig_dest_imx_arr, int sig_length);
        void get_dft_output_mag(double* sig_dest_mag_arr, double* sig_src_rex_arr, double* sig_src_imx_arr );
        void calc_idft(double* idft_out_arr, double* sig_src_rex_arr,double* sig_src_imx_arr, int idft_length);




};
#endif // DFT_H
