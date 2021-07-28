// ackit - returnonerror.com
#ifndef ACKIT_LMODULES
#define ACKIT_LMODULES

#include <filesystem>
#include <vector>
#include <string>

#define PATH "modules/"

namespace ackit{
    class load_modules{
        private:
            std::vector<std::string> modules;
            std::vector<std::string>::iterator it;
        public:
            load_modules();
            std::string get_item(void);
            void reset(void);
    };
}
#endif /* ACKIT_LMODULES */
