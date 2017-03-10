```
**BUILDING LTNET**

1/ BOOST
Download and extract Boost 1.62 to C:\boost_1_62_0
Go to C:\boost_1_62_0 and execute "bootstrap.bat", then ".\b2 --toolset=msvc-14.0 address-model=64 architecture=x86"
Add BOOST_ROOT (C:\boost_1_62_0), BOOST_BUILD_PATH (C:\boost_1_62_0\tools\build) to Environment path and C:\boost_1_62_0 to Path

2/ Libtorrent
Download and extract libtorrent-rasterbar to C:\libtorrent-rasterbar-1.0.10
Compile libtorrent using "bjam geoip=off resolve-countries=off link=static variant=release boost=source boost-link=static encryption=tommath address-model=64 architecture=x86"

3/ Ltnet
Open administrator text editor and edit :
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\thread
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\mutex
Delete :
#ifdef _M_CEE
  #error <thread> is not supported when compiling with /clr or /clr:pure.
#endif /* _M_CEE */

Open solution, set Release/x64, build.
```
