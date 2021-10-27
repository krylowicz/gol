#include "cinder/app/RendererGl.h"
#include "GameOfLife.hh"

using namespace ci;

void prepareSettings(GameOfLife::Settings* settings) {
  settings->setWindowSize(600, 400);
  settings->setFrameRate(60.0f);
}
 
CINDER_APP(GameOfLife, app::RendererGl, prepareSettings)
