# SDL2 WEB (Using EMSCRIPTEN) 

Flask app used to presents the great SDL2 Web portability showed by the siko-dev blog tutorial 


## Usage (if you only want to run the app)

```python
python3 app.py
```

## If you want to create another SDL2 Web assembly app 


## Prerequisite installation

CMAKE & NODEJS

```bash
sudo apt-get install cmake nodejs
```



## Configure EMSDK

- Use the SDK in this github repository or download it

- Extract it 

```bash
    tar zxf emsdk_portable.tgz
```

- Go in it

```bash
     cd emsdk_portable
```


- Update the EMSDK

```bash
     ./emsdk update
```


- Install the latest version

```bash
     ./emsdk install latest
```

- Activate the latest version

```bash
     ./emsdk activate latest
```


- Change the NODE_JS variable in the script which contains EMSCRIPTEN's environment variables
  - Usage :  Give the access of the different modules (Example: the em++ command) 
  - File : You can find it in the SDK directory 
  - Example :  directory-of-emsdk/.emscripten

    NODE_JS = 'nodejs'


- Source 
  - Usage : Load EMSCRIPTEN environnement in our current environment 


```bash
     source /path/through/emsdk-portable/emsdk_env.sh
```

## Use the configured EMSDK you just configured 
 
- Create your SDL2 project (or use the source code of main.cpp script)
- Build it (without EMSDK option)

```bash
     gcc main.cpp -o demo `sdl2-config --cflags --libs`
```

- Build it (with EMSDK)

```bash
     em++ main.cpp -o demo.html -s USE_SDL=2 -O2
```

## Now you can run it
 
- demo.js  
  - Converted game ready to be deploy on the web

- demo.html 
  - It will call the generated JS script  

- demo.html.mem 
  - Memory file   

- demo.html.wasm
  - Web assembly file


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Initial author - Big thanks 
(Thanks to Isabelle Garcia and her siko-dev blog tutorial, please use the link below to visit it ! 
 )

# Sources 
https://www.sikorama.fr/2017/05/07/tutoriel-emscripten-et-sdl2/

