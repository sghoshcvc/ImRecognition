//
// MATLAB Compiler: 4.17 (R2012a)
// Date: Tue Dec 16 16:58:05 2014
// Arguments: "-B" "macro_default" "-W" "cpplib:libReadIm" "-T" "link:lib"
// "read_im" "img2attr" "AttWindows" "createLexAtts" 
//

#ifndef __libReadIm_h
#define __libReadIm_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__SUNPRO_CC)
/* Solaris shared libraries use __global, rather than mapfiles
 * to define the API exported from a shared library. __global is
 * only necessary when building the library -- files including
 * this header file to use the library do not need the __global
 * declaration; hence the EXPORTING_<library> logic.
 */

#ifdef EXPORTING_libReadIm
#define PUBLIC_libReadIm_C_API __global
#else
#define PUBLIC_libReadIm_C_API /* No import statement needed. */
#endif

#define LIB_libReadIm_C_API PUBLIC_libReadIm_C_API

#elif defined(_HPUX_SOURCE)

#ifdef EXPORTING_libReadIm
#define PUBLIC_libReadIm_C_API __declspec(dllexport)
#else
#define PUBLIC_libReadIm_C_API __declspec(dllimport)
#endif

#define LIB_libReadIm_C_API PUBLIC_libReadIm_C_API


#else

#define LIB_libReadIm_C_API

#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_libReadIm_C_API 
#define LIB_libReadIm_C_API /* No special import/export declaration */
#endif

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV libReadImInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV libReadImInitialize(void);

extern LIB_libReadIm_C_API 
void MW_CALL_CONV libReadImTerminate(void);



extern LIB_libReadIm_C_API 
void MW_CALL_CONV libReadImPrintStackTrace(void);

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV mlxRead_im(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV mlxImg2attr(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV mlxAttWindows(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_libReadIm_C_API 
bool MW_CALL_CONV mlxCreateLexAtts(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__BORLANDC__)

#ifdef EXPORTING_libReadIm
#define PUBLIC_libReadIm_CPP_API __declspec(dllexport)
#else
#define PUBLIC_libReadIm_CPP_API __declspec(dllimport)
#endif

#define LIB_libReadIm_CPP_API PUBLIC_libReadIm_CPP_API

#else

#if !defined(LIB_libReadIm_CPP_API)
#if defined(LIB_libReadIm_C_API)
#define LIB_libReadIm_CPP_API LIB_libReadIm_C_API
#else
#define LIB_libReadIm_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_libReadIm_CPP_API void MW_CALL_CONV read_im(int nargout, mwArray& W, mwArray& H, mwArray& patch, const mwArray& path, const mwArray& imname, const mwArray& save2disk);

extern LIB_libReadIm_CPP_API void MW_CALL_CONV img2attr(int nargout, mwArray& featSize, mwArray& numBlockX, mwArray& numBlockY, mwArray& fv_Rep, const mwArray& im);

extern LIB_libReadIm_CPP_API void MW_CALL_CONV AttWindows(int nargout, mwArray& attsWin, const mwArray& windows, const mwArray& atts, const mwArray& N, const mwArray& D);

extern LIB_libReadIm_CPP_API void MW_CALL_CONV createLexAtts(int nargout, mwArray& phocs, mwArray& words);

#endif
#endif
