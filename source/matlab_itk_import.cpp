/** 
 * @file matlab_itk_import.cpp
 * @brief gateway function
 * @author Matthew McCormick (thewtex)
 * @version 
 * @date 2009-07-01
 */

#include "mex.h" 

#include "MainPipeline.h"


void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
  // argument check
  if (nrhs < 1 || 
    nrhs > 2 ||
    !mxIsChar(prhs[0]) ||
    (nrhs == 2 && !mxIsNumeric(prhs[1])) )
    mexErrMsgTxt("Incorrect arguments, see 'help @MATLAB_FUNCTION_NAME@'");

  char* filepath = mxArrayToString(prhs[0]);
  unsigned int slice = 0;
  if (nrhs > 1)
    slice = static_cast<unsigned int>(*mxGetPr(prhs[1]));

  try
    {
    MainPipeline pipeline(filepath, slice);
    pipeline.Update();
    }
  catch (std::exception& e)
    {
    mexErrMsgTxt(e.what());
    return;
    }

} 

