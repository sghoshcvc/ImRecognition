 #include "libReadIm.h"
 #include<iostream>
 #include<stdio.h>
int main(void)

 {
     
     
    if (!mclInitializeApplication(NULL,0))
    {
        std::cerr << "Could not initialize the application properly."
                  << std::endl;
        return -1;
    }
     
     
if( !libReadImInitialize() )
    {
        std::cerr << "Could not initialize the library properly."
                  << std::endl;
        return -1;
    }
     mwArray H;

     mwArray W;
     
     mwArray flag(1);
     mwArray path ="temp";
     mwArray im_name ="02_06.jpg";
     mwArray im;

     //double *y;

     //double ret;

     /* Create an mxArray to input into mlfFoo */

     //x_ptr = mxCreateDoubleScalar(1);

     /* Call the library initialization function */

     

     /* read image */
     /*************************/
     /* Input path = path where image is stored*/
     /* Input im_name image file name without path*/
     /* flag =1 create a binary representation flag =0 no binary representation*/
     /* Output W = width of the image*/
     /* Output H= Height of the iage*/
     /*output im = image matrix in unit8 */
     

      read_im(3,W,H,im,path,im_name,flag);
      
      /*create attribute representations*/
      /************************************/
      /* Input im = image matrix*/
      /*Output atts = attribute representation*/
      /* Output attDim = dimension of attribute*/
      /*Output NumBlockX = number of Blocks in X direction*/
      /* Output NumBlockY Number of Block in Y direction*/
      mwArray attDim;
      mwArray numBlockX;
      mwArray numBlockY;
      mwArray atts;
      img2attr(4,attDim,numBlockX,numBlockY,atts,im);
      
      /* attribute for each candidate window given by detection */
      /* Input windows to be evaluated in (start_row,star_col,end_row,end_col) format 
      * this input should be of size (4*N) where N is number of detected text windows to be evaluated*/
      /* attribute representation for the image*/
      /*output attsWin a matrix of dimension W*N where W is the dimension of attribute representation and N is number of candiadte*/
      
      mwArray attsWin; /* to hold the attributes of windows */
              double  window_r[]={2,4,50,80,20,36,120,290}; /*Just taken randomly to test*/ 
              //double window_c[] =0;
      mwArray windows(2,4,mxDOUBLE_CLASS); /* this should be assigned to detecetd candidate boxes by detection routine*/
       windows.SetData(window_r, 8);   
                      
     AttWindows(1,attsWin,windows,atts,numBlockX,numBlockY);
     //std::cout <<attsWin << std::endl;
     /* this function is to calculate attribute representation for the lexicon*/
     /* output attsLex : matrix of the form attDim*LexN where attDim is dimension of attribute space and LexN is number of words in lexicon*/
     /*Output Lexicon is  list of words in given lexicon*/
     /* the lexicon is taken from the file model/SVT_lexicon_PHOCs_l2345_lb2_nb50.mat */
      mwArray attsLex;
      mwArray Lexicon;
      createLexAtts(2,attsLex,Lexicon);
     
      //score = attsWin *attsLex;
      //std::cout <<Lexicon << std::endl;
      
//std::cout <<attDim << std::endl;
//std::cout << numBlockX << std::endl;
//std::cout << numBlockY << std::endl;
//printf('%d',B);
     /* Call the library termination function */

    libReadImTerminate();
      /*libvigenereTerminate();*/
    mclTerminateApplication();
    /*return B;*/
    
    
//     /* The return value from mlfFoo is an mxArray so we must extract the data from it */

    /* y = mxGetPr(y_ptr);

     ret = *y;*/

     /* Print a double precision number*/

     /*printf("The output of foo is %f\n",ret);*/

 }