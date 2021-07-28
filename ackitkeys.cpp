//softkeys - ackit www.returnonerror.com
//#include <Python.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include "include/optarg.h"
#include "include/load_modules.h"
#include "include/python_loader.h"

using namespace std; 

/* some vars */
#define MAX_LEN 100
#define DELIM " \n"

int main(int argc,char** argv){

    /* load module filenames */
    ackit::load_modules *modules = new ackit::load_modules();
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

          modules->reset();
          while(1){
                std::string ret = modules->get_item();
                if(ret == ""){
                    break;
                }
                if(!strncmp(token,ret.c_str(),MAX_LEN)){
                  flag = 1;
                  ackit::python_loader* python = new ackit::python_loader(ret);
                  delete python;
                  cmd = ret;
                  break;
              }
           }
 
          if(flag == 0){
              std::cout<<"syntax error #003"<<std::endl;
          }
       }

       if(!strncmp(token,"list",MAX_LEN)){
           std::cout<<"\nmodule list:"<<std::endl;
           std::cout<<"----------------"<<std::endl;
           std::string ret;
           modules->reset();

           while(1){
                std::string ret = modules->get_item();
                if(strlen(ret.c_str()) < 1){
                    break;
                }
                std::cout<<ret<<std::endl;
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
    delete modules;
    delete argu;
}

