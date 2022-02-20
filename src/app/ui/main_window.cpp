#include "app/ui/main_window.hpp"

#include <gtkmm/builder.h>
#include <giomm/menu.h>

namespace app {
   MainWindow::MainWindow() {
      set_title("Mars");

      auto menuObj = Gtk::Builder::create_from_resource("/ui/menubar.xml")->get_object("menubar");
      add(*Gtk::make_managed<Gtk::MenuBar>(Glib::RefPtr<Gio::Menu>::cast_dynamic(menuObj)));

      show_all_children();
   }
} // namespace app