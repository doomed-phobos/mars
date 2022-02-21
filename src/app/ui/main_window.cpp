#include "app/ui/main_window.hpp"

// TODO: Add functions to load files,
//       All entry possibles forward to an one function

namespace app {
   MainWindow::MainWindow() :
      Gtk::ApplicationWindow() {
      set_title("Mars");
      set_position(Gtk::WIN_POS_CENTER);
      configureMenuBar();

   }

   void MainWindow::configureMenuBar() {
      /*#define BEGIN_ACTION_GROUP() {\
         auto ag = Gio::SimpleActionGroup::create();
      #define ADD_ACTION(group_name, name) \
         ag->add_action(#name, sigc::mem_fun0(this, &MainWindow::on_menu_##group_name##_##name));
      #define END_ACTION_GROUP(group_name) \
         insert_action_group(#group_name, ag); \
      }
      // =============
      // File
      // =============
      BEGIN_ACTION_GROUP()
         ADD_ACTION(file, exit)
      END_ACTION_GROUP(file)*/
   }
} // namespace app