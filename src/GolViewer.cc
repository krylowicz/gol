#include "cinder/app/App.h"
#include "cinder/app/KeyEvent.h"
#include "GolViewer.hh"

using namespace ci;

void GolViewer::keyDown(app::KeyEvent& event) {
  if (app::KeyEvent::KEY_SPACE) {
    if (playing) {
      app::setFrameRate(0.0f);
      playing = false;  
    } else {
      app::setFrameRate(60.0f);
      playing = true;
    }  
  }
}