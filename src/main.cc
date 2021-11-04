#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "cinder/app/RendererGl.h"
#include "Game.hh"

using namespace ci;

void prepareSettings(Game::Settings* settings) {
  settings->setWindowSize(600, 400);
  settings->setFrameRate(0.0f);
}

void Game::setup() {}

void Game::draw() {
  gl::clear();
  for (size_t i = 0; i < window.rows; ++i) {
    for (size_t j = 0; j < window.cols; ++j) {
      gol.drawCell(i, j);
    }
  }
  // gol.next();
}

CINDER_APP(Game, app::RendererGl, prepareSettings)
