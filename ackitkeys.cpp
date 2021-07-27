//softkeys - ackit www.returnonerror.com
#include <iostream>
#include <string.h>
#include <vector>
#include <string>

using namespace std; 

/* some vars */
#define MAX_LEN 100
#define DELIM " \n"

int main(int argc, char** argv){

/* command line fun stuff */
   std::string cmd = "";
   char command[MAX_LEN];
   char* token;

/* load modules commands set in stone */
   std::vector<std::string> command_options;

    command_options.push_back("vuln-scan");
    command_options.push_back("web-spider");
    command_options.push_back("vuln-web");
    command_options.push_back("auto-exploit");
    command_options.push_back("fuzzer");
    command_options.push_back("dll-injector");
    command_options.push_back("shellcode");
    command_options.push_back("backdoors");
    command_options.push_back("rootkits");
    command_options.push_back("debug");
    command_options.push_back("help");

   std::vector<std::string>::iterator ackit_beg;

/* our fun little command line */

   while(1){
       cout<<cmd<<">";
       cin.getline(command,MAX_LEN);
       if(strlen(command) < 2) continue;
       token = strtok(command,DELIM);

       if(!strncmp(token,"load",MAX_LEN)){
          token = strtok(NULL,DELIM);
          if(!token)continue;
          for( ackit_beg = command_options.begin(); ackit_beg != command_options.end(); ackit_beg++){
              if(!strncmp(token,(*ackit_beg).c_str(),MAX_LEN)){
                  /******* TODO need to create module loading here *******/
                  std::cout<<"loading: "<<(*ackit_beg).c_str()<<std::endl;
                  cmd = *ackit_beg;
              }
          }
       }

       /* list modules that can be loaded with load command */
       if(!strncmp(token,"help",MAX_LEN)){
           std::cout<<"\nmodule list:"<<std::endl;
           std::cout<<"----------------"<<std::endl;
           for( ackit_beg = command_options.begin(); ackit_beg != command_options.end(); ackit_beg++){
                  std::cout<<(*ackit_beg).c_str()<<std::endl;
           }
           std::cout<<"\n";
        }
        
       /* exit the program */
       if(!strncmp(token,"exit",MAX_LEN)){
           break;
       }

    }
}
