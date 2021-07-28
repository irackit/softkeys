//softkeys - ackit www.returnonerror.com
//#include <Python.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <filesystem>
#include "include/optarg.h"

using namespace std; 

/* some vars */
#define MAX_LEN 100
#define DELIM " \n"

int main(int argc,char** argv){

    /* load module filenames */
    std::vector<std::string> modules;
    std::vector<std::string>::iterator ackit_beg;
    std::string path = "modules/";
    for(const auto& entry : std::filesystem::directory_iterator(path)){
        std::string path = entry.path().string();
        modules.push_back(path);
    }

    const std::string options = "l:s:d:h";
    ackit::softkeys_optarg *argu = new ackit::softkeys_optarg(argc,argv,options);

    char command[MAX_LEN];
    char* token;
    std::string cmd;
    int flag=0;

    while(1){

       cout<<cmd<<">";
       cin.getline(command,MAX_LEN);
       if(strlen(command) < 2) continue;
       token = strtok(command,DELIM);

       if(!strncmp(token,"load",MAX_LEN)){
          flag = 0;
          token = strtok(NULL,DELIM);
          if(!token){
              std::cout<<"syntax error"<<std::endl;
              continue;
          }
          for( ackit_beg = modules.begin(); ackit_beg != modules.end(); ackit_beg++){
              if(!strncmp(token,(*ackit_beg).c_str(),MAX_LEN)){
                  flag = 1;
                  std::cout<<"loading: "<<(*ackit_beg).c_str()<<std::endl;
                  std::string load = "python modules/" + *ackit_beg + ".py";
                  cmd = *ackit_beg;

                  /*
                    TODO: Load an run python script here
                 */
              }
          }
          if(flag == 0){
              std::cout<<"syntax error"<<std::endl;
          }
              
       }

       if(!strncmp(token,"list",MAX_LEN)){
           std::cout<<"\nmodule list:"<<std::endl;
           std::cout<<"----------------"<<std::endl;
           for( ackit_beg = modules.begin(); ackit_beg != modules.end(); ackit_beg++){
                  std::cout<<(*ackit_beg).c_str()<<std::endl;
           }
           std::cout<<"\n";
        }
        
       if(!strncmp(token,"help",MAX_LEN)){
           std::cout<<"softkeys [load | list | exit]"<<std::endl;
       }

       if(!strncmp(token,"exit",MAX_LEN)){
           break;
       }

    }

}
