```
**BUILDING LTNET**

1/ BOOST
Download and extract Boost 1.63 to C:\boost_1_63_0
Go to C:\boost_1_63_0 and execute "bootstrap.bat", then ".\b2 --toolset=msvc-14.0 address-model=64 architecture=x86"
Add BOOST_ROOT (C:\boost_1_63_0), BOOST_BUILD_PATH (C:\boost_1_63_0\tools\build) to Environment path and C:\boost_1_63_0 to Path

2/ Libtorrent
Download and extract libtorrent-rasterbar to C:\libtorrent-libtorrent-1_1_3
Compile libtorrent using "bjam link=static variant=release boost-link=static address-model=64 architecture=x86"

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
