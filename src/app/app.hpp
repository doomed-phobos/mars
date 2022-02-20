#ifndef _MARS_APP_HPP
#define _MARS_APP_HPP
#include <gtkmm/application.h>

namespace app {
   class MainWindow;

   class App : public Gtk::Application {
   public:
      App(int argc, char* argv[]);
      ~App();
   protected:
      virtual void on_startup() override;
   private:
      static App* s_instance;

      void loadMenuBar();

      Glib::RefPtr<MainWindow> mMainWindow;
   };
} // namespace app

#endif