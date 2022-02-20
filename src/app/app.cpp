#include "app/app.hpp"

#include "app/ui/main_window.hpp"

#include <cassert>
#include <gtkmm/application.h>
#include <gtkmm/builder.h>

#define MARS_APPLICATION_ID "com.phobos.mars"

namespace app {
   App* App::s_instance = nullptr;

   App::App(int argc, char* argv[]) :
      Gtk::Application(argc, argv, MARS_APPLICATION_ID),
      mMainWindow(new MainWindow()) {
      assert(!s_instance);s_instance = this;
   }

   App::~App() {
      assert(s_instance);s_instance = nullptr;
   }

   void App::on_startup() {
      Gtk::Application::on_startup();

      loadMenuBar();

      add_window(*mMainWindow.get());
      mMainWindow->present();
   }

   static void foo() {
      puts("--foo--");
   }

   void App::loadMenuBar() {
      auto refBuilder = Gtk::Builder::create();
      refBuilder->add_from_resource("/ui/menubar.ui");
      auto obj = refBuilder->get_object("menubar");
      auto menuBar = Glib::RefPtr<Gio::MenuModel>::cast_dynamic(obj);
      set_menubar(menuBar);
   }
} // namespace app