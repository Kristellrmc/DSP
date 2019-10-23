#ifndef CONVOLUTION
#define CONVOLUTION

class  Convolution{

private:
    double* sig_src_arr;
    double *sig_dest_arr;
    double *imp_response_arr;
    int sig_src_length = 320;
    int  imp_response_length = 29;

public:
    Convolution(double* _sig_src_arr,double* _sig_dest_arr, double* _imp_response_arr, int _sig_src_length, int  _imp_response_length);

    double convolution_input();
    double convolution_output();

};
#endif


