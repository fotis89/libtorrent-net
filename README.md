```
**BUILDING LTNET**

1/ BOOST
Download and extract Boost 1.64 to C:\boost_1_64_0
Go to C:\boost_1_64_0 and execute "bootstrap.bat", then ".\b2 --toolset=msvc-14.1 architecture=x86"
Add BOOST_ROOT (C:\boost_1_64_0), BOOST_BUILD_PATH (C:\boost_1_64_0\tools\build) to Environment path and C:\boost_1_64_0 to Path

2/ Libtorrent
Download and extract libtorrent-rasterbar to C:\libtorrent-rasterbar-1.1.3
Compile libtorrent using "bjam link=static variant=release boost-link=static architecture=x86"

3/ Ltnet
Open solution, set Release/x86, build.
```

# Usage

* Include the library as a reference to any .NET project and simply use the libtorrent API.