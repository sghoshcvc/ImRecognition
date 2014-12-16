//
// MATLAB Compiler: 4.17 (R2012a)
// Date: Tue Dec 16 17:09:33 2014
// Arguments: "-B" "macro_default" "-W" "cpplib:ImRecognition" "-T" "link:lib"
// "read_im" "img2attr" "AttWindows" "createLexAtts" 
//

#include <stdio.h>
#define EXPORTING_ImRecognition 1
#include "ImRecognition.h"

static HMCRINSTANCE _mcr_inst = NULL;


#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultPrintHandler(const char *s)
{
  return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int mclDefaultErrorHandler(const char *s)
{
  int written = 0;
  size_t len = 0;
  len = strlen(s);
  written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
  if (len > 0 && s[ len-1 ] != '\n')
    written += mclWrite(2 /* stderr */, "\n", sizeof(char));
  return written;
}

#ifdef __cplusplus
} /* End extern "C" block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_ImRecognition_C_API
#define LIB_ImRecognition_C_API /* No special import/export declaration */
#endif

LIB_ImRecognition_C_API 
bool MW_CALL_CONV ImRecognitionInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
  if (_mcr_inst != NULL)
    return true;
  if (!mclmcrInitialize())
    return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream((void *)(ImRecognitionInitializeWithHandlers));
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(   &_mcr_inst,
                                                                error_handler, 
                                                                print_handler,
                                                                ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
  return true;
}

LIB_ImRecognition_C_API 
bool MW_CALL_CONV ImRecognitionInitialize(void)
{
  return ImRecognitionInitializeWithHandlers(mclDefaultErrorHandler, 
                                             mclDefaultPrintHandler);
}

LIB_ImRecognition_C_API 
void MW_CALL_CONV ImRecognitionTerminate(void)
{
  if (_mcr_inst != NULL)
    mclTerminateInstance(&_mcr_inst);
}

LIB_ImRecognition_C_API 
void MW_CALL_CONV ImRecognitionPrintStackTrace(void) 
{
  char** stackTrace;
  int stackDepth = mclGetStackTrace(&stackTrace);
  int i;
  for(i=0; i<stackDepth; i++)
  {
    mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
    mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
  }
  mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_ImRecognition_C_API 
bool MW_CALL_CONV mlxRead_im(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "read_im", nlhs, plhs, nrhs, prhs);
}

LIB_ImRecognition_C_API 
bool MW_CALL_CONV mlxImg2attr(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "img2attr", nlhs, plhs, nrhs, prhs);
}

LIB_ImRecognition_C_API 
bool MW_CALL_CONV mlxAttWindows(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "AttWindows", nlhs, plhs, nrhs, prhs);
}

LIB_ImRecognition_C_API 
bool MW_CALL_CONV mlxCreateLexAtts(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[])
{
  return mclFeval(_mcr_inst, "createLexAtts", nlhs, plhs, nrhs, prhs);
}

LIB_ImRecognition_CPP_API 
void MW_CALL_CONV read_im(int nargout, mwArray& W, mwArray& H, mwArray& patch, const 
                          mwArray& path, const mwArray& imname, const mwArray& save2disk)
{
  mclcppMlfFeval(_mcr_inst, "read_im", nargout, 3, 3, &W, &H, &patch, &path, &imname, &save2disk);
}

LIB_ImRecognition_CPP_API 
void MW_CALL_CONV img2attr(int nargout, mwArray& featSize, mwArray& numBlockX, mwArray& 
                           numBlockY, mwArray& fv_Rep, const mwArray& im)
{
  mclcppMlfFeval(_mcr_inst, "img2attr", nargout, 4, 1, &featSize, &numBlockX, &numBlockY, &fv_Rep, &im);
}

LIB_ImRecognition_CPP_API 
void MW_CALL_CONV AttWindows(int nargout, mwArray& attsWin, const mwArray& windows, const 
                             mwArray& atts, const mwArray& N, const mwArray& D)
{
  mclcppMlfFeval(_mcr_inst, "AttWindows", nargout, 1, 4, &attsWin, &windows, &atts, &N, &D);
}

LIB_ImRecognition_CPP_API 
void MW_CALL_CONV createLexAtts(int nargout, mwArray& phocs, mwArray& words)
{
  mclcppMlfFeval(_mcr_inst, "createLexAtts", nargout, 2, 0, &phocs, &words);
}

