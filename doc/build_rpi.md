## Issue with RPI

**It is recommended to not use Raspbian, instead use [Ubuntu Server for RPI](https://ubuntu.com/download/raspberry-pi)**

### Main Issue: Berkeley DB

The main issue you will face when compiling is activating CXX headers from berkeley-db. Normal download of db-4.8.30 will come with
config.sub and config.guess for desktop Linux, however these files need to be changed. To do so, first download db-4.8.30 to `~`:

`wget http://download.oracle.com/berkeley-db/db-4.8.30.zip`

`unzip db-4.8.30.zip`

Then follow these steps:

1. `cd /usr/share/automake-1.15`

2. `cp config.guess ~/db-4.8.30/dist`

3. `cp config.sub ~/db-4.8.30/dist`

4. `cd ~/db-4.8.30/build_unix`

5. `../dist/configure --prefix=/usr/local --enable-cxx`

6. `make`

7. `make install`
