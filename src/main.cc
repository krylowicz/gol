#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/gl/gl.h"
#include "cinder/app/RendererGl.h"

#include "GameOfLife.hh"
#include "GolViewer.hh"

using namespace ci;

class Game : public app::App {
  private:
    const size_t res {10};
    const size_t rows {app::getWindowWidth() / res};
    const size_t cols {app::getWindowHeight() / res};

    GameOfLife gol {res, rows, cols};
    GolViewer viewer {};

  public:
    void setup() override;
    void draw() override;

    void keyDown(app::KeyEvent event) override { viewer.keyDown(event); }
};

void prepareSettings(Game::Settings* settings) {
  settings->setWindowSize(600, 400);
  settings->setFrameRate(60.0f);
}

void Game::setup() {}

void Game::draw() {
  gl::clear();
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (gol.isCellActive(i, j)) {
        auto top {ci::vec2(i * res, j * res)};
        auto bottom {ci::vec2((i + 1) * res - 1, (j + 1) * res - 1)};        

        gl::drawSolidRect(Rectf(top, bottom));
      }
    }
  }
  gol.next();
}

CINDER_APP(Game, app::RendererGl, prepareSettings)
