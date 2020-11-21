mkdir -p interface/emscripten
docker run --rm -v ${PWD}:/src trzeci/emscripten /bin/bash -c "cd interface/emscripten &&  emcmake cmake ../.. -DEMSCRIPTEN=True && emmake make"

# Complie docker container
# docker build -t rzeci/emscripten .