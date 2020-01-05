# flySimulator1.0
link to git hub: 
this project is 
## Installation
to start the simulator ypu need to install flightgear simulator from the link: https://www.flightgear.org/
or do the following command at the terminal:
* sudo add-apt-repository ppa:saiarcot895/flightgear
* sudo apt-get update
* sudo apt-get install flightgear
after getting the simulator, there're several change at the setting:
--generic=socket,out,10,127.0.0.1,5400,tcp,generic_small   
--telnet=socket,in,10,127.0.0.1,5402,tcp
then, download the file generic_small to the protocol folder under data of the simulator code.
in addintion, add to the project file that give the simultor Instructions how to fly the airplane.
## Usage
compile the main.cpp with argument that contains the name file that the simulator will read the information from.
gcc main.cpp <argumen>
for example gcc main.cpp fly.txt
## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D
## History
TODO: Write history
## Credits
TODO: Write credits
## License
TODO: Write license
]]></content>
  <tabTrigger>readme</tabTrigger>
</snippet>
