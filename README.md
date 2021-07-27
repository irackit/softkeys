# softkeys
vuln scanner, web spider, web scanner, auto exploiter, fuzzer, dll injector, shellcoder, backdoors, rootkits, debugger framework
-----------------------------------------------------------------------------------------------------------------------------------


/* vuln-scan */

vuln-scan -d type select-db user [password]
          -h ([ip | url])
          -p ([port | port-range | port [,]])
          -o os-type
         

vuln-scan ::= '-' switch [options]

  switch ::= 'd','h','p','o'

  d ::= database
  h ::= host
  p ::= port
  o ::= os-type

  database ::= type select-db user [password]
   type ::= ([MySQL | postgresal])
   select-db ::= "database to select"
   user ::= "username"
   password ::= "sql password"

  host ::= (ip | url)
   ip ::= "ipv4 address"
   url ::= ( http | https ) "site address"

  port ::= (dport | dport-range | dport-comma)
   dport ::= port-number
   dport-range ::= port-number:port-number
   dport-comma ::= *(port-number ',')
   port-number ::= *('1' '2' '3' '4' '5' '6' '7' '8' '9' '0')

  os-type ::= (operating-system | all) [version]
   operating-system ::= "operating system name"
   all ::= "scan with all could"
   version ::= "service patch, version number"
