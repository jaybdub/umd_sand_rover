keytrack
===

This repository contains code and data related to the ENES100 sand rover course.


Installing dependencies for GUI
---

1. Install Qt5.X
  1. Download Qt Online Installer for Linux 64-bit from [here](http://qt-project.org/downloads)
  2. The file should download to the ~/Downloads directory.  Open up a terminal and navigate to this directory:
  
    ```
    cd ~/Downloads
    ```
  3. Change permissions on the file so you can actually run it to install Qt.  
    
    ```
    chmod +x qt-opensource-linux-x64-1.6.0-3-online.run
    ```
  4.  Run the installer
    
    ```
    ./qt-opensource-linux-x64-1.6.0-3-online.run
    ```
  5.  Follow the instructions in the installation gui to install Qt (including Qt Creator)
2. Install CMake
    ```
    sudo pacman -S cmake
    ```

3. Install OpenCV2.4.9
  1. Download Opencv2.4.9 for Linux/Mac from [here](http://opencv.org/downloads.html)
  2. Extract the files to your home directory ~/
  3. Execute the following commands to install OpenCv

    ```
    cd ~/opencv-2.4.9
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    ```

4. Install ArUco 1.2.5
  1.  Download [aruco 1.2.5](http://sourceforge.net/projects/aruco/files/1.2.5/aruco-1.2.5.tgz/download)
  2.  Extract the downloaded file to your home directory (~/)
  3.  Execute the following commands in the terminal to install Aruco

    ```
    cd aruco-1.2.5
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    ```

5. Add the /usr/local/lib libraries to the library search path (so the installed programs are found by the compiler)
  1. Open up a text editor to edit the library config file
  
    ```
    sudo gedit /etc/ld.so.conf
    ```
  2. Add the following line anywhere in the file, and save.
    
    ```
    /usr/local/lib
    ```
  3.  Run ldconfig in the terminal

    ```
    sudo ldconfig
    ```
