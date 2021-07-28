// ackit - returnonerro.com
#include "include/load_modules.h"

ackit::load_modules::load_modules(){
/*
    for(const auto& entry : std::filesystem::directory_iterator(PATH)){
        std::string path = entry.path().string();
        this->modules.push_back(path);
    }
    this->it = this->modules.begin();
*/
    DIR *dir;
    dirent* ent;
    if((dir = opendir(PATH)) != NULL){
        while((ent = readdir(dir)) != NULL){
            if(!strncmp(".",ent->d_name,MAX_LEN) || !strncmp("..",ent->d_name,MAX_LEN))continue;
            std::string fullname = PATH;
            fullname += ent->d_name;
            this->modules.push_back(fullname);
        }
        closedir(dir);
    }
    else{
        std::cout<<"file error"<<std::endl;
    }
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
