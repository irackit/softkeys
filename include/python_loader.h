//ackit - returnonerror.com

#ifndef PYTHON_LOAD
#define PYTHON_LOAD

#include <Python.h>
#include <iostream>
#include <string>

namespace ackit{
    class python_loader{
        private:
            std::string filename;
            FILE *fp;
        public:
            python_loader(std::string);
    };
}

#endif /* PYTHON_LOAD */
