#ifndef _MARS_APP_UI_MAIN_WINDOW_HPP
#define _MARS_APP_UI_MAIN_WINDOW_HPP
#include <gtkmm/applicationwindow.h>

namespace app {
   class MainWindow : public Gtk::ApplicationWindow {
   public:
      MainWindow();
   private:
      // ==============
      // Menues
      // ==============
      void configureMenuBar();
   };
} // namespace app

#endif