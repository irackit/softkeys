// ackit - returnonerro.com
#include "include/load_modules.h"

ackit::load_modules::load_modules(){

    for(const auto& entry : std::filesystem::directory_iterator(PATH)){
        std::string path = entry.path().string();
        this->modules.push_back(path);
    }

    this->it = this->modules.begin();

}
    
void ackit::load_modules::reset(void){
    this->it = this->modules.begin();
}

std::string ackit::load_modules::get_item( void ){

    if( this->it != (this->modules).end()){
        return *((this->it)++);
    }
    return "";
}
