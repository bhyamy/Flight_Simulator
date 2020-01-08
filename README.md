# Flight Gear Simulator
This is a second year on-going project in the course "Advanced Programming".  
In this milestone we will implement an interpreter that will allow us to control the plane virtually.  
We will operate the plane according to a pre-written list of commands(fly.txt), use a lexer to split the file into tokens, parse them and operate the plane. 
This program acts both as a server and and as a client to the simulator:  
- Client: sends the simulator data via fly.txt file with instructions according to the data in the program
- Server: receives flight information from the simulator and updates it in the program          

 Our goals in this milestone: client-server architecture, establish TCP connection, Threading.          
 In this milestone we focused on making the plane takeoff, in the future project we will use comparison algorithms, recieve several clients, etc.
## Installation

1. Download the FlightGear Simulator from the official website: [https://www.flightgear.org/](https://www.flightgear.org/) (Linux version)
2. Inside the FlightGear program add these commands in Settings->Additional Settings:  
- ‫‪--telnet=socket,in,10,127.0.0.1,5402,tcp‬‬ --httpd=8080                                 
-  --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
3. Plant "generic_small.xml" to "‫‪‫‪data/protocol‬‬‬‬" inside the flightgear folder
4. Download the files from git and put them all in the same folder

## Compilation
1. Run the following commands in Linux terminal:                                                  
- g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o fly -pthread       
- ./fly                                               
2. Start the FlightGear by pressing "Fly!"



## Authors
Yam Ben-Hamo - Bar Ilan Universty

Iris Gorelek - Bar Ilan University
