//ackit - returnonerror.com
#include "include/optarg.h"

/* TODO most everything */
ackit::softkeys_optarg::softkeys_optarg(const int& argc,char** argv, const std::string& options):count(argc),argv(argv),options(options){

    while((this->opt = getopt(this->count,this->argv,this->options.c_str())) != -1){
        switch(this->opt){
            case 'l':
                std::cout<<"load"<<std::endl;
            break;
            case 's':
                std::cout<<"set"<<std::endl;
            break;
            case 'd':
                std::cout<<"database"<<std::endl;
            break;
            case 'h':
            default:
                std::cout<<"softkeys -l module -s vars -d background process"<<std::endl;
                std::cout<<"\t -l MODULE Load a module"<<std::endl;
                std::cout<<"\t -s KEY=VALUE Set vars for loaded module"<<std::endl;
                std::cout<<"\t -d Run as background process"<<std::endl;
                std::cout<<"\t -h This menu"<<std::endl;
        }
    }
}
