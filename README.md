# cli-boost
simple example on how to use boost to handle command line interface. The example is from an old simple molecular dynamics programme I have written long time ago

##build the project 
```
#clone the project... 
git clone https://github.com/alinelena/cli-boost.git
#get inside... 
pushd cli-boost
mkdir -p build
pushd build
cmake ../
make
make test
make docs
popd
popd
```

##sample usage

```
[15:55:36 alin@abaddon:~/playground/cli-boost/build]: bin/cli 
Creating empty config file 
Echo the options used 
config options.conf 
method TAMC 
steps 42 
```

```
[15:55:39 alin@abaddon:~/playground/cli-boost/build]: bin/cli -h
Command line Options:
Command Line and Config File Options:

Command Line Only Options:
  -h [ --help ]                        Prints help messages
  -v [ --version ]                     Show me the version
  -c [ --config ] arg (=options.conf)  Config file from where options can be 
                                       read

Config File Options:
  -s [ --steps ] arg (=42)             Number of steps
  -m [ --method ] arg (=TAMC)          Method to be employed
```

```
[15:55:41 alin@abaddon:~/playground/cli-boost/build]: bin/cli 
Echo the options used
config options.conf
method TAMC
steps 42
```
