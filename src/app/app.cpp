#include "app/app.hpp"

#include "app/ui/main_window.hpp"

#include <cassert>
#include <gtkmm/application.h>

#define MARS_APPLICATION_ID "com.phobos.mars"

namespace app {
   static Glib::RefPtr<Gtk::Application> s_gtkApp(nullptr);
   App* App::s_instance = nullptr;

   App::App(int argc, char* argv[]) {
      assert(!s_instance);s_instance = this;

      s_gtkApp = Gtk::Application::create(argc, argv, MARS_APPLICATION_ID);
      mMainWindow = new MainWindow();
   }

   App::~App() {
      assert(s_instance);s_instance = nullptr;
      s_gtkApp.reset();

      delete mMainWindow;
   }

   int App::run() const {
      return s_gtkApp->run(*mMainWindow);
   }
} // namespace app