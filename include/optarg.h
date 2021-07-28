// ackit - returnonerror.com

#ifndef ACKIT_OPTARG
#define ACKIT_OPTARG

#include <iostream>
#include <string>
#include <map>
#include "unistd.h"

namespace ackit {
    class softkeys_optarg{
        private:
            const std::string options;
            int opt;
            const int count;
            char** argv;
        public:
            softkeys_optarg(const int&, char**, const std::string&);
    }; 
}

#endif /* ACKIT_OPTARG */
