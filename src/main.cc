#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;

class BasicApp : public app::App {
  public:
    void draw() override;
};

void BasicApp::draw() {
  gl::clear();
  gl::drawSolidCircle(getWindowCenter(), 200);
}

CINDER_APP(BasicApp, app::RendererGl);