/** 
 * @file MainPipeline.h
 * @brief Creates and executes the ITK pipeline
 * @author Matthew McCormick (thewtex)
 * @version 
 * @date 2009-07-01
 */

#ifndef _MAINPIPELINE_H
#define _MAINPIPELINE_H

#include "itkImageFileReader.h"

class MainPipeline
{
public:
  MainPipeline(char* filepath, unsigned int slice=0);

  /** 
   * @brief Update the pipeline
   */
  void Update();

  // main itk types
  typedef double PixelType;
  const static unsigned int Dimension = 3;
  typedef itk::Image<PixelType, Dimension> ImageType;

protected:
  // filter types
  typedef itk::ImageFileReader<ImageType> ReaderType;
  ReaderType::Pointer m_reader;

  char* m_filepath;
  unsigned int m_slice;

};

#endif // _MAINPIPELINE_H
