#include "DFT.hpp"

DFT::DFT(double *_sig_src_arr, double *_sig_dest_rex_arr,double  *_sig_dest_imx_arr,int _sig_length,
          double *_sig_dest_mag_arr, double *_sig_src_rex_arr, double *_sig_src_imx_arr, double *_idft_out_arr, int _idft_length)
{
    sig_src_arr = _sig_src_arr;
    sig_dest_rex_arr = _sig_dest_rex_arr;
    sig_dest_imx_arr = _sig_dest_imx_arr;
    sig_length = _sig_length;

    sig_dest_mag_arr = _sig_dest_mag_arr;
    sig_src_rex_arr =  _sig_src_rex_arr;
    sig_src_imx_arr = _sig_src_imx_arr;

    idft_out_arr = _idft_out_arr;
    idft_length = _idft_length;
}


void DFT:: calc_sig_dft( double *sig_src_arr, double *sig_dest_rex_arr, double  *sig_dest_imx_arr,int sig_length)
{
	int j,k,i;

	for(j=0;j<sig_length;j++)
	{
	  sig_dest_imx_arr[j] =0;
		sig_dest_rex_arr[j] =0;
	}

	for(k=0;k<sig_length;k++)
	{
	   for(i=0;i<sig_length;i++)
		{
		     sig_dest_rex_arr[k] =  sig_dest_rex_arr[k] + sig_src_arr[i]*cos(2*M_PI*k*i/sig_length);
				 sig_dest_imx_arr[k] =  sig_dest_imx_arr[k] - sig_src_arr[i]*sin(2*M_PI*k*i/sig_length);
        }
	}
}

void DFT:: get_dft_output_mag(double * sig_dest_mag_arr, double * sig_src_rex_arr, double * sig_src_imx_arr )
{
    int x;
    for(x =0;x<SIG_LENGTH/2;x++){
        sig_dest_mag_arr[x]  = sqrt(pow(sig_src_rex_arr[x],2)+ pow(sig_src_imx_arr[x],2));
    }

}

void DFT::calc_idft(double *idft_out_arr, double *sig_src_rex_arr,double *sig_src_imx_arr, int idft_length)
{

int i,k;

    for(k=0;k<idft_length;k++){

         sig_src_rex_arr[k] =  sig_src_rex_arr[k]/(idft_length/2);
         sig_src_imx_arr[k] =  sig_src_imx_arr[k]/(idft_length/2);
    }

     for(k =0;k<idft_length;k++){
        idft_out_arr[k] = 0;
     }

     for(k =0;k<idft_length/2;k++){

        for(i =0;i<idft_length;i++){

            idft_out_arr[i] = idft_out_arr[i] +  sig_src_rex_arr[k]* cos(2*M_PI*k*i/idft_length);
            idft_out_arr[i] =  idft_out_arr[i] + sig_src_imx_arr[k]* sin(2*M_PI*k*i/idft_length);
        }
     }
}

