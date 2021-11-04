#include <array>
#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "cinder/app/MouseEvent.h"
#include "GameOfLife.hh"
#include "GolViewer.hh"
#include "Window.hh"

using namespace ci;

GolViewer::GolViewer(GameOfLife& gol_, Window& window_): gol {gol_}, window {window_} {}

bool GolViewer::isPlaying() {
  return playing;
}

bool GolViewer::isMouseInWindow(size_t i, size_t j) const {
  if (i > 0 && j > 0 && i < app::getWindowWidth() && j < app::getWindowHeight()) {
    return true;
  }
  return false;
}

std::array<size_t, 2> GolViewer::getCoordinates(size_t i, size_t j) {
  if (i > 0 && j > 0 && i < app::getWindowWidth() && j < app::getWindowHeight()) {
    i = (i * window.rows) / app::getWindowWidth();
    j = (j * window.cols) / app::getWindowHeight();

    return std::array<size_t, 2> {i, j};
  }
  return std::array<size_t, 2> {};
}

void GolViewer::keyDown(app::KeyEvent& event) {
  if (event.KEY_SPACE) {
    if (playing) {
      playing = false;
    } else {
      playing = true;
    }  
  }
}

void GolViewer::mouseDown(app::MouseEvent& event) {
  if (event.isLeft() || event.isRight()) {
    drawing = true;
    auto i {event.getX()};
    auto j {event.getY()};

    if (isMouseInWindow(i, j)) {
      auto [x, y] = getCoordinates(i, j);
      event.isLeft() ? gol.setCellActive(x, y)  : gol.setCellInactive(x, y);
    }
  }
}

void GolViewer::mouseUp(app::MouseEvent& event) {
  if (drawing) {
    if (event.isLeft() || event.isRight()) {
      drawing = false;
    }
  }
}

void GolViewer::mouseDrag(app::MouseEvent& event) {
  if (drawing) {
    if (event.isLeft()) {
      auto i {event.getX()};
      auto j {event.getY()};

      if (isMouseInWindow(i, j)) {
        auto [x, y] = getCoordinates(i, j);
        gol.setCellActive(x, y);
      }
    }
    if (event.isRight()) {
      auto i {event.getX()};
      auto j {event.getY()};

      if (isMouseInWindow(i, j)) {
        auto [x, y] = getCoordinates(i, j);
        gol.setCellInactive(x, y);
      }
    }
  }
}