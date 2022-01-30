#ifndef _APP_APP_HPP
#define _APP_APP_HPP

namespace app {
   class App {
   public:
      App(int argc, char* argv[]);
      ~App();

      bool run();
   }; 
} // namespace app

#endif