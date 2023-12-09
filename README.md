# lfs_hw
Complex Linux project homework

## Usage

### Getting started

1) Clone the repository.
    ```git clone https://github.com/yur4sh/lfs_hw.git```
2) Go to repo directory.
    ```cd lfs_hw```

### Building targets

1) To build the projects in one step try:
    ```make```

2) To compile general files of the project
    ```make compile```

3) To compile dynamic library of the project
    ```make shared```

4) Check if library is installed successfully.
    ```ls -l /usr/local/lib/libconvert.so```

5) To link all build artifacts including shared library.
    ```make link```

6) To clean local build artifacts.
    ```make clean```
