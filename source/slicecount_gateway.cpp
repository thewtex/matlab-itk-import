/**
 * @file slicecount_gateway.cpp
 * @brief Matlab mex gateway function
 * @author Matthew McCormick (thewtex)
 * @version
 * @date 2009-07-01
 */

#include <memory>
#include <string>

using std::auto_ptr;

#include "mex.h"

#include "SliceCountPipeline.h"


void mexFunction(int nlhs, mxArray *plhs[],
    int nrhs, const mxArray *prhs[])
{
  // argument check
  if (nrhs != 1 ||
    (nlhs != 0 && nlhs !=1) ||
    !mxIsChar(prhs[0])
    )
    {
    std::string msg;
    msg += "Incorrect arguments, see 'help ";
    msg += mexFunctionName();
    msg += '\'';
    mexErrMsgTxt(msg.c_str());
    }

  char* filepath = mxArrayToString(prhs[0]);

  try
    {
    auto_ptr<SliceCountPipeline> pipeline(new SliceCountPipeline(filepath));
    plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
    double* s = mxGetPr(plhs[0]);
    pipeline->GetSlices(s);
    }
  catch (std::exception& e)
    {
    mexErrMsgTxt(e.what());
    return;
    }
}

