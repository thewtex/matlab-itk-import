#include "MainPipeline.h"

MainPipeline::MainPipeline(char* filepath, unsigned int slice):
  m_filepath(filepath),
  m_slice(slice)
{
  m_reader = ReaderType::New();
  m_reader->SetFileName(filepath);
  
  m_roi_filter = ROIType::New();
  m_reader->UpdateOutputInformation();
  m_roi_filter->SetInput(m_reader->GetOutput());
  ImageType::RegionType in_region = m_reader->GetOutput()->GetLargestPossibleRegion();
  ImageType::SizeType size = in_region.GetSize();
  ImageType::IndexType index = in_region.GetIndex();
  size[2] = slice;
  ImageType::RegionType desired_region;
  desired_region.SetSize(size);
  desired_region.SetIndex(index);
  m_roi_filter->SetRegionOfInterest(desired_region);
}

void MainPipeline::Update()
{
  m_roi_filter->Update();
}

