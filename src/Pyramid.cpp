#include "Pyramid.h"

Pyramid computeMultiScaleChannelFeaturePyramid(Mat)
{
    ;
}

Pyramid Pyramid::computeSingleScaleChannelFeaturePyramid(Mat I, Channel pChns)
{
    //crop I so it becomes divisible by shrink
    int height = I.rows - (I.rows % pChns.shrink);
    int width =  I.cols - (I.cols % pChns.shrink);


    //compute color channels
    I = this->pChns.pColor.rgbConvert(I);
    I = this->pChns.pColor.convConst(I, CONV_TRI);

}

Mat Pyramid::TriangleFilterConvolution(Mat I, int r, int s, int nomex)
{
    Mat result = I;
    if(!I.empty() && !(r==0 && s==1))
    {
        int m = min(I.rows, I.cols);
        if(m>=4 && m>2*r+1)
        {
            if(nomex==0)
            {
                if(r>0 && r<=1 && s<=2)
                    result = this->pChns.pColor.convConst(I,CONV_TRI1);
                else
                    result = this->pChns.pColor.convConst(I,CONV_TRI);
            }
            else
            {
                double f[3];
                if (r <= 1)
                {
                    double p=12/r/(r+2)-2;
                    f[0] = 1/(2+p);
                    f[2] = f[0];
                    f[3] = p / (2+p);
                    r=1;
                }
                else
                {
                    for (int i=1; i <= r+1; i++)
                        f[i] = i/(pow(r+1,2));
                    for (int i=2*r+1; i > r+1; i--)
                        f[i] = i/(pow(r+1,2));
                }
                //result = padarray(I,[r r],"symmetric","both");
                copyMakeBorder(I, result, 0, 0, r, r, BORDER_REPLICATE);
                //result = convn(convn(result,f,"valid"),f',"valid");
                if (s>1)
                {
                    int t=floor(s/2)+1;
                    Mat temp;
                    /*for (int i=t; i < result.rows-s+t+1; i = i + s)
                        for (int j=t; j < result.cols-s+t+1; j = j + s)
                            temp*/
                    //result = result(t:s:end-s+t,t:s:end-s+t,:);
                }
            }
        }
    }
    return result;
}
