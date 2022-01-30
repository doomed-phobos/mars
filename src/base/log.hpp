#ifndef _BASE_LOG_HPP
#define _BASE_LOG_HPP

namespace base {
   class Logger {
   public:
      static Logger& GetInstance();
   private:
      static inline Logger s_instance;
   };
} // namespace base

#endif