#include "MainPipeline.h"

MainPipeline::MainPipeline(char* filepath, unsigned int slice):
  m_filepath(filepath),
  m_slice(slice)
{
  m_reader = ReaderType::New();
  m_reader->SetFileName(filepath);
}

void MainPipeline::Update()
{
  m_reader->Update();
}

