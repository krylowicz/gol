#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "GameOfLife.hh"

using namespace ci;

void GameOfLife::draw() {
  gl::clear();
  gl::drawSolidCircle(getWindowCenter(), 200);
}

CINDER_APP(GameOfLife, app::RendererGl);
