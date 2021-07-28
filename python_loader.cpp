//ackit - returnonerror.com
#include "include/python_loader.h"

ackit::python_loader::python_loader(std::string filename):filename(filename){
    Py_Initialize();
    PyObject *obj = Py_BuildValue("s",this->filename.c_str());
    this->fp = _Py_fopen_obj(obj,"r+");
    if(this->fp != NULL){
        PyRun_SimpleFile(this->fp,this->filename.c_str());
    }
    else{
        std::cout<<"python error"<<std::endl;
    }
    Py_Finalize();
}
