#ifndef _MARS_APP_HPP
#define _MARS_APP_HPP

namespace app {
   class MainWindow;

   class App {
   public:
      App(int argc, char* argv[]);
      ~App();

      int run() const;
   private:
      static App* s_instance;

      MainWindow* mMainWindow;
   };
} // namespace app

#endif