# LBM mini project in C++ OpenACC (GPU)

A minimal cmake based project skeleton for 2D LBM (Lattice Boltzmann Method) simulation.

This C++ code has been adapted from the python code [lbmFlowAroundCylinder.py](https://github.com/sidsriv/Simulation-and-modelling-of-natural-processes/blob/master/lbmFlowAroundCylinder.py)

## about cmake

This template has been derived from [cuda-proj-tmpl](https://github.com/pkestene/cuda-proj-tmpl) so that it is ready for CUDA.

## How to build the serial version ?

```bash
mkdir build
cd build
cmake ..
make
# then you can run the application
./src/lbm
```

## Task

Derive a parallel version of this code using OpenACC.

The graph below resumes the results for different size of grid. The speed up is more impressive for bigger grid.    
                  <div style="text-align:center">![image](https://user-images.githubusercontent.com/64479324/111080437-be0cc680-84fe-11eb-8f09-547f321bb3f9.png)</div>


## How to build the OpenACC version ?
comment all the OpenAcc directive under the TODO comment in the main and in the different CMakeLists.Txt
```bash
mkdir build_openacc
cd build_openacc
export CXX=nvc++
cmake -DOpenACC_TARGET_FLAGS:STRING="-ta=tesla:cc75 -Minfo=all" ..
make
```

Variable `OpenACC_TARGET_FLAGS` allows you to pass compiler flags to `nvc++` compiler.
